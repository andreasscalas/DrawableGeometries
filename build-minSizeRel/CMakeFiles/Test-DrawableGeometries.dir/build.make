# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andreas/Documenti/Progetti/DrawableGeometries

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel

# Include any dependencies generated for this target.
include CMakeFiles/Test-DrawableGeometries.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test-DrawableGeometries.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test-DrawableGeometries.dir/flags.make

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o: ../src/TriangleMesh/drawabletrianglemesh.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawabletrianglemesh.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawabletrianglemesh.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawabletrianglemesh.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o: ../src/TriangleMesh/drawableannotation.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawableannotation.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawableannotation.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawableannotation.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o: ../src/TriangleMesh/drawablesurfaceannotation.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablesurfaceannotation.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablesurfaceannotation.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablesurfaceannotation.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o: ../src/TriangleMesh/drawablelineannotation.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablelineannotation.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablelineannotation.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablelineannotation.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o: ../src/TriangleMesh/drawablepointannotation.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablepointannotation.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablepointannotation.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/TriangleMesh/drawablepointannotation.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o: ../src/Geometric\ primitives/drawableparallelepiped.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o -c "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableparallelepiped.cpp"

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableparallelepiped.cpp" > CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableparallelepiped.cpp" -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o: ../src/Geometric\ primitives/drawablecylinder.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o -c "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawablecylinder.cpp"

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawablecylinder.cpp" > CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawablecylinder.cpp" -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o: ../src/Geometric\ primitives/drawableellipsoid.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o -c "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableellipsoid.cpp"

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableellipsoid.cpp" > CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/andreas/Documenti/Progetti/DrawableGeometries/src/Geometric primitives/drawableellipsoid.cpp" -o CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.s

CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/flags.make
CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o: CMakeFiles/Test-DrawableGeometries.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o -MF CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o.d -o CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o -c /home/andreas/Documenti/Progetti/DrawableGeometries/src/main.cpp

CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/DrawableGeometries/src/main.cpp > CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.i

CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/DrawableGeometries/src/main.cpp -o CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.s

# Object files for target Test-DrawableGeometries
Test__DrawableGeometries_OBJECTS = \
"CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o" \
"CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o"

# External object files for target Test-DrawableGeometries
Test__DrawableGeometries_EXTERNAL_OBJECTS =

Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawabletrianglemesh.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawableannotation.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablesurfaceannotation.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablelineannotation.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/TriangleMesh/drawablepointannotation.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableparallelepiped.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawablecylinder.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/Geometric_primitives/drawableellipsoid.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/src/main.cpp.o
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/build.make
Test-DrawableGeometries: /usr/local/lib/libvtkInfovisCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkGUISupportQt-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/SemantisedTriangleMesh-1.0/libKDTree-lib.a
Test-DrawableGeometries: /usr/local/lib/SemantisedTriangleMesh-1.0/libSemantisedTriangleMesh.a
Test-DrawableGeometries: /usr/local/lib/SemantisedTriangleMesh-1.0/libTriangle-lib.a
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingOpenGL2-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingHyperTreeGrid-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingUI-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkglew-9.2.so.9.2.2
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libGLX.so
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libOpenGL.so
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libX11.so
Test-DrawableGeometries: /usr/local/lib/libvtkInteractionWidgets-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkInteractionStyle-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingContext2D-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkImagingSources-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkIOImage-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingFreeType-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkfreetype-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkImagingCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkRenderingCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonColor-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkFiltersSources-9.2.so.9.2.2
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
Test-DrawableGeometries: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
Test-DrawableGeometries: /usr/local/lib/libvtkFiltersGeneral-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonComputationalGeometry-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkFiltersCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkIOLegacy-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkIOCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonExecutionModel-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonDataModel-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonTransforms-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonMisc-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonMath-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkCommonCore-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtksys-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkkissfft-9.2.so.9.2.2
Test-DrawableGeometries: /usr/local/lib/libvtkzlib-9.2.so.9.2.2
Test-DrawableGeometries: CMakeFiles/Test-DrawableGeometries.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Test-DrawableGeometries"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test-DrawableGeometries.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test-DrawableGeometries.dir/build: Test-DrawableGeometries
.PHONY : CMakeFiles/Test-DrawableGeometries.dir/build

CMakeFiles/Test-DrawableGeometries.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test-DrawableGeometries.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test-DrawableGeometries.dir/clean

CMakeFiles/Test-DrawableGeometries.dir/depend:
	cd /home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreas/Documenti/Progetti/DrawableGeometries /home/andreas/Documenti/Progetti/DrawableGeometries /home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel /home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel /home/andreas/Documenti/Progetti/DrawableGeometries/build-minSizeRel/CMakeFiles/Test-DrawableGeometries.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test-DrawableGeometries.dir/depend

