# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\hub\SW\VEDA\linux\gu\server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\hub\SW\VEDA\linux\gu\server\build

# Include any dependencies generated for this target.
include CMakeFiles/chat_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chat_server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chat_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chat_server.dir/flags.make

CMakeFiles/chat_server.dir/connect.c.obj: CMakeFiles/chat_server.dir/flags.make
CMakeFiles/chat_server.dir/connect.c.obj: ../connect.c
CMakeFiles/chat_server.dir/connect.c.obj: CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\hub\SW\VEDA\linux\gu\server\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chat_server.dir/connect.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chat_server.dir/connect.c.obj -MF CMakeFiles\chat_server.dir\connect.c.obj.d -o CMakeFiles\chat_server.dir\connect.c.obj -c D:\hub\SW\VEDA\linux\gu\server\connect.c

CMakeFiles/chat_server.dir/connect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chat_server.dir/connect.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\hub\SW\VEDA\linux\gu\server\connect.c > CMakeFiles\chat_server.dir\connect.c.i

CMakeFiles/chat_server.dir/connect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chat_server.dir/connect.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\hub\SW\VEDA\linux\gu\server\connect.c -o CMakeFiles\chat_server.dir\connect.c.s

CMakeFiles/chat_server.dir/server.c.obj: CMakeFiles/chat_server.dir/flags.make
CMakeFiles/chat_server.dir/server.c.obj: ../server.c
CMakeFiles/chat_server.dir/server.c.obj: CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\hub\SW\VEDA\linux\gu\server\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/chat_server.dir/server.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chat_server.dir/server.c.obj -MF CMakeFiles\chat_server.dir\server.c.obj.d -o CMakeFiles\chat_server.dir\server.c.obj -c D:\hub\SW\VEDA\linux\gu\server\server.c

CMakeFiles/chat_server.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chat_server.dir/server.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\hub\SW\VEDA\linux\gu\server\server.c > CMakeFiles\chat_server.dir\server.c.i

CMakeFiles/chat_server.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chat_server.dir/server.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\hub\SW\VEDA\linux\gu\server\server.c -o CMakeFiles\chat_server.dir\server.c.s

CMakeFiles/chat_server.dir/user.c.obj: CMakeFiles/chat_server.dir/flags.make
CMakeFiles/chat_server.dir/user.c.obj: ../user.c
CMakeFiles/chat_server.dir/user.c.obj: CMakeFiles/chat_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\hub\SW\VEDA\linux\gu\server\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/chat_server.dir/user.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/chat_server.dir/user.c.obj -MF CMakeFiles\chat_server.dir\user.c.obj.d -o CMakeFiles\chat_server.dir\user.c.obj -c D:\hub\SW\VEDA\linux\gu\server\user.c

CMakeFiles/chat_server.dir/user.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chat_server.dir/user.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\hub\SW\VEDA\linux\gu\server\user.c > CMakeFiles\chat_server.dir\user.c.i

CMakeFiles/chat_server.dir/user.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chat_server.dir/user.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\hub\SW\VEDA\linux\gu\server\user.c -o CMakeFiles\chat_server.dir\user.c.s

# Object files for target chat_server
chat_server_OBJECTS = \
"CMakeFiles/chat_server.dir/connect.c.obj" \
"CMakeFiles/chat_server.dir/server.c.obj" \
"CMakeFiles/chat_server.dir/user.c.obj"

# External object files for target chat_server
chat_server_EXTERNAL_OBJECTS =

chat_server.exe: CMakeFiles/chat_server.dir/connect.c.obj
chat_server.exe: CMakeFiles/chat_server.dir/server.c.obj
chat_server.exe: CMakeFiles/chat_server.dir/user.c.obj
chat_server.exe: CMakeFiles/chat_server.dir/build.make
chat_server.exe: CMakeFiles/chat_server.dir/linklibs.rsp
chat_server.exe: CMakeFiles/chat_server.dir/objects1.rsp
chat_server.exe: CMakeFiles/chat_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\hub\SW\VEDA\linux\gu\server\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable chat_server.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chat_server.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chat_server.dir/build: chat_server.exe
.PHONY : CMakeFiles/chat_server.dir/build

CMakeFiles/chat_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chat_server.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chat_server.dir/clean

CMakeFiles/chat_server.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\hub\SW\VEDA\linux\gu\server D:\hub\SW\VEDA\linux\gu\server D:\hub\SW\VEDA\linux\gu\server\build D:\hub\SW\VEDA\linux\gu\server\build D:\hub\SW\VEDA\linux\gu\server\build\CMakeFiles\chat_server.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chat_server.dir/depend

