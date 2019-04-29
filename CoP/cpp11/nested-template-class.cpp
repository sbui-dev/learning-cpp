#include <iostream>
#include <string>
#include "ring.h"
using namespace std;

void templateClass() {
    
    // nested classes
    //Ring<int>::iterator it;
    //it.print();
    
    // ring buffer
    Ring<string> textring(3);
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    // print out ring buffer
    for (int i = 0; i < textring.size(); i++) {
        cout << textring.get(i) << endl;
    }

    cout << endl;

    // c++98 syntax
    for (Ring<string>::iterator it = textring.begin(); it != textring.end(); it++) {
        cout << *it << endl;
    }

    cout << endl;

    // range based for loops need begin(), end(), ++, and != to work
    // see c++98 syntax
    for (string value : textring) {
        cout << value << endl;
    }
}