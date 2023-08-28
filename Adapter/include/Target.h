#pragma one
#include <string>

class Target {
public:
  virtual ~Target() = default;
  virtual std::string Request() const;
};