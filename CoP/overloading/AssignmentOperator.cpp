// OverloadingAssignmentOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;

public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}
    Test(const Test& other) {
        cout << "copy constructor" << endl;
        id = other.id;
        name = other.name;
    }

    void print() {
        cout << id << ": " << name << endl;
    }

    const Test& operator=(const Test& other) {
        cout << "assignment" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }
};

void assignmentOperator()
{
    Test test1(10, "Mike");
    cout << "test1 ";
    test1.print();

    Test test2(20, "Bob");

    test2 = test1;
    cout << "test2 ";
    test2.print();

    // operator = returns references
    Test test3;
    test3 = test2 = test1;

    // equivalent to test3 = test2
    test3.operator=(test2);
    cout << "test3 ";
    test3.print();

    cout << endl;

    // doesn't use the = operator; it is a copy initialization 
    Test test4 = test1;
    test4.print();
}