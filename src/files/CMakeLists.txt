cmake_minimum_required(VERSION 3.16)

aux_source_directory(. SRC_LIST)

add_executable(files main.c ${SRC_LIST})
