#include <iostream>
#include <vector>
using namespace std;

class Parent {
    int dogs{ 5 };
    string text;
public:
    
    // delegating constructor
    // c++11 will allow a constructor to call another constructor
    // c++98 used a "init()" to get by this
    Parent() : Parent("hello") {
        cout << "no parameter parent constructor" << endl;
    }

    // c++98: creating a constructor will lose the default constructor
    Parent(string text) {
        this->text = text;
        cout << "string parent constructor" << endl;
    }
};

class Child : public Parent {
public:
    // c++98: can select which constructor to use
    //Child(): Parent("hello") {
    //}

    // c++11: use default constructor
    Child() = default;
};

class Test {
private:
    static const int SIZE = 100;
    int* pBuffer{nullptr};
public:
    Test() {
        cout << "constructor" << endl;
        pBuffer = new int[SIZE] {};
    }

    Test(int i) {
        cout << "parameterized constructor" << endl;
        pBuffer = new int[SIZE] {};

        for (int i = 0; i < SIZE; i++) {
            pBuffer[i] = 7 * 1;
        }
    }

    Test(const Test& other) {
        cout << "copy constructor" << endl;
        pBuffer = new int[SIZE] {};

        memcpy(pBuffer, other.pBuffer, SIZE * sizeof(int));
    }

    Test(Test&& other) {
        cout << "move constructor" << endl;
        // takes the allocated buffer from another obj
        pBuffer = other.pBuffer;

        // must set other pBuffer to null pointer or the other's destructor will deallocate it
        other.pBuffer = nullptr;
    }

    ~Test() {
        cout << "destructor" << endl;
        delete[] pBuffer;
    }

    Test& operator=(const Test& other) {
        cout << "assignment" << endl;
        pBuffer = new int[SIZE] {};

        memcpy(pBuffer, other.pBuffer, SIZE * sizeof(int));
        return *this;
    }

    Test& operator=(Test&& other) {
        cout << "move assignment" << endl;

        // memory leak and problems can occur if you're not careful

        // delete current pBuffer
        delete[] pBuffer;

        // take allocation of other's pBuffer
        pBuffer = other.pBuffer;

        // must set other pBuffer to null pointer or the other's destructor will deallocate it
        other.pBuffer = nullptr;
        return *this;
    }
};

ostream& operator<<(ostream& out, const Test& test) {
    out << "Hello from test";
    return out;
}

Test getTest() {
    return Test();
}

void delegatingContructor() {
    // see notes in classes
    Parent parent("Hello");
    Child child;
}

void constructorMemory() {

    // return value of function getTest() is a rvalue
    Test test1 = getTest();

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    // rvalue example
    int value1 = 7;

    // lvalue example
    int* pValue1 = &value1;

    // lvalue example
    // this will work
    int* pValue3 = &++value1;
    cout << *pValue3 << endl;

    // rvalue example
    // this will not work; post fix is operating on a temporary value
    //int* pValue4 = &value1++;
}

void lValueRef() {

    Test test1 = getTest();
    
    Test &lTest1 = test1;

    // can't bind lValue to temporary rvalues

    // can't work return value is a temporary value
    //Test& rTest2 = getTest();

    // const will make lvalue bind to rvalues
    const Test& rTest3 = getTest();

    // Test() is an rvalue but it gets copied
    Test test2(Test(1));
}

/*
** Check if obj ref is lvalue or rvalue
*/
void check(const Test& value) {
    cout << "lValue function" << endl;
}

void check(Test&& value) {
    cout << "rValue function" << endl;
}

void rValueRef() {
    Test test1 = getTest();

    cout << test1 << endl;

    Test& lTest1 = test1;

    // can bind rvalue to rvalue
    Test&& rtest1 = Test();

    Test&& rtest2 = getTest();

    check(test1); //lvalue
    check(getTest()); // rvalue
    check(Test()); // rvalue
}

void moveConstructor() {
    vector<Test> vec;
    vec.push_back(Test());
}

void moveAssignment() {
    Test test;
    test = getTest();
}

int main() {
    delegatingContructor();
    constructorMemory();
    lValueRef();
    rValueRef();
    moveConstructor();
    moveAssignment();
    return 0;
}