//
// Created by viviwu on 2022/4/7.
//

#include <iostream>
using namespace std;

//#define 预处理
#define PI 3.14159

//参数宏
#define MIN(a,b) (a<b ? a : b)

//条件编译
#define DEBUG

// # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
#define MKSTR( x ) #x

// ## 运算符用于连接两个令牌。
#define concat(a, b) a ## b

int pretreament ()
{

  cout << "Value of PI :" << PI << endl;

  int i  = 100, j = 30;

#ifdef DEBUG
  cerr <<"Trace: Inside main function" << endl;
  /* 这是注释部分 */
  cout << MKSTR(HELLO C++) << endl;
#endif

  cout <<"The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
  cerr <<"Trace: Coming out of main function" << endl;
#endif


  int xy = 100;
  cout << concat(x, y);

  cout << "Value of __LINE__ : " << __LINE__ << endl;
  cout << "Value of __FILE__ : " << __FILE__ << endl;
  cout << "Value of __DATE__ : " << __DATE__ << endl;
  cout << "Value of __TIME__ : " << __TIME__ << endl;

  return 0;
}