#ifndef DRAWABLEEUCLIDEANMEASURE_H
#define DRAWABLEEUCLIDEANMEASURE_H

#include <drawableattribute.hpp>
#include <euclideanmeasure.hpp>
#include <vtkPoints.h>

namespace Drawables {

    /**
     * @brief A class representing a drawable Euclidean measure that can be rendered in a 3D scene.
     * It inherits properties from SemantisedTriangleMesh::EuclideanMeasure and provides additional drawing capabilities.
     */
    class DrawableEuclideanMeasure : public SemantisedTriangleMesh::EuclideanMeasure, public DrawableAttribute
    {
    public:
        /**
         * @brief Default constructor.
         */
        DrawableEuclideanMeasure();

        /**
         * @brief Constructor taking a EuclideanMeasure object as a parameter.
         * @param measure The EuclideanMeasure object to copy data from.
         */
        DrawableEuclideanMeasure(EuclideanMeasure measure);

        /**
         * @brief Destructor.
         */
        virtual ~DrawableEuclideanMeasure() override;

        /**
         * @brief Draw the drawable Euclidean measure on the specified canvas.
         * @param assembly The canvas where the Euclidean measure should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;

        /**
         * @brief Update the drawable Euclidean measure (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Print information about the drawable Euclidean measure to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream& os) override;

    protected:
        vtkSmartPointer<vtkPoints> points;                   // Points data structure in VTK for the measure points
        vtkSmartPointer<vtkPoints> points2D;                 // Points data structure in VTK for 2D representation of measure points
        vtkSmartPointer<vtkCellArray> measureSegmentCells;   // Cell array data structure in VTK for line segments of the measure

    };

} // namespace Drawables


#endif // DRAWABLEEUCLIDEANMEASURE_H
