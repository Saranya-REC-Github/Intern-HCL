//Use typedef or using to create an alias for a structure and demonstrate usage.
#include <iostream>
using namespace std;
struct Student {
    int id;
    string name;
};
using Stu = Student;

int main() {
    Stu s;

    cout << "Enter ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "\nStudent Details:\n";
    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.name << endl;

    return 0;
}
