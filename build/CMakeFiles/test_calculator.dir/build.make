# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cheyenne/Documents/GitHub/OSPSD-HW1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cheyenne/Documents/GitHub/OSPSD-HW1/build

# Include any dependencies generated for this target.
include CMakeFiles/test_calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_calculator.dir/flags.make

CMakeFiles/test_calculator.dir/codegen:
.PHONY : CMakeFiles/test_calculator.dir/codegen

CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o: /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/test_calculator.cpp
CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o: CMakeFiles/test_calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cheyenne/Documents/GitHub/OSPSD-HW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o -MF CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o.d -o CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o -c /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/test_calculator.cpp

CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/test_calculator.cpp > CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.i

CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/test_calculator.cpp -o CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.s

CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o: CMakeFiles/test_calculator.dir/flags.make
CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o: /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/calculator.cpp
CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o: CMakeFiles/test_calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/cheyenne/Documents/GitHub/OSPSD-HW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o -MF CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o.d -o CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o -c /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/calculator.cpp

CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/calculator.cpp > CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.i

CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cheyenne/Documents/GitHub/OSPSD-HW1/src/calculator/calculator.cpp -o CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.s

# Object files for target test_calculator
test_calculator_OBJECTS = \
"CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o" \
"CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o"

# External object files for target test_calculator
test_calculator_EXTERNAL_OBJECTS =

test_calculator: CMakeFiles/test_calculator.dir/src/calculator/test_calculator.cpp.o
test_calculator: CMakeFiles/test_calculator.dir/src/calculator/calculator.cpp.o
test_calculator: CMakeFiles/test_calculator.dir/build.make
test_calculator: /Users/cheyenne/Documents/GitHub/OSPSD-HW1/vcpkg/installed/x64-osx/debug/lib/manual-link/libgtest_main.a
test_calculator: /Users/cheyenne/Documents/GitHub/OSPSD-HW1/vcpkg/installed/x64-osx/debug/lib/libgtest.a
test_calculator: CMakeFiles/test_calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/cheyenne/Documents/GitHub/OSPSD-HW1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_calculator.dir/build: test_calculator
.PHONY : CMakeFiles/test_calculator.dir/build

CMakeFiles/test_calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_calculator.dir/clean

CMakeFiles/test_calculator.dir/depend:
	cd /Users/cheyenne/Documents/GitHub/OSPSD-HW1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cheyenne/Documents/GitHub/OSPSD-HW1 /Users/cheyenne/Documents/GitHub/OSPSD-HW1 /Users/cheyenne/Documents/GitHub/OSPSD-HW1/build /Users/cheyenne/Documents/GitHub/OSPSD-HW1/build /Users/cheyenne/Documents/GitHub/OSPSD-HW1/build/CMakeFiles/test_calculator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_calculator.dir/depend

