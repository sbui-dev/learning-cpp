#include <iostream>
#include <map>
using namespace std;

void myMultimap() {
    multimap<int, string> lookup;

    // multimap will order the keys
    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vickey"));
    lookup.insert(make_pair(20, "Bob"));

    // multimap will allow duplicate keys
    lookup.insert(make_pair(30, "Raj"));

    // print out multimap
    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // find will return one iterator
    for (multimap<int, string>::iterator it = lookup.find(20); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // will give two iterator of beginning and end of a range
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for (multimap<int, string>::iterator it = its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // c++11 auto saves typing out the type
    auto its2 = lookup.equal_range(30);

    for (auto it = its2.first; it != its2.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

}