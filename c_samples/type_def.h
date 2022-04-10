//
// Created by viviwu on 2022/4/4.
//

#ifndef C_SAMPLES_TYPE_DEF_H
#define C_SAMPLES_TYPE_DEF_H

typedef unsigned char BYTE;


enum WEEK_DAY
{
  MON=1, TUE, WED, THU, FRI, SAT, SUN
}weekDay;

typedef struct
{
  char    name[32];  // name
  float   stature;
  int     age;
  char    sex;  // 0\1\a\x
  long    uid;
} User;

#endif //C_SAMPLES_TYPE_DEF_H


//sizeof(XUser) = 56
//User jim/* ={'S'}*/;
/*
 * memset(&jim, '$', sizeof(struct User));

 * XUser jake = {
    .name = "jake",
    .uid = 10001011,
    .age = 32,
    .stature = 1.76,
    .sex = '0'
};  *//*{0};*//*
  printf("sizeof(XUser) = %d\n", sizeof(XUser));
  printf("%c \n", jake.sex);
  printf("%d \n", jake.age);

  XUser pony = {
    name:"pony",
    age:48
  };
  printf("name: %s \n ", pony.name);

  XUser vivi = jake;
  printf("name: %s \n ", vivi.name);
  printf("age: %d \n ", vivi.age);
  */

