//Implement Matrix with rows/cols and initialize elements via std::initializer_list. Show different construction styles and confirm destructor frees memory correctly.
#include <iostream>
#include <initializer_list>
using namespace std;

class Matrix {
    int rows, cols;
    int** data;

public:
    // Default constructor
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // Constructor with size
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]{0};
        }
    }

    // Constructor using initializer_list
    Matrix(initializer_list<initializer_list<int>> list) {
        rows = list.size();
        cols = list.begin()->size();

        data = new int*[rows];

        int i = 0;
        for (auto row : list) {
            data[i] = new int[cols];
            int j = 0;
            for (auto val : row) {
                data[i][j++] = val;
            }
            i++;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        cout << "Memory freed (Destructor called)\n";
    }
};

int main() {


    Matrix m1;
    Matrix m2(2, 3);
    cout << "Matrix m2:\n";
    m2.display();
    Matrix m3 = {{1, 2, 3}, {4, 5, 6}};
    cout << "\nMatrix m3:\n";
    m3.display();

    return 0;
}
