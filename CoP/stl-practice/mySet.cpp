#include <iostream>
#include <set>
using namespace std;

class Test {
private:
    string name;
    int id;

public:
    Test() : name(""), id(0) {}
    Test(int age, string name) : id(age), name(name) {}

    void print() const {
        cout << id << ": " << name << endl;
    }

    // need a < comparision function to compare objects
    bool operator<(const Test &other) const {
        return name < other.name;
    }
};

void mySet() {
    set<int> numbers;

    // a set will order the elements and doesn't allow duplicates
    numbers.insert(41);
    numbers.insert(12);
    numbers.insert(23);
    numbers.insert(33);
    numbers.insert(23);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    // find an element within a set
    set<int>::iterator itFind = numbers.find(33);
    
    if (itFind != numbers.end()) {
        cout << "Found " << *itFind << endl;
    }

    // can use count to find elements
    if (numbers.count(33)) {
        cout << "Number found " << endl;
    }


}

void myObjectSet() {
    set<Test> tests;

    // insert data
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(20, "Sue"));

    // won't insert because of the < operator compares only name
    tests.insert(Test(33, "Joe"));

    // print contents
    for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }
}