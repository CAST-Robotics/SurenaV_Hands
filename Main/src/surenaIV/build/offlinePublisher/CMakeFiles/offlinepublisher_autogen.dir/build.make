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

# Utility rule file for offlinepublisher_autogen.

# Include the progress variables for this target.
include offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/progress.make

offlinePublisher/CMakeFiles/offlinepublisher_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cast/surenaIV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target offlinepublisher"
	cd /home/cast/surenaIV/build/offlinePublisher && /usr/bin/cmake -E cmake_autogen /home/cast/surenaIV/build/offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/AutogenInfo.json ""

offlinepublisher_autogen: offlinePublisher/CMakeFiles/offlinepublisher_autogen
offlinepublisher_autogen: offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/build.make

.PHONY : offlinepublisher_autogen

# Rule to build all files generated by this target.
offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/build: offlinepublisher_autogen

.PHONY : offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/build

offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/clean:
	cd /home/cast/surenaIV/build/offlinePublisher && $(CMAKE_COMMAND) -P CMakeFiles/offlinepublisher_autogen.dir/cmake_clean.cmake
.PHONY : offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/clean

offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/depend:
	cd /home/cast/surenaIV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cast/surenaIV/src /home/cast/surenaIV/src/offlinePublisher /home/cast/surenaIV/build /home/cast/surenaIV/build/offlinePublisher /home/cast/surenaIV/build/offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : offlinePublisher/CMakeFiles/offlinepublisher_autogen.dir/depend

