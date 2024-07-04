#include <iostream>
#include <string>

// Forward declarations of visitable classes to be used in Visitor interface.
class Book;
class Fruit;

// Visitor interface declares visit methods for each type of Visitable.
class Visitor {
public:
    virtual void visit(Book* book) = 0; // Pure virtual method for Book.
    virtual void visit(Fruit* fruit) = 0; // Pure virtual method for Fruit.
};

// Visitable interface declares an accept method that takes a Visitor.
class Visitable {
public:
    virtual void accept(Visitor* visitor) = 0; // Pure virtual method for accept.
};

// Concrete implementation of Visitable representing a Book.
class Book : public Visitable {
    std::string title; // Book's title.
public:
    // Constructor initializes the title.
    Book(const std::string& title) : title(title) {}
    
    // Getter for the title.
    std::string getTitle() const { return title; }
    
    // Accept method calls visit on the visitor, passing this instance.
    void accept(Visitor* visitor) override { visitor->visit(this); }
};

// Concrete implementation of Visitable representing a Fruit.
class Fruit : public Visitable {
    std::string name; // Fruit's name.
public:
    // Constructor initializes the name.
    Fruit(const std::string& name) : name(name) {}
    
    // Getter for the name.
    std::string getName() const { return name; }
    
    // Accept method calls visit on the visitor, passing this instance.
    void accept(Visitor* visitor) override { visitor->visit(this); }
};

// Concrete implementation of Visitor. Implements behavior for each visitable type.
class ConcreteVisitor : public Visitor {
public:
    // Method for visiting Book objects.
    void visit(Book* book) override {
        std::cout << "Visiting book: " << book->getTitle() << std::endl;
    }
    // Method for visiting Fruit objects.
    void visit(Fruit* fruit) override {
        std::cout << "Visiting fruit: " << fruit->getName() << std::endl;
    }
};

// Example usage of the Visitor pattern.
int main() {
    // Create a concrete visitor.
    ConcreteVisitor visitor;
    
    // Create visitable objects.
    Book book("Design Patterns");
    Fruit fruit("Apple");
    
    // Have the visitor visit each object.
    book.accept(&visitor);
    fruit.accept(&visitor);
    
    return 0;
}
