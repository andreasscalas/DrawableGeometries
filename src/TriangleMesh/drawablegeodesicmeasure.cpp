#include "drawablegeodesicmeasure.hpp"

#include <vtkLine.h>
#include <vtkPoints.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkBillboardTextActor3D.h>


using namespace Drawables;

DrawableGeodesicMeasure::DrawableGeodesicMeasure(): SemantisedTriangleMesh::GeodesicMeasure(), DrawableAttribute()
{
    pointsActor = vtkSmartPointer<vtkActor>::New();
    measureLineActor =  vtkSmartPointer<vtkActor>::New();
    measureStringDistance = 0.0;
}

DrawableGeodesicMeasure::DrawableGeodesicMeasure(GeodesicMeasure measure)
{
    pointsActor = vtkSmartPointer<vtkActor>::New();
    measureLineActor =  vtkSmartPointer<vtkActor>::New();
    measureStringDistance = 0.0;
    points = measure.getPoints();
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

void DrawableGeodesicMeasure::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{

    assembly->RemovePart(canvas);
    canvas = vtkSmartPointer<vtkPropAssembly>::New();
    if(drawAttribute && points.size() > 0)
    {
        assembly->RemovePart(canvas);
        measureLineActor =  vtkSmartPointer<vtkActor>::New();
        pointsActor = vtkSmartPointer<vtkActor>::New();
        //Visualization of the polyline defining the measure
        vtkSmartPointer<vtkPolyData> measureLineData = vtkSmartPointer<vtkPolyData>::New();
        measureLineData->Initialize();
        measureLineData->SetPoints(polylinePoints);
        measureLineData->SetLines(segments);
        measureLineData->Modified();
        vtkSmartPointer<vtkPolyDataMapper> measureLineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        measureLineMapper->SetInputData(measureLineData);
        measureLineMapper->Update();
        measureLineActor->SetMapper(measureLineMapper);

        if(error)
            measureLineActor->GetProperty()->SetColor(1,0,0);
        else
            measureLineActor->GetProperty()->SetColor(0.0, 0.0, 0.0);
        measureLineActor->GetProperty()->SetLineWidth(3.0f);

        //Visualization of the extreme points
        visualizedPoints->InsertNextPoint(points[0]->getX(), points[0]->getY(), points[0]->getZ());
        if(points.size() > 1)
            visualizedPoints->InsertNextPoint(points.back()->getX(), points.back()->getY(), points.back()->getZ());
        vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
        polydata->Initialize();
        polydata->SetPoints(visualizedPoints);
        polydata->Modified();
        vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
        vertexFilter->SetInputData(polydata);
        vertexFilter->Update();
        vtkSmartPointer<vtkPolyDataMapper> pointsMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        pointsMapper->SetInputConnection(vertexFilter->GetOutputPort());
        pointsActor->SetMapper(pointsMapper);

        if(error)
            pointsActor->GetProperty()->SetColor(1,0,0);
        else
            pointsActor->GetProperty()->SetColor(0.0, 0.0, 0.0);
        pointsActor->GetProperty()->SetPointSize(10.0f);

        vtkSmartPointer<vtkBillboardTextActor3D> textActor = vtkSmartPointer<vtkBillboardTextActor3D>::New();
        std::stringstream ss;
        ss << std::fixed << std::setprecision(3) << *static_cast<double*>(value);
        textActor->SetInput( ss.str().c_str() );
        SemantisedTriangleMesh::Point p(0,0,0);
        for(unsigned int i = 0; i < measurePointsID.size(); i++)
            p += *(this->mesh->getVertex(measurePointsID[i]));
        p /= measurePointsID.size();
        std::shared_ptr<SemantisedTriangleMesh::Vertex> best = nullptr;
        double bestDist = std::numeric_limits<double>::max();
        for(unsigned int i = 0; i < measurePointsID.size(); i++)
        {
            auto v = this->mesh->getVertex(measurePointsID[i]);
            double dist = (p - (*v)).norm();
            if(bestDist > dist)
            {
                best = v;
                bestDist = dist;
            }
        }
        p = (*best) + best->computeNormal() * MEASURE_DISTANCE;
        if(best != nullptr)
            textActor->SetPosition(p.getX(), p.getY(), p.getZ());
        textActor->GetTextProperty()->SetBold(1);
        textActor->GetTextProperty()->SetItalic(1);
        textActor->GetTextProperty()->SetShadow(1);
        textActor->GetTextProperty()->SetOpacity(1.0);
        textActor->GetTextProperty()->SetFontFamilyToArial();
        textActor->GetTextProperty()->SetFontSize(28);
        if(error)
            textActor->GetTextProperty()->SetColor(1,0,0);
        else
            textActor->GetTextProperty()->SetColor(0,0,0);
        canvas->AddPart(measureLineActor);
        canvas->AddPart(pointsActor);
        canvas->AddPart(textActor);
        canvas->Modified();

    }

    canvas->Modified();
    assembly->AddPart(canvas);
    assembly->Modified();
}

void DrawableGeodesicMeasure::update()
{

    polylinePoints = vtkSmartPointer<vtkPoints>::New();
    visualizedPoints = vtkSmartPointer<vtkPoints>::New();
    segments = vtkSmartPointer<vtkCellArray>::New();

    points.clear();
    if(this->value == nullptr)
        this->value = new double();

    double* measurePointer = static_cast<double*>(this->value);
    *measurePointer = 0;
    if(measurePointsID.size() > 0)
    {
        for(unsigned int i = 0; i < measurePointsID.size(); i++)
        {
            auto p = mesh->getVertex(measurePointsID[i]);
            points.push_back(p);
            vtkIdType last = polylinePoints->InsertNextPoint(p->getX(), p->getY(), p->getZ());
            if(i > 0)
            {
                *measurePointer += ((*p) - (*mesh->getVertex(measurePointsID[i - 1]))).norm();
                vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
                line->GetPointIds()->SetNumberOfIds(2);
                line->GetPointIds()->SetId(0, last - 1);
                line->GetPointIds()->SetId(1, last);
                segments->InsertNextCell(line);
            }
        }

    }
}

void DrawableGeodesicMeasure::print(std::ostream &os)
{
    DrawableAttribute::print(os);
    os << "This is a geodesic measure" << std::endl;
}

