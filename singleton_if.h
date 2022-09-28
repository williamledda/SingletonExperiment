#pragma once 

#include <memory>

namespace singleton {
class SingletonInterface {
public:
  virtual ~SingletonInterface();
  virtual void do_something() = 0;
};

namespace instance {
  extern std::unique_ptr<SingletonInterface> current;
}

SingletonInterface& get_instance();
void set_instance(std::unique_ptr<SingletonInterface> new_instance);
}
