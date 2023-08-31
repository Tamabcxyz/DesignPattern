#pragma one
#include "IShape.h"
class Square : public IShape {
private:
  int size;

public:
  Square(int s) : size(s) {}
  IShape *clone() const override;
  void draw() const override;
};