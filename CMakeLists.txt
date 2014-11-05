cmake_minimum_required(VERSION 2.8.4)
project(cpptest)

set(SERVER_SOURCE_FILES server.cc socket.cc server_socket.cc socket_exception.h)
set(CLIENT_SOURCE_FILES client.cc socket.cc socket_exception.h client_socket.cc)
add_executable(server ${SERVER_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES})