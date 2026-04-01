//Create classes: Device → Phone & Camera → SmartPhone
//Use virtual base classes to avoid duplicate Device members.
#include <iostream>
using namespace std;
class Device {
public:
    void deviceFeature() {
    cout << "General Device\n"; }
};
class Phone : virtual public Device {
public:
    void phoneFeature() {
    cout << "Phone: Calling\n"; }
};
class Camera : virtual public Device {
public:
    void cameraFeature() {
    cout << "Camera: Taking photos\n"; }
};
class SmartPhone : public Phone, public Camera {
public:
    void smartFeature() {
    cout << "SmartPhone: Apps + Internet\n"; }
};
int main() {
    SmartPhone sp;
    sp.deviceFeature();
    sp.phoneFeature();
    sp.cameraFeature();
    sp.smartFeature();
}
