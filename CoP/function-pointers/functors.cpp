#include <iostream>
using namespace std;

// abstract base
struct Test {
    virtual bool operator()(string& test) = 0;
};

struct MatchTest : Test {
    // functor
    bool operator()(string& text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    // test operators like a function
    if (test(text)) {
        cout << "Text matches" << endl;
    }
    else {
        cout << "No match" << endl;
    }
}

void functors() {
    MatchTest pred;

    string value = "lion";

    // test operators like a function
    cout << pred(value) << endl;

    MatchTest m;

    check("lion", m);
}