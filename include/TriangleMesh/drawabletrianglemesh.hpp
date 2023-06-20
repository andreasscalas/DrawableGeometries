#ifndef DRAWABLE_TRIANGLEMESH_H
#define DRAWABLE_TRIANGLEMESH_H

#include "drawableobject.hpp"
#include <TriangleMesh.hpp>
#include <vtkUnsignedCharArray.h>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
class DrawableTriangleMesh : public DrawableObject, public SemantisedTriangleMesh::TriangleMesh
{
public:

    const unsigned char BLUE[3] = {0,0,255};
    const unsigned char RED[3] = {255, 0, 0};
    const unsigned char BLACK[3] = {0,0,0};
    const unsigned char ORIGINAL_COLOR[3] = {200, 200, 200};
    const unsigned char GRAY[3] = {200, 200, 200};
    DrawableTriangleMesh();
    ~DrawableTriangleMesh();
    virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;
    virtual void update() override;
    int load(std::string filename);

    bool getDrawVertices() const;
    void setDrawVertices(bool newDrawVertices);

    bool getDrawWireframe() const;
    void setDrawWireframe(bool newDrawEdges);

    bool getDrawSurface() const;
    void setDrawSurface(bool newDrawSurface);

    bool getDrawAnnotations() const;
    void setDrawAnnotations(bool newDrawAnnotations);
    const std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation> > getSelectedAnnotations() const;
    void setAnnotations(const std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation> > &newAnnotations);
    bool addAnnotation(const std::shared_ptr<SemantisedTriangleMesh::Annotation> &newAnnotation);

    vtkSmartPointer<vtkActor> getSurfaceActor() const;

    vtkSmartPointer<vtkPoints> getMeshVertices() const;
    void setMeshVertices(vtkSmartPointer<vtkPoints> newMeshVertices);

    vtkSmartPointer<vtkActor> getPointsActor() const;

    void setTriangleColor(std::string, const unsigned char*);

protected:
    vtkSmartPointer<vtkUnsignedCharArray> meshVColors;
    vtkSmartPointer<vtkUnsignedCharArray> meshEColors;
    vtkSmartPointer<vtkUnsignedCharArray> meshTColors;
    vtkSmartPointer<vtkPoints> meshVertices;
    vtkSmartPointer<vtkCellArray> meshEdges;
    vtkSmartPointer<vtkCellArray> meshTriangles;
    vtkSmartPointer<vtkActor> pointsActor;
    vtkSmartPointer<vtkActor> wireframeActor;
    vtkSmartPointer<vtkActor> surfaceActor;
    vtkSmartPointer<vtkPropAssembly> annotationsActor;

    bool drawVertices, drawWireframe, drawSurface, drawAnnotations;

    void buildVTKStructure();

};

#endif //DRAWABLE_TRIANGLEMESH_H
