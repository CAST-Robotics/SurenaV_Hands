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
CMAKE_SOURCE_DIR = /home/cast/surenaIV/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cast/surenaIV/build

# Utility rule file for surena_eth_gennodejs.

# Include the progress variables for this target.
include surena_eth/CMakeFiles/surena_eth_gennodejs.dir/progress.make

surena_eth_gennodejs: surena_eth/CMakeFiles/surena_eth_gennodejs.dir/build.make

.PHONY : surena_eth_gennodejs

# Rule to build all files generated by this target.
surena_eth/CMakeFiles/surena_eth_gennodejs.dir/build: surena_eth_gennodejs

.PHONY : surena_eth/CMakeFiles/surena_eth_gennodejs.dir/build

surena_eth/CMakeFiles/surena_eth_gennodejs.dir/clean:
	cd /home/cast/surenaIV/build/surena_eth && $(CMAKE_COMMAND) -P CMakeFiles/surena_eth_gennodejs.dir/cmake_clean.cmake
.PHONY : surena_eth/CMakeFiles/surena_eth_gennodejs.dir/clean

surena_eth/CMakeFiles/surena_eth_gennodejs.dir/depend:
	cd /home/cast/surenaIV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cast/surenaIV/src /home/cast/surenaIV/src/surena_eth /home/cast/surenaIV/build /home/cast/surenaIV/build/surena_eth /home/cast/surenaIV/build/surena_eth/CMakeFiles/surena_eth_gennodejs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : surena_eth/CMakeFiles/surena_eth_gennodejs.dir/depend

