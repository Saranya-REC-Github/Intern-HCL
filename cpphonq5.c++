//Demonstrate AND, OR, XOR, and shift operations on two integers.
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Bitwise AND (a & b) = " << a & b << endl;
    cout << "Bitwise OR (a | b) = " << a | b << endl;
    cout << "Bitwise XOR (a ^ b) = " << (a ^ b) << endl;
    cout << "Left Shift (a << 1) = " << (a << 1) << endl;
    cout << "Right Shift (a >> 1) = " << (a >> 1) << endl;
    return 0;
}
