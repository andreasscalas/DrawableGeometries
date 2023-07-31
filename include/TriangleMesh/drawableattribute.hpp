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


namespace Drawables {

    /**
     * @brief A class representing a drawable attribute that can be rendered in a 3D scene.
     * It inherits properties from SemantisedTriangleMesh::Attribute and provides additional drawing capabilities.
     */
    class DrawableAttribute : public virtual SemantisedTriangleMesh::Attribute
    {

    public:
        DrawableAttribute()
        {
            canvas = vtkSmartPointer<vtkPropAssembly>::New();
            drawAttribute = true;
            drawValue = true;
            error = false;
        }

        /**
         * @brief Destructor.
         */
        virtual ~DrawableAttribute() override { mesh = nullptr; }

        /**
         * @brief Draw the drawable attribute on the specified canvas.
         * @param assembly The canvas where the attribute should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> assembly) = 0;

        /**
         * @brief Update the drawable attribute (e.g., recalculate geometry) before drawing.
         */
        virtual void update() = 0;

        /**
         * @brief Get whether the attribute is drawn.
         * @return True if the attribute is drawn, false otherwise.
         */
        bool getDrawAttribute() const
        {
            return drawAttribute;
        }

        /**
         * @brief Set whether the attribute should be drawn.
         * @param value True if the attribute should be drawn, false otherwise.
         */
        void setDrawAttribute(bool value)
        {
            drawAttribute = value;
        }

        /**
         * @brief Get whether the attribute value is drawn.
         * @return True if the attribute value is drawn, false otherwise.
         */
        bool getDrawValue() const
        {
            return drawValue;
        }

        /**
         * @brief Set whether the attribute value should be drawn.
         * @param value True if the attribute value should be drawn, false otherwise.
         */
        void setDrawValue(bool value)
        {
            drawValue = value;
        }

        /**
         * @brief Get the canvas where the attribute is drawn.
         * @return The canvas where the attribute is drawn.
         */
        vtkSmartPointer<vtkPropAssembly> getCanvas() const {
            return canvas;
        }

        /**
         * @brief Set the canvas where the attribute should be drawn.
         * @param value The canvas where the attribute should be drawn.
         */
        void setCanvas(const vtkSmartPointer<vtkPropAssembly> &value) {
            canvas = value;
        }

        /**
         * @brief Get whether there was an error in rendering the attribute.
         * @return True if there was an error, false otherwise.
         */
        bool getError() const {
            return error;
        }

        /**
         * @brief Set whether there was an error in rendering the attribute.
         * @param value True if there was an error, false otherwise.
         */
        void setError(bool value) {
            error = value;
        }

        /**
         * @brief Get the mesh associated with the drawable attribute.
         * @return A shared pointer to the drawable triangle mesh.
         */
        inline std::shared_ptr<DrawableTriangleMesh> getMesh() const
        {
            return mesh;
        }

        /**
         * @brief Set the mesh associated with the drawable attribute.
         * @param newMesh A shared pointer to the drawable triangle mesh to be set.
         */
        inline void setMesh(std::shared_ptr<DrawableTriangleMesh> newMesh)
        {
            mesh = newMesh;
        }

        /**
         * @brief Print information about the drawable attribute to the specified output stream.
         * @param os The output stream where the information should be printed.
         */
        inline virtual void print(std::ostream& os) override
        {
            Attribute::print(os);
            if (drawAttribute)
                os << "Attribute is drawn" << std::endl;
            else
                os << "Attribute isn't drawn" << std::endl;
            if (drawValue)
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

} // namespace Drawables




#endif // DRAWABLEATTRIBUTE_H

