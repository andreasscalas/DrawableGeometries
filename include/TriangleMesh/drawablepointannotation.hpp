#ifndef DRAWABLEPOINTANNOTATION_H
#define DRAWABLEPOINTANNOTATION_H

#include "drawableannotation.hpp"

#include <pointannotation.hpp>
#include <vtkUnsignedCharArray.h>


namespace Drawables {

    /**
     * @brief A class representing a drawable point annotation that can be rendered in a 3D scene.
     * It inherits properties from both SemantisedTriangleMesh::PointAnnotation and DrawableAnnotation.
     */
    class DrawablePointAnnotation : public SemantisedTriangleMesh::PointAnnotation, public DrawableAnnotation
    {
    public:
        DrawablePointAnnotation();
        DrawablePointAnnotation(PointAnnotation*);

        /**
         * @brief Destructor.
         */
        virtual ~DrawablePointAnnotation() override;

        /**
         * @brief Draw the drawable point annotation on the specified canvas.
         * @param canvas The canvas where the point annotation should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Update the drawable point annotation (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Clear the drawable point annotation (e.g., remove all points and attributes).
         */
        virtual void clear() override;

        /**
         * @brief Print information about the drawable point annotation to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream& os) override;

    protected:
        /**
         * @brief Initialize the drawable point annotation.
         */
        void init();

        vtkSmartPointer<vtkPoints> annotatedPoints;             //Data structure in VTK for the annotated points
        vtkSmartPointer<vtkUnsignedCharArray> annotationColors; //Array of colors of the annotated points
        float pointSize = 10.0;                                // Size of the rendered point
    };

} // namespace Drawables


#endif // DRAWABLEPOINTANNOTATION_H
