# 最低版本号
cmake_minimum_required(VERSION 3.30.3)

# 项目名称
project(learm_cmake)

# 头文件路径
include_directories(${PROJECT_BINARY_DIR}/../inc)

# 源文件路径
aux_source_directory(${PROJECT_BINARY_DIR}/../src MAIN_SRC)

# 设置编译选项，包含调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 生成动态库
add_library(SharedLib SHARED ${PROJECT_BINARY_DIR}/../src/SharedLib.cpp)

# 生成静态库
add_library(StaticLib STATIC ${PROJECT_BINARY_DIR}/../src/StaticLib.cpp)

# 设置最终生成库的名称
set_target_properties(SharedLib PROPERTIES OUTPUT_NAME "MY_LIB")
set_target_properties(StaticLib PROPERTIES OUTPUT_NAME "MY_LIB")

# 设置库默认生成位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../lib)

# 设置可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

# 生成可执行文件
add_executable(test ${MAIN_SRC})

# 链接库
target_link_libraries(test SharedLib StaticLib)