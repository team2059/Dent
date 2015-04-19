cmake_minimum_required(VERSION 2.8.11)
project(dent)

# The roboRIO (default: admin@10.20.59.2)
set(REMHOST admin@10.20.59.2)

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
# Just for debugging
#message(STATUS "DENT_SOURCES: ${DENT_SOURCES}")
#message(STATUS "DENT_HEADERS: ${DENT_HEADERS}")
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
add_custom_target(deploy sh -c "${READER} FRCUserProgram|ssh ${REMHOST} '(rm /home/lvuser/FRCUserProgram)</dev/null;cat>/home/lvuser/FRCUserProgram;chmod a+x /home/lvuser/FRCUserProgram'" VERBATIM)
# UNTESTED
add_custom_target(run sh -c "ssh ${REMHOST} 'mkdir -p /home/lvuser/FRCUserProgram;chmod +x /home/lvuser/FRCUserProgram;/home/lvuser/FRCUserProgram 2>&1|tee /home/lvuser/logs/$(date +%F_%T).log'" VERBATIM)
add_custom_target(putkey sh -c "test -d ~/.ssh||mkdir ~/.ssh;test -f ~/.ssh/id_rsa||ssh-keygen -t rsa -f ~/.ssh/id_rsa -b 4096 -q -N '';cat ~/.ssh/id_rsa.pub|ssh ${REMHOST} '(mkdir -p ~/.ssh;test -f ~/.ssh/id_rsa||ssh-keygen -t rsa -b 4096 -q -N $(cat /dev/null))</dev/null;cat>>~/.ssh/authorized_keys'" VERBATIM)
add_custom_target(clean-all sh -c "make clean;rm -rf cmake_install.cmake CMakeCache.txt CMakeFiles" VERBATIM)
# vim: ts=2:sw=2:et:tw=0
