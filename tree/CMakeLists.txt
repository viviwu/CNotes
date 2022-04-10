cmake_minimum_required(VERSION 3.17)
project(CNotes)

set(CMAKE_CXX_STANDARD 14)

include_directories(
#        tree
)

aux_source_directory(./ TREE_SRC)

add_executable(CNotes
        ${TREE_SRC}
        geometry.h)