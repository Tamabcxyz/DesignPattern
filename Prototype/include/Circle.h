#pragma one
#include "IShape.h"
class Circle : public IShape {
private:
  int radius;

public:
  Circle(int r) : radius(r) {}
  IShape *clone() const override;
  void draw() const override;
};