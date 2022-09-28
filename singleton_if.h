#pragma once 

namespace singleton {
class SingletonInterface {
public:
  virtual void do_something() = 0;
};

namespace instance {
  extern SingletonInterface* current;
}

SingletonInterface* get_instance();
void set_instance(SingletonInterface* new_instance);
}
