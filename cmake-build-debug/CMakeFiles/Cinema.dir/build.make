# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mahdi\CLionProjects\Cinema

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cinema.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cinema.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cinema.dir/flags.make

CMakeFiles/Cinema.dir/main1.c.obj: CMakeFiles/Cinema.dir/flags.make
CMakeFiles/Cinema.dir/main1.c.obj: ../main1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Cinema.dir/main1.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Cinema.dir\main1.c.obj   -c C:\Users\mahdi\CLionProjects\Cinema\main1.c

CMakeFiles/Cinema.dir/main1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Cinema.dir/main1.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\mahdi\CLionProjects\Cinema\main1.c > CMakeFiles\Cinema.dir\main1.c.i

CMakeFiles/Cinema.dir/main1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Cinema.dir/main1.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\mahdi\CLionProjects\Cinema\main1.c -o CMakeFiles\Cinema.dir\main1.c.s

# Object files for target Cinema
Cinema_OBJECTS = \
"CMakeFiles/Cinema.dir/main1.c.obj"

# External object files for target Cinema
Cinema_EXTERNAL_OBJECTS =

Cinema.exe: CMakeFiles/Cinema.dir/main1.c.obj
Cinema.exe: CMakeFiles/Cinema.dir/build.make
Cinema.exe: CMakeFiles/Cinema.dir/linklibs.rsp
Cinema.exe: CMakeFiles/Cinema.dir/objects1.rsp
Cinema.exe: CMakeFiles/Cinema.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Cinema.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Cinema.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cinema.dir/build: Cinema.exe

.PHONY : CMakeFiles/Cinema.dir/build

CMakeFiles/Cinema.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Cinema.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Cinema.dir/clean

CMakeFiles/Cinema.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mahdi\CLionProjects\Cinema C:\Users\mahdi\CLionProjects\Cinema C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug C:\Users\mahdi\CLionProjects\Cinema\cmake-build-debug\CMakeFiles\Cinema.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cinema.dir/depend
