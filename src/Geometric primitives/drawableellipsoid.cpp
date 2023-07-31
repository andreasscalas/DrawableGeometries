#include "drawableellipsoid.hpp"

#include <vtkActor.h>
#include <vtkParametricEllipsoid.h>
#include <vtkParametricFunctionSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkProperty.h>

using namespace Drawables;
Ellipsoid::Ellipsoid()
{
    xRadius = 0;
    yRadius = 0;
    zRadius = 0;
}

Ellipsoid::~Ellipsoid()
{

}

double Ellipsoid::getXRadius() const
{
    return xRadius;
}

void Ellipsoid::setXRadius(double newXRadius)
{
    xRadius = newXRadius;
}

double Ellipsoid::getYRadius() const
{
    return yRadius;
}

void Ellipsoid::setYRadius(double newYRadius)
{
    yRadius = newYRadius;
}

double Ellipsoid::getZRadius() const
{
    return zRadius;
}

void Ellipsoid::setZRadius(double newZRadius)
{
    zRadius = newZRadius;
}

SemantisedTriangleMesh::Point Ellipsoid::getCentre() const
{
    return centre;
}

void Ellipsoid::setCentre(SemantisedTriangleMesh::Point newCentre)
{
    centre = newCentre;
}


DrawableEllipsoid::DrawableEllipsoid()
{
    this->color = static_cast<double *>(malloc(3 * sizeof(double)));
}

DrawableEllipsoid::~DrawableEllipsoid()
{
    delete[] this->color;
}

void DrawableEllipsoid::update()
{
    auto vtkEllipsoid = vtkNew<vtkParametricEllipsoid>();
    auto parametricFunctionSource = vtkNew<vtkParametricFunctionSource>();
    auto surfaceMapper = vtkNew<vtkPolyDataMapper>();
    auto surfaceActor = vtkNew<vtkActor>();
    auto wireframeMapper = vtkNew<vtkPolyDataMapper>();
    auto wireframeActor = vtkNew<vtkActor>();

    canvas = vtkNew<vtkPropAssembly>();

    parametricFunctionSource->SetUResolution(uResolution);
    parametricFunctionSource->SetVResolution(vResolution);
    parametricFunctionSource->SetWResolution(wResolution);
    parametricFunctionSource->SetScalarModeToNone();
    parametricFunctionSource->GenerateTextureCoordinatesOff();

    vtkEllipsoid->SetXRadius(xRadius);
    vtkEllipsoid->SetYRadius(yRadius);
    vtkEllipsoid->SetZRadius(zRadius);
    parametricFunctionSource->SetParametricFunction(vtkEllipsoid);
    parametricFunctionSource->Update();
    parametricFunctionSource->SetOutputPointsPrecision(vtkAlgorithm::DOUBLE_PRECISION);
    auto transform = vtkNew<vtkTransform>();
    transform->Translate(centre.getX(), centre.getY(), centre.getZ());
    auto transformFilter = vtkNew<vtkTransformPolyDataFilter>();
    transformFilter->SetTransform(transform);
    transformFilter->SetInputData(parametricFunctionSource->GetOutput());
    transformFilter->Update();

    surfaceMapper->SetInputConnection(transformFilter->GetOutputPort());
    surfaceActor->SetMapper(surfaceMapper);
    surfaceActor->SetOrigin(centre.getX(), centre.getY(), centre.getZ());
    surfaceActor->GetProperty()->SetOpacity(opacity);
    surfaceActor->GetProperty()->SetColor(color[0], color[1], color[2]);
    if(drawSurface)
        canvas->AddPart(surfaceActor);
    wireframeMapper->SetInputConnection(transformFilter->GetOutputPort());
    wireframeActor->SetMapper(wireframeMapper);
    wireframeActor->SetOrigin(centre.getX(), centre.getY(), centre.getZ());
    wireframeActor->GetProperty()->SetColor(0, 0, 0);
    wireframeActor->GetProperty()->SetRepresentationToWireframe();
    if(drawWireframe)
        canvas->AddPart(wireframeActor);

}

void DrawableEllipsoid::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    assembly->RemovePart(canvas);
    assembly->AddPart(canvas);
    assembly->Modified();
}

double DrawableEllipsoid::getUResolution() const
{
    return uResolution;
}

void DrawableEllipsoid::setUResolution(double newUResolution)
{
    uResolution = newUResolution;
}

double DrawableEllipsoid::getVResolution() const
{
    return vResolution;
}

void DrawableEllipsoid::setVResolution(double newVResolution)
{
    vResolution = newVResolution;
}

double DrawableEllipsoid::getWResolution() const
{
    return wResolution;
}

void DrawableEllipsoid::setWResolution(double newWResolution)
{
    wResolution = newWResolution;
}

double *DrawableEllipsoid::getColor() const
{
    return color;
}

void DrawableEllipsoid::setColor(double *newColor)
{
    color = newColor;
}

void DrawableEllipsoid::setColor(double r, double g, double b)
{
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

