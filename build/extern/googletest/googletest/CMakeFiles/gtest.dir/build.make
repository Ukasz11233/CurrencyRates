# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/ukasz/Clion/clion-2021.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ukasz/Clion/clion-2021.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ukasz/CLionProjects/CurrencyRates

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ukasz/CLionProjects/CurrencyRates/build

# Include any dependencies generated for this target.
include extern/googletest/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include extern/googletest/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include extern/googletest/googletest/CMakeFiles/gtest.dir/flags.make

extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: extern/googletest/googletest/CMakeFiles/gtest.dir/flags.make
extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../extern/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ukasz/CLionProjects/CurrencyRates/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/ukasz/CLionProjects/CurrencyRates/extern/googletest/googletest/src/gtest-all.cc

extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ukasz/CLionProjects/CurrencyRates/extern/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ukasz/CLionProjects/CurrencyRates/extern/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: extern/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: extern/googletest/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: extern/googletest/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ukasz/CLionProjects/CurrencyRates/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest.a"
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/googletest/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : extern/googletest/googletest/CMakeFiles/gtest.dir/build

extern/googletest/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : extern/googletest/googletest/CMakeFiles/gtest.dir/clean

extern/googletest/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/ukasz/CLionProjects/CurrencyRates/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ukasz/CLionProjects/CurrencyRates /home/ukasz/CLionProjects/CurrencyRates/extern/googletest/googletest /home/ukasz/CLionProjects/CurrencyRates/build /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest /home/ukasz/CLionProjects/CurrencyRates/build/extern/googletest/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/googletest/googletest/CMakeFiles/gtest.dir/depend

