#pragma one
#include "Circle.h"
#include "Square.h"
#include <string>
#include <unordered_map>
class ShapeCache {
private:
  std::unordered_map<std::string, IShape *> cache;

public:
  IShape *getShape(const std::string &type);
  void loadCache();
};