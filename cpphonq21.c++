//Create a program Media Player with base class Media with virtual play(). Derived classes Audio and Video override play().
#include <iostream>
using namespace std;
class Media {
public:
    virtual void play() {
    cout << "Playing media...\n"; }
};
class Audio : public Media {
public:
    void play() override {
    cout << "Playing audio file\n"; }
};
class Video : public Media {
public:
    void play() override {
    cout << "Playing video file\n"; }
};
int main() {
    Media* m1 = new Audio();
    Media* m2 = new Video();
    m1->play();  // Audio
    m2->play();  // Video
    delete m1;
    delete m2;
}
