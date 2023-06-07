#include "drawableannotation.hpp"

#include <drawableboundingmeasure.hpp>
#include <drawableeuclideanmeasure.hpp>
#include <drawablegeodesicmeasure.hpp>
#include <geometricattribute.hpp>

DrawableAnnotation::DrawableAnnotation()
{
    meshPoints = vtkSmartPointer<vtkPoints>::New();
    canvas = vtkSmartPointer<vtkPropAssembly>::New();
    this->drawAttributes = false;
    this->selected = false;
    this->opacity = 1.0;
}

vtkSmartPointer<vtkPoints> DrawableAnnotation::getMeshPoints() const
{
    return meshPoints;
}

void DrawableAnnotation::setMeshPoints(vtkSmartPointer<vtkPoints> newMeshPoints)
{
    meshPoints = newMeshPoints;
}

void DrawableAnnotation::addAttribute(std::shared_ptr<SemantisedTriangleMesh::Attribute> attribute)
{
    std::shared_ptr<DrawableAttribute> newAttribute;
    if(attribute->isGeometric())
    {
        auto geometricAttribute = std::dynamic_pointer_cast<SemantisedTriangleMesh::GeometricAttribute>(attribute);
        switch(geometricAttribute->getType())
        {

        case SemantisedTriangleMesh::GeometricAttributeType::EUCLIDEAN_MEASURE:
        {
            auto euclideanMeasure = std::dynamic_pointer_cast<SemantisedTriangleMesh::EuclideanMeasure>(geometricAttribute);
            newAttribute = std::make_shared<DrawableEuclideanMeasure>(*euclideanMeasure);
            break;
        }

        case SemantisedTriangleMesh::GeometricAttributeType::GEODESIC_MEASURE:
        {
            auto geodesicMeasure = std::dynamic_pointer_cast<SemantisedTriangleMesh::GeodesicMeasure>(geometricAttribute);
            newAttribute = std::make_shared<DrawableGeodesicMeasure>(*geodesicMeasure);
            break;
        }

        case SemantisedTriangleMesh::GeometricAttributeType::BOUNDING_MEASURE:
        {
            auto boundingMeasure = std::dynamic_pointer_cast<SemantisedTriangleMesh::BoundingMeasure>(geometricAttribute);
            newAttribute = std::make_shared<DrawableBoundingMeasure>(*boundingMeasure);
            break;
        }

        default:
            return;
        }

    }

    if(newAttribute != nullptr)
    {
        auto mesh = this->getMesh();
        auto drawable = std::static_pointer_cast<DrawableTriangleMesh>(mesh);
        newAttribute->setMesh(drawable);
        newAttribute->update();
        attributes.push_back(newAttribute);
    }
}

bool DrawableAnnotation::getDrawAttributes() const
{
    return drawAttributes;
}

void DrawableAnnotation::setDrawAttributes(bool newDrawAttributes)
{
    drawAttributes = newDrawAttributes;
}

bool DrawableAnnotation::getSelected() const
{
    return selected;
}

void DrawableAnnotation::setSelected(bool newSelected)
{
    selected = newSelected;
}

double DrawableAnnotation::getOpacity() const
{
    return opacity;
}

void DrawableAnnotation::setOpacity(double newOpacity)
{
    opacity = newOpacity;
}

void DrawableAnnotation::print(std::ostream& os)
{
    Annotation::print(os);
    os << "Opacity: " << opacity << std::endl;
    if(drawAttributes)
        os << "Attributes are drawn";
    else
        os << "Attributes aren't drawn";
    os << std::endl;
    if(selected)
        os << "Annotation is selected";
    else
        os << "Annotation isn't selected";
    os << std::endl;
}
