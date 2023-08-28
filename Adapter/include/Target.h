#pragma one
#include <string>
// Target have request and client using it now
class Target {
public:
  virtual ~Target() = default;
  virtual std::string request() const;
};