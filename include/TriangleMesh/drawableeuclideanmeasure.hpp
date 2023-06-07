#ifndef DRAWABLEEUCLIDEANMEASURE_H
#define DRAWABLEEUCLIDEANMEASURE_H

#include <drawableattribute.hpp>
#include <euclideanmeasure.hpp>
#include <vtkPoints.h>

class DrawableEuclideanMeasure : public SemantisedTriangleMesh::EuclideanMeasure, public DrawableAttribute
{
public:
    DrawableEuclideanMeasure();
    DrawableEuclideanMeasure(EuclideanMeasure measure);

    virtual ~DrawableEuclideanMeasure() override;

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;
    virtual void update() override;
    virtual void print(std::ostream& os) override;

protected:
    vtkSmartPointer<vtkPoints> points;
    vtkSmartPointer<vtkPoints> points2D;
    vtkSmartPointer<vtkCellArray> measureSegmentCells;

};

#endif // DRAWABLEEUCLIDEANMEASURE_H
