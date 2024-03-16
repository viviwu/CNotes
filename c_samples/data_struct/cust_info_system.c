/**
 ******************************************************************************
 * @file           : cust_info_system.c
 * @author         : viviwu
 * @brief          : None
 * @attention      : None
 * @date           : 3/13/24
 ******************************************************************************
 */
// Created by viviwu on 3/13/24.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义个人信息结构体
struct Person {
    int id;
    char name[50];
    int age;
    char gender;
    float height;
    char remark[100];
};

// 定义链表节点
struct Node {
    struct Person *data;
    struct Node *next;
};

// 全局变量，指向链表头节点
struct Node *head = NULL;

// 函数声明
void insertPerson();
void displayAll();
void searchPerson();
void updatePerson();
void destroySystem();

int main() {
    int choice;
    do {
        printf("\n");
        printf("1. Insert a person\n");
        printf("2. Display all persons\n");
        printf("3. Search for a person\n");
        printf("4. Update a person's information\n");
        printf("5. Destroy the system and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertPerson();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchPerson();
                break;
            case 4:
                updatePerson();
                break;
            case 5:
                destroySystem();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// 插入个人信息
void insertPerson() {
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
    if (newPerson == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter id: ");
    scanf("%d", &newPerson->id);
    printf("Enter name: ");
    scanf("%s", newPerson->name);
    printf("Enter age: ");
    scanf("%d", &newPerson->age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &newPerson->gender);
    printf("Enter height: ");
    scanf("%f", &newPerson->height);
    printf("Enter remark: ");
    scanf("%s", newPerson->remark);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        free(newPerson);
        return;
    }

    newNode->data = newPerson;
    newNode->next = head;
    head = newNode;

    printf("Person inserted successfully.\n");
}

// 显示所有个人信息
void displayAll() {
    struct Node *current = head;
    if (current == NULL) {
        printf("No persons in the system.\n");
        return;
    }

    printf("Id\tName\tAge\tGender\tHeight\tRemark\n");
    while (current != NULL) {
        struct Person *person = current->data;
        printf("%d\t%s\t%d\t%c\t%.2f\t%s\n", person->id, person->name, person->age, person->gender, person->height, person->remark);
        current = current->next;
    }
}

// 查询个人信息
void searchPerson() {
    int id;
    printf("Enter id to search: ");
    scanf("%d", &id);

    struct Node *current = head;
    while (current != NULL) {
        struct Person *person = current->data;
        if (person->id == id) {
            printf("Id\tName\tAge\tGender\tHeight\tRemark\n");
            printf("%d\t%s\t%d\t%c\t%.2f\t%s\n", person->id, person->name, person->age, person->gender, person->height, person->remark);
            return;
        }
        current = current->next;
    }

    printf("Person with id %d not found.\n", id);
}

// 更新个人信息
void updatePerson() {
    int id;
    printf("Enter id to update: ");
    scanf("%d", &id);

    struct Node *current = head;
    while (current != NULL) {
        struct Person *person = current->data;
        if (person->id == id) {
            printf("Enter new id: ");
            scanf("%d", &person->id);
            printf("Enter new name: ");
            scanf("%s", person->name);
            printf("Enter new age: ");
            scanf("%d", &person->age);
            printf("Enter new gender (M/F): ");
            scanf(" %c", &person->gender);
            printf("Enter new height: ");
            scanf("%f", &person->height);
            printf("Enter new remark: ");
            scanf("%s", person->remark);
            printf("Person information updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Person with id %d not found.\n", id);
}

// 销毁系统
void destroySystem() {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    head = NULL;
    printf("System destroyed. Exiting...\n");
}
