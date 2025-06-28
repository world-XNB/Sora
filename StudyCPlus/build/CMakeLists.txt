# cmake version
cmake_minimum_required(VERSION 3.30.3)

# project name
project(StudyCPlus)

# head file path
include_directories(${PROJECT_BINARY_DIR}/../inc)

# source directory
aux_source_directory(${PROJECT_BINARY_DIR}/../src MAIN_SRC)

# set compilation options, including debug information
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# set the executable file output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

# build executable file
add_executable(test ${MAIN_SRC})
