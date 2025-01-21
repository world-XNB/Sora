# cmake version
cmake_minimum_required(VERSION 3.30.3)

# project name
project(learm_cmake)

# head file path
include_directories(${PROJECT_BINARY_DIR}/../inc)

# source directory
aux_source_directory(${PROJECT_BINARY_DIR}/../src MAIN_SRC)

# set compilation options, including debug information
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# build dynamic libraries
add_library(SharedLib SHARED ${PROJECT_BINARY_DIR}/../src/SharedLib.cpp)

# build static libraries
add_library(StaticLib STATIC ${PROJECT_BINARY_DIR}/../src/StaticLib.cpp)

# set the name of the dynamic library and static library
set_target_properties(SharedLib PROPERTIES OUTPUT_NAME "MY_LIB")
set_target_properties(StaticLib PROPERTIES OUTPUT_NAME "MY_LIB")

# set the dynamic library and static library output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

# set the executable file output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

# build executable file
add_executable(test ${MAIN_SRC})

# link dynamic library and static library
target_link_libraries(test SharedLib StaticLib)