#ifndef DRAWABLEANNOTATION_H
#define DRAWABLEANNOTATION_H

#include "drawableobject.hpp"
#include <annotation.hpp>
#include <vtkPoints.h>
#include <vtkActor.h>
#include <vtkPropAssembly.h>
#include <attribute.hpp>
class DrawableAnnotation : virtual public DrawableObject, virtual public SemantisedTriangleMesh::Annotation
{
public:
    DrawableAnnotation();

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) = 0;
    virtual void update() = 0;
    virtual void clear() = 0;
    vtkSmartPointer<vtkPoints> getMeshPoints() const;
    void setMeshPoints(vtkSmartPointer<vtkPoints> newMeshPoints);
    void addAttribute(std::shared_ptr<SemantisedTriangleMesh::Attribute> attribute);

    bool getDrawAttributes() const;
    void setDrawAttributes(bool newDrawAttributes);

    bool getSelected() const;
    void setSelected(bool newSelected);

    double getOpacity() const;
    void setOpacity(double newOpacity);

    virtual void print(std::ostream& os) override;

    bool getDrawAnnotation() const;
    void setDrawAnnotation(bool newDrawAnnotation);

protected:
    vtkSmartPointer<vtkPoints> meshPoints;                     //Points data structure in VTK for the mesh

    double opacity;
    bool drawAttributes;                                       //True if the attributes has to be shown
    bool selected;
    bool drawAnnotation;
};

#endif // DRAWABLEANNOTATION_H
