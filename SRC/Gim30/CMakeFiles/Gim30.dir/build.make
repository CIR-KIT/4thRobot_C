# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC

# Include any dependencies generated for this target.
include Gim30/CMakeFiles/Gim30.dir/depend.make

# Include the progress variables for this target.
include Gim30/CMakeFiles/Gim30.dir/progress.make

# Include the compile flags for this target's objects.
include Gim30/CMakeFiles/Gim30.dir/flags.make

Gim30/CMakeFiles/Gim30.dir/gim30.c.o: Gim30/CMakeFiles/Gim30.dir/flags.make
Gim30/CMakeFiles/Gim30.dir/gim30.c.o: Gim30/gim30.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object Gim30/CMakeFiles/Gim30.dir/gim30.c.o"
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Gim30.dir/gim30.c.o   -c /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30/gim30.c

Gim30/CMakeFiles/Gim30.dir/gim30.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Gim30.dir/gim30.c.i"
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30/gim30.c > CMakeFiles/Gim30.dir/gim30.c.i

Gim30/CMakeFiles/Gim30.dir/gim30.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Gim30.dir/gim30.c.s"
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30/gim30.c -o CMakeFiles/Gim30.dir/gim30.c.s

Gim30/CMakeFiles/Gim30.dir/gim30.c.o.requires:
.PHONY : Gim30/CMakeFiles/Gim30.dir/gim30.c.o.requires

Gim30/CMakeFiles/Gim30.dir/gim30.c.o.provides: Gim30/CMakeFiles/Gim30.dir/gim30.c.o.requires
	$(MAKE) -f Gim30/CMakeFiles/Gim30.dir/build.make Gim30/CMakeFiles/Gim30.dir/gim30.c.o.provides.build
.PHONY : Gim30/CMakeFiles/Gim30.dir/gim30.c.o.provides

Gim30/CMakeFiles/Gim30.dir/gim30.c.o.provides.build: Gim30/CMakeFiles/Gim30.dir/gim30.c.o

# Object files for target Gim30
Gim30_OBJECTS = \
"CMakeFiles/Gim30.dir/gim30.c.o"

# External object files for target Gim30
Gim30_EXTERNAL_OBJECTS =

Gim30/libGim30.a: Gim30/CMakeFiles/Gim30.dir/gim30.c.o
Gim30/libGim30.a: Gim30/CMakeFiles/Gim30.dir/build.make
Gim30/libGim30.a: Gim30/CMakeFiles/Gim30.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libGim30.a"
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && $(CMAKE_COMMAND) -P CMakeFiles/Gim30.dir/cmake_clean_target.cmake
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gim30.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Gim30/CMakeFiles/Gim30.dir/build: Gim30/libGim30.a
.PHONY : Gim30/CMakeFiles/Gim30.dir/build

Gim30/CMakeFiles/Gim30.dir/requires: Gim30/CMakeFiles/Gim30.dir/gim30.c.o.requires
.PHONY : Gim30/CMakeFiles/Gim30.dir/requires

Gim30/CMakeFiles/Gim30.dir/clean:
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 && $(CMAKE_COMMAND) -P CMakeFiles/Gim30.dir/cmake_clean.cmake
.PHONY : Gim30/CMakeFiles/Gim30.dir/clean

Gim30/CMakeFiles/Gim30.dir/depend:
	cd /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30 /home/cir-kit/Documents/CIR-KIT/Robot/2014/4thRobot/SRC/Gim30/CMakeFiles/Gim30.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Gim30/CMakeFiles/Gim30.dir/depend
