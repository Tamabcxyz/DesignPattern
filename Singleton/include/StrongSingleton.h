#pragma one
#include <mutex>
#include <string>
#include <thread>
class StrongSingleton {
private:
  static StrongSingleton *instance; // common resources
  static std::mutex mutex_;         // for solve the problem in thread
  std::string name;
  StrongSingleton(){}; // have to put in private to prevent call and created instance
  StrongSingleton(std::string value) : name{value} {};

public:
  StrongSingleton(StrongSingleton &) = delete; // need to delete copy constructor
  StrongSingleton * operator=(StrongSingleton &) = delete; // need to delete copy assignment
  static StrongSingleton * getSingletonInstance(std::string value); // function static to get instance
  std::string getName();
};