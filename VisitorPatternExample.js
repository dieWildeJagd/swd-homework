// Constructor function for Book, a Visitable object.
function Book(title) {
    this.title = title; // Initialize book's title.
}

// Method to accept a visitor, calls the visitor's method for Book.
Book.prototype.accept = function(visitor) {
    visitor.visitBook(this);
};

// Constructor function for Fruit, a Visitable object.
function Fruit(name) {
    this.name = name; // Initialize fruit's name.
}

// Method to accept a visitor, calls the visitor's method for Fruit.
Fruit.prototype.accept = function(visitor) {
    visitor.visitFruit(this);
};

// Constructor function for Visitor, defines visiting behavior.
function Visitor() {}

// Method to visit Book objects.
Visitor.prototype.visitBook = function(book) {
    console.log("Visiting book: " + book.title);
};

// Method to visit Fruit objects.
Visitor.prototype.visitFruit = function(fruit) {
    console.log("Visiting fruit: " + fruit.name);
};

// Example usage of the Visitor pattern.
const book = new Book("Design Patterns"); // Create a Book object.
const fruit = new Fruit("Apple"); // Create a Fruit object.
const visitor = new Visitor(); // Create a Visitor object.

book.accept(visitor); // Have the visitor visit the book.
fruit.accept(visitor); // Have the visitor visit the fruit.
