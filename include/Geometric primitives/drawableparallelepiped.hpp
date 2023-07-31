#ifndef DRAWABLEPARALLELEPIPED_H
#define DRAWABLEPARALLELEPIPED_H

#include "drawableobject.hpp"

#include <Point.hpp>
#include <memory>

namespace Drawables {

    /**
     * @brief A simple Parallelepiped class representing a 3D parallelepiped defined by two corner points.
     */
    class Parallelepiped
    {
    public:

        /**
         * @brief Get the first corner point (P1) of the parallelepiped.
         * @return The first corner point of the parallelepiped.
         */
        SemantisedTriangleMesh::Point getP1() const;

        /**
         * @brief Set the first corner point (P1) of the parallelepiped.
         * @param newP1 The new first corner point to be set.
         */
        void setP1(SemantisedTriangleMesh::Point newP1);

        /**
         * @brief Get the second corner point (P2) of the parallelepiped.
         * @return The second corner point of the parallelepiped.
         */
        SemantisedTriangleMesh::Point getP2() const;

        /**
         * @brief Set the second corner point (P2) of the parallelepiped.
         * @param newP2 The new second corner point to be set.
         */
        void setP2(SemantisedTriangleMesh::Point newP2);

    protected:
        SemantisedTriangleMesh::Point p1, p2;
    };


    /**
     * @brief A DrawableParallelepiped class that represents a drawable parallelepiped in the scene.
     * It inherits properties from both DrawableObject and Parallelepiped.
     */
    class DrawableParallelepiped : public Parallelepiped, public DrawableObject
    {
    public:
        DrawableParallelepiped();
        ~DrawableParallelepiped();

        /**
         * @brief Draw the drawable parallelepiped on the specified canvas.
         * @param canvas The canvas where the parallelepiped should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Update the drawable parallelepiped (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Get the color of the drawable parallelepiped.
         * @return A pointer to an array containing the RGB color values.
         */
        double* getColor() const;

        /**
         * @brief Set the color of the drawable parallelepiped.
         * @param newColor A pointer to an array containing the new RGB color values.
         */
        void setColor(double* newColor);

        /**
         * @brief Set the color of the drawable parallelepiped.
         * @param r Red component of the new color.
         * @param g Green component of the new color.
         * @param b Blue component of the new color.
         */
        void setColor(double r, double g, double b);

        /**
         * @brief Get the opacity of the drawable parallelepiped.
         * @return The opacity value of the drawable parallelepiped.
         */
        double getOpacity() const;

        /**
         * @brief Set the opacity of the drawable parallelepiped.
         * @param newOpacity The new opacity value to be set.
         */
        void setOpacity(double newOpacity);

        /**
         * @brief Get the flag indicating if the surface of the parallelepiped should be drawn.
         * @return True if the surface should be drawn, false otherwise.
         */
        bool getDrawSurface() const;

        /**
         * @brief Set the flag indicating if the surface of the parallelepiped should be drawn.
         * @param newDrawSurface The new flag value to be set.
         */
        void setDrawSurface(bool newDrawSurface);

        /**
         * @brief Get the flag indicating if the wireframe of the parallelepiped should be drawn.
         * @return True if the wireframe should be drawn, false otherwise.
         */
        bool getDrawWireframe() const;

        /**
         * @brief Set the flag indicating if the wireframe of the parallelepiped should be drawn.
         * @param newDrawWireframe The new flag value to be set.
         */
        void setDrawWireframe(bool newDrawWireframe);

    protected:
        double* color;
        bool drawSurface, drawWireframe;
        double opacity;

    };

} // namespace Drawables


#endif // DRAWABLEPARALLELEPIPED_H
