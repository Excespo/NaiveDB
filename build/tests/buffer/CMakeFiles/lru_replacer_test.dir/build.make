# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yijie/AI3613-Project-2022-Spring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yijie/AI3613-Project-2022-Spring/build

# Include any dependencies generated for this target.
include tests/buffer/CMakeFiles/lru_replacer_test.dir/depend.make

# Include the progress variables for this target.
include tests/buffer/CMakeFiles/lru_replacer_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/buffer/CMakeFiles/lru_replacer_test.dir/flags.make

tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o: tests/buffer/CMakeFiles/lru_replacer_test.dir/flags.make
tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o: ../tests/buffer/lru_replacer_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yijie/AI3613-Project-2022-Spring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o"
	cd /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o -c /home/yijie/AI3613-Project-2022-Spring/tests/buffer/lru_replacer_test.cc

tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.i"
	cd /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yijie/AI3613-Project-2022-Spring/tests/buffer/lru_replacer_test.cc > CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.i

tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.s"
	cd /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yijie/AI3613-Project-2022-Spring/tests/buffer/lru_replacer_test.cc -o CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.s

# Object files for target lru_replacer_test
lru_replacer_test_OBJECTS = \
"CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o"

# External object files for target lru_replacer_test
lru_replacer_test_EXTERNAL_OBJECTS =

tests/buffer/lru_replacer_test: tests/buffer/CMakeFiles/lru_replacer_test.dir/lru_replacer_test.cc.o
tests/buffer/lru_replacer_test: tests/buffer/CMakeFiles/lru_replacer_test.dir/build.make
tests/buffer/lru_replacer_test: libnaivedb.a
tests/buffer/lru_replacer_test: /usr/lib/x86_64-linux-gnu/libfmt.so.7.1.3
tests/buffer/lru_replacer_test: tests/buffer/CMakeFiles/lru_replacer_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yijie/AI3613-Project-2022-Spring/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lru_replacer_test"
	cd /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lru_replacer_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/buffer/CMakeFiles/lru_replacer_test.dir/build: tests/buffer/lru_replacer_test

.PHONY : tests/buffer/CMakeFiles/lru_replacer_test.dir/build

tests/buffer/CMakeFiles/lru_replacer_test.dir/clean:
	cd /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer && $(CMAKE_COMMAND) -P CMakeFiles/lru_replacer_test.dir/cmake_clean.cmake
.PHONY : tests/buffer/CMakeFiles/lru_replacer_test.dir/clean

tests/buffer/CMakeFiles/lru_replacer_test.dir/depend:
	cd /home/yijie/AI3613-Project-2022-Spring/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yijie/AI3613-Project-2022-Spring /home/yijie/AI3613-Project-2022-Spring/tests/buffer /home/yijie/AI3613-Project-2022-Spring/build /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer /home/yijie/AI3613-Project-2022-Spring/build/tests/buffer/CMakeFiles/lru_replacer_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/buffer/CMakeFiles/lru_replacer_test.dir/depend

