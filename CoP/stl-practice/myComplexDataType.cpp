#include <iostream>
#include <map>
#include <vector>
using namespace std;

void myComplexDataType() {
    map<string, vector<int>> scores;

    // uses map key for name and vector for scores
    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20); // mike will have two scores
    scores["Vicky"].push_back(40);

    // print out contents
    for (map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++) {
        string name = it->first;
        vector<int> scoreList = it->second;

        cout << name << ": " << flush;

        for (int i = 0; i < scoreList.size(); i++) {
            cout << scoreList[i] << " ";
        }
        cout << endl;
    }
}