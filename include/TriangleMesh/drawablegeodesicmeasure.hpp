#ifndef DRAWABLEGEODESICMEASURE_H
#define DRAWABLEGEODESICMEASURE_H

#include <drawableattribute.hpp>
#include <geodesicmeasure.hpp>

namespace Drawables {

    /**
     * @brief A class representing a drawable geodesic measure that can be rendered in a 3D scene.
     * It inherits properties from SemantisedTriangleMesh::GeodesicMeasure and provides additional drawing capabilities.
     */
    class DrawableGeodesicMeasure : public SemantisedTriangleMesh::GeodesicMeasure, public DrawableAttribute
    {
    public:
        const double MEASURE_DISTANCE = 0.1;

        /**
         * @brief Default constructor.
         */
        DrawableGeodesicMeasure();

        /**
         * @brief Constructor taking a GeodesicMeasure object as a parameter.
         * @param measure The GeodesicMeasure object to copy data from.
         */
        DrawableGeodesicMeasure(GeodesicMeasure measure);

        /**
         * @brief Destructor.
         */
        virtual ~DrawableGeodesicMeasure() override {}

        /**
         * @brief Draw the drawable geodesic measure on the specified canvas.
         * @param assembly The canvas where the geodesic measure should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;

        /**
         * @brief Update the drawable geodesic measure (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Print information about the drawable geodesic measure to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream &os) override;

    protected:
        vtkSmartPointer<vtkActor> pointsActor;                // Actor for displaying the measure points
        vtkSmartPointer<vtkActor> measureLineActor;          // Actor for displaying the measure line
        vtkSmartPointer<vtkPoints> polylinePoints;           // Points data structure in VTK for the measure line
        vtkSmartPointer<vtkPoints> visualizedPoints;         // Points data structure in VTK for visualized measure points
        vtkSmartPointer<vtkCellArray> segments;              // Cell array data structure in VTK for line segments

        double measureStringDistance;                        // Distance for displaying the measure value

    };

} // namespace Drawables


#endif // DRAWABLEGEODESICMEASURE_H
