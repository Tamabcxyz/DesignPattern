#pragma one
#include <iostream>
#include <string>

class Pizza {
private:
  std::string dough_;
  std::string sauce_;
  std::string topping_;

public:
  void setDough(std::string dough);
  void setSauce(std::string sauce);
  void setTopping(std::string topping);
  void disPlay() const;
};