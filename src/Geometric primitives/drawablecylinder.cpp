#include "drawablecylinder.hpp"

#include <vtkActor.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkProperty.h>

using namespace Drawables;
Cylinder::Cylinder()
{
    radius = 0;
    height = 0;
}

Cylinder::~Cylinder()
{

}

double Cylinder::getRadius() const
{
    return radius;
}

void Cylinder::setRadius(double newRadius)
{
    radius = newRadius;
}

double Cylinder::getHeight() const
{
    return height;
}

void Cylinder::setHeight(double newHeight)
{
    height = newHeight;
}

SemantisedTriangleMesh::Point Cylinder::getCentre() const
{
    return centre;
}

void Cylinder::setCentre(SemantisedTriangleMesh::Point newCentre)
{
    centre = newCentre;
}

SemantisedTriangleMesh::Point Cylinder::getAxis() const
{
    return axis;
}

void Cylinder::setAxis(SemantisedTriangleMesh::Point newAxis)
{
    axis = newAxis;
}

DrawableCylinder::DrawableCylinder()
{
    color = new double[3];
    resolution = 0;
}

void DrawableCylinder::update()
{
    auto cylinder = vtkNew<vtkCylinderSource>();
    cylinder->SetCenter(centre.getX(), centre.getY(), centre.getZ());
    cylinder->SetHeight(height);
    cylinder->SetRadius(radius);
    cylinder->SetResolution(resolution);
    cylinder->Update();
    SemantisedTriangleMesh::Point zAxis(0, 0, 1);
    double angle = std::acos(zAxis * axis);
    auto transform = vtkNew<vtkTransform>();
    transform->RotateWXYZ(angle, axis.getX(), axis.getY(), axis.getZ());
    auto transformFilter = vtkNew<vtkTransformPolyDataFilter>();
    transformFilter->SetTransform(transform);
    transformFilter->SetInputData(cylinder->GetOutput());
    transformFilter->Update();
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(transformFilter->GetOutputPort());
    vtkNew<vtkActor> surfaceActor;
    surfaceActor->SetMapper(mapper);
    surfaceActor->GetProperty()->SetColor(color[0], color[1], color[2]);
    surfaceActor->GetProperty()->SetOpacity(opacity);
    canvas->AddPart(surfaceActor);
    vtkNew<vtkActor> wireframeActor;
    wireframeActor->SetMapper(mapper);
    wireframeActor->GetProperty()->SetColor(0, 0, 0);
    canvas->AddPart(wireframeActor);
}

void DrawableCylinder::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    assembly->RemovePart(canvas);
    assembly->AddPart(canvas);
    assembly->Modified();

}

double *DrawableCylinder::getColor() const
{
    return color;
}

void DrawableCylinder::setColor(double *newColor)
{
    color = newColor;
}

void DrawableCylinder::setColor(double r, double g, double b)
{

    color[0] = r;
    color[1] = g;
    color[2] = b;
}

uint DrawableCylinder::getResolution() const
{
    return resolution;
}

void DrawableCylinder::setResolution(uint newResolution)
{
    resolution = newResolution;
}
