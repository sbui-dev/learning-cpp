// BinaryFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

// pragma to prevent struct padding
#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main()
{
    Person someone = {"Tim", 20, 150};

    string fileName = "test.bin";
   
    // write a binary file
    ofstream outputFile(fileName, ios::binary);

    if (outputFile.is_open()) {

        // cast pointer to a char *
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

        outputFile.close();
    }
    else {
        cout << "Could not create file: " << fileName << endl;
    }

    Person someoneElse = {};

    // read binary file
    ifstream inputFile(fileName, ios::binary);

    if (inputFile.is_open()) {

        // cast pointer to a char *
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

        inputFile.close();
    }
    else {
        cout << "Could not create file: " << fileName << endl;
    }
    
    cout << someoneElse.name << ", " << someoneElse.age << ", " <<  someoneElse.weight << endl;

    return 0;
}
