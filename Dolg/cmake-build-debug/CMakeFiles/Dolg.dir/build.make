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
include CMakeFiles/Dolg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dolg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dolg.dir/flags.make

CMakeFiles/Dolg.dir/main.cpp.o: CMakeFiles/Dolg.dir/flags.make
CMakeFiles/Dolg.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dolg.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dolg.dir/main.cpp.o -c /home/ivan/CLionProjects/Dolg/main.cpp

CMakeFiles/Dolg.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dolg.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/CLionProjects/Dolg/main.cpp > CMakeFiles/Dolg.dir/main.cpp.i

CMakeFiles/Dolg.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dolg.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/CLionProjects/Dolg/main.cpp -o CMakeFiles/Dolg.dir/main.cpp.s

CMakeFiles/Dolg.dir/map.cpp.o: CMakeFiles/Dolg.dir/flags.make
CMakeFiles/Dolg.dir/map.cpp.o: ../map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dolg.dir/map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dolg.dir/map.cpp.o -c /home/ivan/CLionProjects/Dolg/map.cpp

CMakeFiles/Dolg.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dolg.dir/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/CLionProjects/Dolg/map.cpp > CMakeFiles/Dolg.dir/map.cpp.i

CMakeFiles/Dolg.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dolg.dir/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/CLionProjects/Dolg/map.cpp -o CMakeFiles/Dolg.dir/map.cpp.s

CMakeFiles/Dolg.dir/Player.cpp.o: CMakeFiles/Dolg.dir/flags.make
CMakeFiles/Dolg.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Dolg.dir/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dolg.dir/Player.cpp.o -c /home/ivan/CLionProjects/Dolg/Player.cpp

CMakeFiles/Dolg.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dolg.dir/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/CLionProjects/Dolg/Player.cpp > CMakeFiles/Dolg.dir/Player.cpp.i

CMakeFiles/Dolg.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dolg.dir/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/CLionProjects/Dolg/Player.cpp -o CMakeFiles/Dolg.dir/Player.cpp.s

CMakeFiles/Dolg.dir/Engine.cpp.o: CMakeFiles/Dolg.dir/flags.make
CMakeFiles/Dolg.dir/Engine.cpp.o: ../Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Dolg.dir/Engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dolg.dir/Engine.cpp.o -c /home/ivan/CLionProjects/Dolg/Engine.cpp

CMakeFiles/Dolg.dir/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dolg.dir/Engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/CLionProjects/Dolg/Engine.cpp > CMakeFiles/Dolg.dir/Engine.cpp.i

CMakeFiles/Dolg.dir/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dolg.dir/Engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/CLionProjects/Dolg/Engine.cpp -o CMakeFiles/Dolg.dir/Engine.cpp.s

# Object files for target Dolg
Dolg_OBJECTS = \
"CMakeFiles/Dolg.dir/main.cpp.o" \
"CMakeFiles/Dolg.dir/map.cpp.o" \
"CMakeFiles/Dolg.dir/Player.cpp.o" \
"CMakeFiles/Dolg.dir/Engine.cpp.o"

# External object files for target Dolg
Dolg_EXTERNAL_OBJECTS =

Dolg: CMakeFiles/Dolg.dir/main.cpp.o
Dolg: CMakeFiles/Dolg.dir/map.cpp.o
Dolg: CMakeFiles/Dolg.dir/Player.cpp.o
Dolg: CMakeFiles/Dolg.dir/Engine.cpp.o
Dolg: CMakeFiles/Dolg.dir/build.make
Dolg: /usr/lib/x86_64-linux-gnu/libcurses.so
Dolg: /usr/lib/x86_64-linux-gnu/libform.so
Dolg: CMakeFiles/Dolg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Dolg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dolg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dolg.dir/build: Dolg

.PHONY : CMakeFiles/Dolg.dir/build

CMakeFiles/Dolg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dolg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dolg.dir/clean

CMakeFiles/Dolg.dir/depend:
	cd /home/ivan/CLionProjects/Dolg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/CLionProjects/Dolg /home/ivan/CLionProjects/Dolg /home/ivan/CLionProjects/Dolg/cmake-build-debug /home/ivan/CLionProjects/Dolg/cmake-build-debug /home/ivan/CLionProjects/Dolg/cmake-build-debug/CMakeFiles/Dolg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dolg.dir/depend

