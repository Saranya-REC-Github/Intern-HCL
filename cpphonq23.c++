//Overload printDiag to accept int, double, std::string, and std::vector<int>. Ensure the vector overload is chosen over the generic template (if added) by using more specific signatures.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printDiag(int x) {
    cout << "Integer: " << x << endl;
}
void printDiag(double d) {
    cout << "Double: " << d << endl;
}
void printDiag(const string& s) {
    cout << "String: " << s << endl;
}
void printDiag(const vector<int>& v) {
    cout << "Vector: ";
    for(int val : v) cout << val << " ";
    cout << endl;
}
int main() {
    printDiag(42);
    printDiag(3.14);
    printDiag("Hello");
    printDiag(vector<int>{1,2,3,4});
}
