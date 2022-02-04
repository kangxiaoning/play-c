cmake_minimum_required(VERSION 3.21)

include_directories(include)
include_directories(lib)

aux_source_directory(./lib SRC_LIST)

add_executable(pointer main.c ${SRC_LIST})
