# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nina/zad5_3-n-bartnik

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nina/zad5_3-n-bartnik/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/src/example.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/example.cpp.o: ../src/example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/src/example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/example.cpp.o -c /home/nina/zad5_3-n-bartnik/src/example.cpp

CMakeFiles/engine.dir/src/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/example.cpp > CMakeFiles/engine.dir/src/example.cpp.i

CMakeFiles/engine.dir/src/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/example.cpp -o CMakeFiles/engine.dir/src/example.cpp.s

CMakeFiles/engine.dir/src/Cuboid.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Cuboid.cpp.o: ../src/Cuboid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/src/Cuboid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Cuboid.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Cuboid.cpp

CMakeFiles/engine.dir/src/Cuboid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Cuboid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Cuboid.cpp > CMakeFiles/engine.dir/src/Cuboid.cpp.i

CMakeFiles/engine.dir/src/Cuboid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Cuboid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Cuboid.cpp -o CMakeFiles/engine.dir/src/Cuboid.cpp.s

CMakeFiles/engine.dir/src/GeoSolid.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/GeoSolid.cpp.o: ../src/GeoSolid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/src/GeoSolid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/GeoSolid.cpp.o -c /home/nina/zad5_3-n-bartnik/src/GeoSolid.cpp

CMakeFiles/engine.dir/src/GeoSolid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/GeoSolid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/GeoSolid.cpp > CMakeFiles/engine.dir/src/GeoSolid.cpp.i

CMakeFiles/engine.dir/src/GeoSolid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/GeoSolid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/GeoSolid.cpp -o CMakeFiles/engine.dir/src/GeoSolid.cpp.s

CMakeFiles/engine.dir/src/matrix.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/matrix.cpp.o: ../src/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/src/matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/matrix.cpp.o -c /home/nina/zad5_3-n-bartnik/src/matrix.cpp

CMakeFiles/engine.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/matrix.cpp > CMakeFiles/engine.dir/src/matrix.cpp.i

CMakeFiles/engine.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/matrix.cpp -o CMakeFiles/engine.dir/src/matrix.cpp.s

CMakeFiles/engine.dir/src/Matrix3x3.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Matrix3x3.cpp.o: ../src/Matrix3x3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/src/Matrix3x3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Matrix3x3.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Matrix3x3.cpp

CMakeFiles/engine.dir/src/Matrix3x3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Matrix3x3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Matrix3x3.cpp > CMakeFiles/engine.dir/src/Matrix3x3.cpp.i

CMakeFiles/engine.dir/src/Matrix3x3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Matrix3x3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Matrix3x3.cpp -o CMakeFiles/engine.dir/src/Matrix3x3.cpp.s

CMakeFiles/engine.dir/src/Prism.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Prism.cpp.o: ../src/Prism.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/src/Prism.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Prism.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Prism.cpp

CMakeFiles/engine.dir/src/Prism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Prism.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Prism.cpp > CMakeFiles/engine.dir/src/Prism.cpp.i

CMakeFiles/engine.dir/src/Prism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Prism.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Prism.cpp -o CMakeFiles/engine.dir/src/Prism.cpp.s

CMakeFiles/engine.dir/src/Drone.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Drone.cpp.o: ../src/Drone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/engine.dir/src/Drone.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Drone.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Drone.cpp

CMakeFiles/engine.dir/src/Drone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Drone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Drone.cpp > CMakeFiles/engine.dir/src/Drone.cpp.i

CMakeFiles/engine.dir/src/Drone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Drone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Drone.cpp -o CMakeFiles/engine.dir/src/Drone.cpp.s

CMakeFiles/engine.dir/src/vector.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/vector.cpp.o: ../src/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/engine.dir/src/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/vector.cpp.o -c /home/nina/zad5_3-n-bartnik/src/vector.cpp

CMakeFiles/engine.dir/src/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/vector.cpp > CMakeFiles/engine.dir/src/vector.cpp.i

CMakeFiles/engine.dir/src/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/vector.cpp -o CMakeFiles/engine.dir/src/vector.cpp.s

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o: ../src/lacze_do_gnuplota.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o -c /home/nina/zad5_3-n-bartnik/src/lacze_do_gnuplota.cpp

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/lacze_do_gnuplota.cpp > CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/lacze_do_gnuplota.cpp -o CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s

