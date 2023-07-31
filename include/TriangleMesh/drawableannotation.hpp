#ifndef DRAWABLEANNOTATION_H
#define DRAWABLEANNOTATION_H

#include "drawableobject.hpp"
#include <annotation.hpp>
#include <vtkPoints.h>
#include <vtkActor.h>
#include <vtkPropAssembly.h>
#include <attribute.hpp>

namespace Drawables {

    /**
     * @brief A class representing a drawable annotation that can be rendered in a 3D scene.
     * It inherits properties from both DrawableObject and SemantisedTriangleMesh::Annotation.
     */
    class DrawableAnnotation : virtual public DrawableObject, virtual public SemantisedTriangleMesh::Annotation
    {
    public:
        DrawableAnnotation();

        /**
         * @brief Draw the drawable annotation on the specified canvas.
         * @param assembly The canvas where the annotation should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;

        /**
         * @brief Update the drawable annotation (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override = 0;

        /**
         * @brief Clear the drawable annotation (e.g., remove all points and attributes).
         */
        virtual void clear() = 0;

        /**
         * @brief Get the points of the annotation.
         * @return A pointer to the points data structure in VTK for the annotation.
         */
        vtkSmartPointer<vtkPoints> getMeshPoints() const;

        /**
         * @brief Set the points of the annotation.
         * @param newMeshPoints A pointer to the new points data structure in VTK for the annotation to be set.
         */
        void setMeshPoints(vtkSmartPointer<vtkPoints> newMeshPoints);

        /**
         * @brief Add an attribute to the annotation.
         * @param attribute A shared pointer to the new attribute to be added.
         */
        void addAttribute(std::shared_ptr<SemantisedTriangleMesh::Attribute> attribute);

        /**
         * @brief Get the flag indicating if the attributes of the annotation should be drawn.
         * @return True if the attributes should be drawn, false otherwise.
         */
        bool getDrawAttributes() const;

        /**
         * @brief Set the flag indicating if the attributes of the annotation should be drawn.
         * @param newDrawAttributes The new flag value to be set.
         */
        void setDrawAttributes(bool newDrawAttributes);

        /**
         * @brief Get the flag indicating if the annotation is selected.
         * @return True if the annotation is selected, false otherwise.
         */
        bool getSelected() const;

        /**
         * @brief Set the flag indicating if the annotation is selected.
         * @param newSelected The new flag value to be set.
         */
        void setSelected(bool newSelected);

        /**
         * @brief Get the opacity of the annotation.
         * @return The opacity value of the annotation.
         */
        double getOpacity() const;

        /**
         * @brief Set the opacity of the annotation.
         * @param newOpacity The new opacity value to be set.
         */
        void setOpacity(double newOpacity);

        /**
         * @brief Print information about the annotation to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Get the flag indicating if the annotation should be drawn.
         * @return True if the annotation should be drawn, false otherwise.
         */
        bool getDrawAnnotation() const;

        /**
         * @brief Set the flag indicating if the annotation should be drawn.
         * @param newDrawAnnotation The new flag value to be set.
         */
        void setDrawAnnotation(bool newDrawAnnotation);

    protected:
        vtkSmartPointer<vtkPoints> meshPoints;                     //Points data structure in VTK for the mesh
        double opacity;
        bool drawAttributes;                                       //True if the attributes have to be shown
        bool selected;
        bool drawAnnotation;

    };

} // namespace Drawables


#endif // DRAWABLEANNOTATION_H
