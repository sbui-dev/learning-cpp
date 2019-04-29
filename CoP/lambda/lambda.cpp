#include <iostream>
using namespace std;

class Test {
private:
    int one{ 1 };
    int two{ 2 };
public:
    void run() {
        int three{ 3 };
        int four{ 4 };

        // 'this' will capture all instance variables by reference
        auto pLambda = [&, this]() {
            one = 111; // one can be changed
            cout << one << endl;
            cout << two << endl;
            cout << three << endl;
            cout << four << endl;
        };

        pLambda();
    }
};

void test(void (*pFunc)()) {
    pFunc();
}

void testGreet(void (*greet)(string)) {
    greet("Bob");
}

void runDivide(double (*divide)(double a, double b)) {
    auto rval = divide(9, 3);

    cout << "Divide = " << rval << endl;
}

void lambdaExpression()
{
    // valid lambda expression that doesn't do anything
    []() {};

    // anonymous function
    auto func = []() {cout << "Hello World" << endl; };

    // similar to a functor
    func();

    // calls itself
    []() {cout << "Hello Again" << endl; }();

    // calls the lambda expression
    test(func);

    // can send a lambda expression directly
    test([]() {cout << "Hi" << endl; });

}

void lambdaExpressionWithParameters() {

    // lambda expression with parameter
    auto pGreet = [](string name) {cout << "Hello " << name << endl; };

    pGreet("Mike");

    testGreet(pGreet);

    // can use -> trailing return to specify type
    auto pDivide = [](double a, double b) -> double {
        if (b == 0.0) {
            return 0; // int
        }
        return a / b; // double
    };

    cout << pDivide(10.0, 5.0) << endl;
    cout << pDivide(10.0, 0.0) << endl;

    // passing a lambda expression with two parameters
    runDivide(pDivide);
}

void lambdaCapture() {
    int one = 1;
    int two = 2;
    int three = 3;

    // doesn't work due to scoping
    //[]() { cout << one << endl; }();

    // capture one and two by value
    [one, two]() { cout << one << ", " << two << endl; }();

    // capture all local variables by value
    [=]() { cout << one << ", " << two << endl; }();

    // default is capture all local variables by value, but capture three by reference
    [=, &three]() { cout << one << ", " << two << endl; }();

    // can change reference variable values
    [=, &three]() { three = 7;  cout << one << ", " << two << endl; }();
    cout << three << endl;

    // capture all local variables by reference
    [&]() { three = 7;  cout << one << ", " << two << endl; }();

    // capture all local variables by reference but two and three by value
    // doesn't work because three is by value
    //[&, two, three]() { three = 7;  cout << one << two << endl; }();

    // two is not valid because it's already capturing by reference
    //[&, &two, three]() { one = 700;  cout << one << ", " << two << endl; }();

    // must capture other variables by value if the default is capture by reference
    [&, two, three]() { one = 700;  cout << one << ", " << two << endl; }();
}

void captureThisWithLambda() {
    Test test;
    test.run();
}

int main() {
    lambdaExpression();
    lambdaExpressionWithParameters();
    lambdaCapture();
    captureThisWithLambda();
    return 0;
}