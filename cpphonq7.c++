//Write a function to swap two integers using pointers.
#include <iostream>
using namespace std;

// Function to swap using pointers
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    swap(&a, &b);   // passing addresses

    cout << "After swapping:\n";
    cout << "a = " << a << " b = " << b;

    return 0;
}
