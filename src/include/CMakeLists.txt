cmake_minimum_required(VERSION 3.16)

include_directories(.)

aux_source_directory(. SRC_LIST)

# 生成名为 include 的库文件
add_library(include STATIC ${SRC_LIST})