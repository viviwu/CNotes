cmake_minimum_required(VERSION 3.17)
project(cc_samples)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRCS multi_threads/*.cpp)
#aux_source_directory()
add_executable(cc_samples
        main.cpp
        operator_overload.cpp
        pretreatment.cpp
        signal_processing.cpp

        ${SRCS}

        )