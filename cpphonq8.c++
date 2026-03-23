//Create a structure Order containing another structure Customer. Display complete order details.
#include <iostream>
using namespace std;
struct Customer {
    int id;
    string name;
    string city;
};
struct Order {
    int orderId;
    string product;
    float amount;
    Customer cust;
};
int main() {
    Order o;
    cout << "Enter Customer ID: ";
    cin >> o.cust.id;
    cout << "Enter Customer Name: ";
    cin >> o.cust.name;
    cout << "Enter Customer City: ";
    cin >> o.cust.city;
    cout << "Enter Order ID: ";
    cin >> o.orderId;
    cout << "Enter Product Name: ";
    cin >> o.product;
    cout << "Enter Amount: ";
    cin >> o.amount;
    cout << "\n--- Order Details ---\n";
    cout << "Customer ID: " << o.cust.id << endl;
    cout << "Customer Name: " << o.cust.name << endl;
    cout << "Customer City: " << o.cust.city << endl;
    cout << "Order ID: " << o.orderId << endl;
    cout << "Product: " << o.product << endl;
    cout << "Amount: " << o.amount << endl;
    return 0;
}
