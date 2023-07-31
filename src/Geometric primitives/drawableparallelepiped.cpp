#include "drawableparallelepiped.hpp"

#include <vtkActor.h>
#include <vtkDataSetMapper.h>
#include <vtkPoints.h>
#include <vtkUnstructuredGrid.h>
#include <vtkVoxel.h>
#include <vtkProperty.h>
#include <vtkCellData.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkTriangle.h>

using namespace Drawables;
SemantisedTriangleMesh::Point Parallelepiped::getP1() const
{
    return p1;
}

void Parallelepiped::setP1(SemantisedTriangleMesh::Point newP1)
{
    p1 = newP1;
}

SemantisedTriangleMesh::Point Parallelepiped::getP2() const
{
    return p2;
}

void Parallelepiped::setP2(SemantisedTriangleMesh::Point newP2)
{
    p2 = newP2;
}

DrawableParallelepiped::DrawableParallelepiped()
{
    this->color = static_cast<double *>(malloc(3 * sizeof(double)));
}

DrawableParallelepiped::~DrawableParallelepiped()
{
    delete[] this->color;
}

void DrawableParallelepiped::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    assembly->RemovePart(canvas);
    assembly->AddPart(canvas);
    assembly->Modified();
}

void DrawableParallelepiped::update()
{
    auto points = vtkNew<vtkPoints>();
    auto triangles = vtkNew<vtkCellArray>();
    auto polydata = vtkNew<vtkPolyData>();
    auto wireframePolydata = vtkNew<vtkPolyData>();
    auto surfaceMapper = vtkNew<vtkDataSetMapper>();
    auto wireframeMapper = vtkNew<vtkDataSetMapper>();
    auto surfaceActor = vtkNew<vtkActor>();
    auto wireframeActor = vtkNew<vtkActor>();
    canvas = vtkNew<vtkPropAssembly>();

    points->InsertNextPoint(p1.getX(), p1.getY(), p1.getZ());
    points->InsertNextPoint(p1.getX(), p1.getY(), p2.getZ());
    points->InsertNextPoint(p1.getX(), p2.getY(), p1.getZ());
    points->InsertNextPoint(p1.getX(), p2.getY(), p2.getZ());
    points->InsertNextPoint(p2.getX(), p1.getY(), p1.getZ());
    points->InsertNextPoint(p2.getX(), p1.getY(), p2.getZ());
    points->InsertNextPoint(p2.getX(), p2.getY(), p1.getZ());
    points->InsertNextPoint(p2.getX(), p2.getY(), p2.getZ());

    auto t0 = vtkNew<vtkTriangle>();
    t0->GetPointIds()->SetId(0, 0);
    t0->GetPointIds()->SetId(1, 5);
    t0->GetPointIds()->SetId(2, 1);
    triangles->InsertNextCell(t0);
    auto t1 = vtkNew<vtkTriangle>();
    t1->GetPointIds()->SetId(0, 0);
    t1->GetPointIds()->SetId(1, 4);
    t1->GetPointIds()->SetId(2, 5);
    triangles->InsertNextCell(t1);
    auto t2 = vtkNew<vtkTriangle>();
    t2->GetPointIds()->SetId(0, 4);
    t2->GetPointIds()->SetId(1, 7);
    t2->GetPointIds()->SetId(2, 5);
    triangles->InsertNextCell(t2);
    auto t3 = vtkNew<vtkTriangle>();
    t3->GetPointIds()->SetId(0, 4);
    t3->GetPointIds()->SetId(1, 6);
    t3->GetPointIds()->SetId(2, 7);
    triangles->InsertNextCell(t3);
    auto t4 = vtkNew<vtkTriangle>();
    t4->GetPointIds()->SetId(0, 6);
    t4->GetPointIds()->SetId(1, 3);
    t4->GetPointIds()->SetId(2, 7);
    triangles->InsertNextCell(t4);
    auto t5 = vtkNew<vtkTriangle>();
    t5->GetPointIds()->SetId(0, 6);
    t5->GetPointIds()->SetId(1, 2);
    t5->GetPointIds()->SetId(2, 3);
    triangles->InsertNextCell(t5);
    auto t6 = vtkNew<vtkTriangle>();
    t6->GetPointIds()->SetId(0, 2);
    t6->GetPointIds()->SetId(1, 1);
    t6->GetPointIds()->SetId(2, 3);
    triangles->InsertNextCell(t6);
    auto t7 = vtkNew<vtkTriangle>();
    t7->GetPointIds()->SetId(0, 2);
    t7->GetPointIds()->SetId(1, 0);
    t7->GetPointIds()->SetId(2, 1);
    triangles->InsertNextCell(t7);
    auto t8 = vtkNew<vtkTriangle>();
    t8->GetPointIds()->SetId(0, 1);
    t8->GetPointIds()->SetId(1, 7);
    t8->GetPointIds()->SetId(2, 3);
    triangles->InsertNextCell(t8);
    auto t9 = vtkNew<vtkTriangle>();
    t9->GetPointIds()->SetId(0, 1);
    t9->GetPointIds()->SetId(1, 5);
    t9->GetPointIds()->SetId(2, 7);
    triangles->InsertNextCell(t9);
    auto t10 = vtkNew<vtkTriangle>();
    t10->GetPointIds()->SetId(0, 2);
    t10->GetPointIds()->SetId(1, 4);
    t10->GetPointIds()->SetId(2, 0);
    triangles->InsertNextCell(t10);
    auto t11 = vtkNew<vtkTriangle>();
    t11->GetPointIds()->SetId(0, 2);
    t11->GetPointIds()->SetId(1, 6);
    t11->GetPointIds()->SetId(2, 4);
    triangles->InsertNextCell(t11);
    triangles->Modified();

    polydata->SetPoints(points);
    polydata->SetPolys(triangles);
    polydata->Modified();
    surfaceMapper->SetInputData(polydata);
    surfaceActor->SetMapper(surfaceMapper);
    surfaceActor->GetProperty()->SetOpacity(this->opacity);
    surfaceActor->Modified();
    surfaceActor->GetProperty()->SetRepresentationToSurface();
    surfaceActor->GetProperty()->SetColor(color);
    if(drawSurface)
        canvas->AddPart(surfaceActor);
    wireframePolydata->SetPoints(points);
    wireframePolydata->SetPolys(triangles);
    wireframePolydata->Modified();
    wireframeMapper->SetInputData(wireframePolydata);
    wireframeActor->SetMapper(wireframeMapper);
    wireframeActor->GetProperty()->SetRepresentationToWireframe();
    wireframeActor->GetProperty()->SetLineWidth(2);
    wireframeActor->GetProperty()->SetColor(0, 0, 0);
    if(drawWireframe)
        canvas->AddPart(wireframeActor);
    wireframeActor->Modified();
}

void DrawableParallelepiped::setColor(double r, double g, double b)
{
    this->color[0] = r;
    this->color[1] =g;
    this->color[2] = b;
}

bool DrawableParallelepiped::getDrawWireframe() const
{
    return drawWireframe;
}

void DrawableParallelepiped::setDrawWireframe(bool newDrawWireframe)
{
    drawWireframe = newDrawWireframe;
}

double *DrawableParallelepiped::getColor() const
{
    return color;
}

void DrawableParallelepiped::setColor(double *newColor)
{
    color = newColor;
}

double DrawableParallelepiped::getOpacity() const
{
    return opacity;
}

void DrawableParallelepiped::setOpacity(double newOpacity)
{
    opacity = newOpacity;
}

bool DrawableParallelepiped::getDrawSurface() const
{
    return drawSurface;
}

void DrawableParallelepiped::setDrawSurface(bool newDrawSurface)
{
    drawSurface = newDrawSurface;
}
