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
CMAKE_SOURCE_DIR = /home/zh/proj/vsCode_proj/chart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zh/proj/vsCode_proj/chart/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/ChartServer.dir/depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/ChartServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/ChartServer.dir/flags.make

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o: ../src/server/ChartServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/ChartServer.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/ChartServer.cpp

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/ChartServer.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/ChartServer.cpp > CMakeFiles/ChartServer.dir/ChartServer.cpp.i

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/ChartServer.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/ChartServer.cpp -o CMakeFiles/ChartServer.dir/ChartServer.cpp.s

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o


src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o: ../src/server/ChartService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/ChartService.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/ChartService.cpp

src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/ChartService.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/ChartService.cpp > CMakeFiles/ChartServer.dir/ChartService.cpp.i

src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/ChartService.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/ChartService.cpp -o CMakeFiles/ChartServer.dir/ChartService.cpp.s

src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o


src/server/CMakeFiles/ChartServer.dir/main.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/main.cpp.o: ../src/server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/ChartServer.dir/main.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/main.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/main.cpp

src/server/CMakeFiles/ChartServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/main.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/main.cpp > CMakeFiles/ChartServer.dir/main.cpp.i

src/server/CMakeFiles/ChartServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/main.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/main.cpp -o CMakeFiles/ChartServer.dir/main.cpp.s

src/server/CMakeFiles/ChartServer.dir/main.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/main.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/main.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/main.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/main.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/main.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/main.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/main.cpp.o


src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o: ../src/server/db/db.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/db/db.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/db/db.cpp

src/server/CMakeFiles/ChartServer.dir/db/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/db/db.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/db/db.cpp > CMakeFiles/ChartServer.dir/db/db.cpp.i

src/server/CMakeFiles/ChartServer.dir/db/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/db/db.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/db/db.cpp -o CMakeFiles/ChartServer.dir/db/db.cpp.s

src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o


src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o: ../src/server/model/friendmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/model/friendmodel.cpp

src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/model/friendmodel.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/model/friendmodel.cpp > CMakeFiles/ChartServer.dir/model/friendmodel.cpp.i

src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/model/friendmodel.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/model/friendmodel.cpp -o CMakeFiles/ChartServer.dir/model/friendmodel.cpp.s

src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o


src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o: ../src/server/model/groupmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/model/groupmodel.cpp

src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/model/groupmodel.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/model/groupmodel.cpp > CMakeFiles/ChartServer.dir/model/groupmodel.cpp.i

src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/model/groupmodel.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/model/groupmodel.cpp -o CMakeFiles/ChartServer.dir/model/groupmodel.cpp.s

src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o


src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o: ../src/server/model/groupuser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/model/groupuser.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/model/groupuser.cpp

src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/model/groupuser.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/model/groupuser.cpp > CMakeFiles/ChartServer.dir/model/groupuser.cpp.i

src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/model/groupuser.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/model/groupuser.cpp -o CMakeFiles/ChartServer.dir/model/groupuser.cpp.s

src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o


src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o: ../src/server/model/offlinemsgmodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/model/offlinemsgmodel.cpp

src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/model/offlinemsgmodel.cpp > CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.i

src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/model/offlinemsgmodel.cpp -o CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.s

src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o


src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o: src/server/CMakeFiles/ChartServer.dir/flags.make
src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o: ../src/server/model/usermodel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ChartServer.dir/model/usermodel.cpp.o -c /home/zh/proj/vsCode_proj/chart/src/server/model/usermodel.cpp

src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChartServer.dir/model/usermodel.cpp.i"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zh/proj/vsCode_proj/chart/src/server/model/usermodel.cpp > CMakeFiles/ChartServer.dir/model/usermodel.cpp.i

src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChartServer.dir/model/usermodel.cpp.s"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zh/proj/vsCode_proj/chart/src/server/model/usermodel.cpp -o CMakeFiles/ChartServer.dir/model/usermodel.cpp.s

src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.requires:

.PHONY : src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.requires

src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.provides: src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.requires
	$(MAKE) -f src/server/CMakeFiles/ChartServer.dir/build.make src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.provides.build
.PHONY : src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.provides

src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.provides.build: src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o


# Object files for target ChartServer
ChartServer_OBJECTS = \
"CMakeFiles/ChartServer.dir/ChartServer.cpp.o" \
"CMakeFiles/ChartServer.dir/ChartService.cpp.o" \
"CMakeFiles/ChartServer.dir/main.cpp.o" \
"CMakeFiles/ChartServer.dir/db/db.cpp.o" \
"CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o" \
"CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o" \
"CMakeFiles/ChartServer.dir/model/groupuser.cpp.o" \
"CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o" \
"CMakeFiles/ChartServer.dir/model/usermodel.cpp.o"

# External object files for target ChartServer
ChartServer_EXTERNAL_OBJECTS =

../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/main.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/build.make
../bin/ChartServer: src/server/CMakeFiles/ChartServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zh/proj/vsCode_proj/chart/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ../../../bin/ChartServer"
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChartServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/ChartServer.dir/build: ../bin/ChartServer

.PHONY : src/server/CMakeFiles/ChartServer.dir/build

src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/ChartServer.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/ChartService.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/main.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/db/db.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/model/friendmodel.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/model/groupmodel.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/model/groupuser.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/model/offlinemsgmodel.cpp.o.requires
src/server/CMakeFiles/ChartServer.dir/requires: src/server/CMakeFiles/ChartServer.dir/model/usermodel.cpp.o.requires

.PHONY : src/server/CMakeFiles/ChartServer.dir/requires

src/server/CMakeFiles/ChartServer.dir/clean:
	cd /home/zh/proj/vsCode_proj/chart/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/ChartServer.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/ChartServer.dir/clean

src/server/CMakeFiles/ChartServer.dir/depend:
	cd /home/zh/proj/vsCode_proj/chart/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zh/proj/vsCode_proj/chart /home/zh/proj/vsCode_proj/chart/src/server /home/zh/proj/vsCode_proj/chart/build /home/zh/proj/vsCode_proj/chart/build/src/server /home/zh/proj/vsCode_proj/chart/build/src/server/CMakeFiles/ChartServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/ChartServer.dir/depend

