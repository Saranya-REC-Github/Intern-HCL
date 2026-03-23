//Create an Order class that owns a collection of line items (IDs and quantities). Provide addLineItem(int id, int qty) and totalItems(); show object creation, modification, and summary printing.
#include <iostream>
using namespace std;

struct LineItem {
    int id;
    int qty;
};

class Order {
    LineItem items[100];
    int count;

public:

    Order() {
        count = 0;
    }


    void addLineItem(int id, int qty) {
        items[count].id = id;
        items[count].qty = qty;
        count++;
    }


    int totalItems() {
        int total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i].qty;
        }
        return total;
    }

    void display() {
        cout << "\n--- Order Summary ---\n";
        for (int i = 0; i < count; i++) {
            cout << "Item ID: " << items[i].id
                 << ", Quantity: " << items[i].qty << endl;
        }
        cout << "Total Items: " << totalItems() << endl;
    }
};

int main() {

    Order o;
    o.addLineItem(101, 2);
    o.addLineItem(102, 5);
    o.addLineItem(103, 3);
    o.display();
    return 0;
}
