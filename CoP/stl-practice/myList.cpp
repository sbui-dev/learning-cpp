#include <iostream>
#include <list>
using namespace std;

void myList() {

    cout << "***** myList *****" << endl;

    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it = numbers.begin();
    it++;

    // inserting a new element between elements
    numbers.insert(it, 100);
    cout << "Element: "<< *it << endl;

    // removing element between elements
    list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;

    // iterator becomes invalid when erased
    // erase will return next iterator
    eraseIt = numbers.erase(eraseIt);
    cout << "Element: " << *eraseIt << endl;

    // looping via while loop
    list<int>::iterator it2 = numbers.begin();
    while(it2 != numbers.end()) {
        if (*it2 == 2) {
            numbers.insert(it2, 1234);
            it2++; // increment to next element
        }
        else if (*it2 == 1) {
            it2 = numbers.erase(it2);
        }
        else {
            it2++;
        }
    }

    // print out list
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
}