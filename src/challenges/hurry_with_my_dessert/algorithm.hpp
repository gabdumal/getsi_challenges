#ifndef HURRY_WITH_MY_DESSERT_HPP_
#define HURRY_WITH_MY_DESSERT_HPP_

#include <tester.hpp>
#include <vector>

using namespace std;

class HurryWithMyDessert
{
private:
    struct BusStop
    {
        int identifier;
        int time_to_next;
    };

    struct BusLine
    {
        int line_number;
        vector<BusStop> bus_stops;
    };

    static string name;
    static vector<Tester::Test> tests;

    static vector<BusStop> parseBusStops(string input)
    {
        int identifier, time_to_next, quantity;
        try
        {
            vector<BusStop> bus_stops;
            while (input.find("(") != string::npos)
            {
                size_t start = input.find("(") + 1;
                size_t end = input.find(")");
                string bus_stop = input.substr(start, end - start);
                input = input.substr(end + 1);
                identifier = stoi(bus_stop.substr(0, bus_stop.find(" ")));
                time_to_next = stoi(bus_stop.substr(bus_stop.find(" ") + 1));
                bus_stops.push_back({identifier, time_to_next});
            }
            return bus_stops;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return {};
    }

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
                vector<BusStop> bus_stops(parseBusStops(bus_line));
                bus_lines.push_back({stoi(line_number), bus_stops});
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
