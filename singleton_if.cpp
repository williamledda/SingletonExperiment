#include "singleton_if.h"
#include "singleton_impl.h"

namespace singleton {

SingletonInterface* instance::current = nullptr;

SingletonInterface& get_instance() {
  static bool init = []() -> bool{
    if(instance::current == nullptr) {
      static SingletonImpl impl;
      instance::current = &impl;
    }
    return true;
  }();

  return *instance::current;
}

void set_instance(SingletonInterface* new_instance) {
  instance::current = new_instance;
}
}