#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <vtkSmartPointer.h>
#include <vtkPropAssembly.h>

class DrawableObject
{
public:
    DrawableObject()
    {
        canvas = vtkNew<vtkPropAssembly>();
        drawSurface = true;
        drawWireframe = false;
        opacity = 1;
    }

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) = 0;
    virtual void update() = 0;

    inline bool getDrawSurface() const
    {
        return drawSurface;
    }

    inline void setDrawSurface(bool newDrawSurface)
    {
        drawSurface = newDrawSurface;
    }

    inline bool getDrawWireframe() const
    {
        return drawSurface;
    }

    inline void setDrawWireframe(bool newDrawWireframe)
    {
        drawSurface = newDrawWireframe;
    }

    double getOpacity() const;
    void setOpacity(double newOpacity);

    vtkSmartPointer<vtkPropAssembly> getCanvas() const;

protected:
    vtkSmartPointer<vtkPropAssembly> canvas;
    bool drawSurface, drawWireframe;
    double opacity;
};

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



#endif // DRAWABLEOBJECT_H
