// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void mightGoWrong() {
    bool error1 = false;
    bool error2 = true;

    if (error1) {
        throw "Something went wrong";
    }

    // second exception will never be reached if first exception is triggered
    if (error2) {
        throw string("Something else went wrong");
    }
}

void usesMightGoWrong() {
    // throws will go through call stack for nested functions 
    mightGoWrong();
}

int main()
{
    try {
        usesMightGoWrong();
    }
    catch (int e) {
        cout << "Error code: " << e << endl;
    }
    catch (char const* e) {
        cout << "Error message: " << e << endl;
    }
    catch (string &e) {
        cout << "String error message: " << e << endl;
    }

    return 0;
}