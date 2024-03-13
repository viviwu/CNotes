cmake_minimum_required(VERSION 3.24)
project(cs C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(client client.c)

add_executable(server server.c)

message("CMAKE_RUNTIME_OUTPUT_DIRECTORY:" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
