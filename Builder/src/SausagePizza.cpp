#include "SausagePizza.h"
void SausagePizza::buildDough(std::string dough) { pizza_.setDough(dough); }
void SausagePizza::buildSauce(std::string sauce) { pizza_.setSauce(sauce); }
void SausagePizza::buildTopping(std::string topping) {
  pizza_.setTopping(topping);
}
Pizza SausagePizza::getPizza() { return pizza_; }
void SausagePizza::displaySpecialIngredient() const {
  std::cout << "SausagePizza have a special ingredient: " << specialIngredient << std::endl;
}