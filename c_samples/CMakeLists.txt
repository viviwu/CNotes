cmake_minimum_required(VERSION 3.17)
project(c_samples C)

set(CMAKE_C_STANDARD 99)

file(GLOB THREAD_SRC thread/*.c)

add_executable(c_samples main.c
        utils/cstr_utils.c utils/cstr_utils.h
        cptr.c
        type_def.h
        var_list_func.c
        func_ptr.c
        ${THREAD_SRC}
        cstr.cpp
        )