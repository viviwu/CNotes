#include <iostream>

extern int operator_overload();

extern int pretreament ();

extern int send_args_through_thread ();

extern int threads_join ();

extern int std_thread();

extern int signal_processing ();


int main() {
//  operator_overload();

//  pretreament ();

//  send_args_through_thread ();
//  threads_join ();
  std_thread();

//  signal_processing ();


  std::cout << "Hello, World!" << std::endl;
  return 0;
}
