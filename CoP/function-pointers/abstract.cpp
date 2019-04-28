#include <iostream>
using namespace std;

// animal is an abstract class which cannot be instantiated
class Animal {
public:
    // pure virtual function; no implementation
    virtual void speak() = 0;
    virtual void run() = 0;
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Bark!" << endl;
    }
};

class Labrador : public Dog {
public:
    void run() {
        cout << "Labrador running" << endl;
    }
};

void abstractClasses() {

    // cannot do animal because of pure virtual function
    //Animal animal;
    
    // Dog doesn't work because it is missing run() implementation
    //Dog dog;
    //dog.speak();

    // Labrador works because it has all required implemented functions
    Labrador lab;
    lab.run();
    lab.speak();

    // can create a parent pointer to subclasses
    Animal* animals[5];
    animals[0] = &lab;
    animals[0]->speak();
}