cmake_minimum_required(VERSION 3.21)

include_directories(.)

aux_source_directory(. SRC_LIST)

# 生成名为 algorithm 的库文件
add_library(algorithm STATIC ${SRC_LIST})