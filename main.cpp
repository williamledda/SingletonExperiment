#include <iostream>
#include "singleton_if.h"
#include "new_impl.h"
#include "client.h"


// #include <memory>

int main() {
  Client a_client;
  singleton::get_instance().do_something();
  a_client.use_singleton();

  std::cout << "\nSwitching impl...\n";
  singleton::set_instance(std::make_unique<singleton::NewImpl>(30));
  a_client.use_singleton();
  singleton::get_instance().do_something();

  std::cout << "\nDone!\n";
}