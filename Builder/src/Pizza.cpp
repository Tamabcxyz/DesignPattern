#include "Pizza.h"
void Pizza::setDough(std::string dough) { dough_ = dough; }
void Pizza::setSauce(std::string sauce) { sauce_ = sauce; }
void Pizza::setTopping(std::string topping) { topping_ = topping; }
void Pizza::disPlay() const {
  std::cout << "Dough: " << dough_ << ", Sauce: " << sauce_ << ", Topping: " << topping_ << std::endl;
}