#include "tester.hpp"
#include <iostream>

using namespace std;

vector<Tester::Test> Tester::pickTests(vector<Tester::Test> tests, vector<int> input_identifiers)
{
    vector<Tester::Test> selected_tests;
    for (int input_identifier : input_identifiers)
    {
        for (Tester::Test test : tests)
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

string Tester::runTests(string challenge_name, vector<Tester::Test> tests, function<string(string)> main)
{
    string output = "=-= " + challenge_name + " =-=\n";
    for (Tester::Test test : tests)
    {
        output += "Teste " + to_string(test.identifier) + ":\n";
        output += test.input + "\n";
        output += "---\n";
        output += main(test.input) + "\n===\n";
    }
    return output;
}
