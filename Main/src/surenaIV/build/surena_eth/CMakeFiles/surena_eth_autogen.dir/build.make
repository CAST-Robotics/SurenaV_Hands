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

# Utility rule file for surena_eth_autogen.

# Include the progress variables for this target.
include surena_eth/CMakeFiles/surena_eth_autogen.dir/progress.make

surena_eth/CMakeFiles/surena_eth_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cast/surenaIV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target surena_eth"
	cd /home/cast/surenaIV/build/surena_eth && /usr/bin/cmake -E cmake_autogen /home/cast/surenaIV/build/surena_eth/CMakeFiles/surena_eth_autogen.dir/AutogenInfo.json ""

surena_eth_autogen: surena_eth/CMakeFiles/surena_eth_autogen
surena_eth_autogen: surena_eth/CMakeFiles/surena_eth_autogen.dir/build.make

.PHONY : surena_eth_autogen

# Rule to build all files generated by this target.
surena_eth/CMakeFiles/surena_eth_autogen.dir/build: surena_eth_autogen

.PHONY : surena_eth/CMakeFiles/surena_eth_autogen.dir/build

surena_eth/CMakeFiles/surena_eth_autogen.dir/clean:
	cd /home/cast/surenaIV/build/surena_eth && $(CMAKE_COMMAND) -P CMakeFiles/surena_eth_autogen.dir/cmake_clean.cmake
.PHONY : surena_eth/CMakeFiles/surena_eth_autogen.dir/clean

surena_eth/CMakeFiles/surena_eth_autogen.dir/depend:
	cd /home/cast/surenaIV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cast/surenaIV/src /home/cast/surenaIV/src/surena_eth /home/cast/surenaIV/build /home/cast/surenaIV/build/surena_eth /home/cast/surenaIV/build/surena_eth/CMakeFiles/surena_eth_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : surena_eth/CMakeFiles/surena_eth_autogen.dir/depend

