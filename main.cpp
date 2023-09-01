#include "config.h"
#include <iostream>
#ifdef ADAPTER_DP
#include "Adapter.h"
#elifdef FACTORYMETHOD_DP
#include "App.h"
#elifdef ABSTRACTFACTORY_DP
#include "LinuxTemplate.h"
#include "WindowTemplate.h"
#elifdef BUILDER_DP
#include "PepperoniPizza.h"
#include "SausagePizza.h"
#include "Shipper.h"
#elifdef PROTOTYPE_DP
#include "ShapeCache.h"
#elifdef SINGLETON_DP
#include "StrongSingleton.h"
#include "WeakSingleton.h"
#endif

using namespace std;

#ifdef ADAPTER_DP
void ClientCode(const Target *target) {
  std::cout << target->request() << std::endl;
}
#elifdef SINGLETON_DP
// case one: WeakSingleton
WeakSingleton *WeakSingleton::instance = nullptr; // have to initial in global

void processOne() {
  WeakSingleton *instance = WeakSingleton::getSingletonInstance("Bob");
  std::cout << instance->getName() << std::endl;
}
void processTwo() {
  WeakSingleton *instance = WeakSingleton::getSingletonInstance("Bi");
  std::cout << instance->getName() << std::endl;
}

// case two: StrongSingleton
StrongSingleton *StrongSingleton::instance = nullptr;
mutex StrongSingleton::mutex_;
void processThree() {
  StrongSingleton *instance = StrongSingleton::getSingletonInstance("Bob");
  std::cout << instance->getName() << std::endl;
}
void processFour() {
  StrongSingleton *instance = StrongSingleton::getSingletonInstance("Bi");
  std::cout << instance->getName() << std::endl;
}
#endif

int main() {
#ifdef ADAPTER_DP
  Target *t = new Target;
  ClientCode(t); // Target: The default target's behavior.
  // client code using SpecificRequest via the Adapter
  Adaptee *adaptee = new Adaptee;
  Adapter *adap = new Adapter(adaptee);
  ClientCode(adap); // Adapter: (TRANSLATED) Special behavior of the Adaptee
#elifdef FACTORYMETHOD_DP
  App app;
  auto object = app.createItem("IPhone14");
  object->print_object();
#elifdef ABSTRACTFACTORY_DP
  std::unique_ptr<IAbstractFactory> gf;
  gf = std::make_unique<LinuxTemplate>();
  auto button = gf->createButton();
  auto checkbox = gf->createCheckbox();
  button->pain();   // LinuxButton
  checkbox->pain(); // LinuxCheckBox

  gf = std::make_unique<WindowTemplate>();
  button = gf->createButton();
  checkbox = gf->createCheckbox();
  button->pain();   // WindowButton
  checkbox->pain(); // WindowCheckbox
#elifdef BUILDER_DP
  Shipper shipper;

  PepperoniPizza pp;
  pp.buildDough("PepperoniPizza dough");
  pp.buildSauce("PepperoniPizza sauce");
  pp.buildTopping("PepperoniPizza topping");
  shipper.setPizza(&pp);
  Pizza tm = shipper.getPizza();
  tm.disPlay();

  SausagePizza sp;
  sp.buildDough("SausagePizza dough");
  sp.buildSauce("SausagePizza sauce");
  sp.buildTopping("SausagePizza topping");
  sp.displaySpecialIngredient();
  shipper.setPizza(&sp);
  Pizza ti = shipper.getPizza();
  ti.disPlay();
#elifdef PROTOTYPE_DP
  ShapeCache sc;
  sc.loadCache();

  IShape *c = sc.getShape("circle");
  IShape *s = sc.getShape("square");

  c->draw();
  s->draw();

  delete c;
  delete s;
#elifdef SINGLETON_DP
  // case one: WeakSingleton class
  // std::thread t1(processOne);
  // std::thread t2(processTwo);
  // t1.join();
  // t2.join();
  // => this is a weak of singleton in multiple thread. when you run many time
  // at some time it will be print out "Bob" and "Bi"

  // case two: StrongSingleton class
  std::thread t1(processThree);
  std::thread t2(processFour);
  t1.join();
  t2.join();
  // => Only print out "Bob" or "Bi"
#else
  std::cout << "Check option CMakeLists.txt" << std::endl;
#endif
  return 0;
}