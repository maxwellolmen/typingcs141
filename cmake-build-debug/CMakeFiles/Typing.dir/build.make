# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maxwell/CLionProjects/Typing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maxwell/CLionProjects/Typing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Typing.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Typing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Typing.dir/flags.make

CMakeFiles/Typing.dir/main.cpp.o: CMakeFiles/Typing.dir/flags.make
CMakeFiles/Typing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxwell/CLionProjects/Typing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Typing.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Typing.dir/main.cpp.o -c /Users/maxwell/CLionProjects/Typing/main.cpp

CMakeFiles/Typing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Typing.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maxwell/CLionProjects/Typing/main.cpp > CMakeFiles/Typing.dir/main.cpp.i

CMakeFiles/Typing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Typing.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maxwell/CLionProjects/Typing/main.cpp -o CMakeFiles/Typing.dir/main.cpp.s

# Object files for target Typing
Typing_OBJECTS = \
"CMakeFiles/Typing.dir/main.cpp.o"

# External object files for target Typing
Typing_EXTERNAL_OBJECTS =

Typing: CMakeFiles/Typing.dir/main.cpp.o
Typing: CMakeFiles/Typing.dir/build.make
Typing: CMakeFiles/Typing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maxwell/CLionProjects/Typing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Typing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Typing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Typing.dir/build: Typing
.PHONY : CMakeFiles/Typing.dir/build

CMakeFiles/Typing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Typing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Typing.dir/clean

CMakeFiles/Typing.dir/depend:
	cd /Users/maxwell/CLionProjects/Typing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maxwell/CLionProjects/Typing /Users/maxwell/CLionProjects/Typing /Users/maxwell/CLionProjects/Typing/cmake-build-debug /Users/maxwell/CLionProjects/Typing/cmake-build-debug /Users/maxwell/CLionProjects/Typing/cmake-build-debug/CMakeFiles/Typing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Typing.dir/depend
