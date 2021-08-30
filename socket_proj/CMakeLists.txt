cmake_minimum_required(VERSION 2.8)

project(Network)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_executable(echo_server echo_server.c)
add_executable(echo_client echo_cli.c)
