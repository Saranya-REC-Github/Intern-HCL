//phone book using dll
#include <iostream>
#include <algorithm>//swap()
#include <cctype>//tolower()
using namespace std;
// Convert string to lowercase (for sorting)
string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
// Node (Contact)
class Contact {
public:
    string name, phone, email, address, category;
    Contact *prev, *next;
    Contact(string n, string p, string e, string a, string c) {
        name = n;
        phone = p;
        email = e;
        address = a;
        category = c;
        prev = next = NULL;
    }
};
// Head pointer
Contact* head = NULL;
// Add Contact
void addContact() {
    string n, p, e, a, c;
    cout << "\nEnter Name: ";
    cin >> n;
    cout << "Enter Phone: ";
    cin >> p;
    cout << "Enter Email: ";
    cin >> e;
    cout << "Enter Address: ";
    cin >> a;
    cout << "Enter Category(family/friend/work): ";
    cin >> c;
    Contact* newNode = new Contact(n, p, e, a, c);//creating a node
    if (head == NULL) {
        head = newNode;
    } else {
        Contact* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << " Contact Added!\n";
}
// Display Contacts
void displayContacts() {
    if (head == NULL) {
        cout << "\n Phone Book is Empty!\n";
        return;
    }
    Contact* temp = head;
    cout << "\n========== CONTACT LIST ==========\n";
    while (temp != NULL) {
        cout << "\nName: " << temp->name
             << "\nPhone: " << temp->phone
             << "\nEmail: " << temp->email
             << "\nAddress: " << temp->address
             << "\nCategory: " << temp->category << endl;
        temp = temp->next;
    }
}
// Search Contact
void searchContact() {
    string key;
    cout << "\nEnter name to search: ";
    cin >> key;
    Contact* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (toLower(temp->name).find(toLower(key)) != string::npos) {
            cout << "\n Found:\n";
            cout << "Name: " << temp->name
                 << "\nPhone: " << temp->phone
                 << "\nEmail: " << temp->email << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
        cout << " Contact not found!\n";
}
// Update Contact
void updateContact() {
    string name;
    cout << "\nEnter name to update: ";
    cin >> name;
    Contact* temp = head;
    while (temp != NULL) {
        if (toLower(temp->name) == toLower(name)) {
            cout << "Enter new phone: ";
            cin >> temp->phone;
            cout << "Enter new email: ";
            cin >> temp->email;
            cout << "Enter new address: ";
            cin >> temp->address;
            cout << " Updated Successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << " Contact not found!\n";
}
// Delete Contact
void deleteContact() {
    string name;
    cout << "\nEnter name to delete: ";
    cin >> name;
    Contact* temp = head;
    while (temp != NULL) {
        if (toLower(temp->name) == toLower(name)) {
            if (temp == head) {//(deleting head)
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {//(deleting middle/last node)
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            delete temp;
            cout << " Deleted Successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << " Contact not found!\n";
}
// Sort Contacts (Case-insensitive Bubble Sort)
void sortContacts() {
    if (head == NULL) return;
    bool swapped;
    Contact* ptr;
    do {
        swapped = false;
        ptr = head;
        while (ptr->next != NULL) {
            if (toLower(ptr->name) > toLower(ptr->next->name)) {
                // Swap full data
                swap(ptr->name, ptr->next->name);
                swap(ptr->phone, ptr->next->phone);
                swap(ptr->email, ptr->next->email);
                swap(ptr->address, ptr->next->address);
                swap(ptr->category, ptr->next->category);
                swapped = true;
            }
            ptr = ptr->next;
        }
    } while (swapped);
    cout << " Contacts Sorted Alphabetically!\n";
}
// Menu
void menu() {
    cout << "\n=====================================\n";
    cout << "         PHONE BOOK (DLL)\n";
    cout << "=====================================\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Update Contact\n";
    cout << "5. Delete Contact\n";
    cout << "6. Sort Contacts\n";
    cout << "7. Exit\n";
    cout << "=====================================\n";
    cout << "Enter choice: ";
}
// Main
int main() {
    int choice;
    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: sortContacts(); break;
            case 7: cout << "\n Exiting...\n"; break;
            default: cout << " Invalid Choice!\n";
        }
    } while (choice != 7);
    return 0;
}
