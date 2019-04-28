#include <iostream>
#include "Complex.h"
using namespace std;

void plusOperator() {
    Complex c1(3, 4);
    Complex c2(2, 4);

    // overloaded + operator with Complex and Complex
    Complex c3 = c1 + c2;

    cout << "c1 " << c1 << endl;
    cout << "c2 " << c2 << endl;
    cout << "c3 " << c3 << endl;

    cout << "c1 + c2 + c3 = " << c1 + c2 + c3 << endl;

    Complex c4(4, 2);

    // works if there is an overloaded + operator with Complex and double
    Complex c5 = c4 + 7;

    cout << "c4 " << c4 << endl;

    cout << "c5 = " << c5 << endl;

    Complex c6(1, 7);

    // doesn't work if there isn't an overloaded + operator with double and Complex; order matters
    cout << 3.2 + c6 << endl;

    // chaining different ways will work
    cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;
}