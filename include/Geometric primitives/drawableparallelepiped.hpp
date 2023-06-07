#ifndef DRAWABLEPARALLELEPIPED_H
#define DRAWABLEPARALLELEPIPED_H

#include "drawableobject.hpp"

#include <Point.hpp>
#include <memory>

class Parallelepiped
{
public:

    SemantisedTriangleMesh::Point getP1() const;
    void setP1(SemantisedTriangleMesh::Point newP1);

    SemantisedTriangleMesh::Point getP2() const;
    void setP2(SemantisedTriangleMesh::Point newP2);

protected:
    SemantisedTriangleMesh::Point p1, p2;
};

class DrawableParallelepiped : public Parallelepiped, public DrawableObject
{
public:
    DrawableParallelepiped();
    ~DrawableParallelepiped();

    virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;
    virtual void update() override;

    double *getColor() const;
    void setColor(double *newColor);
    void setColor(double r, double g, double b);

    double getOpacity() const;
    void setOpacity(double newOpacity);

    bool getDrawSurface() const;
    void setDrawSurface(bool newDrawSurface);
    bool getDrawWireframe() const;
    void setDrawWireframe(bool newDrawWireframe);


protected:
    double* color;
    bool drawSurface, drawWireframe;
    double opacity;

};

#endif // DRAWABLEPARALLELEPIPED_H
