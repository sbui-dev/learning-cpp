#include <iostream>
#include <functional> // for bind

using namespace std;
using namespace std::placeholders;

class Test {
public:
    int add(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

int run(function<int(int,int)> func) {
    return func(7, 3);
}

int main()
{
    // bind arguments to a function
    auto calculate1 = bind(add, 3, 4, 5);

    cout << calculate1() << endl;

    // _1, _2, _3 are place holders
    // bind placeholders to a function
    auto calculate2 = bind(add, _1, _2, _3);

    cout << calculate2(10, 20, 30) << endl;

    // placeholder order can be moved around
    auto calculate3 = bind(add, _2, _3, _1);

    cout << calculate3(10, 20, 30) << endl;

    // can mixed placeholders and default values
    auto calculate4 = bind(add, _2, 100, _1);

    cout << calculate4(10, 20) << endl;

    // can pass the bind into anything that accepts a function
    cout << run(calculate4) << endl;

    // can bind to class methods
    Test test;
    auto calculate5 = bind(&Test::add, test, _2, 400, _1);
    cout << run(calculate5) << endl;

    return 0;
}