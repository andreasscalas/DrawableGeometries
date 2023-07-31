#ifndef DRAWABLECYLINDER_HPP
#define DRAWABLECYLINDER_HPP

#include <Point.hpp>
#include <drawableobject.hpp>


namespace Drawables {

    /**
     * @brief A simple Cylinder class representing a 3D cylinder.
     */
    class Cylinder
    {
    public:
        Cylinder();
        ~Cylinder();

        /**
         * @brief Get the radius of the cylinder.
         * @return The radius of the cylinder.
         */
        double getRadius() const;

        /**
         * @brief Set the radius of the cylinder.
         * @param newRadius The new radius value to be set.
         */
        void setRadius(double newRadius);

        /**
         * @brief Get the height of the cylinder.
         * @return The height of the cylinder.
         */
        double getHeight() const;

        /**
         * @brief Set the height of the cylinder.
         * @param newHeight The new height value to be set.
         */
        void setHeight(double newHeight);

        /**
         * @brief Get the center point of the cylinder.
         * @return The center point of the cylinder.
         */
        SemantisedTriangleMesh::Point getCentre() const;

        /**
         * @brief Set the center point of the cylinder.
         * @param newCentre The new center point to be set.
         */
        void setCentre(SemantisedTriangleMesh::Point newCentre);

        /**
         * @brief Get the axis direction of the cylinder.
         * @return The axis direction of the cylinder.
         */
        SemantisedTriangleMesh::Point getAxis() const;

        /**
         * @brief Set the axis direction of the cylinder.
         * @param newAxis The new axis direction to be set.
         */
        void setAxis(SemantisedTriangleMesh::Point newAxis);

    protected:
        double radius;
        double height;
        SemantisedTriangleMesh::Point axis;
        SemantisedTriangleMesh::Point centre;
    };


    /**
     * @brief A DrawableCylinder class that represents a drawable cylinder in the scene.
     * It inherits properties from both DrawableObject and Cylinder.
     */
    class DrawableCylinder : public Cylinder, public DrawableObject
    {
    public:
        DrawableCylinder();

        /**
         * @brief Update the drawable cylinder (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Draw the drawable cylinder on the specified canvas.
         * @param canvas The canvas where the cylinder should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Get the color of the drawable cylinder.
         * @return A pointer to an array containing the RGB color values.
         */
        double* getColor() const;

        /**
         * @brief Set the color of the drawable cylinder.
         * @param newColor A pointer to an array containing the new RGB color values.
         */
        void setColor(double* newColor);

        /**
         * @brief Set the color of the drawable cylinder.
         * @param r Red component of the new color.
         * @param g Green component of the new color.
         * @param b Blue component of the new color.
         */
        void setColor(double r, double g, double b);

        /**
         * @brief Get the resolution of the drawable cylinder.
         * @return The resolution of the drawable cylinder.
         */
        uint getResolution() const;

        /**
         * @brief Set the resolution of the drawable cylinder.
         * @param newResolution The new resolution value to be set.
         */
        void setResolution(uint newResolution);

    protected:
        uint resolution;
        double* color;
    };

} // namespace Drawables

#endif // DRAWABLECYLINDER_HPP
