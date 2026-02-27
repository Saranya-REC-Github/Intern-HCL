#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int choice;
    string orderID;
    float amount;

    do {
        cout << "\n===== ONLINE SHOPPING SYSTEM =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Generate Finance Report\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                ofstream fout1("orderID.txt", ios::app);
                ofstream fout2("amount.txt", ios::app);

                cout << "Enter Order ID: ";
                cin >> orderID;

                cout << "Enter Order Amount: ";
                cin >> amount;

                fout1 << orderID << endl;
                fout2 << amount << endl;

                fout1.close();
                fout2.close();

                cout << "Order added successfully!\n";
                break;
            }

            case 2: {
                ifstream fin1("orderID.txt");
                ifstream fin2("amount.txt");

                cout << "\n----- FINANCE REPORT -----\n";

                while (fin1 >> orderID && fin2 >> amount) {
                    cout << "Order: " << orderID
                         << " | Amount Paid: Rs. "
                         << amount << endl;
                }

                fin1.close();
                fin2.close();
                break;
            }

            case 3:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}
