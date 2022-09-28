#include "singleton_if.h"
#include <memory>
#include <iostream>

namespace singleton {

class MyInt {
public:
  MyInt(int num) : num_(num) {}
  ~MyInt() { std::cout << "Deleting my int...\n"; }
  int get_num() { return num_; }
private:
  int num_;
};

class NewImpl : public SingletonInterface {
public:
  NewImpl(int number);
  ~NewImpl();

  NewImpl(NewImpl&& oth);
  NewImpl(const NewImpl& oth);

  NewImpl& operator=(NewImpl&& oth);
  NewImpl& operator=(const NewImpl& oth);
  
  void do_something() override;

private:
   std::unique_ptr<MyInt> number_;
};

}