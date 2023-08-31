#ifndef ISHAPE_H
#define ISHAPE_H
class IShape {
public:
  virtual ~IShape() {}
  virtual IShape *clone() const = 0;
  virtual void draw() const = 0;
};
#endif