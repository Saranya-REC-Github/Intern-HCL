//implement a dynamic array that doubles its size when capacity is exceeded.
#include <iostream>
using namespace std;
class DynamicArray {
    int *arr;
    int size;
    int capacity;
public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }
    void push_back(int value) {
        if (size == capacity) {

            capacity *= 2;
            int *newArr = new int[capacity];


            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;   // free old memory
            arr = newArr;
        }

        arr[size++] = value;
    }


    void display() {
        cout << "Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void info() {
        cout << "Size: " << size << ", Capacity: " << capacity << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray d;

    d.push_back(10);
    d.push_back(20);
    d.info();

    d.push_back(30);
    d.push_back(40);
    d.info();

    d.display();

    return 0;
}
