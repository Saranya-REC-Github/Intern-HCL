//In a Rectangle class, ensure width and height are always positive via private members + public setters. Use this in setters to throw or clamp values; demonstrate attempts to violate constraints from main().

#include <iostream>
using namespace std;

class Rectangle {
private:
    float width;
    float height;

public:

    void setWidth(float width) {
        if (width <= 0) {
            throw "Width must be positive!";
        }
        this->width = width;
    }

    void setHeight(float height) {
        if (height <= 0) {
            throw "Height must be positive!";
        }
        this->height = height;
    }

    void display() {
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {
    Rectangle r;

    try {
        r.setWidth(5);
        r.setHeight(3);
        r.display();


        r.setWidth(-2);   // ❌ will throw error
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
