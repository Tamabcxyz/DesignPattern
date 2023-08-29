#### Adapter pattern: is a structural design pattern that allows objects with incompatible interfaces to collaborate.

Scenario code:
Basicly, Client using Target class (request method), but Adaptee have class call specificRequest and Client wanna use it. Approach create Adapter class inheritant from Target and implement new request method