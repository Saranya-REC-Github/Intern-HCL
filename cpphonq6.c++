//Create a menu-driven program using do-while for repeated user input until exit.

#include <iostream>
using namespace std;

int main() {
    int choice, a, b;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a + b << endl;
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a - b << endl;
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a * b << endl;
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);
    return 0;
}
