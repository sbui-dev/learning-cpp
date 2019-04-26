#include <iostream>
#include <vector>
using namespace std;

void vectorPractice() {
    cout << "***** vectorPractice *****" << endl;

    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    // using an index
    for (size_t i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }

    // using an iterator
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
        cout << *it << endl;
    }

    // adding two will move iterator two positions in vector
    vector<string>::iterator it = strings.begin();
    it += 2;

    cout << *it << endl;
}

void vectorAndMemory() {
    cout << "***** vectorAndMemory *****" << endl;

    vector<double> numbers(0);

    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity();

    cout << "Capcity: " << capacity << endl;

    // capacity is doubled each time it runs out
    for (int i = 0; i < 10000; i++) {
        if (numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }
        numbers.push_back(i);
    }

    // clear will remove all elements but the capacity remains the same
    cout << "Clear" << endl;
    numbers.clear();
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    // reserve will change capacity size
    cout << "Reserve" << endl;
    numbers.reserve(100000);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
}

void twoDimensionalVectors() {
    cout << "***** twoDimensionalVectors *****" << endl;
    // 3 by 4 grid created by vectors
    //vector<int>(4,7) initializes data to 7 within that vector
    vector<vector<int>> grid(3, vector<int>(4,7));

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            cout << grid[row][col];
        }
        cout << endl;
    }
}