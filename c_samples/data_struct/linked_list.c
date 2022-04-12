//
//  main.c
//  liined_list
//
//  Created by viviwu on 2021/1/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define STR_SIZE 10
#define STR_SIZE_LIMIT 20

typedef struct DataItem {
  int number;
  char name[STR_SIZE];
  char phone[STR_SIZE];
};

typedef struct TNode {
  struct DataItem s;
  struct TNode *next;
};

char command_str[] = {"\n1 display all member;\n2 insert member;\n3 del member;\n4 exit\nCommand selection:"};

struct DataItem students[STR_SIZE];
struct TNode *head = NULL;


void display_student(struct TNode *pStu) {
  printf("number:%d name:%s phone:%s \n", pStu->s.number, pStu->s.name, pStu->s.phone);
}

void insert_student(struct DataItem student) {

  struct TNode *pNode;
  struct TNode *pStu = NULL;
  int size = sizeof(struct TNode);
  pStu = (struct TNode *) malloc(size);
  if (pStu == NULL) {
    return;
  }
  memcpy(&pStu->s, &student, sizeof(student));

  if (head == NULL) {

    pStu->next = head;
    head = pStu;
    head->next = head;
    return;
  }
  pStu->next = head->next;
  head->next = pStu;


}

void del_student(struct DataItem student) {
  struct TNode *pNode = NULL, *p = NULL;
  if (head->next == head && head->s.number == student.number) {
    pNode = head;
    head = NULL;
    free(pNode);
    printf("success");
    return;
  }
  for (pNode = head->next; pNode != head; pNode = pNode->next) {
    if (pNode->next->s.number == student.number) {
      p = pNode->next->next;

      free(pNode->next);
      pNode->next = p;

      printf("Delete success!\n");
      return;
    }

  }
  printf("Not Found\n");
}


//int main(int argc, char* argv[])
void linked_list_demo() {
  int command, i;
  struct DataItem student;
  struct TNode *pStu = head;
  memset(&student, 0, sizeof(student));

  while (1) {
    printf("%s", command_str);
    scanf("%d", &command);
    switch (command) {
      case 1:
        if (head == NULL) {
          printf("empty!!!!!!!!!!!!\n");
          break;
        }
        if (head->next == head) {
          display_student(head);
        } else {
          pStu = head->next;
          do {
            display_student(pStu);
            pStu = pStu->next;
          } while (pStu != head->next);
//
        }

        break;
      case 2:
        printf("enter new student number:");
        scanf("%d", &student.number);
        printf("enter new student name:");
        scanf("%s", &student.name);
        if (strlen(student.name) > STR_SIZE_LIMIT) {
          printf("name is too long!!\n");
          continue;
        }

        printf("enter new student phone:");
        scanf("%s", &student.phone);

        if (strlen(student.phone) > STR_SIZE_LIMIT) {
          printf("phone is too long!!\n");
          continue;
        }

        printf("\n");

        if (student.number != 0)
          insert_student(student);

        break;
      case 3:
        printf("Inter deleted student number:");
        scanf("%d", &student.number);
        del_student(student);
        break;
      case 4:
        break;
      default:
        printf("error command, try again\n");
        break;
    }
    sleep(1);
  }
}
