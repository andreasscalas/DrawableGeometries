#ifndef DRAWABLELINEANNOTATION_H
#define DRAWABLELINEANNOTATION_H
#include "drawableannotation.hpp"
#include <lineannotation.hpp>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>

class DrawableLineAnnotation : public SemantisedTriangleMesh::LineAnnotation, public DrawableAnnotation
{
public:
    DrawableLineAnnotation();
    DrawableLineAnnotation(LineAnnotation*);
    ~DrawableLineAnnotation() override {}

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;
    virtual void update() override;
    virtual void clear() override;

    float getLineWidth() const;
    void setLineWidth(float value);

    virtual void print(std::ostream &os) override;

protected:

    void init();

    vtkSmartPointer<vtkCellArray> annotatedLines;          //Data structure in VTK for the annotated triangles
    vtkSmartPointer<vtkUnsignedCharArray> annotationColors;   //Array of colors of the annotated triangles
    float lineWidth = 3.0;

};

#endif // DRAWABLELINEANNOTATION_H
