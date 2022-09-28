#include "singleton_if.h"
#include "singleton_impl.h"

#include <iostream>

namespace singleton {

std::unique_ptr<SingletonInterface> instance::current = nullptr;

SingletonInterface::~SingletonInterface() {
  std::cout << "Interface D-ctor\n";
}

SingletonInterface& get_instance() {
  bool init = []() -> bool{
    if(instance::current == nullptr) {
      // static SingletonImpl impl;
      // instance::current.reset(&impl);
      std::cout << "Creating the Singleton for the first time!!!\n\n";
      instance::current = std::make_unique<SingletonImpl>();
    }
    return true;
  }();

  return *instance::current;
}

void set_instance(std::unique_ptr<SingletonInterface> new_instance) {
  instance::current = std::move(new_instance);
}
}