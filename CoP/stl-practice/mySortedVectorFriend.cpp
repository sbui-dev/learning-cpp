#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Record {
private:
    string name;
    int id;

public:
    Record() : name(""), id(0) {}
    Record(int age, string name) : id(age), name(name) {}

    void print() const {
        cout << id << ": " << name << endl;
    }

    // need a < comparision function to compare objects when inserting objects
    /*bool operator<(const Record& other) const {
        return name < other.name;
    }*/

    // friend allows comp function to access private members
    friend bool comp(const Record& a, const Record& b);
};

bool comp(const Record& a, const Record& b) {
    return a.name < b.name;
}

void mySortedVector() {
    vector<Record> records;

    records.push_back(Record(3, "Vicky"));
    records.push_back(Record(10, "Mike"));
    records.push_back(Record(30, "Joe"));
    records.push_back(Record(20, "Sue"));
    records.push_back(Record(7, "Raj"));

    // sorts by name by using the < function
    //sort(records.begin(), records.end());

    // sort by custom compare function
    sort(records.begin(), records.end(), comp);

    // Note: any more elements inserted after the sort will not be sorted

    // print elements
    for (int i = 0; i < records.size(); i++) {
        records[i].print();
    }
}