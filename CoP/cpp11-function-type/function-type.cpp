#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string& test) {
    return test.size() == 3;
}

class Check {
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
} check1;

void run(function<bool(string&)> check) {
    string test = "stars";
    cout << check(test) << endl;
}

int main()
{
    int size = 5;
    vector<string> vec{ "one", "two", "three" };
    auto lambda = [size](string test) {return test.size() == size; };

    // lambda expression can be used wherever a function is used
    int count = count_if(vec.begin(), vec.end(), [size](string test) {return test.size() == size; });

    cout << count << endl;

    // by function
    count = count_if(vec.begin(), vec.end(), check);

    cout << count << endl;

    // by functor
    count = count_if(vec.begin(), vec.end(), check1);

    cout << count << endl;

    // function, functor, and lambda expression can be passed in with 'function'
    run(lambda);
    run(check1);
    run(check);

    // can create a callable function
    function<int(int, int)> add = [](int one, int two) { return one + two; };
    cout << add(7, 3) << endl;
}