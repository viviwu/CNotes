/**
 ******************************************************************************
 * @file           : dynamic_array.c
 * @author         : viviwu
 * @brief          : None
 * @attention      : None
 * @date           : 3/13/24
 ******************************************************************************
 */
// Created by viviwu on 3/13/24.

#include <stdio.h>
#include <stdlib.h>

// 链表节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 动态数组
typedef struct {
    Node* head;
    int size;
} DynamicArray;

// 初始化动态数组
void initDynamicArray(DynamicArray* arr) {
    arr->head = NULL;
    arr->size = 0;
}

// 向动态数组添加元素
void addElement(DynamicArray* arr, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = arr->head;
    arr->head = newNode;
    arr->size++;
}

// 打印动态数组
void printDynamicArray(DynamicArray* arr) {
    Node* current = arr->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 释放动态数组内存
void freeDynamicArray(DynamicArray* arr) {
    Node* current = arr->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    arr->head = NULL;
    arr->size = 0;
}

int main() {
    DynamicArray arr;
    initDynamicArray(&arr);

    addElement(&arr, 1);
    addElement(&arr, 2);
    addElement(&arr, 3);

    printf("Dynamic Array: ");
    printDynamicArray(&arr);

    freeDynamicArray(&arr);

    return 0;
}
