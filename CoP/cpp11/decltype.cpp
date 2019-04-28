#include <iostream>
using namespace std;

void typeInfo(){

    int value;
    double dValue;
    string text;

    cout << typeid(value).name() << endl;
    cout << typeid(dValue).name() << endl;
    cout << typeid(text).name() << endl;

    // c++11 decltype
    // declare variables of an existing type
    decltype(text) name = "Bob";

    cout << name << endl;
}