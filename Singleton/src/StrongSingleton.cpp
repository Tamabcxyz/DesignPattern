#include "StrongSingleton.h"
StrongSingleton *StrongSingleton::getSingletonInstance(std::string value) {
  if (instance == nullptr) {
    std::lock_guard<std::mutex> lock(mutex_); // to make sure one instance created at that time
    if (instance == nullptr) {
      instance = new StrongSingleton(value);
    }
  }
  return instance;
}
std::string StrongSingleton::getName() { return name; }