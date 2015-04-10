cmake_minimum_required(VERSION 2.8.11)
project(dent)

set(REMOTEIP 10.20.59.2)

# Compiler flags
set(CMAKE_CXX_COMPILER "/usr/bin/arm-frc-linux-gnueabi-g++")
set(CMAKE_EXE_LINKER_FLAGS -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a)
add_compile_options(-std=c++11 -O0 -g3 -Wall -c -fmessage-length=0)

# Add sources and headers
file(GLOB_RECURSE DENT_SOURCES "Commands/*.cpp")
file(GLOB_RECURSE TMP "Subsystems/*.cpp")
set(DENT_SOURCES DentRobot.cpp OI.cpp ${DENT_SOURCES} ${TMP})
file(GLOB_RECURSE DENT_HEADERS "Commands/*.h")
file(GLOB_RECURSE DENT_HEADERS "Subsystems/*.h")
set(DENT_HEADERS DentRobot.h OI.h ${DENT_HEADERS} ${TMP})
message(STATUS "DENT_SOURCES: ${DENT_SOURCES}")
message(STATUS "DENT_HEADERS: ${DENT_HEADERS}")
set(DENT_INCLUDE_DIRS "")
foreach(_headerFile ${DENT_HEADERS})
  get_filename_component(_dir ${_headerFile} PATH)
  list(APPEND DENT_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES DENT_INCLUDE_DIRS)
include_directories(/var/frc/wpilib/include)

# Build binary
include_directories(${DENT_INCLUDE_DIRS})
add_executable(FRCUserProgram ${DENT_SOURCES})
target_link_libraries(FRCUserProgram /var/frc/wpilib/lib/libwpi_2015.so)
find_program(READER pv)
if(!READER)
  find_program(READER cat)
endif()
find_program(echo echo)
#TODO: This should be working, but doesn't...
add_custom_target(deploy ${READER} FRCUserProgram|ssh admin@${REMOTEIP} '(rm /home/lvuser/FRCUserProgram)</dev/null;cat>/home/lvuser/FRCUserProgram;chmod a+x /home/lvuser/FRCUserProgram')
# vim: ts=2:sw=2:et
