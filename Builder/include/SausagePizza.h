#pragma one
#include "IPizzaBuilder.h"
class SausagePizza : public PizzaBuilder {
private:
  Pizza pizza_;
  std::string specialIngredient = "specialIngredient";

public:
  void buildDough(std::string dough) override;
  void buildSauce(std::string sauce) override;
  void buildTopping(std::string topping) override;
  Pizza getPizza() override;
  void displaySpecialIngredient() const;
};