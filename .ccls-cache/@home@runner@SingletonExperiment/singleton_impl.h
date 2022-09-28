#pragma once

#include "singleton_if.h"

namespace singleton {

class SingletonImpl : public SingletonInterface {
public:
  SingletonImpl();
  ~SingletonImpl();

  SingletonImpl(SingletonImpl&& oth);
  SingletonImpl(const SingletonImpl& oth);

  SingletonImpl& operator=(SingletonImpl&& oth);
  SingletonImpl& operator=(const SingletonImpl& oth);
  
  void do_something() override;
};

}