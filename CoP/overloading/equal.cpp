#include <iostream>
#include "Complex.h"
using namespace std;

void equalOperator() {
    Complex c1(3, 2);
    Complex c2(3, 2);
    Complex c3(4, 2);

    if (c1 == c2) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }

    if (c2 != c3) {
        cout << "Not Equal" << endl;
    }
    else {
        cout << "Equal" << endl;
    }
}