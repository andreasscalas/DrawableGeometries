#ifndef DRAWABLEATTRIBUTE_H
#define DRAWABLEATTRIBUTE_H

#include "drawabletrianglemesh.hpp"
#include <attribute.hpp>
#include <vtkSmartPointer.h>
#include <vtkPropAssembly.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkVectorText.h>
#include <string>
#include <vtkMapper2D.h>
#include <vtkPolyDataMapper2D.h>
#include <vtkProperty2D.h>


class DrawableAttribute : public virtual SemantisedTriangleMesh::Attribute
{

public:

    DrawableAttribute() {
        canvas = vtkSmartPointer<vtkPropAssembly>::New();
        drawAttribute = true;
        drawValue = true;
        error = false;
    }

    virtual ~DrawableAttribute() override { mesh = nullptr; }

    virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) = 0;

    virtual void update() = 0;

    bool getDrawAttribute() const
    {
        return drawAttribute;
    }

    void setDrawAttribute(bool value)
    {
        drawAttribute = value;
    }

    bool getDrawValue() const
    {
        return drawValue;
    }

    void setDrawValue(bool value)
    {
        drawValue = value;
    }

    vtkSmartPointer<vtkPropAssembly> getCanvas() const{
        return canvas;
    }

    void setCanvas(const vtkSmartPointer<vtkPropAssembly> &value){
        canvas = value;
    }

    bool getError() const{
        return error;
    }
    void setError(bool value){
        error = value;
    }

    inline std::shared_ptr<DrawableTriangleMesh> getMesh() const
    {
        return mesh;
    }

    inline void setMesh(std::shared_ptr<DrawableTriangleMesh> newMesh)
    {
        mesh = newMesh;
    }


    inline virtual void print(std::ostream& os) override
    {
        Attribute::print(os);
        if(drawAttribute)
            os << "Attribute is drawn" << std::endl;
        else
            os << "Attribute isn't drawn" << std::endl;
        if(drawValue)
            os << "Value is drawn" << std::endl;
        else
            os << "Value isn't drawn" << std::endl;
        os << "Error: " << error << std::endl;

    }


protected:
    vtkSmartPointer<vtkPropAssembly> canvas;
    bool drawAttribute;
    bool drawValue;
    bool error;
    std::shared_ptr<DrawableTriangleMesh> mesh;
    std::pair<unsigned int, unsigned int> textPosition;
};



#endif // DRAWABLEATTRIBUTE_H

