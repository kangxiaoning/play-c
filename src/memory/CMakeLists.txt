cmake_minimum_required(VERSION 3.21)

aux_source_directory(. SRC_LIST)

add_executable(memory main.c ${SRC_LIST})
