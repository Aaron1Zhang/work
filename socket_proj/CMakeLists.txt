cmake_minimum_required(VERSION 2.8)

project(Network)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# add_executable(echo_server echo_server.c)
# add_executable(echo_server2 echo_server2.c)
# add_executable(echo_client echo_cli.c)
# add_executable(peer_server peer_server.c)
# add_executable(peer_client peer_client.c)

#add_executable(echo_server_upd echo_server_udp.c)
#add_executable(echo_client_udp echo_client_udp.c)

#add_executable(thread_create thread_create.c)
add_executable(echo_server_thread echo_serv_thread.c)
target_link_libraries(echo_server_thread pthread)
add_executable(pthread_key pthread_key.c)
target_link_libraries(pthread_key pthread)

