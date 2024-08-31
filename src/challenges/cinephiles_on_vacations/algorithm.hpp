#ifndef CINEPHILES_ON_VACATIONS_HPP_
#define CINEPHILES_ON_VACATIONS_HPP_

#include "../../data_structures/unordered_map/unordered_map.hpp"
#include <tester.hpp>
#include <vector>
#include <string>

using namespace std;

class CinephilesOnVacations
{
public:
    struct Score
    {
        string movie_name;
        int plot;
        int acting;
        int direction;
        int soundtrack;
        int special_effects;
    };

    struct Movie
    {
        int quantity;
        int plot_sum;
        int acting_sum;
        int direction_sum;
        int soundtrack_sum;
        int special_effects_sum;
    };

private:
    static string name;
    static vector<Tester::Test> tests;

public:
    static vector<Score> parseInputToScores(string input)
    {
        try
        {
            size_t start = 0;
            size_t end = input.find("\n");
            string quantity_string = input.substr(start, end);
            int quantity = stoi(quantity_string);

            vector<Score> scores(quantity);
            start = start + end + 1;
            end = input.find("\n", end + 1);
            for (int i = 0; i < quantity; i++)
            {
                string score_string = input.substr(start, end - start);
                string movie_name = score_string.substr(0, score_string.find(" "));
                score_string = score_string.substr(movie_name.length() + 1, score_string.length());
                string plot = score_string.substr(0, score_string.find(" "));
                score_string = score_string.substr(plot.length() + 1, score_string.length());
                string acting = score_string.substr(0, score_string.find(" "));
                score_string = score_string.substr(acting.length() + 1, score_string.length());
                string direction = score_string.substr(0, score_string.find(" "));
                score_string = score_string.substr(direction.length() + 1, score_string.length());
                string soundtrack = score_string.substr(0, score_string.find(" "));
                score_string = score_string.substr(soundtrack.length() + 1, score_string.length());
                string special_effects = score_string.substr(0, score_string.find(" "));
                Score score{
                    movie_name,
                    stoi(plot),
                    stoi(acting),
                    stoi(direction),
                    stoi(soundtrack),
                    stoi(special_effects)};
                scores[i] = score;
                start = end + 1;
                end = input.find("\n", start);
            }
            return scores;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return {};
    }

    static string parseFloatToString(float value)
    {
        string value_string = to_string(value);
        if (value_string.find(".") != string::npos)
        {
            value_string = value_string.substr(0, value_string.find(".") + 3);
        }
        return value_string;
    }

    static string printMovies(UnorderedMap<string, Movie> movies)
    {
        string output = "";
        for (auto [movie_name, movie] : movies)
        {
            float plot_avg = (float)movie.plot_sum / movie.quantity;
            float acting_avg = (float)movie.acting_sum / movie.quantity;
            float direction_avg = (float)movie.direction_sum / movie.quantity;
            float soundtrack_avg = (float)movie.soundtrack_sum / movie.quantity;
            float special_effects_avg = (float)movie.special_effects_sum / movie.quantity;

            output += movie_name + " " + parseFloatToString(plot_avg) + " " + parseFloatToString(acting_avg) + " " + parseFloatToString(direction_avg) + " " + parseFloatToString(soundtrack_avg) + " " + parseFloatToString(special_effects_avg) + "\n";
        }
        return output;
    }

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

#endif // CINEPHILES_ON_VACATIONS_HPP_
