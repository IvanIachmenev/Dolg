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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/CLionProjects/Dolg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/CLionProjects/Dolg/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rogue_like.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rogue_like.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rogue_like.dir/flags.make

CMakeFiles/rogue_like.dir/main.cpp.o: CMakeFiles/rogue_like.dir/flags.make
CMakeFiles/rogue_like.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rogue_like.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rogue_like.dir/main.cpp.o -c /home/ivan/CLionProjects/Dolg/main.cpp

CMakeFiles/rogue_like.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rogue_like.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/CLionProjects/Dolg/main.cpp > CMakeFiles/rogue_like.dir/main.cpp.i

CMakeFiles/rogue_like.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rogue_like.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/CLionProjects/Dolg/main.cpp -o CMakeFiles/rogue_like.dir/main.cpp.s

# Object files for target rogue_like
rogue_like_OBJECTS = \
"CMakeFiles/rogue_like.dir/main.cpp.o"

# External object files for target rogue_like
rogue_like_EXTERNAL_OBJECTS =

rogue_like: CMakeFiles/rogue_like.dir/main.cpp.o
rogue_like: CMakeFiles/rogue_like.dir/build.make
rogue_like: /usr/lib/x86_64-linux-gnu/libcurses.so
rogue_like: /usr/lib/x86_64-linux-gnu/libform.so
rogue_like: CMakeFiles/rogue_like.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rogue_like"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rogue_like.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rogue_like.dir/build: rogue_like

.PHONY : CMakeFiles/rogue_like.dir/build

CMakeFiles/rogue_like.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rogue_like.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rogue_like.dir/clean

CMakeFiles/rogue_like.dir/depend:
	cd /home/ivan/CLionProjects/Dolg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/CLionProjects/Dolg /home/ivan/CLionProjects/Dolg /home/ivan/CLionProjects/Dolg/cmake-build-debug /home/ivan/CLionProjects/Dolg/cmake-build-debug /home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles/rogue_like.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rogue_like.dir/depend

