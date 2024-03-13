# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(smallchat C)

# Set C standard
set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Add the chatlib library
add_library(chatlib
        chatlib.c
        # Add any other source files from chatlib
        )

# Include directories for chatlib
target_include_directories(chatlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the smallchat-client executable
add_executable(smallchat-client
        smallchat-client.c
        # Add any other source files from smallchat-client
        )

# Link chatlib to smallchat-client
target_link_libraries(smallchat-client PRIVATE chatlib)

# Add the smallchat-server executable
add_executable(smallchat-server
        smallchat-server.c
        # Add any other source files from smallchat-server
        )

# Link chatlib to smallchat-server
target_link_libraries(smallchat-server PRIVATE chatlib)

message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})