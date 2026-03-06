/* Write a program to:
       Read a string and display its length.
       Convert it to uppercase without using built-in functions.*/
#include <iostream>
#include<string>
using namespace std;
int main() {
    char str[100];
    int length = 0;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    while (str[length] != '\0') {
        length++;
    }
    cout << "Length of the string: " << length << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    cout << "String in uppercase: " << str << endl;
    return 0;
}
