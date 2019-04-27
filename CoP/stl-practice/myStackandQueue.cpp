#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Name {
private:
    string name;

public:
    Name(string name) : name(name) {}
    ~Name() {
    }

    void print() const {
        cout << name << endl;
    }

};

void myStack() {
    cout << "*** Stack ***" << endl;

    // stack is LIFO
    stack<Name> testStack;

    testStack.push(Name("Mike"));
    testStack.push(Name("John"));
    testStack.push(Name("Sue"));

    /*
     * Object is destroyed before it can be printed
    Name test1 = testStack.top();
    testStack.pop();
    test1.print();
    */

    // print elements
    while (testStack.size() > 0) {
        Name &test2 = testStack.top();
        test2.print();
        testStack.pop();
    }
    
}

void myQueue() {
    cout << "*** Queue ***" << endl;

    // stack is FIFO
    queue<Name> testQueue;

    testQueue.push(Name("Mike"));
    testQueue.push(Name("John"));
    testQueue.push(Name("Sue"));

    // use back to access the last element
    testQueue.back().print();

    cout << endl;

    // print elements
    while (testQueue.size() > 0) {
        // uses front to access first element
        Name& test = testQueue.front();
        test.print();
        testQueue.pop();
    }
}