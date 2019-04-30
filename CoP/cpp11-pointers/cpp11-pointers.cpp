#include <iostream>

using namespace std;

class Test {
public:
    Test() {
        cout << "created" << endl;
    }
    void greet() {
        cout << "Hello" << endl;
    }
    ~Test() {
        cout << "destroyed" << endl;
    }
};

class Temp {
private:
    unique_ptr<Test[]> pTest;

public:
    Temp() : pTest(new Test[2]) {
    }

    // don't need to declare an explicit destructor to clean up pTest
    // unique_ptr will clean up the memory
};

void uniquePtr()
{
    // new scope
    {
        // smart pointers will clean up memory when it goes out of scope
        unique_ptr<Test> pTest(new Test);

        pTest->greet();
    }// end scope

    cout << "Finished 1" << endl;

    {
        // works on arrays also
        unique_ptr<Test[]> pTest(new Test[2]);

        pTest[1].greet();
    }

    cout << "Finished 2" << endl;

    {
        // see class notes
        Temp temp;
    }

    cout << "Finished 3" << endl;
}

void sharedPtr() {
    // shared ptr don't delete memory until all pointers have gone out of scope

    // declaring a smart null ptr
    shared_ptr<Test> pTest2(nullptr);

    {
        // use make_shared to create the memory
        shared_ptr<Test> pTest1 = make_shared<Test>();
    }

    // pTest1 memory will be destroyed before finished
    cout << "Finished 1" << endl;

    {
        // use make_shared to create the memory
        shared_ptr<Test> pTest1 = make_shared<Test>();
        pTest2 = pTest1;
    }

    // pTest1 memory will be destroyed after finished because pTest2 doesn't go out of scope until after
    cout << "Finished 2" << endl;
}

int main()
{
    uniquePtr();
    sharedPtr();

    return 0;
}