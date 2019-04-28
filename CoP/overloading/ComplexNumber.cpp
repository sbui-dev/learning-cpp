#include <iostream>
#include "Complex.h"
using namespace std;

void complexNumber() {
    Complex c1(2, 3);
    
    // copy constructor
    Complex c2(c1);

    // copy constructor
    Complex c3 = c2;

    // custom << function
    cout << c2 << " " << c3 << endl;
}