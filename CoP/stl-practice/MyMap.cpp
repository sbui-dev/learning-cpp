#include <iostream>
#include <map>
using namespace std;

void myMap() {
    map<string, int> ages;

    // inserting data via key
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    // duplicate keys will overwrite previous data
    ages["Mike"] = 50;

    // insertion via pair
    ages.insert(pair<string, int>("Peter", 43));

    // insertion via make_pair
    ages.insert(make_pair("Jane", 25));

    // finding a key
    if (ages.find("Vicky") != ages.end()) {
        cout << "Found Vicky" << endl;
    }
    else {
        cout << "Key wasn't found" << endl;
    }

    // print via key
    cout << ages["Raj"] << endl;

    // print out map contents via pair
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;
        cout << age.first << " : " << age.second << endl;
    }

    // print out map contents via iterator
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
}