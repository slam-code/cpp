# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/shen/ClionProjects/gtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shen/ClionProjects/gtest/build

# Include any dependencies generated for this target.
include CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest.dir/flags.make

CMakeFiles/gtest.dir/gtest-all.o: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/gtest-all.o: ../gtest-all.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest.dir/gtest-all.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/gtest-all.o -c /home/shen/ClionProjects/gtest/gtest-all.cpp

CMakeFiles/gtest.dir/gtest-all.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/gtest-all.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/gtest-all.cpp > CMakeFiles/gtest.dir/gtest-all.i

CMakeFiles/gtest.dir/gtest-all.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/gtest-all.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/gtest-all.cpp -o CMakeFiles/gtest.dir/gtest-all.s

CMakeFiles/gtest.dir/gtest-all.o.requires:

.PHONY : CMakeFiles/gtest.dir/gtest-all.o.requires

CMakeFiles/gtest.dir/gtest-all.o.provides: CMakeFiles/gtest.dir/gtest-all.o.requires
	$(MAKE) -f CMakeFiles/gtest.dir/build.make CMakeFiles/gtest.dir/gtest-all.o.provides.build
.PHONY : CMakeFiles/gtest.dir/gtest-all.o.provides

CMakeFiles/gtest.dir/gtest-all.o.provides.build: CMakeFiles/gtest.dir/gtest-all.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/gtest-all.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

libgtest.a: CMakeFiles/gtest.dir/gtest-all.o
libgtest.a: CMakeFiles/gtest.dir/build.make
libgtest.a: CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shen/ClionProjects/gtest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest.dir/build: libgtest.a

.PHONY : CMakeFiles/gtest.dir/build

CMakeFiles/gtest.dir/requires: CMakeFiles/gtest.dir/gtest-all.o.requires

.PHONY : CMakeFiles/gtest.dir/requires

CMakeFiles/gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest.dir/clean

CMakeFiles/gtest.dir/depend:
	cd /home/shen/ClionProjects/gtest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shen/ClionProjects/gtest /home/shen/ClionProjects/gtest /home/shen/ClionProjects/gtest/build /home/shen/ClionProjects/gtest/build /home/shen/ClionProjects/gtest/build/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest.dir/depend

