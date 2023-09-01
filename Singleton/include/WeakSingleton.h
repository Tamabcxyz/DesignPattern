#pragma one
#include <string>
#include <thread>
class WeakSingleton {
private:
  static WeakSingleton *instance; // common resources
  std::string name;
  WeakSingleton(){}; // have to put in private to prevent call and created instance
  WeakSingleton(std::string value) : name{value} {};

public:
  WeakSingleton(WeakSingleton &) = delete;            // need to delete copy constructor
  WeakSingleton *operator=(WeakSingleton &) = delete; // need to delete copy assignment
  static WeakSingleton *getSingletonInstance(std::string value); // function static to get instance
  std::string getName();
};