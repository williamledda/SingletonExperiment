#include "singleton_impl.h"
#include <iostream>

namespace singleton {

SingletonImpl::SingletonImpl() {
  std::cout << "Default C-tor\n";
}
SingletonImpl::~SingletonImpl() {
  std::cout << "Default D-tor\n";
}

SingletonImpl::SingletonImpl(SingletonImpl&& oth) {
  std::cout << "Move C-tor\n";
}

SingletonImpl::SingletonImpl(const SingletonImpl& oth) {
  std::cout << "Copy C-tor\n";
}

SingletonImpl& SingletonImpl::operator=(SingletonImpl&& oth) {
  std::cout << "Move assignement operator\n";
  return *this;
}

SingletonImpl& SingletonImpl::operator=(const SingletonImpl& oth) {
  std::cout << "Assignement operator C-tor\n";
  return *this;
}

void SingletonImpl::do_something() {
  std::cout << "Some dummy stuff\n";
}

}