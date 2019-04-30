#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "I'm a parent!" << endl;
    }
};

class Brother : public Parent {

};

class Sister : public Parent {

};

void staticCast()
{
    Parent parent;
    Brother brother;

    Parent* pp = &brother;

    float value = 3.23;

    // c-style casting
    cout << (int)value << endl;

    // c++ casting
    cout << int(value) << endl;


    cout << static_cast<int>(value) << endl;

    // doesn't work
    //Brother* pb = &parent;

    // can force above to work with static_cast because it do any checks
    // it can be very unsafe
    Brother* pb = static_cast<Brother*>(&parent);

    // next example
    Parent* ppb1 = &brother;
    Brother* pbb1 = &brother;

    // same as above but doesn't work
    //Parent* ppb2 = &brother;
    //Brother* pbb2 = ppb;

    // static_cast will let it work but is unsafe
    // the ppb3 pointer may be a parent and brother members will not work
    Parent* ppb3 = &brother;
    Brother* pbb3 = static_cast<Brother *>(ppb3);

    // next example
    // will not work, but they are the same type
    //Parent&& p = parent;

    // can use static cast to make it a parent
    Parent&& p = static_cast<Parent &&>(parent);
    p.speak();
}

void dynamicCast() {
    Parent parent;
    Brother brother;

    Parent* ppb = &parent;

    // casting from parent to brother is invalid
    // dynamic cast does RTTI (Run Time Type Identification) checks and will return nullptr for invalid casts
    // it's better to use dynamic cast over static cast
    Brother* pbb = dynamic_cast<Brother*>(ppb);

    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    }
    else {
        cout << pbb << endl;
    }
}

void reinterpretCast() {
    Parent parent;
    Brother brother;
    Sister sister;

    Parent* ppb = &brother;

    // dynamic_cast doesn't allow this because it's invalid
    Sister* pbb = dynamic_cast<Sister *>(ppb);

    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    }
    else {
        cout << pbb << endl;
    }

    // static_cast doesn't do type checking so it is allowed as seen below
    pbb = static_cast<Sister*>(ppb);

    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    }
    else {
        cout << pbb << endl;
    }

    // reinterpret_cast does even less checking than static_cast
    pbb = reinterpret_cast<Sister*>(ppb);
    if (pbb == nullptr) {
        cout << "Invalid cast" << endl;
    }
    else {
        cout << pbb << endl;
    }
}

int main() {
    staticCast();
    dynamicCast();
    reinterpretCast();
    return 0;
}