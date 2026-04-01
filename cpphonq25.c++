//Create Counter supporting both ++c and c++. Return references/temporaries properly. Demonstrate differences in expression contexts (e.g., int x = c++ vs. int y = ++c).
#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter(int v=0) : value(v) {}

    // Prefix ++c
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix c++
    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }

    int getValue() const { return value; }

    // Conversion operator to int
    operator int() const { return value; }
};

int main() {
    Counter c(5);

    int x = c++; // Postfix: x gets old value, c increments
    cout << "x = " << x << ", c = " << c.getValue() << endl;

    int y = ++c; // Prefix: c increments first, y gets new value
    cout << "y = " << y << ", c = " << c.getValue() << endl;

    return 0;
}
