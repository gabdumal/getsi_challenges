#ifndef TESTER_HPP_
#define TESTER_HPP_

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Tester
{
public:
    struct Test
    {
        int identifier;
        string input;
        string output;
    };

    static vector<Test> pickTests(vector<Test> tests, vector<int> input_identifiers);

    static string runTests(string challenge_name, vector<Test> tests, function<string(string)> main);
};

#endif // TESTER_HPP_
