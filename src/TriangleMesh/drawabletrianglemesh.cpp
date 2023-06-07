#include "drawabletrianglemesh.hpp"

#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkProperty.h>
#include <vtkLine.h>
#include <vtkTriangle.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <drawableannotation.hpp>
#include <drawablepointannotation.hpp>
#include <drawablelineannotation.hpp>
#include <drawablesurfaceannotation.hpp>

using namespace SemantisedTriangleMesh;

DrawableTriangleMesh::DrawableTriangleMesh() : TriangleMesh()
{
    drawVertices = false;
    drawWireframe = true;
    drawSurface = true;
    drawAnnotations = false;
    pointsActor = vtkSmartPointer<vtkActor>::New();
    wireframeActor = vtkSmartPointer<vtkActor>::New();
    surfaceActor = vtkSmartPointer<vtkActor>::New();
    annotationsActor = vtkSmartPointer<vtkPropAssembly>::New();
}

DrawableTriangleMesh::~DrawableTriangleMesh()
{
}

void DrawableTriangleMesh::draw(vtkSmartPointer<vtkPropAssembly> canvas)
{
    if(drawVertices)
        canvas->AddPart(pointsActor);
    if(drawWireframe)
        canvas->AddPart(wireframeActor);
    if(drawSurface)
        canvas->AddPart(surfaceActor);
    if(drawAnnotations)
        for(auto a : annotations)
        {
            annotationsActor = vtkSmartPointer<vtkPropAssembly>::New();
            std::dynamic_pointer_cast<DrawableAnnotation>(a)->draw(annotationsActor);
            canvas->AddPart(annotationsActor);
        }


}

void DrawableTriangleMesh::update()
{
    meshVColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    meshVColors->SetNumberOfComponents(3);
    meshVColors->SetName("VColors");
    meshEColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    meshEColors->SetNumberOfComponents(3);
    meshEColors->SetName("EColors");
    meshTColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    meshTColors->SetNumberOfComponents(3);
    meshTColors->SetName("TColors");

    meshVertices = vtkSmartPointer<vtkPoints>::New();
    meshEdges = vtkSmartPointer<vtkCellArray>::New();
    meshTriangles = vtkSmartPointer<vtkCellArray>::New();

    pointsActor = vtkSmartPointer<vtkActor>::New();
    auto pointsMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    auto pointsPolydata = vtkSmartPointer<vtkPolyData>::New();
    wireframeActor = vtkSmartPointer<vtkActor>::New();
    auto wireframeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    auto wireframePolydata = vtkSmartPointer<vtkPolyData>::New();
    surfaceActor = vtkSmartPointer<vtkActor>::New();
    auto surfaceMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    auto surfacePolydata = vtkSmartPointer<vtkPolyData>::New();
    for (auto v : this->vertices)
    {
        this->meshVertices->InsertNextPoint(v->getX(), v->getY(), v->getZ());
        meshVColors->InsertNextTypedTuple(BLUE);
    }

    for (auto e : this->edges) {
        vtkSmartPointer<vtkLine> edge = vtkSmartPointer<vtkLine>::New();
        edge->GetPointIds()->SetNumberOfIds(2);
        edge->GetPointIds()->SetId(0, static_cast<vtkIdType>(std::stoi(e->getV1()->getId())));
        edge->GetPointIds()->SetId(1, static_cast<vtkIdType>(std::stoi(e->getV1()->getId())));
        this->meshEdges->InsertNextCell(edge);
        this->meshEColors->InsertNextTypedTuple(BLACK);
    }

    for(auto t : this->triangles){
        vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
        triangle->GetPointIds()->SetNumberOfIds(3);
        uint v1id = std::stoi(t->getV1()->getId());
        uint v2id = std::stoi(t->getV2()->getId());
        uint v3id = std::stoi(t->getV3()->getId());
        triangle->GetPointIds()->SetId(0, static_cast<vtkIdType>(v1id));
        triangle->GetPointIds()->SetId(1, static_cast<vtkIdType>(v2id));
        triangle->GetPointIds()->SetId(2, static_cast<vtkIdType>(v3id));
        this->meshTriangles->InsertNextCell(triangle);
        if(t->searchFlag(FlagType::SELECTED) >= 0)
            meshTColors->InsertNextTypedTuple(RED);
        else
            meshTColors->InsertNextTypedTuple(ORIGINAL_COLOR);
    }
    pointsPolydata->SetPoints(this->meshVertices);
    wireframePolydata->SetPoints(this->meshVertices);
    surfacePolydata->SetPoints(this->meshVertices);
    wireframePolydata->SetPolys(this->meshTriangles);
    surfacePolydata->SetPolys(this->meshTriangles);
    pointsPolydata->GetPointData()->SetScalars(meshVColors);
    wireframePolydata->GetCellData()->SetScalars(meshEColors);
    surfacePolydata->GetCellData()->SetScalars(meshTColors);
    pointsMapper->SetInputData(pointsPolydata);
    wireframeMapper->SetInputData(wireframePolydata);
    surfaceMapper->SetInputData(surfacePolydata);
    pointsActor = vtkSmartPointer<vtkActor>::New();
    pointsActor->SetMapper(pointsMapper);
    wireframeActor = vtkSmartPointer<vtkActor>::New();
    wireframeActor->SetMapper(wireframeMapper);
    wireframeActor->GetProperty()->SetRepresentationToWireframe();
    surfaceActor = vtkSmartPointer<vtkActor>::New();
    surfaceActor->SetMapper(surfaceMapper);
    surfaceActor->GetProperty()->SetRepresentationToSurface();

    for(auto a : annotations)
        std::dynamic_pointer_cast<DrawableAnnotation>(a)->update();
}

