#include "Shipper.h"
void Shipper::setPizza(PizzaBuilder *builder) { builder_ = builder; }
Pizza Shipper::getPizza() { return builder_->getPizza(); }