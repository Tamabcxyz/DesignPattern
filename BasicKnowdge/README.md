#### Some basic knowdge before learn design pattern SOLID
SOLID is an acronym that represents a set of five design principles in object-oriented programming intended to make software designs more understandable, flexible, and maintainable.           
##### Single responsibility principle: 
The Single Responsibility Principle (SRP) is a fundamental concept in software development and is one of the five SOLID principles of object-oriented programming.              
1.Single Responsibility: A class should encapsulate one and only one responsibility. It should have a single purpose or reason to exist.                        
2.Separation of Concerns: The principle encourages separating different aspects or concerns of a system into their own classes or modules. This separation improves code maintainability, testability, and flexibility.                     
3.High Cohesion: SRP promotes high cohesion within classes, meaning that the elements within a class should be closely related and focused on fulfilling the class's single responsibility.                 
4.Low Coupling: By having classes with single responsibilities, the dependencies between classes are minimized, leading to low coupling. This makes the system easier to maintain, extend, and refactor.                
5.Refactoring and Maintenance: Following SRP makes code easier to understand, refactor, and maintain.               
6.Domain Modeling: SRP is essential in domain modeling to ensure that classes accurately represent real-world entities and responsibilities.                

##### Open-Closed principle
The Open-Closed Principle (OCP) is one of the five SOLID principles of object-oriented design, formulated by Bertrand Meyer. It states that software entities (classes, modules, functions, etc.) should be open for extension but closed for modification.
1.Maintainability: Since existing code remains unchanged, there's less risk of introducing bugs or unintended side effects when adding new features.
2.Scalability: Your software becomes more flexible and easier to scale, as new functionality can be added without impacting existing code.
3.Reusability: Components designed according to the OCP are often more modular and can be reused in different contexts, leading to better code reuse.
4.Testability: With clearly defined interfaces and separate components, it becomes easier to write unit tests for individual pieces of functionality.
##### Liskov Substition principle
The Liskov Substitution Principle can be summarized as follows:
1.Behavioral Substitutability: Subtypes should be substitutable for their base types without altering the correctness of the program.
2.Inheritance Should Reflect "is-a" Relationship: Subclasses should extend the functionality of their superclasses and adhere to the "is-a" relationship. For example, if Dog is a subtype of Animal, then Dog should inherit from Animal only if it truly is a type of Animal.
3.Postconditions Cannot Be Weakened: Subclasses should not weaken the preconditions of the methods they override or strengthen the postconditions. In other words, a subclass method should require no more and promise no less than the corresponding method in the superclass.
By adhering to the Liskov Substitution Principle, you can achieve several benefits:
Improved Code Reusability: Subclasses can be used interchangeably with their superclasses, allowing for greater code reuse.
Easier Maintenance and Refactoring: The principle promotes a more consistent and predictable behavior across subclasses, making it easier to maintain and refactor the codebase.
Enhanced Flexibility and Extensibility: Subclasses can be added or modified without affecting existing code, providing greater flexibility and extensibility.
##### Interface Segregation principle

##### Dependency Inversion principle
