#ifndef HURRY_WITH_MY_DESSERT_HPP_
#define HURRY_WITH_MY_DESSERT_HPP_

#include <tester.hpp>
#include <vector>

using namespace std;

class HurryWithMyDessert
{
private:
    static string name;
    static vector<Tester::Test> tests;

public:
    static vector<Tester::Test> getTests()
    {
        return tests;
    }

    static string run(vector<int> input_identifiers)
    {
        vector<Tester::Test> selected_tests = Tester::pickTests(getTests(), input_identifiers);
        return Tester::runTests(name, selected_tests, main);
    }

    static string main(string input);
};

#endif // HURRY_WITH_MY_DESSERT_HPP_
