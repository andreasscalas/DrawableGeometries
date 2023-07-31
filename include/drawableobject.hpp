#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <vtkSmartPointer.h>
#include <vtkPropAssembly.h>

namespace Drawables {

    /**
     * @brief The base class for drawable objects in the scene.
     */
    class DrawableObject
    {
    public:

        /**
         * @brief DrawableObject default constructor for the class
         */
        DrawableObject();

        /**
         * @brief Draw the object on the given vtkPropAssembly.
         * @param assembly The vtkPropAssembly to draw the object on.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) = 0;

        /**
         * @brief Update the object if needed.
         */
        virtual void update() = 0;

        /**
         * @brief Get the flag indicating whether to draw the surface of the object.
         * @return true if the surface should be drawn, false otherwise.
         */
        bool getDrawSurface() const;

        /**
         * @brief Set the flag indicating whether to draw the surface of the object.
         * @param newDrawSurface true to draw the surface, false otherwise.
         */
        void setDrawSurface(bool newDrawSurface);

        /**
         * @brief Get the flag indicating whether to draw the wireframe of the object.
         * @return true if the wireframe should be drawn, false otherwise.
         */
        bool getDrawWireframe() const;

        /**
         * @brief Set the flag indicating whether to draw the wireframe of the object.
         * @param newDrawWireframe true to draw the wireframe, false otherwise.
         */
        void setDrawWireframe(bool newDrawWireframe);

        /**
         * @brief Get the opacity of the object.
         * @return The opacity value.
         */
        double getOpacity() const;

        /**
         * @brief Set the opacity of the object.
         * @param newOpacity The new opacity value.
         */
        void setOpacity(double newOpacity);

        /**
         * @brief Get the canvas (vtkPropAssembly) of the object.
         * @return The vtkPropAssembly canvas.
         */
        vtkSmartPointer<vtkPropAssembly> getCanvas() const;

    protected:
        vtkSmartPointer<vtkPropAssembly> canvas;
        bool drawSurface, drawWireframe;
        double opacity;
    };

    inline DrawableObject::DrawableObject()
    {
        canvas = vtkNew<vtkPropAssembly>();
        drawSurface = true;
        drawWireframe = false;
        opacity = 1;
    }

    inline bool DrawableObject::getDrawSurface() const
    {
        return drawSurface;
    }

    inline void DrawableObject::setDrawSurface(bool newDrawSurface)
    {
        drawSurface = newDrawSurface;
    }

    inline bool DrawableObject::getDrawWireframe() const
    {
        return drawWireframe;
    }

    inline void DrawableObject::setDrawWireframe(bool newDrawWireframe)
    {
        drawWireframe = newDrawWireframe;
    }

    inline double DrawableObject::getOpacity() const
    {
        return opacity;
    }

    inline void DrawableObject::setOpacity(double newOpacity)
    {
        opacity = newOpacity;
    }

    inline vtkSmartPointer<vtkPropAssembly> DrawableObject::getCanvas() const
    {
        return canvas;
    }

} // namespace Drawables

#endif // DRAWABLEOBJECT_H
