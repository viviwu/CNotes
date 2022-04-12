//
// Created by viviwu on 2022/4/12.
//

#include <stdio.h>


void file_write()
{
  char str[] = "Created by viviwu on 2022/4/12." ;
  FILE * of;
  of = fopen("test.txt", "w");
  if (of){
    fprint("test wirte %s\n", str);

    fclose(of);
  }

}