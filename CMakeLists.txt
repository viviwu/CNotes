cmake_minimum_required(VERSION 3.17)
project(CNotes)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        base
        util
        tree/include

)

aux_source_directory(tree/src TREE_SRC)

add_executable(CNotes
        main.cpp
        ${TREE_SRC}
)