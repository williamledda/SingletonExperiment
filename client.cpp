#include "client.h"
#include "singleton_if.h"

#include <iostream>

void Client::use_singleton() {
  std::cout << "A client is using the singleton... ";
  singleton::get_instance().do_something();
}

