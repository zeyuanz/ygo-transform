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
CMAKE_SOURCE_DIR = /mnt/d/Mywork/ygoDeckTransform

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Mywork/ygoDeckTransform/build

# Include any dependencies generated for this target.
include CMakeFiles/ygodeck.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ygodeck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ygodeck.dir/flags.make

CMakeFiles/ygodeck.dir/src/deck.cpp.o: CMakeFiles/ygodeck.dir/flags.make
CMakeFiles/ygodeck.dir/src/deck.cpp.o: ../src/deck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mywork/ygoDeckTransform/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ygodeck.dir/src/deck.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ygodeck.dir/src/deck.cpp.o -c /mnt/d/Mywork/ygoDeckTransform/src/deck.cpp

CMakeFiles/ygodeck.dir/src/deck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ygodeck.dir/src/deck.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mywork/ygoDeckTransform/src/deck.cpp > CMakeFiles/ygodeck.dir/src/deck.cpp.i

CMakeFiles/ygodeck.dir/src/deck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ygodeck.dir/src/deck.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mywork/ygoDeckTransform/src/deck.cpp -o CMakeFiles/ygodeck.dir/src/deck.cpp.s

CMakeFiles/ygodeck.dir/src/main.cpp.o: CMakeFiles/ygodeck.dir/flags.make
CMakeFiles/ygodeck.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Mywork/ygoDeckTransform/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ygodeck.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ygodeck.dir/src/main.cpp.o -c /mnt/d/Mywork/ygoDeckTransform/src/main.cpp

CMakeFiles/ygodeck.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ygodeck.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Mywork/ygoDeckTransform/src/main.cpp > CMakeFiles/ygodeck.dir/src/main.cpp.i

CMakeFiles/ygodeck.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ygodeck.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Mywork/ygoDeckTransform/src/main.cpp -o CMakeFiles/ygodeck.dir/src/main.cpp.s

# Object files for target ygodeck
ygodeck_OBJECTS = \
"CMakeFiles/ygodeck.dir/src/deck.cpp.o" \
"CMakeFiles/ygodeck.dir/src/main.cpp.o"

# External object files for target ygodeck
ygodeck_EXTERNAL_OBJECTS =

../bin/ygodeck: CMakeFiles/ygodeck.dir/src/deck.cpp.o
../bin/ygodeck: CMakeFiles/ygodeck.dir/src/main.cpp.o
../bin/ygodeck: CMakeFiles/ygodeck.dir/build.make
../bin/ygodeck: CMakeFiles/ygodeck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Mywork/ygoDeckTransform/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/ygodeck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ygodeck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ygodeck.dir/build: ../bin/ygodeck

.PHONY : CMakeFiles/ygodeck.dir/build

CMakeFiles/ygodeck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ygodeck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ygodeck.dir/clean

CMakeFiles/ygodeck.dir/depend:
	cd /mnt/d/Mywork/ygoDeckTransform/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Mywork/ygoDeckTransform /mnt/d/Mywork/ygoDeckTransform /mnt/d/Mywork/ygoDeckTransform/build /mnt/d/Mywork/ygoDeckTransform/build /mnt/d/Mywork/ygoDeckTransform/build/CMakeFiles/ygodeck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ygodeck.dir/depend

