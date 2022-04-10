#include <stdio.h>


extern void  sprintf_concat_str();

extern int multi_pthreads_work();

extern int pthreads_join_with_lock();

int main(int argc, char **argv) {

  printf("argc = %d \n", argc);
  for (int i = 0; i < argc; ++i)
    printf("argv[%d] : %s \n", i, argv[i]);


//  sprintf_concat_str();

//  thread_with_args ();

//  threads_join();

//  multi_pthreads_work();

  pthreads_join_with_lock();

  printf("Hello, World!\n");
  return 0;
}
