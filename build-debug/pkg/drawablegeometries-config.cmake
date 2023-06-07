# Compute installation prefix relative to this file.
get_filename_component(_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_prefix "${_dir}/../.." ABSOLUTE)

# Import the targets.
include("${_prefix}/lib/DrawableGeometries-1.0/DrawableGeometries-targets.cmake")

# Report other information.
set(DrawableGeometries_INCLUDE_DIRS "${_prefix}/include/DrawableGeometries-1.0")

file(GLOB DrawableGeometries_LIBRARIES "${_prefix}/lib/DrawableGeometries-1.0/lib*")
