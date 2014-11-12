cmake_minimum_required(VERSION 2.8.4)
project(cpptest)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_COMPILER "c")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(SERVER_SOURCE_FILES server.cc socket.cc server_socket.cc socket_exception.h)
set(CLIENT_SOURCE_FILES client.cc socket.cc socket_exception.h client_socket.cc)

add_executable(server ${SERVER_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES})
