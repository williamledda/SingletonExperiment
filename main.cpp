#include <iostream>
#include "singleton_if.h"

int main() {
  std::cout << "Hello World!\n";
  singleton::get_instance().do_something();
}