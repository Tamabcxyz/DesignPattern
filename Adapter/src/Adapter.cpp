#include "Adapter.h"
std::string Adapter::request() const {
  std::string to_reverse = this->adaptee_->specificRequest();
  std::reverse(to_reverse.begin(), to_reverse.end());
  return "Adapter: (TRANSLATED) " + to_reverse;
}