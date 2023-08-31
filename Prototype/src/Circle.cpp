#include "Circle.h"
#include <iostream>
IShape *Circle::clone() const { return new Circle(*this); }
void Circle::draw() const {
  std::cout << "Draw from Circle radius is: " << radius << std::endl;
}