#ifndef HURRY_WITH_MY_DESSERT_HPP_
#define HURRY_WITH_MY_DESSERT_HPP_

#include <tester.hpp>
#include <vector>

using namespace std;

class HurryWithMyDessert
{
private:
    struct BusLine
    {
        int line_number;
        string bus_stops;
    };

    static string name;
    static vector<Tester::Test> tests;

    static vector<BusLine> parseInputToBusLines(string input)
    {
        try
        {
            size_t start = 0;
            size_t end = input.find("\n");
            string quantity_string = input.substr(start, end);
            int quantity = stoi(quantity_string);
            vector<BusLine> bus_lines(quantity);
            start = start + end + 1;
            end = input.find("\n", end + 1);
            for (int i = 0; i < quantity; i++)
            {
                string bus_line = input.substr(start, end - start);
                string line_number = bus_line.substr(0, bus_line.find(" "));
                bus_line = bus_line.substr(line_number.length() + 1, bus_line.length());
                bus_lines[i] = {stoi(line_number), bus_line};
                start = end + 1;
                end = input.find("\n", start);
            }
            return bus_lines;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return {};
    }

public:
    static vector<Tester::Test>
    getTests()
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
