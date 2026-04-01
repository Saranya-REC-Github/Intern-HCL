//Create classes: Device → Mobile → Smartphone
//Add features at each level and show how derived class accesses base class members.
#include <iostream>
using namespace std;
class Device {
public:
    void feature() { cout << "Basic Device features\n"; }
};
class Mobile : public Device {
public:
    void feature() {
        Device::feature();
        cout << "Mobile features: Calling, Messaging\n";
    }
};
class Smartphone : public Mobile {
public:
    void feature() {
        Mobile::feature();
        cout << "Smartphone features: Internet, Apps\n";
    }
};
int main() {
    Smartphone s;
    s.feature();
}
