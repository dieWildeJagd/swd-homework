// Visitor interface declares visit methods for each type of Visitable.
interface Visitor {
    void visit(Book book);
    void visit(Fruit fruit);
}

// Concrete implementation of Visitor. Implements behavior for each visitable type.
class ConcreteVisitor implements Visitor {
    // Method for visiting Book objects.
    public void visit(Book book) {
        System.out.println("Visiting book: " + book.getTitle());
    }
    // Method for visiting Fruit objects.
    public void visit(Fruit fruit) {
        System.out.println("Visiting fruit: " + fruit.getName());
    }
}

// Visitable interface declares an accept method that takes a Visitor.
interface Visitable {
    void accept(Visitor visitor);
}

// Concrete implementation of Visitable representing a Book.
class Book implements Visitable {
    private String title; // Book's title.
    
    // Constructor initializes the title.
    public Book(String title) {
        this.title = title;
    }
    
    // Getter for the title.
    public String getTitle() {
        return title;
    }
    
    // Accept method calls visit on the visitor, passing this instance.
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

// Concrete implementation of Visitable representing a Fruit.
class Fruit implements Visitable {
    private String name; // Fruit's name.
    
    // Constructor initializes the name.
    public Fruit(String name) {
        this.name = name;
    }
    
    // Getter for the name.
    public String getName() {
        return name;
    }
    
    // Accept method calls visit on the visitor, passing this instance.
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }
}

// Example usage of the Visitor pattern.
public class VisitorPatternExample {
    public static void main(String[] args) {
        // Create a concrete visitor.
        Visitor visitor = new ConcreteVisitor();
        
        // Create visitable objects.
        Visitable book = new Book("Design Patterns");
        Visitable fruit = new Fruit("Apple");
        
        // Have the visitor visit each object.
        book.accept(visitor);
        fruit.accept(visitor);
    }
}