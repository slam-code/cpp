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
CMAKE_SOURCE_DIR = /home/shen/ClionProjects/gtest/samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shen/ClionProjects/gtest/samples/build

# Include any dependencies generated for this target.
include CMakeFiles/test_sample1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_sample1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_sample1.dir/flags.make

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o: CMakeFiles/test_sample1.dir/flags.make
CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o: /home/shen/ClionProjects/gtest/gtest-all.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o -c /home/shen/ClionProjects/gtest/gtest-all.cpp

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/gtest-all.cpp > CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.i

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/gtest-all.cpp -o CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.s

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.requires:

.PHONY : CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.requires

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.provides: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_sample1.dir/build.make CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.provides.build
.PHONY : CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.provides

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.provides.build: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o


CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o: CMakeFiles/test_sample1.dir/flags.make
CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o: /home/shen/ClionProjects/gtest/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o -c /home/shen/ClionProjects/gtest/gtest_main.cc

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/gtest_main.cc > CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.i

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/gtest_main.cc -o CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.s

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.requires:

.PHONY : CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.requires

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.provides: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.requires
	$(MAKE) -f CMakeFiles/test_sample1.dir/build.make CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.provides.build
.PHONY : CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.provides

CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.provides.build: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o


CMakeFiles/test_sample1.dir/sample1.cpp.o: CMakeFiles/test_sample1.dir/flags.make
CMakeFiles/test_sample1.dir/sample1.cpp.o: ../sample1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_sample1.dir/sample1.cpp.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_sample1.dir/sample1.cpp.o -c /home/shen/ClionProjects/gtest/samples/sample1.cpp

CMakeFiles/test_sample1.dir/sample1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sample1.dir/sample1.cpp.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/samples/sample1.cpp > CMakeFiles/test_sample1.dir/sample1.cpp.i

CMakeFiles/test_sample1.dir/sample1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sample1.dir/sample1.cpp.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/samples/sample1.cpp -o CMakeFiles/test_sample1.dir/sample1.cpp.s

CMakeFiles/test_sample1.dir/sample1.cpp.o.requires:

.PHONY : CMakeFiles/test_sample1.dir/sample1.cpp.o.requires

CMakeFiles/test_sample1.dir/sample1.cpp.o.provides: CMakeFiles/test_sample1.dir/sample1.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_sample1.dir/build.make CMakeFiles/test_sample1.dir/sample1.cpp.o.provides.build
.PHONY : CMakeFiles/test_sample1.dir/sample1.cpp.o.provides

CMakeFiles/test_sample1.dir/sample1.cpp.o.provides.build: CMakeFiles/test_sample1.dir/sample1.cpp.o


CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o: CMakeFiles/test_sample1.dir/flags.make
CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o: ../sample1_unittest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o -c /home/shen/ClionProjects/gtest/samples/sample1_unittest.cpp

CMakeFiles/test_sample1.dir/sample1_unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sample1.dir/sample1_unittest.cpp.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/samples/sample1_unittest.cpp > CMakeFiles/test_sample1.dir/sample1_unittest.cpp.i

CMakeFiles/test_sample1.dir/sample1_unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sample1.dir/sample1_unittest.cpp.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/samples/sample1_unittest.cpp -o CMakeFiles/test_sample1.dir/sample1_unittest.cpp.s

CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.requires:

.PHONY : CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.requires

CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.provides: CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_sample1.dir/build.make CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.provides.build
.PHONY : CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.provides

CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.provides.build: CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o


CMakeFiles/test_sample1.dir/sdy_sample.cpp.o: CMakeFiles/test_sample1.dir/flags.make
CMakeFiles/test_sample1.dir/sdy_sample.cpp.o: ../sdy_sample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test_sample1.dir/sdy_sample.cpp.o"
	/home/shen/anaconda2/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_sample1.dir/sdy_sample.cpp.o -c /home/shen/ClionProjects/gtest/samples/sdy_sample.cpp

CMakeFiles/test_sample1.dir/sdy_sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_sample1.dir/sdy_sample.cpp.i"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shen/ClionProjects/gtest/samples/sdy_sample.cpp > CMakeFiles/test_sample1.dir/sdy_sample.cpp.i

CMakeFiles/test_sample1.dir/sdy_sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_sample1.dir/sdy_sample.cpp.s"
	/home/shen/anaconda2/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shen/ClionProjects/gtest/samples/sdy_sample.cpp -o CMakeFiles/test_sample1.dir/sdy_sample.cpp.s

CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.requires:

.PHONY : CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.requires

CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.provides: CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_sample1.dir/build.make CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.provides.build
.PHONY : CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.provides

CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.provides.build: CMakeFiles/test_sample1.dir/sdy_sample.cpp.o


# Object files for target test_sample1
test_sample1_OBJECTS = \
"CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o" \
"CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o" \
"CMakeFiles/test_sample1.dir/sample1.cpp.o" \
"CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o" \
"CMakeFiles/test_sample1.dir/sdy_sample.cpp.o"

# External object files for target test_sample1
test_sample1_EXTERNAL_OBJECTS =

test_sample1: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o
test_sample1: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o
test_sample1: CMakeFiles/test_sample1.dir/sample1.cpp.o
test_sample1: CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o
test_sample1: CMakeFiles/test_sample1.dir/sdy_sample.cpp.o
test_sample1: CMakeFiles/test_sample1.dir/build.make
test_sample1: CMakeFiles/test_sample1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shen/ClionProjects/gtest/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable test_sample1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sample1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_sample1.dir/build: test_sample1

.PHONY : CMakeFiles/test_sample1.dir/build

CMakeFiles/test_sample1.dir/requires: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest-all.cpp.o.requires
CMakeFiles/test_sample1.dir/requires: CMakeFiles/test_sample1.dir/home/shen/ClionProjects/gtest/gtest_main.cc.o.requires
CMakeFiles/test_sample1.dir/requires: CMakeFiles/test_sample1.dir/sample1.cpp.o.requires
CMakeFiles/test_sample1.dir/requires: CMakeFiles/test_sample1.dir/sample1_unittest.cpp.o.requires
CMakeFiles/test_sample1.dir/requires: CMakeFiles/test_sample1.dir/sdy_sample.cpp.o.requires

.PHONY : CMakeFiles/test_sample1.dir/requires

CMakeFiles/test_sample1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_sample1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_sample1.dir/clean

CMakeFiles/test_sample1.dir/depend:
	cd /home/shen/ClionProjects/gtest/samples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shen/ClionProjects/gtest/samples /home/shen/ClionProjects/gtest/samples /home/shen/ClionProjects/gtest/samples/build /home/shen/ClionProjects/gtest/samples/build /home/shen/ClionProjects/gtest/samples/build/CMakeFiles/test_sample1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_sample1.dir/depend

