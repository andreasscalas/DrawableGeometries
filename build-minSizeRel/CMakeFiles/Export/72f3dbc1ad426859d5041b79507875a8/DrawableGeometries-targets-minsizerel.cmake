#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "DrawableGeometries-lib" for configuration "MinSizeRel"
set_property(TARGET DrawableGeometries-lib APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(DrawableGeometries-lib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/DrawableGeometries-1.0/libDrawableGeometries-lib.a"
  )

list(APPEND _cmake_import_check_targets DrawableGeometries-lib )
list(APPEND _cmake_import_check_files_for_DrawableGeometries-lib "${_IMPORT_PREFIX}/lib/DrawableGeometries-1.0/libDrawableGeometries-lib.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
