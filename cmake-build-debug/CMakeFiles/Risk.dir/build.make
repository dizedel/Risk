# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Risk.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Risk.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Risk.dir\flags.make

CMakeFiles\Risk.dir\src\Continent.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Continent.cpp.obj: ..\src\Continent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Risk.dir/src/Continent.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Continent.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Continent.cpp"
<<

CMakeFiles\Risk.dir\src\Continent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Continent.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Continent.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Continent.cpp"
<<

CMakeFiles\Risk.dir\src\Continent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Continent.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Continent.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Continent.cpp"
<<

CMakeFiles\Risk.dir\src\Dice.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Dice.cpp.obj: ..\src\Dice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Risk.dir/src/Dice.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Dice.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Dice.cpp"
<<

CMakeFiles\Risk.dir\src\Dice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Dice.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Dice.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Dice.cpp"
<<

CMakeFiles\Risk.dir\src\Dice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Dice.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Dice.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Dice.cpp"
<<

CMakeFiles\Risk.dir\src\Main.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Main.cpp.obj: ..\src\Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Risk.dir/src/Main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Main.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Main.cpp"
<<

CMakeFiles\Risk.dir\src\Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Main.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Main.cpp"
<<

CMakeFiles\Risk.dir\src\Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Main.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Main.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Main.cpp"
<<

CMakeFiles\Risk.dir\src\Map.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Map.cpp.obj: ..\src\Map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Risk.dir/src/Map.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Map.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Map.cpp"
<<

CMakeFiles\Risk.dir\src\Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Map.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Map.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Map.cpp"
<<

CMakeFiles\Risk.dir\src\Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Map.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Map.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Map.cpp"
<<

CMakeFiles\Risk.dir\src\MapLoader.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\MapLoader.cpp.obj: ..\src\MapLoader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Risk.dir/src/MapLoader.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\MapLoader.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\MapLoader.cpp"
<<

CMakeFiles\Risk.dir\src\MapLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/MapLoader.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\MapLoader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\MapLoader.cpp"
<<

CMakeFiles\Risk.dir\src\MapLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/MapLoader.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\MapLoader.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\MapLoader.cpp"
<<

CMakeFiles\Risk.dir\src\Player.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Player.cpp.obj: ..\src\Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Risk.dir/src/Player.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Player.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Player.cpp"
<<

CMakeFiles\Risk.dir\src\Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Player.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Player.cpp"
<<

CMakeFiles\Risk.dir\src\Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Player.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Player.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Player.cpp"
<<

CMakeFiles\Risk.dir\src\stdafx.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\stdafx.cpp.obj: ..\src\stdafx.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Risk.dir/src/stdafx.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\stdafx.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\stdafx.cpp"
<<

CMakeFiles\Risk.dir\src\stdafx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/stdafx.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\stdafx.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\stdafx.cpp"
<<

CMakeFiles\Risk.dir\src\stdafx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/stdafx.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\stdafx.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\stdafx.cpp"
<<

CMakeFiles\Risk.dir\src\Territory.cpp.obj: CMakeFiles\Risk.dir\flags.make
CMakeFiles\Risk.dir\src\Territory.cpp.obj: ..\src\Territory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Risk.dir/src/Territory.cpp.obj"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Risk.dir\src\Territory.cpp.obj /FdCMakeFiles\Risk.dir\ /FS -c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Territory.cpp"
<<

CMakeFiles\Risk.dir\src\Territory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Risk.dir/src/Territory.cpp.i"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\Risk.dir\src\Territory.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Territory.cpp"
<<

CMakeFiles\Risk.dir\src\Territory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Risk.dir/src/Territory.cpp.s"
	C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Risk.dir\src\Territory.cpp.s /c "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\src\Territory.cpp"
<<

# Object files for target Risk
Risk_OBJECTS = \
"CMakeFiles\Risk.dir\src\Continent.cpp.obj" \
"CMakeFiles\Risk.dir\src\Dice.cpp.obj" \
"CMakeFiles\Risk.dir\src\Main.cpp.obj" \
"CMakeFiles\Risk.dir\src\Map.cpp.obj" \
"CMakeFiles\Risk.dir\src\MapLoader.cpp.obj" \
"CMakeFiles\Risk.dir\src\Player.cpp.obj" \
"CMakeFiles\Risk.dir\src\stdafx.cpp.obj" \
"CMakeFiles\Risk.dir\src\Territory.cpp.obj"

# External object files for target Risk
Risk_EXTERNAL_OBJECTS =

Risk.exe: CMakeFiles\Risk.dir\src\Continent.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\Dice.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\Main.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\Map.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\MapLoader.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\Player.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\stdafx.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\src\Territory.cpp.obj
Risk.exe: CMakeFiles\Risk.dir\build.make
Risk.exe: CMakeFiles\Risk.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Risk.exe"
	"C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Risk.dir --manifests  -- C:\PROGRA~2\MICROS~3\2017\ENTERP~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Risk.dir\objects1.rsp @<<
 /out:Risk.exe /implib:Risk.lib /pdb:"C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\Risk.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Risk.dir\build: Risk.exe

.PHONY : CMakeFiles\Risk.dir\build

CMakeFiles\Risk.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Risk.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Risk.dir\clean

CMakeFiles\Risk.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk" "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk" "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug" "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug" "C:\Doc\Concordia\2018 Fall\COMP345\comp345project\Risk\cmake-build-debug\CMakeFiles\Risk.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Risk.dir\depend

