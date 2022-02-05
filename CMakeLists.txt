cmake_minimum_required(VERSION 3.21)

project(play_c C)

set(CMAKE_C_STANDARD 11)

include_directories(src/algorithm)

add_subdirectory(src/algorithm)
add_subdirectory(src/pointer)
add_subdirectory(src/puzzle)
add_subdirectory(src/memory)

add_executable(play_c src/main.c)

# 链接 src/algorithm 生成的库文件，查看 src/algorithm/CMakeLists.txt 文件
target_link_libraries(play_c algorithm)
