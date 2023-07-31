#ifndef DRAWABLEAREAANNOTATION_H
#define DRAWABLEAREAANNOTATION_H

#include <surfaceannotation.hpp>
#include <drawableannotation.hpp>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPolyData.h>

namespace Drawables {

    /**
     * @brief A class representing a drawable surface annotation that can be rendered in a 3D scene.
     * It inherits properties from both SemantisedTriangleMesh::SurfaceAnnotation and DrawableAnnotation.
     */
    class DrawableSurfaceAnnotation : public SemantisedTriangleMesh::SurfaceAnnotation, public DrawableAnnotation
    {
    public:
        DrawableSurfaceAnnotation();
        DrawableSurfaceAnnotation(SurfaceAnnotation* annotation);

        /**
         * @brief Destructor.
         */
        ~DrawableSurfaceAnnotation() override {}

        /**
         * @brief Draw the drawable surface annotation on the specified canvas.
         * @param canvas The canvas where the surface annotation should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Update the drawable surface annotation (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Clear the drawable surface annotation (e.g., remove all points and attributes).
         */
        virtual void clear() override;

        /**
         * @brief Print information about the drawable surface annotation to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream &os) override;

    protected:
        /**
         * @brief Initialize the drawable surface annotation.
         */
        void init();

        vtkSmartPointer<vtkCellArray> annotatedTriangles;          //Data structure in VTK for the annotated triangles
        vtkSmartPointer<vtkUnsignedCharArray> annotationColors;   //Array of colors of the annotated triangles
        vtkSmartPointer<vtkActor> outlinesActor;                 // Actor for displaying outlines of the annotation
    };

} // namespace Drawables


#endif // DRAWABLEAREAANNOTATION_H