int DrawableTriangleMesh::load(std::string filename)
{
    uint retValue = TriangleMesh::load(filename);
    if(retValue == 0)
        update();
    return retValue;

}

bool DrawableTriangleMesh::getDrawVertices() const
{
    return drawVertices;
}

void DrawableTriangleMesh::setDrawVertices(bool newDrawVertices)
{
    drawVertices = newDrawVertices;
}

bool DrawableTriangleMesh::getDrawWireframe() const
{
    return drawWireframe;
}

void DrawableTriangleMesh::setDrawWireframe(bool newDrawEdges)
{
    drawWireframe = newDrawEdges;
}

bool DrawableTriangleMesh::getDrawSurface() const
{
    return drawSurface;
}

void DrawableTriangleMesh::setDrawSurface(bool newDrawSurface)
{
    drawSurface = newDrawSurface;
}

bool DrawableTriangleMesh::getDrawAnnotations() const
{
    return drawAnnotations;
}

void DrawableTriangleMesh::setDrawAnnotations(bool newDrawAnnotations)
{
    drawAnnotations = newDrawAnnotations;
}

void DrawableTriangleMesh::setAnnotations(const std::vector<std::shared_ptr<Annotation> > &newAnnotations)
{
    annotations.clear();
    annotationsActor = vtkSmartPointer<vtkPropAssembly>::New();
    for(auto a : newAnnotations)
        this->addAnnotation(a);
}

bool DrawableTriangleMesh::addAnnotation(const std::shared_ptr<Annotation> &newAnnotation)
{
    std::shared_ptr<DrawableAnnotation> annotation;
    switch(newAnnotation->getType())
    {
        case AnnotationType::Point:
        {
            annotation = std::make_shared<DrawablePointAnnotation>(std::dynamic_pointer_cast<PointAnnotation>(newAnnotation).get());
            break;
        }
        case AnnotationType::Line:
        {
            annotation = std::make_shared<DrawableLineAnnotation>(std::dynamic_pointer_cast<LineAnnotation>(newAnnotation).get());
            break;
        }
        case AnnotationType::Surface:
        {
            annotation = std::make_shared<DrawableSurfaceAnnotation>(std::dynamic_pointer_cast<SurfaceAnnotation>(newAnnotation).get());
            break;
        }
        default:
            std::cerr << "This kind of annotation is still not handled" << std::endl;
            return false;
    }
    auto attributes = annotation->getAttributes();
    annotation->resetAttributes();
    for(auto attribute : attributes)
        annotation->addAttribute(attribute);
    TriangleMesh::addAnnotation(annotation);
    annotation->setMeshPoints(this->meshVertices);
    annotation->setDrawAttributes(true);
    annotation->update();
    annotation->draw(annotationsActor);
    return true;
}

vtkSmartPointer<vtkActor> DrawableTriangleMesh::getSurfaceActor() const
{
    return surfaceActor;
}

vtkSmartPointer<vtkPoints> DrawableTriangleMesh::getMeshVertices() const
{
    return meshVertices;
}

void DrawableTriangleMesh::setMeshVertices(vtkSmartPointer<vtkPoints> newMeshVertices)
{
    meshVertices = newMeshVertices;
}

vtkSmartPointer<vtkActor> DrawableTriangleMesh::getPointsActor() const
{
    return pointsActor;
}

void DrawableTriangleMesh::setTriangleColor(std::string id, const unsigned char * color)
{
    uint pos = std::stoi(id);
    meshTColors->SetTypedTuple(pos, color);
}