CMakeFiles/engine.dir/src/Scene.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Scene.cpp.o: ../src/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/engine.dir/src/Scene.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Scene.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Scene.cpp

CMakeFiles/engine.dir/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Scene.cpp > CMakeFiles/engine.dir/src/Scene.cpp.i

CMakeFiles/engine.dir/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Scene.cpp -o CMakeFiles/engine.dir/src/Scene.cpp.s

CMakeFiles/engine.dir/src/Ground.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Ground.cpp.o: ../src/Ground.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/engine.dir/src/Ground.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Ground.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Ground.cpp

CMakeFiles/engine.dir/src/Ground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Ground.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Ground.cpp > CMakeFiles/engine.dir/src/Ground.cpp.i

CMakeFiles/engine.dir/src/Ground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Ground.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Ground.cpp -o CMakeFiles/engine.dir/src/Ground.cpp.s

CMakeFiles/engine.dir/src/Hill.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Hill.cpp.o: ../src/Hill.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/engine.dir/src/Hill.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Hill.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Hill.cpp

CMakeFiles/engine.dir/src/Hill.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Hill.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Hill.cpp > CMakeFiles/engine.dir/src/Hill.cpp.i

CMakeFiles/engine.dir/src/Hill.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Hill.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Hill.cpp -o CMakeFiles/engine.dir/src/Hill.cpp.s

CMakeFiles/engine.dir/src/Pyramid.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Pyramid.cpp.o: ../src/Pyramid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/engine.dir/src/Pyramid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Pyramid.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Pyramid.cpp

CMakeFiles/engine.dir/src/Pyramid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Pyramid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Pyramid.cpp > CMakeFiles/engine.dir/src/Pyramid.cpp.i

CMakeFiles/engine.dir/src/Pyramid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Pyramid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Pyramid.cpp -o CMakeFiles/engine.dir/src/Pyramid.cpp.s

CMakeFiles/engine.dir/src/Prism2.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Prism2.cpp.o: ../src/Prism2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nina/zad5_3-n-bartnik/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/engine.dir/src/Prism2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Prism2.cpp.o -c /home/nina/zad5_3-n-bartnik/src/Prism2.cpp

CMakeFiles/engine.dir/src/Prism2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Prism2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nina/zad5_3-n-bartnik/src/Prism2.cpp > CMakeFiles/engine.dir/src/Prism2.cpp.i

CMakeFiles/engine.dir/src/Prism2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Prism2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nina/zad5_3-n-bartnik/src/Prism2.cpp -o CMakeFiles/engine.dir/src/Prism2.cpp.s

engine: CMakeFiles/engine.dir/src/example.cpp.o
engine: CMakeFiles/engine.dir/src/Cuboid.cpp.o
engine: CMakeFiles/engine.dir/src/GeoSolid.cpp.o
engine: CMakeFiles/engine.dir/src/matrix.cpp.o
engine: CMakeFiles/engine.dir/src/Matrix3x3.cpp.o
engine: CMakeFiles/engine.dir/src/Prism.cpp.o
engine: CMakeFiles/engine.dir/src/Drone.cpp.o
engine: CMakeFiles/engine.dir/src/vector.cpp.o
engine: CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o
engine: CMakeFiles/engine.dir/src/Scene.cpp.o
engine: CMakeFiles/engine.dir/src/Ground.cpp.o
engine: CMakeFiles/engine.dir/src/Hill.cpp.o
engine: CMakeFiles/engine.dir/src/Pyramid.cpp.o
engine: CMakeFiles/engine.dir/src/Prism2.cpp.o
engine: CMakeFiles/engine.dir/build.make

.PHONY : engine

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine

.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/nina/zad5_3-n-bartnik/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nina/zad5_3-n-bartnik /home/nina/zad5_3-n-bartnik /home/nina/zad5_3-n-bartnik/build /home/nina/zad5_3-n-bartnik/build /home/nina/zad5_3-n-bartnik/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend

