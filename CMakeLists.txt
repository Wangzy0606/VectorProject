# 设置 CMake 的最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)
# 设置项目名称为 MyProject
project(MyProject)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)

# 添加头文件搜索路径，将 include 目录添加到搜索路径中
include_directories(include)

# 收集所有源文件，将 src 目录下的所有 .cpp 文件收集到 SOURCES 变量中
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 添加可执行文件，将收集到的源文件编译成名为 MyProject 的可执行文件
add_executable(MyProject ${SOURCES})    