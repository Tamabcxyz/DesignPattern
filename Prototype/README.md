##### Prototype pattern: is a creational design pattern that lets you **copy existing objects**  without making your code dependent on their classes.
Scenario code:
IShape interface have a virtual method call clone (this method return Ishape). Circle and Square classed inherit from IShape and implement method clone. ShapeCache is a class normal it's using for save shape cache have method loadCache (for initial cache), getShape (for get Shape base on string input).