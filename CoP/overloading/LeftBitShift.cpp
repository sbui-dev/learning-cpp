#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;

public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}

    // friend to access private variables
    friend ostream& operator<<(ostream &out, const Test &test) {
        out << test.id << ": " << test.name;
        return out;
    }
};

void leftBitShift() {
    Test test1(10, "Mike");
    Test test2(20, "Bob");

    // goes from left to right and an outstream reference is returned each time
    cout << test1 << endl << test2 << endl;
}