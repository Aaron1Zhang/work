# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zh/proj/work_proj_github/work/socket_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zh/proj/work_proj_github/work/socket_proj/build

# Include any dependencies generated for this target.
include CMakeFiles/echo_client_udp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/echo_client_udp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/echo_client_udp.dir/flags.make

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o: CMakeFiles/echo_client_udp.dir/flags.make
CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o: ../echo_client_udp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/work_proj_github/work/socket_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o   -c /home/zh/proj/work_proj_github/work/socket_proj/echo_client_udp.c

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/echo_client_udp.dir/echo_client_udp.c.i"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zh/proj/work_proj_github/work/socket_proj/echo_client_udp.c > CMakeFiles/echo_client_udp.dir/echo_client_udp.c.i

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/echo_client_udp.dir/echo_client_udp.c.s"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zh/proj/work_proj_github/work/socket_proj/echo_client_udp.c -o CMakeFiles/echo_client_udp.dir/echo_client_udp.c.s

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.requires:

.PHONY : CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.requires

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.provides: CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.requires
	$(MAKE) -f CMakeFiles/echo_client_udp.dir/build.make CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.provides.build
.PHONY : CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.provides

CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.provides.build: CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o


# Object files for target echo_client_udp
echo_client_udp_OBJECTS = \
"CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o"

# External object files for target echo_client_udp
echo_client_udp_EXTERNAL_OBJECTS =

../bin/echo_client_udp: CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o
../bin/echo_client_udp: CMakeFiles/echo_client_udp.dir/build.make
../bin/echo_client_udp: CMakeFiles/echo_client_udp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zh/proj/work_proj_github/work/socket_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/echo_client_udp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echo_client_udp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/echo_client_udp.dir/build: ../bin/echo_client_udp

.PHONY : CMakeFiles/echo_client_udp.dir/build

CMakeFiles/echo_client_udp.dir/requires: CMakeFiles/echo_client_udp.dir/echo_client_udp.c.o.requires

.PHONY : CMakeFiles/echo_client_udp.dir/requires

CMakeFiles/echo_client_udp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/echo_client_udp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/echo_client_udp.dir/clean

CMakeFiles/echo_client_udp.dir/depend:
	cd /home/zh/proj/work_proj_github/work/socket_proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zh/proj/work_proj_github/work/socket_proj /home/zh/proj/work_proj_github/work/socket_proj /home/zh/proj/work_proj_github/work/socket_proj/build /home/zh/proj/work_proj_github/work/socket_proj/build /home/zh/proj/work_proj_github/work/socket_proj/build/CMakeFiles/echo_client_udp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/echo_client_udp.dir/depend

