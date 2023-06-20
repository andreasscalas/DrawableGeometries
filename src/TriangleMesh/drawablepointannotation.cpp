#include "drawablepointannotation.hpp"
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPointData.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkSphereSource.h>
#include <vtkOBBTree.h>
#include <vtkLine.h>
#include <drawableattribute.hpp>

DrawablePointAnnotation::DrawablePointAnnotation() : DrawableAnnotation()
{
    init();
}

DrawablePointAnnotation::DrawablePointAnnotation(PointAnnotation *annotation)
{
    init();
    this->id = annotation->getId();
    this->tag = annotation->getTag();
    setColor(annotation->getColor());
    this->points = annotation->getPoints();
    this->attributes = annotation->getAttributes();
    this->mesh = annotation->getMesh();

}

DrawablePointAnnotation::~DrawablePointAnnotation()
{
    this->points.clear();
}

void DrawablePointAnnotation::init()
{
    annotatedPoints = vtkSmartPointer<vtkPoints>::New();
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::New();
}


void DrawablePointAnnotation::draw(vtkSmartPointer<vtkPropAssembly> assembly)
{
    DrawableAnnotation::draw(assembly);
    if(drawAnnotation)
    {
        vtkSmartPointer<vtkPolyData> annotationsPolydata = vtkSmartPointer<vtkPolyData>::New();
        vtkSmartPointer<vtkPolyData> pointsPolydata = vtkSmartPointer<vtkPolyData>::New();
        annotatedPoints = vtkSmartPointer<vtkPoints>::NewInstance(annotatedPoints);
        for(unsigned int i = 0; i < points.size(); i++)
            annotatedPoints->InsertNextPoint(points[i]->getX(), points[i]->getY(), points[i]->getZ());
        pointsPolydata->SetPoints(annotatedPoints);
        vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
        vertexFilter->SetInputData(pointsPolydata);
        vertexFilter->Update();
        annotationsPolydata->ShallowCopy(vertexFilter->GetOutput());
        annotationsPolydata->GetPointData()->SetScalars(annotationColors);
        vtkSmartPointer<vtkPolyDataMapper> annotationMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        annotationMapper->SetInputData(annotationsPolydata);
        auto annotationActor = vtkSmartPointer<vtkActor>::New();
        annotationActor->SetMapper(annotationMapper);
        annotationActor->GetProperty()->SetOpacity(this->opacity);
        annotationActor->GetProperty()->SetPointSize(pointSize);
        canvas->AddPart(annotationActor);
        //Drawing bounding box for selected annotated points
        if(selected){
            double corner[3], min[3], mid[3], max[3], sizes[3];
            vtkSmartPointer<vtkPoints> OBBPoints = vtkSmartPointer<vtkPoints>::New();
            vtkSmartPointer<vtkPolyData> OBBPolyData= vtkSmartPointer<vtkPolyData>::New();
            vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
            if(points.size() > 1){
                vtkOBBTree::ComputeOBB(annotatedPoints, corner, max, mid, min, sizes);
            } else {
                sphere->SetCenter(points[0]->getX(), points[0]->getY(), points[0]->getZ());
                sphere->SetRadius(this->mesh->getAABBDiagonalLength() / 100);
                sphere->Update();
                vtkOBBTree::ComputeOBB(sphere->GetOutput()->GetPoints(), corner, max, mid, min, sizes);
            }
            vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
            vtkSmartPointer<vtkLine> line = vtkSmartPointer<vtkLine>::New();
            SemantisedTriangleMesh::Point minAx(min[0], min[1] , min[2]);
            SemantisedTriangleMesh::Point midAx(mid[0], mid[1] , mid[2]);
            SemantisedTriangleMesh::Point maxAx(max[0], max[1] , max[2]);
            SemantisedTriangleMesh::Point d(corner[0], corner[1], corner[2]);
            SemantisedTriangleMesh::Point c(d + minAx);
            SemantisedTriangleMesh::Point e(d + midAx);
            SemantisedTriangleMesh::Point a(d + maxAx);
            SemantisedTriangleMesh::Point b(a + minAx);
            SemantisedTriangleMesh::Point f(a + midAx);
            SemantisedTriangleMesh::Point g(b + midAx);
            SemantisedTriangleMesh::Point h(c + midAx);
            vtkIdType aid = OBBPoints->InsertNextPoint(a.getX(), a.getY(), a.getZ());
            vtkIdType bid = OBBPoints->InsertNextPoint(b.getX(), b.getY(), b.getZ());
            vtkIdType cid = OBBPoints->InsertNextPoint(c.getX(), c.getY(), c.getZ());
            vtkIdType did = OBBPoints->InsertNextPoint(d.getX(), d.getY(), d.getZ());
            vtkIdType eid = OBBPoints->InsertNextPoint(e.getX(), e.getY(), e.getZ());
            vtkIdType fid = OBBPoints->InsertNextPoint(f.getX(), f.getY(), f.getZ());
            vtkIdType gid = OBBPoints->InsertNextPoint(g.getX(), g.getY(), g.getZ());
            vtkIdType hid = OBBPoints->InsertNextPoint(h.getX(), h.getY(), h.getZ());
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, aid);
            line->GetPointIds()->SetId(1, bid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, bid);
            line->GetPointIds()->SetId(1, cid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, cid);
            line->GetPointIds()->SetId(1, did);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, did);
            line->GetPointIds()->SetId(1, aid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, aid);
            line->GetPointIds()->SetId(1, fid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, bid);
            line->GetPointIds()->SetId(1, gid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, cid);
            line->GetPointIds()->SetId(1, hid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, did);
            line->GetPointIds()->SetId(1, eid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, eid);
            line->GetPointIds()->SetId(1, fid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, fid);
            line->GetPointIds()->SetId(1, gid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, gid);
            line->GetPointIds()->SetId(1, hid);
            lines->InsertNextCell(line);
            line = vtkSmartPointer<vtkLine>::New();
            line->GetPointIds()->SetNumberOfIds(2);
            line->GetPointIds()->SetId(0, hid);
            line->GetPointIds()->SetId(1, eid);
            lines->InsertNextCell(line);
            OBBPolyData->SetPoints(OBBPoints);
            OBBPolyData->SetLines(lines);
            vtkSmartPointer<vtkPolyDataMapper> outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
            vtkSmartPointer<vtkActor> outlineActor = vtkSmartPointer<vtkActor>::New();
            outlineMapper->SetInputData(OBBPolyData);
            outlineActor->GetProperty()->SetOpacity(1.0);
            outlineActor->GetProperty()->SetLineWidth(5.0);
            outlineActor->GetProperty()->SetColor(1,0,0);
            outlineActor->SetMapper(outlineMapper);
            canvas->AddPart(outlineActor);
        }
    }
}
void DrawablePointAnnotation::update()
{
    annotationColors = vtkSmartPointer<vtkUnsignedCharArray>::NewInstance(annotationColors);
    annotationColors->SetNumberOfComponents(3);
    annotationColors->SetName("AnnotationsVColors");

    //Update of the data-visualization linking
    for(unsigned int i = 0; i < points.size(); i++)
        annotationColors->InsertNextTypedTuple(color);


}

void DrawablePointAnnotation::clear()
{
    init();
    this->tag = "";
    this->color = nullptr;
    this->points.clear();
    this->mesh = nullptr;
}


void DrawablePointAnnotation::print(std::ostream& os)
{
    DrawableAnnotation::print(os);
    os << "This is a Point annotation" << std::endl;
}
