#pragma one
#include "Factory.h"
class App {
private:
  Factory fac;

public:
  IItem *createItem(std::string str);
};