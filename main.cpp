#include "config.h"
#include <iostream>
#ifdef ADAPTER_DP
#include "Adapter.h"
#elifdef FACTORYMETHOD_DP
#include "App.h"
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
#else
  std::cout << "Check option CMakeLists.txt" << std::endl;
#endif
  return 0;
}