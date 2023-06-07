#ifndef DRAWABLESPHERE_H
#define DRAWABLESPHERE_H

#include <Point.hpp>


class Sphere
{
public:
    SemantisedTriangleMesh::Point getCentre() const;
    void setCentre(SemantisedTriangleMesh::Point newCentre);

protected:
    SemantisedTriangleMesh::Point centre;
    double radius;
};

class DrawableSphere : Sphere
{
public:
    DrawableSphere();
};

#endif // DRAWABLESPHERE_H
