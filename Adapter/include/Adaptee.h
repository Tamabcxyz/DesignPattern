#pragma one
#include <string>

// Adaptee have SpecificRequest and client wanna using it
class Adaptee {
 public:
  std::string specificRequest() const;
};