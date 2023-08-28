#include "Factory.h"

IItem *Factory::createIphone(std::string str) {
  // if(str =="IPhone14"){ return new Iphone14; }
  // if(str =="IPhone15"){ return new Iphone15; }
  // return nullptr;
  IItem *item = nullptr;
  if (str == "IPhone14") {
    item = new Iphone14;
  }
  if (str == "IPhone15") {
    item = new Iphone15;
  }
  return item;
}