#ifndef DRAWABLEBOUNDINGMEASURE_H
#define DRAWABLEBOUNDINGMEASURE_H

#include "drawableattribute.hpp"
#include <boundingmeasure.hpp>
#include <vtkPlaneSource.h>
#include <vtkPoints.h>

class DrawableBoundingMeasure: public SemantisedTriangleMesh::BoundingMeasure,  public DrawableAttribute
{
public:
    DrawableBoundingMeasure();
    DrawableBoundingMeasure(BoundingMeasure);

    virtual ~DrawableBoundingMeasure() override;

    SemantisedTriangleMesh::Point *getBoundingBegin() const;
    void setBoundingBegin(SemantisedTriangleMesh::Point *value);

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;
    virtual void update() override;

    bool getDrawPlanes() const;
    void setDrawPlanes(bool value);
    virtual void print(std::ostream& os) override;

protected:
    vtkSmartPointer<vtkPoints> points;
    vtkSmartPointer<vtkPoints> points2D;
    vtkSmartPointer<vtkCellArray> measureSegmentCells;
    vtkSmartPointer<vtkPlaneSource> planeSource1;
    vtkSmartPointer<vtkPlaneSource> planeSource2;
    bool drawPlanes;
    double planeSize;

};

#endif // DRAWABLEBOUNDINGMEASURE_H
