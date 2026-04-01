//Create strong types for Meters, Seconds, and MetersPerSecond. Implement operator overloading so that dividing Meters by Seconds yields MetersPerSecond. Ensure type safety by omitting overloads that would allow incompatible unit operations.
#include <iostream>
using namespace std;
struct Meters {
    double value;
    explicit Meters(double v) : value(v) {}
};
struct Seconds {
    double value;
    explicit Seconds(double v) : value(v) {}
};
struct MetersPerSecond {
    double value;
    explicit MetersPerSecond(double v) : value(v) {}
};
// Only allow Meters / Seconds
MetersPerSecond operator/(const Meters& m, const Seconds& s) {
    return MetersPerSecond(m.value / s.value);
}
int main() {
    Meters d(100);
    Seconds t(20);
    MetersPerSecond speed = d / t;
    cout << "Speed: " << speed.value << " m/s" << endl;
}
