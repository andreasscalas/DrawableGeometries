#include "drawablelineannotation.hpp"
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCellData.h>
#include <vtkLine.h>
#include <vtkProperty.h>
#include <vtkSphereSource.h>
#include <drawableattribute.hpp>

using namespace std;

DrawableLineAnnotation::DrawableLineAnnotation() : DrawableAnnotation()
{
    init();
}

DrawableLineAnnotation::DrawableLineAnnotation(LineAnnotation* annotation)
{
    init();
    this->id = annotation->getId();
    this->tag = annotation->getTag();
    setColor(annotation->getColor());
    this->polyLines = annotation->getPolyLines();
    this->attributes = annotation->getAttributes();
    this->mesh = annotation->getMesh();
}

void DrawableLineAnnotation::init()
{
    annotatedLines = vtkSmartPointer<vtkCellArray>::New();
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
}

float DrawableLineAnnotation::getLineWidth() const
{
    return lineWidth;
}

void DrawableLineAnnotation::setLineWidth(float value)
{
    lineWidth = value;
}


void DrawableLineAnnotation::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    assembly->RemovePart(canvas);
    canvas = vtkSmartPointer<vtkPropAssembly>::New();
    vtkSmartPointer<vtkPolyData> annotationsPolydata = vtkSmartPointer<vtkPolyData>::New();
    annotationsPolydata->SetPoints(meshPoints);
    annotationsPolydata->SetLines(annotatedLines);
    annotationsPolydata->GetCellData()->SetScalars(annotationColors);
    vtkSmartPointer<vtkPolyDataMapper> annotationMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    auto annotationActor = vtkSmartPointer<vtkActor>::New();
    annotationMapper->SetInputData(annotationsPolydata);
    annotationActor->SetMapper(annotationMapper);
    annotationActor->GetProperty()->SetOpacity(this->opacity);
    annotationActor->GetProperty()->SetLineWidth(lineWidth);
    canvas->AddPart(annotationActor);
    if(drawAttributes)
        for(unsigned int i = 0; i < attributes.size(); i++)
        {
            auto drawableAttribute = std::dynamic_pointer_cast<DrawableAttribute>(attributes[i]);
            drawableAttribute->draw(canvas);
        }
    if(selected){
        double sphereRadius = this->mesh->getAABBDiagonalLength() / 1000;
        for(unsigned int i = 0; i < polyLines.size(); i++){
            vtkSmartPointer<vtkSphereSource> originSphereSource = vtkSmartPointer<vtkSphereSource>::New();
            vtkSmartPointer<vtkPolyDataMapper> originMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            vtkSmartPointer<vtkActor> originActor = vtkSmartPointer<vtkActor>::New();
            vtkSmartPointer<vtkSphereSource> targetSphereSource = vtkSmartPointer<vtkSphereSource>::New();
            vtkSmartPointer<vtkPolyDataMapper> targetMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            vtkSmartPointer<vtkActor> targetActor = vtkSmartPointer<vtkActor>::New();
            originSphereSource->SetCenter(polyLines[i][0]->getX(), polyLines[i][0]->getY(), polyLines[i][0]->getZ());
            originSphereSource->SetRadius(sphereRadius);
            targetSphereSource->SetCenter(polyLines[i][polyLines[i].size() - 1]->getX(), polyLines[i][polyLines[i].size() - 1]->getY(), polyLines[i][polyLines[i].size() - 1]->getZ());
            targetSphereSource->SetRadius(sphereRadius);
            originMapper->SetInputConnection(originSphereSource->GetOutputPort());
            targetMapper->SetInputConnection(targetSphereSource->GetOutputPort());
            originActor->SetMapper(originMapper);
            targetActor->SetMapper(targetMapper);
            originActor->GetProperty()->SetColor(1,0,0);
            originActor->GetProperty()->SetOpacity(this->opacity);
            targetActor->GetProperty()->SetColor(1,0,0);
            targetActor->GetProperty()->SetOpacity(this->opacity);
            canvas->AddPart(originActor);
            canvas->AddPart(targetActor);
        }
    }
    canvas->Modified();
    assembly->AddPart(canvas);
    assembly->Modified();
}

void DrawableLineAnnotation::update()
{
    annotatedLines = vtkSmartPointer<vtkCellArray>::NewInstance(annotatedLines);
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::NewInstance(annotationColors);
    annotationColors->SetNumberOfComponents(3);
    annotationColors->SetName("AnnotationsEColors");

    //Update of the data-visualization linking
    for(unsigned int i = 0; i < polyLines.size(); i++)
        for (unsigned j = 1; j < polyLines[i].size(); j++) {
            vtkSmartPointer<vtkLine> segment = vtkSmartPointer<vtkLine>::New();
            uint v1id = std::stoi(polyLines[i][j - 1]->getId());
            uint v2id = std::stoi(polyLines[i][j]->getId());
            segment->GetPointIds()->SetId(0, static_cast<vtkIdType>(v1id));
            segment->GetPointIds()->SetId(1, static_cast<vtkIdType>(v2id));
            annotatedLines->InsertNextCell(segment);
            annotationColors->InsertNextTypedTuple(color);
        }

}

void DrawableLineAnnotation::clear()
{
    init();
    this->tag = "";
    this->color = nullptr;
    this->polyLines.clear();
    this->mesh = nullptr;
}

void DrawableLineAnnotation::print(std::ostream& os)
{
    DrawableAnnotation::print(os);
    os << "This is a Line annotation" << std::endl;
    os << "Line width is set to " << lineWidth << std::endl;
}
