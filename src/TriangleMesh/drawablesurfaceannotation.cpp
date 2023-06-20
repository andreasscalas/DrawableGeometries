#include "drawablesurfaceannotation.hpp"
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkTriangle.h>
#include <vtkActor.h>
#include <vtkCellData.h>
#include <vtkProperty.h>
#include <vtkLine.h>
#include <drawableattribute.hpp>

using namespace std;

DrawableSurfaceAnnotation::DrawableSurfaceAnnotation() : DrawableAnnotation()
{
    init();
}

DrawableSurfaceAnnotation::DrawableSurfaceAnnotation(SurfaceAnnotation* annotation)
{
    init();
    this->id = annotation->getId();
    this->tag = annotation->getTag();
    setColor(annotation->getColor());
    this->outlines = annotation->getOutlines();
    this->attributes = annotation->getAttributes();
    this->mesh = annotation->getMesh();
}

void DrawableSurfaceAnnotation::init()
{
    annotatedTriangles = vtkSmartPointer<vtkCellArray>::New();
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    outlinesActor = vtkSmartPointer<vtkActor>::New();
    canvas = vtkSmartPointer<vtkPropAssembly>::New();
    drawAttributes = false;
}

void DrawableSurfaceAnnotation::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    DrawableAnnotation::draw(assembly);
    if(drawAnnotation)
    {
        vtkSmartPointer<vtkPolyData> annotationsPolydata = vtkSmartPointer<vtkPolyData>::New();
        annotationsPolydata->SetPoints(meshPoints);
        annotationsPolydata->SetPolys(annotatedTriangles);
        annotationsPolydata->GetCellData()->SetScalars(annotationColors);
        vtkSmartPointer<vtkPolyDataMapper> annotationMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        auto annotationActor = vtkSmartPointer<vtkActor>::New();
        annotationMapper->SetInputData(annotationsPolydata);
        annotationActor->SetMapper(annotationMapper);
        annotationActor->GetProperty()->SetOpacity(this->opacity);
        canvas->AddPart(annotationActor);

        if(selected){
            auto outlinesData = vtkSmartPointer<vtkPolyData>::New();
            auto vtkOutlines = vtkSmartPointer<vtkCellArray>::New();
            auto outlinesMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            outlinesActor = vtkSmartPointer<vtkActor>::NewInstance(outlinesActor);
            for(uint i = 0; i < outlines.size(); i++){
                for(uint j = 1; j < outlines[i].size(); j++){
                    vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
                    uint v1id = std::stoi(outlines[i][j - 1]->getId());
                    uint v2id = std::stoi(outlines[i][j]->getId());
                    line->GetPointIds()->SetNumberOfIds(2);
                    line->GetPointIds()->SetId(0, static_cast<vtkIdType>(v1id));
                    line->GetPointIds()->SetId(1, static_cast<vtkIdType>(v2id));
                    vtkOutlines->InsertNextCell(line);
                }
            }
            outlinesData->SetPoints(meshPoints);
            outlinesData->SetLines(vtkOutlines);
            outlinesMapper->SetInputData(outlinesData);
            outlinesActor->SetMapper(outlinesMapper);
            outlinesActor->GetProperty()->SetLineWidth(5.0);
            outlinesActor->GetProperty()->SetColor(1, 0, 0);
            outlinesActor->GetProperty()->SetOpacity(1.0);
            canvas->AddPart(outlinesActor);
        }
    }
}

void DrawableSurfaceAnnotation::update()
{
    vector<std::shared_ptr<SemantisedTriangleMesh::Triangle> > annotationTriangles = getTriangles();
    annotatedTriangles = vtkSmartPointer<vtkCellArray>::NewInstance(annotatedTriangles);
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::NewInstance(annotationColors);
    annotationColors->SetNumberOfComponents(3);
    annotationColors->SetName("AnnotationsTColors");

    //Update of the data-visualization linking
    for(auto tit = annotationTriangles.begin(); tit != annotationTriangles.end(); tit++){
        vtkSmartPointer<vtkTriangle> t = vtkSmartPointer<vtkTriangle>::New();
        uint v1id = std::stoi((*tit)->getV1()->getId());
        uint v2id = std::stoi((*tit)->getV2()->getId());
        uint v3id = std::stoi((*tit)->getV3()->getId());
        t->GetPointIds()->SetNumberOfIds(3);
        t->GetPointIds()->SetId(0, static_cast<vtkIdType>(v1id));
        t->GetPointIds()->SetId(1, static_cast<vtkIdType>(v2id));
        t->GetPointIds()->SetId(2, static_cast<vtkIdType>(v3id));
        annotatedTriangles->InsertNextCell(t);
        annotationColors->InsertNextTypedTuple(color);
    }

}

void DrawableSurfaceAnnotation::clear()
{
    init();
    this->tag = "";
    this->color = nullptr;
    this->outlines.clear();
    this->mesh = nullptr;

}

void DrawableSurfaceAnnotation::print(std::ostream& os)
{
    DrawableAnnotation::print(os);
    os << "This is a Surface annotation" << std::endl;
}
