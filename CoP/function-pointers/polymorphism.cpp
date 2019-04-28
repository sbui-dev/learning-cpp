#include <iostream>
using namespace std;

class Parent {
public:
    Parent() {
    }
    Parent(const Parent &other){
        cout << "copy parent" << endl;
    }
    virtual void print() {
        cout << "parent" << endl;
    }
};

class Child : public Parent {
public:
    void print() {
        cout << "child" << endl;
    }
};

void poly() {
    Child c1;
    Parent& p1 = c1;

    // calls parent's print when parent print() isn't have virtual
    p1.print();

    // object slicing; upcasting
    Parent p2 = Child();

    // prints "parent"
    p2.print();
}