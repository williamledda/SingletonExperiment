#include <iostream>
#include "singleton_if.h"
#include "new_impl.h"
#include <memory>

int main() {
  singleton::get_instance().do_something();

  std::cout << "\nSwitching impl...\n";
  
  singleton::set_instance(std::make_unique<singleton::NewImpl>(10));
  singleton::get_instance().do_something();

    std::cout << "\nDone!\n";  
}