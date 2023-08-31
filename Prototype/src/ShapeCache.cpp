#include "ShapeCache.h"
IShape *ShapeCache::getShape(const std::string &type) {
  return cache[type]->clone();
}
void ShapeCache::loadCache() {
  // init cache
  cache["circle"] = new Circle(5);
  cache["square"] = new Square(10);
}