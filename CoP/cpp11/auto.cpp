#include <iostream>
using namespace std;

template <class T, class S>
auto test(T value1, S value2) {
    return value1 + value2;
}

int get() {
    return 999;
}

// can be used with a function return
auto test2() {
    return get();
}

void autoType() {

    // compiler will figure out the type
    auto value = 7;
    auto text = "Hello";

    cout << test(5, 6) << endl;

    cout << test2() << endl;
}