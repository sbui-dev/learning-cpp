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

    void print() const {
        cout << name << ": " << age << endl;
    }

    // const to keep the object the same and pass by reference instead of copy
    bool operator<(const Person &other) const {
        // needs both comparison to correct identify if object is the same
        if (name == other.name) {
            return age < other.age;
        }
        else {
            return name < other.name;
        }
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

void customObjectMapKeys() {
    map<Person, int> people;

    // insert object data into map
    people[Person("Mike", 40)] = 40;
    people[Person("Vicky", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    // overwrite's the key's value
    people[Person("Mike", 40)] = 12;

    // value is changed in map but the object's value in the object key isn't updated
    // because the overloaded < operator compares only name
    people[Person("Mike", 44)] = 21;


    // print out map contents
    for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        cout << it->second << ": " << flush;
        // keys are return as const
        it->first.print();
    }

}