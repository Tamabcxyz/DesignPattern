#pragma one
#include <string>
#include <algorithm>
#include "Target.h"
#include "Adaptee.h"
// Client wanna use specificRequest in Adaptee that's reason why this class created
class Adapter : public Target {
 private:
  Adaptee *adaptee_;

 public:
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
  std::string request() const override;
};