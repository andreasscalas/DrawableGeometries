#include "drawabletrianglemesh.hpp"
#include <semanticsfilemanager.hpp>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkAutoInit.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <drawableparallelepiped.hpp>
#include <drawableellipsoid.hpp>
#include <drawablecylinder.hpp>
#include <drawablesurfaceannotation.hpp>
VTK_MODULE_INIT(vtkRenderingOpenGL2)

int main(int argc, char* argv[])
{
    if(argc < 3)
        return 1;
    auto mesh = std::make_shared<Drawables::DrawableTriangleMesh>();
    mesh->load(argv[1]);
    SemantisedTriangleMesh::SemanticsFileManager manager;
    manager.setMesh(mesh);
    auto annotations = manager.readAndStoreAnnotations(argv[2]);
    mesh->setAnnotations(annotations);

    auto renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    auto canvas = vtkSmartPointer<vtkPropAssembly>::New();

    renderer->SetBackground(255,255,255);
    mesh->setDrawWireframe(false);
    mesh->setDrawAnnotations(true);
    mesh->draw(canvas);
    mesh->computeShortestPath(mesh->getVertex("0"), mesh->getVertex(std::to_string(mesh->getVerticesNumber() - 1)), SemantisedTriangleMesh::DistanceType::EUCLIDEAN_DISTANCE, true, true);
    auto parallelepiped = std::make_shared<Drawables::DrawableParallelepiped>();
    mesh->computeProperties();
    parallelepiped->setP1(mesh->getMin());
    parallelepiped->setP2(mesh->getMax());
    parallelepiped->setOpacity(0.5);
    parallelepiped->setColor(0.6,0.4,0.2);
    parallelepiped->setDrawSurface(true);
    parallelepiped->setDrawWireframe(true);
    parallelepiped->update();
    //parallelepiped->draw(canvas);
    auto sphere = std::make_shared<Drawables::DrawableEllipsoid>();
    sphere->setCentre(mesh->getMin());
    sphere->setXRadius(10);
    sphere->setYRadius(10);
    sphere->setZRadius(10);
    sphere->setUResolution(50);
    sphere->setVResolution(50);
    sphere->setWResolution(50);
    sphere->setColor(1, 0, 0);
    sphere->setOpacity(0.5);
    sphere->setDrawSurface(true);
    sphere->update();
    //sphere->draw(canvas);

    auto cylinderAxis = SemantisedTriangleMesh::Point(mesh->getMax().getX() - mesh->getMin().getX(), 0, 0);
    auto cylinder = std::make_shared<Drawables::DrawableCylinder>();
    cylinder->setCentre(mesh->getMax());
    cylinder->setRadius(5);
    cylinder->setHeight(cylinderAxis.norm());
    cylinderAxis.normalise();
    cylinder->setAxis(cylinderAxis);
    cylinder->setDrawSurface(true);
    cylinder->setDrawWireframe(true);
    cylinder->setColor(1, 0, 0);
    cylinder->setOpacity(0.5);
    cylinder->update();
    //cylinder->draw(canvas);

    cylinder->setResolution(100);
    renderer->AddActor(canvas);
    renderWindow->SetSize(640, 480);
    renderWindow->AddRenderer(renderer);
    renderWindowInteractor->SetRenderWindow(renderWindow);
    renderWindow->Render();
    renderWindowInteractor->SetInteractorStyle(vtkInteractorStyleTrackballCamera::New());
    renderWindowInteractor->Start();
    return 0;
}
