#include "singleton_if.h"
#include "singleton_impl.h"

#include <iostream>

namespace singleton {

//std::unique_ptr<SingletonInterface> instance::current = nullptr;
SingletonInterface* instance::current = nullptr;

// SingletonInterface::~SingletonInterface() {
//   std::cout << "Interface D-ctor\n";
// }

SingletonInterface& get_instance() {
  static bool init = []() -> bool{
    if(instance::current == nullptr) {
      std::cout << "Creating the Singleton for the first time!!!\n\n";
       static SingletonImpl impl;
       instance::current = &impl;
       
      // instance::current.reset(&impl);
//      instance::current = std::make_unique<SingletonImpl>();
    }
    return true;
  }();

  return *instance::current;
}

//void set_instance(std::unique_ptr<SingletonInterface> new_instance) {
//  instance::current = std::move(new_instance);
//}

 void set_instance(SingletonInterface* new_instance) {
    if(instance::current != nullptr) {
        delete instance::current;
    }
   instance::current = new_instance;
 }
}