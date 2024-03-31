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
#elifdef BASICKNOWDGE
#include "SingleResponsibilityPrinciple.h"
#include "OpenClosedPriciple.h"
#include "LiskovSubstitutionPrinciple.h"
#include "InterfaceSegregationPrinciple.h"
#include "DependencyInversionPrinciple.h"
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
#elifdef BASICKNOWDGE
  
  //Single responsibility principle
  Journal journal{"Dear Diary"};
  journal.add("I ate a bug");
  journal.add("I cried today");
  PersistenceManager::save(journal, "diary.txt");
  
  /*
  //Open-Closed principle
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  const vector<Product*> all { &apple, &tree, &house };

  BetterFilter bf;
  ColorSpecification green(Color::green);
  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green\n";


  SizeSpecification large(Size::large);
  AndSpecification<Product> green_and_large(green, large);

  //auto big_green_things = bf.filter(all, green_and_large);

  // use the operator instead (same for || etc.)
  auto spec = green && large;
  for (auto& x : bf.filter(all, spec))
    cout << x->name << " is green and large\n";

  // warning: the following will compile but will NOT work
  // auto spec2 = SizeSpecification{Size::large} &&
  //              ColorSpecification{Color::blue};
  */
  /*
  // Liskov Substitution Principle
  Rectangle r{ 5,5 };
  process(r);

  Square s{ 5 };
  process(s);
  */

  /*
    //Interface Segregation principle

  */
  /*
  //Dependency Inversion Principle
  Person parent{"John"};
  Person child1{"Chris"};
  Person child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);
  */
#else
  std::cout << "Check option CMakeLists.txt" << std::endl;
#endif
  return 0;
}