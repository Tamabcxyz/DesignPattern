#include "WeakSingleton.h"
WeakSingleton *WeakSingleton::getSingletonInstance(std::string value) {
  if (instance == nullptr) {
    instance = new WeakSingleton(value);
  }
  return instance;
}
std::string WeakSingleton::getName() { return name; }