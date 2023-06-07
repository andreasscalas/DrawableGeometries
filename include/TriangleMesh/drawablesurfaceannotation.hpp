#ifndef DRAWABLEAREAANNOTATION_H
#define DRAWABLEAREAANNOTATION_H

#include <surfaceannotation.hpp>
#include <drawableannotation.hpp>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPolyData.h>

class DrawableSurfaceAnnotation : public SemantisedTriangleMesh::SurfaceAnnotation, public DrawableAnnotation
{
public:
    DrawableSurfaceAnnotation();
    DrawableSurfaceAnnotation(SurfaceAnnotation* annotation);
    ~DrawableSurfaceAnnotation() override {}

    virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;
    virtual void update() override;
    virtual void clear() override;
    virtual void print(std::ostream &os) override;

protected:

    void init();
    vtkSmartPointer<vtkCellArray> annotatedTriangles;          //Data structure in VTK for the annotated triangles
    vtkSmartPointer<vtkUnsignedCharArray> annotationColors;   //Array of colors of the annotated triangles
    vtkSmartPointer<vtkActor> outlinesActor;
};

#endif // DRAWABLEAREAANNOTATION_H
