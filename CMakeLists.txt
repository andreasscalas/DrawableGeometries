cmake_minimum_required(VERSION 3.21.0)

project(DrawableGeometries)
set(version 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
find_package(SemantisedTriangleMesh REQUIRED)
find_package(VTK COMPONENTS
    CommonCore
    FiltersCore
    InfovisCore
    InteractionStyle
    GUISupportQt
    IOLegacy
    CommonComputationalGeometry
    RenderingAnnotation
)
set(GEOMETRIC_PRIMITIVES "${CMAKE_CURRENT_SOURCE_DIR}/src/Geometric primitives")
set(GEOMETRIC_PRIMITIVES_H "${CMAKE_CURRENT_SOURCE_DIR}/include/Geometric primitives")
set(TRIANGLE_MESH ${CMAKE_CURRENT_SOURCE_DIR}/src/TriangleMesh)
set(TRIANGLE_MESH_H ${CMAKE_CURRENT_SOURCE_DIR}/include/TriangleMesh)
set(DRAWABLE_GEOMETRIES ${CMAKE_CURRENT_SOURCE_DIR})
set(DRAWABLE_GEOMETRIES_H ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCS
    ${TRIANGLE_MESH}/drawabletrianglemesh.cpp
    ${TRIANGLE_MESH}/drawableannotation.cpp
    ${TRIANGLE_MESH}/drawablesurfaceannotation.cpp
    ${TRIANGLE_MESH}/drawablelineannotation.cpp
    ${TRIANGLE_MESH}/drawablepointannotation.cpp
    ${TRIANGLE_MESH}/drawableboundingmeasure.cpp
    ${TRIANGLE_MESH}/drawableeuclideanmeasure.cpp
    ${TRIANGLE_MESH}/drawablegeodesicmeasure.cpp
    ${GEOMETRIC_PRIMITIVES}/drawableparallelepiped.cpp
    ${GEOMETRIC_PRIMITIVES}/drawablecylinder.cpp
    ${GEOMETRIC_PRIMITIVES}/drawableellipsoid.cpp
)

set(HDRS
    ${DRAWABLE_GEOMETRIES_H}/drawableobject.hpp
    ${TRIANGLE_MESH_H}/drawabletrianglemesh.hpp
    ${TRIANGLE_MESH_H}/drawableannotation.hpp
    ${TRIANGLE_MESH_H}/drawableattribute.hpp
    ${TRIANGLE_MESH_H}/drawablesurfaceannotation.hpp
    ${TRIANGLE_MESH_H}/drawablelineannotation.hpp
    ${TRIANGLE_MESH_H}/drawablepointannotation.hpp
    ${TRIANGLE_MESH_H}/drawableattribute.hpp
    ${TRIANGLE_MESH_H}/drawableboundingmeasure.hpp
    ${TRIANGLE_MESH_H}/drawableeuclideanmeasure.hpp
    ${TRIANGLE_MESH_H}/drawablegeodesicmeasure.hpp
    ${GEOMETRIC_PRIMITIVES_H}/drawableparallelepiped.hpp
    ${GEOMETRIC_PRIMITIVES_H}/drawablecylinder.hpp
    ${GEOMETRIC_PRIMITIVES_H}/drawableellipsoid.hpp
)

add_library(${PROJECT_NAME}-lib ${SRCS} ${HDRS})
add_executable(${PROJECT_NAME}-test ${DRAWABLE_GEOMETRIES}/src/main.cpp ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME}-lib PUBLIC
    $<BUILD_INTERFACE:${DRAWABLE_GEOMETRIES_H}>
    $<BUILD_INTERFACE:${GEOMETRIC_PRIMITIVES_H}>
    $<BUILD_INTERFACE:${TRIANGLE_MESH_H}>
    $<BUILD_INTERFACE:${SemantisedTriangleMesh_INCLUDE_DIRS}>)
target_include_directories(${PROJECT_NAME}-test PUBLIC
    $<BUILD_INTERFACE:${DRAWABLE_GEOMETRIES_H}>
    $<BUILD_INTERFACE:${GEOMETRIC_PRIMITIVES_H}>
    $<BUILD_INTERFACE:${TRIANGLE_MESH_H}>
    $<BUILD_INTERFACE:${SemantisedTriangleMesh_INCLUDE_DIRS}>)
target_link_libraries(${PROJECT_NAME}-lib PUBLIC ${VTK_LIBRARIES} ${SemantisedTriangleMesh_LIBRARIES})
target_link_libraries(${PROJECT_NAME}-test PUBLIC ${VTK_LIBRARIES} ${SemantisedTriangleMesh_LIBRARIES})

install(FILES ${HDRS} DESTINATION include/${PROJECT_NAME}-${version})
install(FILES ${SemantisedTriangleMesh_LIBRARIES} DESTINATION lib/${PROJECT_NAME}-${version})
install(TARGETS ${PROJECT_NAME}-lib
        DESTINATION lib/${PROJECT_NAME}-${version}
        EXPORT ${PROJECT_NAME}-targets)

install(EXPORT ${PROJECT_NAME}-targets
        DESTINATION lib/${PROJECT_NAME}-${version})

configure_file(
   ${DrawableGeometries_SOURCE_DIR}/pkg/drawablegeometries-config.cmake.in
   ${DrawableGeometries_BINARY_DIR}/pkg/drawablegeometries-config.cmake @ONLY)

configure_file(
   ${DrawableGeometries_SOURCE_DIR}/pkg/drawablegeometries-config-version.cmake.in
   ${DrawableGeometries_BINARY_DIR}/pkg/drawablegeometries-config-version.cmake @ONLY)

install(FILES ${DrawableGeometries_BINARY_DIR}/pkg/drawablegeometries-config.cmake
         ${DrawableGeometries_BINARY_DIR}/pkg/drawablegeometries-config-version.cmake
         DESTINATION lib/${PROJECT_NAME}-${version})

