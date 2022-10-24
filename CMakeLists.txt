cmake_minimum_required(VERSION 3.16)
project(play_c C)
set(CMAKE_C_STANDARD 99)


add_subdirectory(src/algorithm)
add_subdirectory(src/data_structure)
add_subdirectory(src/files)
add_subdirectory(src/hello)
add_subdirectory(src/memory)
add_subdirectory(src/pointer)
add_subdirectory(src/puzzle)
add_subdirectory(src/string)
add_subdirectory(src/time)
add_subdirectory(src/types)
add_subdirectory(src/include)

#target_include_directories(src/algorithm)
#include_directories(src/include)

add_executable(play_c src/main.c)

# 链接 src/algorithm 生成的库文件，查看 src/algorithm/CMakeLists.txt 文件
target_link_libraries(play_c algorithm)

