//Create classes: Teacher + Researcher → Professor
//Demonstrate multiple inheritance and method overriding.
#include <iostream>
using namespace std;
class Teacher {
public:
    virtual void work() {
    cout << "Teaching students\n"; }
};
class Researcher {
public:
    virtual void work() {

    cout << "Doing research\n"; }
};
class Professor : public Teacher, public Researcher {
public:
    void work() override { cout << "Professor: Teaching and Researching\n"; }
};
int main() {
    Professor p;
    p.work();
}
