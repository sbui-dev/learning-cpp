#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test()
{
    std::cout << "Hello World!\n"; 
}

void test(int value)
{
    std::cout << "Hello " << value << endl;
}

bool match(string test) {
    return test.size() == 3;
}

// takes vector reference and a function pointer
int countStrings(vector<string>& texts, bool(*match)(string test)) {
    int count = 0;

    for (int i = 0; i < texts.size(); i++) {
        if (match(texts[i])) {
            count++;
        }
    }

    return count;
}

void functionPointers() {

    // regular function call
    test();

    // declare function pointer with void return type void and no params
    void (*pTest)();

    // create function pointer; don't need &
    pTest = test;

    // call function via pointer
    pTest();

    // function pointer with int param and void return type
    void (*pTest2)(int) = test;

    // call function via pointer with an int
    pTest2(7);

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");

    cout << match("one") << endl;

    cout << "Number of strings that match size of three: " << countStrings(texts, match) << endl;
}