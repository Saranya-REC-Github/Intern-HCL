//Create a Book class: isbn, title, author. Provide print() and updateTitle(const std::string&). Demonstrate creating objects via default constructor and setting fields through setters (or public methods) only.
#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string isbn;
    string title;
    string author;
public:
    // Default constructor
    Book() {}
    // Setters
    void setISBN(const string& i) {
     isbn = i;
    }
    void setTitle(const string& t) {
    title = t;
    }
    void setAuthor(const string& a) {
     author = a;
     }
    // Update title
    void updateTitle(const string& newTitle) {
    title = newTitle;
    }

    // Print details
    void print() {
        cout << "ISBN: " << isbn << ", Title: " << title << ", Author: " << author << endl;
    }
};
int main() {
    Book b;
    b.setISBN("12345");
    b.setTitle("C++ Basics");
    b.setAuthor("Saranya");
    b.print();
    b.updateTitle("Advanced C++");
    b.print();
}
