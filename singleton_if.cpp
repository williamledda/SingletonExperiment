#include "singleton_if.h"
#include "singleton_impl.h"

#include <iostream>
#include <stdexcept>

namespace singleton {

std::unique_ptr<SingletonInterface> instance::current = nullptr;

SingletonInterface& get_instance() {
  static bool init = []() -> bool{
    if(instance::current == nullptr) {
      std::cout << "Creating the Singleton for the first time!!!\n\n";
      instance::current = std::make_unique<SingletonImpl>();
    }
    return (instance::current != nullptr);
  }();

  if(!init || instance::current == nullptr) {
      throw std::runtime_error("Singleton not initialized");
  }

  return *instance::current;
}

void set_instance(std::unique_ptr<SingletonInterface> new_instance) {
  instance::current = std::move(new_instance);
}

}