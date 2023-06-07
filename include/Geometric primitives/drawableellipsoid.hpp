#ifndef DRAWABLEELLIPSOID_HPP
#define DRAWABLEELLIPSOID_HPP

#include "drawableobject.hpp"

#include <Point.hpp>

class Ellipsoid
{

public:
    Ellipsoid();
    ~Ellipsoid();

    double getXRadius() const;
    void setXRadius(double newXRadius);

    double getYRadius() const;
    void setYRadius(double newYRadius);

    double getZRadius() const;
    void setZRadius(double newZRadius);

    SemantisedTriangleMesh::Point getCentre() const;
    void setCentre(SemantisedTriangleMesh::Point newCentre);

protected:
    double xRadius;
    double yRadius;
    double zRadius;
    SemantisedTriangleMesh::Point centre;

};

class DrawableEllipsoid : public Ellipsoid, public DrawableObject
{
public:
    DrawableEllipsoid();
    ~DrawableEllipsoid();

    virtual void update() override;
    virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;
    double getUResolution() const;
    void setUResolution(double newUResolution);

    double getVResolution() const;
    void setVResolution(double newVResolution);

    double getWResolution() const;
    void setWResolution(double newWResolution);

    double *getColor() const;
    void setColor(double *newColor);
    void setColor(double r, double g, double b);

protected:
    double uResolution, vResolution, wResolution;
    double* color;
};

#endif // DRAWABLEELLIPSOID_HPP
