#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // default constructor is needed
    Person() : name(""), age(0) {
    }
    // constructor
    Person(string name, int age) : name(name), age(age) {
    }

    // copy constructor
    Person(const Person& other) {
        cout << "Copy constructor running\n";
        name = other.name;
        age = other.age;
    }

    void print() {
        cout << name << ": " << age << endl;
    }
};

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

void objectMap() {
    map<int, Person> people;

    // insert object data into map
    people[0] = Person("Mike", 40);
    people[1] = Person("Vicky", 30);
    people[2] = Person("Raj", 20);

    // this is run twice
    people.insert(make_pair(55, Person("Bob", 45)));

    // print out map contents
    for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        it->second.print();
    }

}