//Create a base class Employee with name and salary. Derive Manager that adds department. Implement a function to display all details.
#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    double salary;
public:
    Employee(const string& n, double s) : name(n), salary(s) {}
    virtual void display() {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};
class Manager : public Employee {
private:
    string department;

public:
    Manager(const string& n, double s, const string& d) : Employee(n, s), department(d) {}
    void display() override {
        cout << "Name: " << name << ", Salary: " << salary << ", Department: " << department << endl;
    }
};
int main() {
    Manager m("Saranya", 50000, "IT");
    m.display();
}
