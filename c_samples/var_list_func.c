//
// Created by viviwu on 2022/4/5.
//

#include <stdarg.h>
#include <stdio.h>

typedef struct VarArgsType{
  int arg0;
  float arg1;
}VAT;

void var_args_base_func(VAT in);

#define var_args_func(...) var_args_base_func((VAT){__VA_ARGS__})

void var_args_base_func(VAT in)
{
  printf("%s arg0:%d arg1:%.2f \n", __func__, in.arg0, in.arg1);
}
/*
  var_args_func(9);
  var_args_func(1, 2.34);
  var_args_func(.arg0=5, 7.32);
  var_args_func(.arg1=3.14);
*/

double average_func(int num,...)
{
  va_list valist;

  /* 为 num 个参数初始化 valist */
  va_start(valist, num);

  double sum = 0.0;
  /* 访问所有赋给 valist 的参数 */
  for (int i = 0; i < num; i++)
  {
    sum += va_arg(valist, int);
  }
  /* 清理为 valist 保留的内存 */
  va_end(valist);

  return sum/num;
}
//printf("Average of 2, 3, 4, 5 = %f\n", average_func(4, 2,3,4,5));
//printf("Average of 5, 10, 15 = %f\n", average_func(3, 5,10,15));