#include <iostream>
#include <vector>
using namespace std;

void rloops() {
    auto texts = {"one", "two", "three"};

    // range based loop with char arrays
    for (auto text : texts) {
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(6);
    numbers.push_back(11);

    // range based loop with vectors
    for (auto number : numbers) {
        cout << number << endl;
    }

    string hello = "Hello";

    // range based loop with characters in a string
    for (auto c : hello) {
        cout << c << endl;
    }
}