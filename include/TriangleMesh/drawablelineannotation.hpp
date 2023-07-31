#ifndef DRAWABLELINEANNOTATION_H
#define DRAWABLELINEANNOTATION_H
#include "drawableannotation.hpp"
#include <lineannotation.hpp>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>

namespace Drawables {

    /**
     * @brief A class representing a drawable line annotation that can be rendered in a 3D scene.
     * It inherits properties from both SemantisedTriangleMesh::LineAnnotation and DrawableAnnotation.
     */
    class DrawableLineAnnotation : public SemantisedTriangleMesh::LineAnnotation, public DrawableAnnotation
    {
    public:
        DrawableLineAnnotation();
        DrawableLineAnnotation(LineAnnotation*);

        /**
         * @brief Destructor.
         */
        virtual ~DrawableLineAnnotation() override {}

        /**
         * @brief Draw the drawable line annotation on the specified canvas.
         * @param canvas The canvas where the line annotation should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Update the drawable line annotation (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Clear the drawable line annotation (e.g., remove all lines and attributes).
         */
        virtual void clear() override;

        /**
         * @brief Get the width of the rendered lines.
         * @return The width of the rendered lines.
         */
        float getLineWidth() const;

        /**
         * @brief Set the width of the rendered lines.
         * @param value The width of the lines to be set.
         */
        void setLineWidth(float value);

        /**
         * @brief Print information about the drawable line annotation to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream &os) override;

    protected:
        /**
         * @brief Initialize the drawable line annotation.
         */
        void init();

        vtkSmartPointer<vtkCellArray> annotatedLines;           // Data structure in VTK for the annotated lines
        vtkSmartPointer<vtkUnsignedCharArray> annotationColors; // Array of colors of the annotated lines
        float lineWidth = 3.0;                                 // Width of the rendered lines
    };

} // namespace Drawables


#endif // DRAWABLELINEANNOTATION_H
