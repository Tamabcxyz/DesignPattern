#include <iostream>
#include "Adapter.h"
using namespace std;
// Client using Request from Target
void ClientCode(const Target *target) {
  std::cout << target->request() << std::endl;
}
int main(){
    Target *t = new Target;
    ClientCode(t); // Target: The default target's behavior.
    // client code using SpecificRequest via the Adapter 
    Adaptee *adaptee = new Adaptee;
    Adapter *adap = new Adapter(adaptee);
    ClientCode(adap); // Adapter: (TRANSLATED) Special behavior of the Adaptee.

    return 0;
}