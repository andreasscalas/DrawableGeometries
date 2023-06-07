#ifndef DRAWABLEPOINTANNOTATION_H
#define DRAWABLEPOINTANNOTATION_H

#include "drawableannotation.hpp"

#include <pointannotation.hpp>
#include <vtkUnsignedCharArray.h>


class DrawablePointAnnotation : public SemantisedTriangleMesh::PointAnnotation, public DrawableAnnotation
{
public:
    DrawablePointAnnotation();
    DrawablePointAnnotation(PointAnnotation*);
    virtual ~DrawablePointAnnotation() override;

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;
    virtual void update() override;
    virtual void clear() override;

    virtual void print(std::ostream& os) override;
protected:
    void init();

    vtkSmartPointer<vtkPoints> annotatedPoints;             //Data structure in VTK for the annotated triangles
    vtkSmartPointer<vtkUnsignedCharArray> annotationColors; //Array of colors of the annotated triangles
    float pointSize = 10.0;
};

#endif // DRAWABLEPOINTANNOTATION_H
