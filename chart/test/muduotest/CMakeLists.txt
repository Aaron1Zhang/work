cmake_minimum_required(VERSION 2.8)
project(server)

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}, -g)

#header file search path
#include_directories()

#lib serch path
#link_directories()

#set(SRC_LIST muduo_server.cpp)
#add_executable(server ${SRC_LIST})

#put . path's all source file to var SRC_LIST 
#aux_source_directory(. SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(server muduo_server.cpp)

target_link_libraries(server muduo_net muduo_base pthread)




