# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\git\CocktailAmpel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\git\CocktailAmpel\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CocktailAmpel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CocktailAmpel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CocktailAmpel.dir/flags.make

CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj: CMakeFiles/CocktailAmpel.dir/flags.make
CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj: CMakeFiles/CocktailAmpel.dir/includes_CXX.rsp
CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\git\CocktailAmpel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj"
	C:\Users\Johannes\.platformio\packages\toolchain-xtensa\bin\xtensa-lx106-elf-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CocktailAmpel.dir\src\main.cpp.obj -c E:\git\CocktailAmpel\src\main.cpp

CMakeFiles/CocktailAmpel.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CocktailAmpel.dir/src/main.cpp.i"
	C:\Users\Johannes\.platformio\packages\toolchain-xtensa\bin\xtensa-lx106-elf-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\git\CocktailAmpel\src\main.cpp > CMakeFiles\CocktailAmpel.dir\src\main.cpp.i

CMakeFiles/CocktailAmpel.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CocktailAmpel.dir/src/main.cpp.s"
	C:\Users\Johannes\.platformio\packages\toolchain-xtensa\bin\xtensa-lx106-elf-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\git\CocktailAmpel\src\main.cpp -o CMakeFiles\CocktailAmpel.dir\src\main.cpp.s

CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.requires

CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.provides: CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\CocktailAmpel.dir\build.make CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.provides

CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.provides.build: CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj


# Object files for target CocktailAmpel
CocktailAmpel_OBJECTS = \
"CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj"

# External object files for target CocktailAmpel
CocktailAmpel_EXTERNAL_OBJECTS =

CocktailAmpel.exe: CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj
CocktailAmpel.exe: CMakeFiles/CocktailAmpel.dir/build.make
CocktailAmpel.exe: CMakeFiles/CocktailAmpel.dir/linklibs.rsp
CocktailAmpel.exe: CMakeFiles/CocktailAmpel.dir/objects1.rsp
CocktailAmpel.exe: CMakeFiles/CocktailAmpel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\git\CocktailAmpel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CocktailAmpel.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CocktailAmpel.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CocktailAmpel.dir/build: CocktailAmpel.exe

.PHONY : CMakeFiles/CocktailAmpel.dir/build

CMakeFiles/CocktailAmpel.dir/requires: CMakeFiles/CocktailAmpel.dir/src/main.cpp.obj.requires

.PHONY : CMakeFiles/CocktailAmpel.dir/requires

CMakeFiles/CocktailAmpel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CocktailAmpel.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CocktailAmpel.dir/clean

CMakeFiles/CocktailAmpel.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\git\CocktailAmpel E:\git\CocktailAmpel E:\git\CocktailAmpel\cmake-build-debug E:\git\CocktailAmpel\cmake-build-debug E:\git\CocktailAmpel\cmake-build-debug\CMakeFiles\CocktailAmpel.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CocktailAmpel.dir/depend

