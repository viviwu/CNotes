//
// Created by viviwu on 2022/4/4.
//

#include <stdio.h>
#include <string.h>


void  sprintf_concat_str()
{
  char *strv[10];
  for (int i = 1; i <= 10; ++i) {
    char fn[8];
    sprintf(fn, "n%*d.%*s", 1, i, 3, "txt");
    strv[i]=fn;
    printf("fn: %s \n", strv[i]);
  }
}