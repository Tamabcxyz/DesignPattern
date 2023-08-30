#pragma one
#include "IPizzaBuilder.h"
class PepperoniPizza : public PizzaBuilder {
private:
  Pizza pizza_;

public:
  void buildDough(std::string dough) override;
  void buildSauce(std::string sauce) override;
  void buildTopping(std::string topping) override;
  Pizza getPizza() override;
};