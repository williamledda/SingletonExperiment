#pragma once

#include "singleton_if.h"

namespace singleton {

class SingletonImpl : public SingletonInterface {
public:
  void do_something() override;
};
}