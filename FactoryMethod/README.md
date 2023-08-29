#### Factory method pattern: is a creational design pattern that provides **an interface for creating objects in a superclass**, but allows **subclasses to alter the type of objects that will be created** (purposely separate service and app. When I have more subclasses, it does not affect the App class).

Scenario code:
As you know we have many type of Iphone so need to create IItem. it's an interface now Iphone or ... can inherit from IItem. After that create a Factory to collect all subclasses. 

Note:
In class IItem #prama one can't use (error redefine) it's just work with #ifndef
Can't seperate .h, .cpp file when using factory method (that's weakness of prama one)