#include <iostream>
#include "Complex.h"
using namespace std;

void dereferenceOperator() {
    Complex c1(2, 4);

    cout << *c1 << endl;

    cout << *c1 + *Complex(4, 3) << endl;
}