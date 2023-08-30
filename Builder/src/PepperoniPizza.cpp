#include "PepperoniPizza.h"
void PepperoniPizza::buildDough(std::string dough) { pizza_.setDough(dough); }
void PepperoniPizza::buildSauce(std::string sauce) { pizza_.setSauce(sauce); }
void PepperoniPizza::buildTopping(std::string topping) {
  pizza_.setTopping(topping);
}
Pizza PepperoniPizza::getPizza() { return pizza_; }