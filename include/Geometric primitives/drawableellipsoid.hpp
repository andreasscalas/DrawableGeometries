#ifndef DRAWABLEELLIPSOID_HPP
#define DRAWABLEELLIPSOID_HPP

#include "drawableobject.hpp"

#include <Point.hpp>

namespace Drawables {

    /**
     * @brief A simple Ellipsoid class representing a 3D ellipsoid.
     */
    class Ellipsoid
    {
    public:
        Ellipsoid();
        ~Ellipsoid();

        /**
         * @brief Get the x-radius of the ellipsoid.
         * @return The x-radius of the ellipsoid.
         */
        double getXRadius() const;

        /**
         * @brief Set the x-radius of the ellipsoid.
         * @param newXRadius The new x-radius value to be set.
         */
        void setXRadius(double newXRadius);

        /**
         * @brief Get the y-radius of the ellipsoid.
         * @return The y-radius of the ellipsoid.
         */
        double getYRadius() const;

        /**
         * @brief Set the y-radius of the ellipsoid.
         * @param newYRadius The new y-radius value to be set.
         */
        void setYRadius(double newYRadius);

        /**
         * @brief Get the z-radius of the ellipsoid.
         * @return The z-radius of the ellipsoid.
         */
        double getZRadius() const;

        /**
         * @brief Set the z-radius of the ellipsoid.
         * @param newZRadius The new z-radius value to be set.
         */
        void setZRadius(double newZRadius);

        /**
         * @brief Get the center point of the ellipsoid.
         * @return The center point of the ellipsoid.
         */
        SemantisedTriangleMesh::Point getCentre() const;

        /**
         * @brief Set the center point of the ellipsoid.
         * @param newCentre The new center point to be set.
         */
        void setCentre(SemantisedTriangleMesh::Point newCentre);

    protected:
        double xRadius;
        double yRadius;
        double zRadius;
        SemantisedTriangleMesh::Point centre;
    };


    /**
     * @brief A DrawableEllipsoid class that represents a drawable ellipsoid in the scene.
     * It inherits properties from both DrawableObject and Ellipsoid.
     */
    class DrawableEllipsoid : public Ellipsoid, public DrawableObject
    {
    public:
        DrawableEllipsoid();
        ~DrawableEllipsoid();

        /**
         * @brief Update the drawable ellipsoid (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Draw the drawable ellipsoid on the specified canvas.
         * @param canvas The canvas where the ellipsoid should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Get the U-resolution of the drawable ellipsoid.
         * @return The U-resolution of the drawable ellipsoid.
         */
        double getUResolution() const;

        /**
         * @brief Set the U-resolution of the drawable ellipsoid.
         * @param newUResolution The new U-resolution value to be set.
         */
        void setUResolution(double newUResolution);

        /**
         * @brief Get the V-resolution of the drawable ellipsoid.
         * @return The V-resolution of the drawable ellipsoid.
         */
        double getVResolution() const;

        /**
         * @brief Set the V-resolution of the drawable ellipsoid.
         * @param newVResolution The new V-resolution value to be set.
         */
        void setVResolution(double newVResolution);

        /**
         * @brief Get the W-resolution of the drawable ellipsoid.
         * @return The W-resolution of the drawable ellipsoid.
         */
        double getWResolution() const;

        /**
         * @brief Set the W-resolution of the drawable ellipsoid.
         * @param newWResolution The new W-resolution value to be set.
         */
        void setWResolution(double newWResolution);

        /**
         * @brief Get the color of the drawable ellipsoid.
         * @return A pointer to an array containing the RGB color values.
         */
        double* getColor() const;

        /**
         * @brief Set the color of the drawable ellipsoid.
         * @param newColor A pointer to an array containing the new RGB color values.
         */
        void setColor(double* newColor);

        /**
         * @brief Set the color of the drawable ellipsoid.
         * @param r Red component of the new color.
         * @param g Green component of the new color.
         * @param b Blue component of the new color.
         */
        void setColor(double r, double g, double b);

    protected:
        double uResolution, vResolution, wResolution;
        double* color;
    };

} // namespace Drawables


#endif // DRAWABLEELLIPSOID_HPP
