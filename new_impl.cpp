#include "new_impl.h"
#include <iostream>

namespace singleton {

NewImpl::NewImpl(int number) : number_(std::make_unique<MyInt>(number)) {
  std::cout << "New Impl C-ctor\n";
}

NewImpl::~NewImpl() {
  std::cout << "New Impl D-ctor\n";  
}

NewImpl::NewImpl(NewImpl&& oth) {
  std::cout << "New Impl Move C-ctor\n";
}

NewImpl::NewImpl(const NewImpl& oth) {
  std::cout << "New Impl Copy C-ctor\n";
}

NewImpl& NewImpl::operator=(NewImpl&& oth) {
  std::cout << "New Impl move operator=\n";
}

NewImpl& NewImpl::operator=(const NewImpl& oth) {
  std::cout << "New Impl operator=\n";
}
  
void NewImpl::do_something(){ 
  std::cout << "Number: " << number_->get_num() << "\n";
};

}