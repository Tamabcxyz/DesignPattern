#ifndef PIZZABUILDER_H
#define PIZZABUILDER_H
#include "Pizza.h"
class PizzaBuilder {
public:
  virtual void buildDough(std::string dough) = 0;
  virtual void buildSauce(std::string sauce) = 0;
  virtual void buildTopping(std::string topping) = 0;
  virtual Pizza getPizza() = 0;
};
#endif