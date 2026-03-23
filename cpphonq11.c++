//Write a recursive function to calculate the factorial of a number and compare with iterative approach.
#include <iostream>
using namespace std;
// Recursive function
int fact_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact_recursive(n - 1);
}
// Iterative function
int fact_iterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial (Recursive) = " << fact_recursive(n) << endl;
    cout << "Factorial (Iterative) = " << fact_iterative(n) << endl;

    return 0;
}
