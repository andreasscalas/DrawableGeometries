#ifndef DRAWABLEBOUNDINGMEASURE_H
#define DRAWABLEBOUNDINGMEASURE_H

#include "drawableattribute.hpp"
#include <boundingmeasure.hpp>
#include <vtkPlaneSource.h>
#include <vtkPoints.h>

namespace Drawables {

    /**
     * @brief A class representing a drawable bounding measure that can be rendered in a 3D scene.
     * It inherits properties from SemantisedTriangleMesh::BoundingMeasure and provides additional drawing capabilities.
     */
    class DrawableBoundingMeasure : public SemantisedTriangleMesh::BoundingMeasure, public DrawableAttribute
    {
    public:
        /**
         * @brief Default constructor.
         */
        DrawableBoundingMeasure();

        /**
         * @brief Constructor taking a BoundingMeasure object as a parameter.
         * @param measure The BoundingMeasure object to copy data from.
         */
        DrawableBoundingMeasure(BoundingMeasure measure);

        /**
         * @brief Destructor.
         */
        virtual ~DrawableBoundingMeasure() override;

        /**
         * @brief Get the pointer to the beginning of the bounding measure.
         * @return A pointer to the beginning point of the bounding measure.
         */
        SemantisedTriangleMesh::Point* getBoundingBegin() const;

        /**
         * @brief Set the pointer to the beginning of the bounding measure.
         * @param value A pointer to the beginning point of the bounding measure.
         */
        void setBoundingBegin(SemantisedTriangleMesh::Point* value);

        /**
         * @brief Draw the drawable bounding measure on the specified canvas.
         * @param assembly The canvas where the bounding measure should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) override;

        /**
         * @brief Update the drawable bounding measure (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Get whether the planes of the bounding measure should be drawn.
         * @return True if the planes should be drawn, false otherwise.
         */
        bool getDrawPlanes() const;

        /**
         * @brief Set whether the planes of the bounding measure should be drawn.
         * @param value True to draw the planes, false otherwise.
         */
        void setDrawPlanes(bool value);

        /**
         * @brief Print information about the drawable bounding measure to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        virtual void print(std::ostream& os) override;

    protected:
        vtkSmartPointer<vtkPoints> points;                   // Points data structure in VTK for the bounding points
        vtkSmartPointer<vtkPoints> points2D;                 // Points data structure in VTK for 2D representation of bounding points
        vtkSmartPointer<vtkCellArray> measureSegmentCells;   // Cell array data structure in VTK for line segments of the bounding measure
        vtkSmartPointer<vtkPlaneSource> planeSource1;        // Plane source data structure in VTK for the first bounding plane
        vtkSmartPointer<vtkPlaneSource> planeSource2;        // Plane source data structure in VTK for the second bounding plane
        bool drawPlanes;                                    // True if the bounding planes should be drawn
        double planeSize;                                   // Size of the bounding planes

    };

} // namespace Drawables


#endif // DRAWABLEBOUNDINGMEASURE_H
