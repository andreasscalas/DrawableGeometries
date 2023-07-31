#ifndef DRAWABLE_TRIANGLEMESH_H
#define DRAWABLE_TRIANGLEMESH_H

#include "drawableobject.hpp"
#include <TriangleMesh.hpp>
#include <vtkUnsignedCharArray.h>
#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>

namespace Drawables {

    /**
     * @brief A class representing a drawable triangle mesh that can be rendered in a 3D scene.
     * It inherits properties from both DrawableObject and SemantisedTriangleMesh::TriangleMesh.
     */
    class DrawableTriangleMesh : public DrawableObject, public SemantisedTriangleMesh::TriangleMesh
    {
    public:

        const unsigned char BLUE[3] = {0,0,255};
        const unsigned char RED[3] = {255, 0, 0};
        const unsigned char BLACK[3] = {0,0,0};
        const unsigned char ORIGINAL_COLOR[3] = {200, 200, 200};
        const unsigned char GRAY[3] = {200, 200, 200};

        DrawableTriangleMesh();
        ~DrawableTriangleMesh();

        /**
         * @brief Draw the drawable triangle mesh on the specified canvas.
         * @param canvas The canvas where the triangle mesh should be drawn.
         */
        virtual void draw(vtkSmartPointer<vtkPropAssembly> canvas) override;

        /**
         * @brief Update the drawable triangle mesh (e.g., recalculate geometry) before drawing.
         */
        virtual void update() override;

        /**
         * @brief Load a triangle mesh from a file.
         * @param filename The name of the file to load the triangle mesh from.
         * @return An integer value representing the success or failure of the loading process.
         */
        int load(std::string filename);

        /**
         * @brief Get the flag indicating if the vertices of the triangle mesh should be drawn.
         * @return True if the vertices should be drawn, false otherwise.
         */
        bool getDrawVertices() const;

        /**
         * @brief Set the flag indicating if the vertices of the triangle mesh should be drawn.
         * @param newDrawVertices The new flag value to be set.
         */
        void setDrawVertices(bool newDrawVertices);

        /**
         * @brief Get the flag indicating if the wireframe of the triangle mesh should be drawn.
         * @return True if the wireframe should be drawn, false otherwise.
         */
        bool getDrawWireframe() const;

        /**
         * @brief Set the flag indicating if the wireframe of the triangle mesh should be drawn.
         * @param newDrawEdges The new flag value to be set.
         */
        void setDrawWireframe(bool newDrawEdges);

        /**
         * @brief Get the flag indicating if the surface of the triangle mesh should be drawn.
         * @return True if the surface should be drawn, false otherwise.
         */
        bool getDrawSurface() const;

        /**
         * @brief Set the flag indicating if the surface of the triangle mesh should be drawn.
         * @param newDrawSurface The new flag value to be set.
         */
        void setDrawSurface(bool newDrawSurface);

        /**
         * @brief Get the flag indicating if the annotations of the triangle mesh should be drawn.
         * @return True if the annotations should be drawn, false otherwise.
         */
        bool getDrawAnnotations() const;

        /**
         * @brief Set the flag indicating if the annotations of the triangle mesh should be drawn.
         * @param newDrawAnnotations The new flag value to be set.
         */
        void setDrawAnnotations(bool newDrawAnnotations);

        /**
         * @brief Get the selected annotations of the triangle mesh.
         * @return A vector containing pointers to the selected annotations.
         */
        const std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation>> getSelectedAnnotations() const;

        /**
         * @brief Set the annotations of the triangle mesh.
         * @param newAnnotations A vector containing pointers to the new annotations to be set.
         */
        void setAnnotations(const std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation>> &newAnnotations);

        /**
         * @brief Add a new annotation to the triangle mesh.
         * @param newAnnotation A pointer to the new annotation to be added.
         * @return True if the annotation was successfully added, false otherwise.
         */
        bool addAnnotation(const std::shared_ptr<SemantisedTriangleMesh::Annotation> &newAnnotation);

        /**
         * @brief Get the actor representing the surface of the triangle mesh.
         * @return A pointer to the actor representing the surface of the triangle mesh.
         */
        vtkSmartPointer<vtkActor> getSurfaceActor() const;

        /**
         * @brief Get the points of the triangle mesh.
         * @return A pointer to the points of the triangle mesh.
         */
        vtkSmartPointer<vtkPoints> getMeshVertices() const;

        /**
         * @brief Set the points of the triangle mesh.
         * @param newMeshVertices A pointer to the new points of the triangle mesh to be set.
         */
        void setMeshVertices(vtkSmartPointer<vtkPoints> newMeshVertices);

        /**
         * @brief Get the actor representing the vertices of the triangle mesh.
         * @return A pointer to the actor representing the vertices of the triangle mesh.
         */
        vtkSmartPointer<vtkActor> getPointsActor() const;

        /**
         * @brief Set the color of a specific triangle in the triangle mesh.
         * @param triangleId The ID of the triangle to set the color for.
         * @param newColor A pointer to an array containing the new RGB color values.
         */
        void setTriangleColor(std::string triangleId, const unsigned char* newColor);

    protected:
        vtkSmartPointer<vtkUnsignedCharArray> meshVColors;
        vtkSmartPointer<vtkUnsignedCharArray> meshEColors;
        vtkSmartPointer<vtkUnsignedCharArray> meshTColors;
        vtkSmartPointer<vtkPoints> meshVertices;
        vtkSmartPointer<vtkCellArray> meshEdges;
        vtkSmartPointer<vtkCellArray> meshTriangles;
        vtkSmartPointer<vtkActor> pointsActor;
        vtkSmartPointer<vtkActor> wireframeActor;
        vtkSmartPointer<vtkActor> surfaceActor;
        vtkSmartPointer<vtkPropAssembly> annotationsActor;

        bool drawVertices, drawWireframe, drawSurface, drawAnnotations;

        /**
         * @brief Build the VTK structure to represent the triangle mesh.
         */
        void buildVTKStructure();

    };

} // namespace Drawables


#endif //DRAWABLE_TRIANGLEMESH_H
