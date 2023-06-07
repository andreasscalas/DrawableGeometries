#ifndef DRAWABLECYLINDER_HPP
#define DRAWABLECYLINDER_HPP

#include <Point.hpp>
#include <drawableobject.hpp>


class Cylinder
{
public:
    Cylinder();
    ~Cylinder();
    double getRadius() const;
    void setRadius(double newRadius);

    double getHeight() const;
    void setHeight(double newHeight);

    SemantisedTriangleMesh::Point getCentre() const;
    void setCentre(SemantisedTriangleMesh::Point newCentre);


    SemantisedTriangleMesh::Point getAxis() const;
    void setAxis(SemantisedTriangleMesh::Point newAxis);

protected:
    double radius;
    double height;
    SemantisedTriangleMesh::Point axis;
    SemantisedTriangleMesh::Point centre;
};

class DrawableCylinder : public Cylinder, public DrawableObject
{
public:
    DrawableCylinder();

    virtual void update() override;
    virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

    double *getColor() const;
    void setColor(double *newColor);
    void setColor(double r, double g, double b);

    uint getResolution() const;
    void setResolution(uint newResolution);

protected:
    uint resolution;
    double* color;
};

#endif // DRAWABLECYLINDER_HPP
