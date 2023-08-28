#include <iostream>
#include "Target.h"
using namespace std;
// Client using Request from Target
void ClientCode(const Target *target) {
  std::cout << target->Request() << std::endl;
}
int main(){
    Target *t = new Target;
    ClientCode(t); // Target: The default target's behavior.
    return 0;
}