# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/avicii/Dropbox/BGR/Data Unit/cserver"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/cserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cserver.dir/flags.make

CMakeFiles/cserver.dir/src/main.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cserver.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/main.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/main.c"

CMakeFiles/cserver.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/main.c" > CMakeFiles/cserver.dir/src/main.c.i

CMakeFiles/cserver.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/main.c" -o CMakeFiles/cserver.dir/src/main.c.s

CMakeFiles/cserver.dir/src/output.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/output.c.o: ../src/output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cserver.dir/src/output.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/output.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/output.c"

CMakeFiles/cserver.dir/src/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/output.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/output.c" > CMakeFiles/cserver.dir/src/output.c.i

CMakeFiles/cserver.dir/src/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/output.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/output.c" -o CMakeFiles/cserver.dir/src/output.c.s

CMakeFiles/cserver.dir/src/handleMessage.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/handleMessage.c.o: ../src/handleMessage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cserver.dir/src/handleMessage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/handleMessage.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/handleMessage.c"

CMakeFiles/cserver.dir/src/handleMessage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/handleMessage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/handleMessage.c" > CMakeFiles/cserver.dir/src/handleMessage.c.i

CMakeFiles/cserver.dir/src/handleMessage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/handleMessage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/handleMessage.c" -o CMakeFiles/cserver.dir/src/handleMessage.c.s

CMakeFiles/cserver.dir/src/tools.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/tools.c.o: ../src/tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/cserver.dir/src/tools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/tools.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/tools.c"

CMakeFiles/cserver.dir/src/tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/tools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/tools.c" > CMakeFiles/cserver.dir/src/tools.c.i

CMakeFiles/cserver.dir/src/tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/tools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/tools.c" -o CMakeFiles/cserver.dir/src/tools.c.s

CMakeFiles/cserver.dir/src/dbTools.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/dbTools.c.o: ../src/dbTools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/cserver.dir/src/dbTools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/dbTools.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/dbTools.c"

CMakeFiles/cserver.dir/src/dbTools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/dbTools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/dbTools.c" > CMakeFiles/cserver.dir/src/dbTools.c.i

CMakeFiles/cserver.dir/src/dbTools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/dbTools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/dbTools.c" -o CMakeFiles/cserver.dir/src/dbTools.c.s

CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o: ../src/semiBlockingQueue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o   -c "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/semiBlockingQueue.c"

CMakeFiles/cserver.dir/src/semiBlockingQueue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cserver.dir/src/semiBlockingQueue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/semiBlockingQueue.c" > CMakeFiles/cserver.dir/src/semiBlockingQueue.c.i

CMakeFiles/cserver.dir/src/semiBlockingQueue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cserver.dir/src/semiBlockingQueue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/avicii/Dropbox/BGR/Data Unit/cserver/src/semiBlockingQueue.c" -o CMakeFiles/cserver.dir/src/semiBlockingQueue.c.s

# Object files for target cserver
cserver_OBJECTS = \
"CMakeFiles/cserver.dir/src/main.c.o" \
"CMakeFiles/cserver.dir/src/output.c.o" \
"CMakeFiles/cserver.dir/src/handleMessage.c.o" \
"CMakeFiles/cserver.dir/src/tools.c.o" \
"CMakeFiles/cserver.dir/src/dbTools.c.o" \
"CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o"

# External object files for target cserver
cserver_EXTERNAL_OBJECTS =

cserver: CMakeFiles/cserver.dir/src/main.c.o
cserver: CMakeFiles/cserver.dir/src/output.c.o
cserver: CMakeFiles/cserver.dir/src/handleMessage.c.o
cserver: CMakeFiles/cserver.dir/src/tools.c.o
cserver: CMakeFiles/cserver.dir/src/dbTools.c.o
cserver: CMakeFiles/cserver.dir/src/semiBlockingQueue.c.o
cserver: CMakeFiles/cserver.dir/build.make
cserver: /usr/local/lib/libmongoc-1.0.so
cserver: /usr/local/lib/libbson-1.0.so
cserver: /usr/lib/x86_64-linux-gnu/libsasl2.so
cserver: /usr/lib/x86_64-linux-gnu/libssl.so
cserver: /usr/lib/x86_64-linux-gnu/libcrypto.so
cserver: CMakeFiles/cserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable cserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cserver.dir/build: cserver

.PHONY : CMakeFiles/cserver.dir/build

CMakeFiles/cserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cserver.dir/clean

CMakeFiles/cserver.dir/depend:
	cd "/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/avicii/Dropbox/BGR/Data Unit/cserver" "/home/avicii/Dropbox/BGR/Data Unit/cserver" "/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug" "/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug" "/home/avicii/Dropbox/BGR/Data Unit/cserver/cmake-build-debug/CMakeFiles/cserver.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/cserver.dir/depend

