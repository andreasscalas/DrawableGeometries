#include "drawablesphere.hpp"



SemantisedTriangleMesh::Point Sphere::getCentre() const
{
    return centre;
}

void Sphere::setCentre(SemantisedTriangleMesh::Point newCentre)
{
    centre = newCentre;
}

DrawableSphere::DrawableSphere()
{

}
