cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(lineitem-dispatcher)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(third-party)



set(CMAKE_EXPORT_COMPILE_COMMANDS True)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")