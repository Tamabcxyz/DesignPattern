#include "Square.h"
#include <iostream>
IShape *Square::clone() const { return new Square(*this); }
void Square::draw() const {
  std::cout << "Draw from Square size is: " << size << std::endl;
}