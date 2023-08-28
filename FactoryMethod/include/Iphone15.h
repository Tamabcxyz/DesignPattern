#pragma once
#include "IItem.h"
using namespace std;
class IItem;
class Iphone15 : public IItem {
public:
  void print_object() const override;
};