#pragma one
#include "Iphone14.h"
#include "Iphone15.h"
#include <string>
class Factory {
public:
  IItem *createIphone(std::string str);
};