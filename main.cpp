#include "config.h"
#include <iostream>
#ifdef ADAPTER_DP
#include "Adapter.h"
#elifdef FACTORYMETHOD_DP
#include "App.h"
#elifdef ABSTRACTFACTORY_DP
#include "LinuxTemplate.h"
#include "WindowTemplate.h"
#endif

using namespace std;

#ifdef ADAPTER_DP
void ClientCode(const Target *target) {
  std::cout << target->request() << std::endl;
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
  button->pain();// LinuxButton
  checkbox->pain();// LinuxCheckBox

  gf = std::make_unique<WindowTemplate>();
  button = gf->createButton();
  checkbox = gf->createCheckbox();
  button->pain();// WindowButton
  checkbox->pain();// WindowCheckbox
#else
  std::cout << "Check option CMakeLists.txt" << std::endl;
#endif
  return 0;
}