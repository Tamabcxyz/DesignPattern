#pragma one
#include "IPizzaBuilder.h"
class Shipper {
private:
  PizzaBuilder *builder_;

public:
  void setPizza(PizzaBuilder *builder);
  Pizza getPizza();
};