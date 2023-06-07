# Install script for directory: /home/andreas/Documenti/Progetti/DrawableGeometries

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "MinSizeRel")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DrawableGeometries-1.0" TYPE FILE FILES
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/drawableobject.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawabletrianglemesh.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawableannotation.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawableattribute.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawablesurfaceannotation.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawablelineannotation.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawablepointannotation.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawableattribute.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawableboundingmeasure.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawableeuclideanmeasure.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/TriangleMesh/drawablegeodesicmeasure.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/Geometric primitives/drawableparallelepiped.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/Geometric primitives/drawablecylinder.hpp"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/include/Geometric primitives/drawableellipsoid.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0" TYPE FILE FILES
    "/usr/local/lib/SemantisedTriangleMesh-1.0/libDataStructures-lib.a"
    "/usr/local/lib/SemantisedTriangleMesh-1.0/libKDTree-lib.a"
    "/usr/local/lib/SemantisedTriangleMesh-1.0/libSemantisedTriangleMesh.a"
    "/usr/local/lib/SemantisedTriangleMesh-1.0/libTriangle-lib.a"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0" TYPE STATIC_LIBRARY FILES "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/libDrawableGeometries-lib.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0/DrawableGeometries-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0/DrawableGeometries-targets.cmake"
         "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles/Export/72f3dbc1ad426859d5041b79507875a8/DrawableGeometries-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0/DrawableGeometries-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0/DrawableGeometries-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0" TYPE FILE FILES "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles/Export/72f3dbc1ad426859d5041b79507875a8/DrawableGeometries-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0" TYPE FILE FILES "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles/Export/72f3dbc1ad426859d5041b79507875a8/DrawableGeometries-targets-minsizerel.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DrawableGeometries-1.0" TYPE FILE FILES
    "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/pkg/drawablegeometries-config.cmake"
    "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/pkg/drawablegeometries-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
