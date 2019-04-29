#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public:
    Test(initializer_list<string> texts) {
        // texts is an iterator
        for (auto value : texts) {
            cout << value << endl;
        }
    }
    void print(initializer_list<string> texts) {
        for (auto value : texts) {
            cout << value << endl;
        }
    }
};

class Obj {
private:
    int id{ 3 };
    string name{ "Mike" };

public:
    // makes Obj() the default implementation
    Obj() = default;

    // makes copy constructor the default implementation
    Obj(const Obj& other) = default;

    Obj(int id) : id(id) {}

    // explictly delete the implementation
    Obj &operator=(const Obj& other) = delete;

    void print() {
        cout << id << ": " << name << endl;
    }
};

void myInit()
{
    //c++11 initialization with {}

    // can initialize int with {}
    int value{ 5 };
    cout << value << endl;

    // can initialize string with {}
    string text{ "Hello" };
    cout << text << endl;

    // can initialize int array with {}
    int numbers[]{ 1,2,3 };
    cout << numbers[1] << endl;

    // can initialize int with {}
    int* pInts = new int[3]{ 1, 2,3 };
    cout << pInts[1] << endl;
    delete [] pInts;

    // initializes to 0 by default
    int value1{};
    cout << value1 << endl;

    // equivalent to null pointer
    int* pSomething{};
    cout << pSomething << endl;

    // initializes all elements to 0 by default
    int numbers1[5]{};
    cout << numbers1[1] << endl;

    // initialize a struct
    struct {
        int value;
        string text;
    } s1{5, "hello"};

    cout << s1.text << endl;

    // can now initalize a vector without having to do push_back()
    vector<string> strings{ "one", "two", "three", "four" };
    cout << strings[3] << endl;
}

int main()
{
    // initializer list
    Test test{ "apple", "orange", "banana" };
    test.print({"one", "two", "three", "four"});

    Obj obj1;
    obj1.print();

    Obj obj2(77);
    obj2.print();

    // will fail because the assignment operator is deleted
    //Obj obj2 = obj1;
}