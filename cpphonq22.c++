/*1.	Overload distance to compute:
•	Between two points (double x1, double y1, double x2, double y2)
•	Between two Point objects
•	Between a Point and the origin (single parameter)
*/
#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
};

// Overload 1: Between two coordinates
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

// Overload 2: Between two Point objects
double distance(const Point& p1, const Point& p2) {
    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

// Overload 3: Between a Point and origin
double distance(const Point& p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

int main() {
    Point p1(3,4), p2(6,8);

    cout << "Distance (coords): " << distance(0,0,3,4) << endl;
    cout << "Distance (points): " << distance(p1,p2) << endl;
    cout << "Distance (origin): " << distance(p1) << endl;
}
