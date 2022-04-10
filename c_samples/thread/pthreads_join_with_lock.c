//
// Created by viviwu on 2022/4/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS  100

static int goods_num = 1000;

pthread_mutex_t lock;

typedef struct {
  long tid;
  int flag;
  char msg[10];
} Info;


void *market_making_buy(void *arg) {
  Info *type = arg;
  pthread_mutex_lock(&lock);
  goods_num++;
  printf("-->%s:[thread %ld] now %d goods left\n", (*type).msg, (*type).tid, goods_num);
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

void *market_making_sall(void *arg) {
  Info *type = arg;
  pthread_mutex_lock(&lock);
  goods_num--;
  printf("-->%s:[thread %ld]: now %d goods left\n", (*type).msg, (*type).tid, goods_num);
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}


int pthreads_join_with_lock() {
  pthread_t threads[NUM_THREADS];

  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

//  mutex initalization to shared memory
//  pthread_mutexattr_t mutexAttr;
//  pthread_mutexattr_init(&mutexAttr);
//  pthread_mutexattr_setpshared(&mutexAttr, PTHREAD_PROCESS_SHARED);
//  pthread_mutex_init(&lock, &mutexAttr);
  pthread_mutex_init(&lock, NULL);

  Info arg = {0, 0, "0"};

  for (int i = 0; i < NUM_THREADS; ++i) {
    arg.tid = i;
    if (0 == i % 2) {
      arg.flag = 0;
      strncpy(arg.msg, "SALL", sizeof(arg.msg));
      pthread_create(&threads[i], NULL, market_making_buy, &arg);
    } else {
      arg.flag = 1;
      strncpy(arg.msg, "BUY", sizeof(arg.msg));
      pthread_create(&threads[i], NULL, market_making_sall, &arg);
    }
    printf("%s\n", arg.msg);
  }

  pthread_attr_destroy(&attr);

  for (int i = 0; i < NUM_THREADS; ++i) {
    pthread_join(threads[i], NULL);
  }

  printf("[main thread ] now %d goods left\n", goods_num);
  printf("Main: program exiting. \n");

  pthread_mutex_destroy(&lock);

  pthread_exit(NULL);
}


//****************************************************//

void *work_func1(void * args){
  int i=10;
  while (--i>0){
    printf("%s: goods_num=%d \n", __func__ , ++goods_num);
    sleep(1);
  }
  pthread_exit(NULL);
}

void *work_func2(void * args){

  int i=10;
  while (--i>0){
    printf("%s: goods_num=%d \n", __func__ , --goods_num);
    sleep(1);
  }
  pthread_exit(NULL);
}

int multi_pthreads_work(){
  clock_t start_time, end_time;
  start_time = clock(); // 开始时间

  pthread_t thread1;
  pthread_t thread2;

  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  pthread_create(&thread1, NULL, work_func1, NULL);
  pthread_create(&thread2, NULL, work_func2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_attr_destroy(&attr);

  end_time = clock();  // 结束时间
  /* 计算得出程序运行时间, 并将其输出到屏幕 */
  printf("timeuse = %lf \n", (double)(end_time - start_time) /* /CLOCKS_PER_SEC */);

  pthread_exit(NULL);
}