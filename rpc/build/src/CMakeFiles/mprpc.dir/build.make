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
CMAKE_SOURCE_DIR = /home/zh/proj/work_proj_github/work/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zh/proj/work_proj_github/work/rpc/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mprpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mprpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mprpc.dir/flags.make

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o: ../src/mprpcapplication.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/work_proj_github/work/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/mprpcapplication.cc.o -c /home/zh/proj/work_proj_github/work/rpc/src/mprpcapplication.cc

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpcapplication.cc.i"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/work_proj_github/work/rpc/src/mprpcapplication.cc > CMakeFiles/mprpc.dir/mprpcapplication.cc.i

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpcapplication.cc.s"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/work_proj_github/work/rpc/src/mprpcapplication.cc -o CMakeFiles/mprpc.dir/mprpcapplication.cc.s

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.requires:

.PHONY : src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.requires

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.provides: src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.requires
	$(MAKE) -f src/CMakeFiles/mprpc.dir/build.make src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.provides.build
.PHONY : src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.provides

src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.provides.build: src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o


src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o: ../src/mprpcconfig.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/work_proj_github/work/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/mprpcconfig.cc.o -c /home/zh/proj/work_proj_github/work/rpc/src/mprpcconfig.cc

src/CMakeFiles/mprpc.dir/mprpcconfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/mprpcconfig.cc.i"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/work_proj_github/work/rpc/src/mprpcconfig.cc > CMakeFiles/mprpc.dir/mprpcconfig.cc.i

src/CMakeFiles/mprpc.dir/mprpcconfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/mprpcconfig.cc.s"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/work_proj_github/work/rpc/src/mprpcconfig.cc -o CMakeFiles/mprpc.dir/mprpcconfig.cc.s

src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.requires:

.PHONY : src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.requires

src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.provides: src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.requires
	$(MAKE) -f src/CMakeFiles/mprpc.dir/build.make src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.provides.build
.PHONY : src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.provides

src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.provides.build: src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o


src/CMakeFiles/mprpc.dir/rpcprovider.cc.o: src/CMakeFiles/mprpc.dir/flags.make
src/CMakeFiles/mprpc.dir/rpcprovider.cc.o: ../src/rpcprovider.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/work_proj_github/work/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mprpc.dir/rpcprovider.cc.o"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mprpc.dir/rpcprovider.cc.o -c /home/zh/proj/work_proj_github/work/rpc/src/rpcprovider.cc

src/CMakeFiles/mprpc.dir/rpcprovider.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mprpc.dir/rpcprovider.cc.i"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/work_proj_github/work/rpc/src/rpcprovider.cc > CMakeFiles/mprpc.dir/rpcprovider.cc.i

src/CMakeFiles/mprpc.dir/rpcprovider.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mprpc.dir/rpcprovider.cc.s"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/work_proj_github/work/rpc/src/rpcprovider.cc -o CMakeFiles/mprpc.dir/rpcprovider.cc.s

src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.requires:

.PHONY : src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.requires

src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.provides: src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.requires
	$(MAKE) -f src/CMakeFiles/mprpc.dir/build.make src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.provides.build
.PHONY : src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.provides

src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.provides.build: src/CMakeFiles/mprpc.dir/rpcprovider.cc.o


# Object files for target mprpc
mprpc_OBJECTS = \
"CMakeFiles/mprpc.dir/mprpcapplication.cc.o" \
"CMakeFiles/mprpc.dir/mprpcconfig.cc.o" \
"CMakeFiles/mprpc.dir/rpcprovider.cc.o"

# External object files for target mprpc
mprpc_EXTERNAL_OBJECTS =

../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/rpcprovider.cc.o
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/build.make
../lib/libmprpc.a: src/CMakeFiles/mprpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zh/proj/work_proj_github/work/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libmprpc.a"
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean_target.cmake
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mprpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mprpc.dir/build: ../lib/libmprpc.a

.PHONY : src/CMakeFiles/mprpc.dir/build

src/CMakeFiles/mprpc.dir/requires: src/CMakeFiles/mprpc.dir/mprpcapplication.cc.o.requires
src/CMakeFiles/mprpc.dir/requires: src/CMakeFiles/mprpc.dir/mprpcconfig.cc.o.requires
src/CMakeFiles/mprpc.dir/requires: src/CMakeFiles/mprpc.dir/rpcprovider.cc.o.requires

.PHONY : src/CMakeFiles/mprpc.dir/requires

src/CMakeFiles/mprpc.dir/clean:
	cd /home/zh/proj/work_proj_github/work/rpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mprpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mprpc.dir/clean

src/CMakeFiles/mprpc.dir/depend:
	cd /home/zh/proj/work_proj_github/work/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zh/proj/work_proj_github/work/rpc /home/zh/proj/work_proj_github/work/rpc/src /home/zh/proj/work_proj_github/work/rpc/build /home/zh/proj/work_proj_github/work/rpc/build/src /home/zh/proj/work_proj_github/work/rpc/build/src/CMakeFiles/mprpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/mprpc.dir/depend

