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

    static vector<Test> pickTests(vector<Test> tests, vector<int> input_identifiers)
    {
        vector<Test> selected_tests;
        for (int input_identifier : input_identifiers)
        {
            for (Test test : tests)
            {
                if (test.identifier == input_identifier)
                {
                    selected_tests.push_back(test);
                    break;
                }
            }
        }
        return selected_tests;
    }

    static string runTests(string challenge_name, vector<Test> tests, function<string(string)> main)
    {
        string output = "=-= " + challenge_name + " =-=\n";
        for (Test test : tests)
        {
            output += "Teste " + to_string(test.identifier) + ":\n";
            output += test.input + "\n";
            output += "---\n ";
            output += main(test.input) + "\n===\n";
        }
        return output;
    }
};

#endif // TESTER_HPP_
