/**
 ******************************************************************************
 * @file           : print_on_terminal.c
 * @author         : viviwu
 * @brief          : None
 * @attention      : None
 * @date           : 3/13/24
 ******************************************************************************
 */
// Created by viviwu on 3/13/24.

#include <stdio.h>
#include <unistd.h>


int main() {
    printf("Hello, world!\n");

    puts("Hello, world!");

    fputs("Hello, world!\n", stdout);

    // #include <unistd.h> 直接向标准输出文件描述符（STDOUT_FILENO）写入字符串
    write(STDOUT_FILENO, "Hello, world!\n", 14);

    return 0;
}
