#ifndef DRAWABLEGEODESICMEASURE_H
#define DRAWABLEGEODESICMEASURE_H

#include <drawableattribute.hpp>
#include <geodesicmeasure.hpp>

class DrawableGeodesicMeasure : public SemantisedTriangleMesh::GeodesicMeasure, public DrawableAttribute
{
public:
    const double MEASURE_DISTANCE = 0.1;

    DrawableGeodesicMeasure();
    DrawableGeodesicMeasure(GeodesicMeasure);
	virtual ~DrawableGeodesicMeasure()  override {}
    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;
    virtual void update() override;
    virtual void print(std::ostream &os) override;

protected:
    vtkSmartPointer<vtkActor> pointsActor;
    vtkSmartPointer<vtkActor> measureLineActor;
    vtkSmartPointer<vtkPoints> polylinePoints;
    vtkSmartPointer<vtkPoints> visualizedPoints;
    vtkSmartPointer<vtkCellArray> segments;

    double measureStringDistance;

};

#endif // DRAWABLEGEODESICMEASURE_H
