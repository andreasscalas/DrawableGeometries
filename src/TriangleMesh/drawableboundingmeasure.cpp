#include "drawableboundingmeasure.hpp"


#include <vtkProperty2D.h>
#include <vtkActor2D.h>
#include <vtkPolyDataMapper2D.h>
#include <vtkLine.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkAxisActor2D.h>

DrawableBoundingMeasure::DrawableBoundingMeasure() : BoundingMeasure(), DrawableAttribute()
{
    points = vtkSmartPointer<vtkPoints>::New();
    direction = nullptr;
    drawPlanes = false;
    planeSize = 0.0;
    value = nullptr;
}

DrawableBoundingMeasure::DrawableBoundingMeasure(BoundingMeasure measure) : BoundingMeasure(measure)
{
    points = vtkSmartPointer<vtkPoints>::New();
    origin = measure.getOrigin();
    direction = measure.getDirection();
    measurePointsID = measure.getMeasurePointsID();
    id = measure.getId();
    key = measure.getKey();
    type = measure.getType();
    setIsGeometric(true);
    if(value != nullptr)
        value = measure.getValue();
    else
        value = nullptr;
}

DrawableBoundingMeasure::~DrawableBoundingMeasure()
{
}

void DrawableBoundingMeasure::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    assembly->RemovePart(canvas);
    canvas = vtkSmartPointer<vtkPropAssembly>::New();
    if(drawAttribute)
    {

        if(measurePointsID.size() > 1)
        {
            vtkSmartPointer<vtkAxisActor2D> axisActor2D = vtkSmartPointer<vtkAxisActor2D>::New();
            axisActor2D->GetPoint1Coordinate()->SetCoordinateSystemToWorld();
            axisActor2D->GetPoint2Coordinate()->SetCoordinateSystemToWorld();
            axisActor2D->SetNumberOfLabels(5);
            axisActor2D->LabelVisibilityOff();
            axisActor2D->AdjustLabelsOff();
            axisActor2D->SetTitle("Distance");
            axisActor2D->GetTitleTextProperty()->SetBold(1);
            axisActor2D->GetTitleTextProperty()->SetItalic(1);
            axisActor2D->GetTitleTextProperty()->SetShadow(1);
            axisActor2D->GetTitleTextProperty()->SetFontFamilyToArial();
            axisActor2D->GetTitleTextProperty()->SetFontSize(16);
            if(error)
                axisActor2D->GetTitleTextProperty()->SetColor(1,0,0);
            else
                axisActor2D->GetTitleTextProperty()->SetColor(0,0,0);
            axisActor2D->SetFontFactor(1.0);
            axisActor2D->SetLabelFactor(1.0);
            axisActor2D->GetPoint1Coordinate()->SetValue(extreme0.getX(), extreme0.getY(), extreme0.getZ());
            axisActor2D->GetPoint2Coordinate()->SetValue(extreme1.getX(), extreme1.getY(), extreme1.getZ());
            axisActor2D->SetRulerMode(true);
            axisActor2D->GetProperty()->SetLineWidth(2.0);
            if(error)
                axisActor2D->GetProperty()->SetColor(1,0,0);
            else
                axisActor2D->GetProperty()->SetColor(0,0,0);
            char string[512];
            sprintf(string, "%-#6.3g", ((extreme0) - (extreme1)).norm());
            axisActor2D->SetTitle(string);
            canvas->AddPart(axisActor2D);


            if(drawPlanes)
            {
                vtkSmartPointer<vtkPolyDataMapper> planeMapper1 = vtkSmartPointer<vtkPolyDataMapper>::New();
                planeMapper1->SetInputConnection(planeSource1->GetOutputPort());
                vtkSmartPointer<vtkActor> planeActor1 = vtkSmartPointer<vtkActor>::New();
                planeActor1->SetMapper(planeMapper1);
                canvas->AddPart(planeActor1);
                vtkSmartPointer<vtkPolyDataMapper> planeMapper2 = vtkSmartPointer<vtkPolyDataMapper>::New();
                planeMapper2->SetInputConnection(planeSource2->GetOutputPort());
                vtkSmartPointer<vtkActor> planeActor2 = vtkSmartPointer<vtkActor>::New();
                planeActor2->SetMapper(planeMapper2);
                canvas->AddPart(planeActor2);
            }
        }

        canvas->Modified();
        assembly->AddPart(canvas);
        assembly->Modified();
    }
    assembly->Modified();
}

void DrawableBoundingMeasure::update()
{
    if(origin == nullptr)
        return;

    if(measurePointsID.size() < 2)
        return;
    auto p0 = mesh->getVertex(measurePointsID[0]);
    auto p1 = mesh->getVertex(measurePointsID[1]);
    extreme0 = *p0;
    extreme0 -= *origin;
    extreme0 = (*direction) * (extreme0 * (*direction));
    extreme0 += *origin;
    extreme1 = *p1;
    extreme1 -= *origin;
    extreme1 = (*direction) * (extreme1 * (*direction));
    extreme1 += *origin;

    double measure = (extreme1 - extreme0).norm();
    if(this->value == nullptr)
        this->value = new double(measure);
    else
        *static_cast<double*>(this->value) = measure;
    points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(extreme0.getX(), extreme0.getY(), extreme0.getZ());
    points->InsertNextPoint(extreme1.getX(), extreme1.getY(), extreme1.getZ());
    planeSource1 = vtkSmartPointer<vtkPlaneSource>::New();
    planeSource2 = vtkSmartPointer<vtkPlaneSource>::New();
    std::pair<SemantisedTriangleMesh::Point*, SemantisedTriangleMesh::Point*> p = direction->compute2OrthogonalVersors();
    *p.first *= measure * 5;
    *p.second *= measure * 5;
    SemantisedTriangleMesh::Point o1 = extreme0 - (*p.first) - (*p.second);
    SemantisedTriangleMesh::Point p1_1 = o1 + (*p.first) * 2;
    SemantisedTriangleMesh::Point p2_1 = o1 + (*p.second) * 2;
    planeSource1->SetOrigin(o1.getX(), o1.getY(), o1.getZ());
    planeSource1->SetPoint1(p1_1.getX(), p1_1.getY(), p1_1.getZ());
    planeSource1->SetPoint2(p2_1.getX(), p2_1.getY(), p2_1.getZ());
    planeSource1->Update();
    SemantisedTriangleMesh::Point o2 = extreme1 - (*p.first) - (*p.second);
    SemantisedTriangleMesh::Point p1_2 = o2 + (*p.first) * 2;
    SemantisedTriangleMesh::Point p2_2 = o2 + (*p.second) * 2;
    delete p.first;
    delete p.second;
    planeSource2->SetOrigin(o2.getX(), o2.getY(), o2.getZ());
    planeSource2->SetPoint1(p1_2.getX(), p1_2.getY(), p1_2.getZ());
    planeSource2->SetPoint2(p2_2.getX(), p2_2.getY(), p2_2.getZ());
    planeSource2->Update();

}



bool DrawableBoundingMeasure::getDrawPlanes() const
{
    return drawPlanes;
}

void DrawableBoundingMeasure::setDrawPlanes(bool value)
{
    drawPlanes = value;
}

void DrawableBoundingMeasure::print(std::ostream &os)
{
    DrawableAttribute::print(os);
    os << "This is a Bounding measure" << std::endl;
    if(drawPlanes)
        os << "Planes are drawn" << std::endl;
    else
        os << "Planes are drawn" << std::endl;
    os << "Plane size: " << planeSize << std::endl;
}
