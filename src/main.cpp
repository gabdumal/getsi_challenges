#include "hurry_with_my_dessert/algorithm.hpp"
#include <console_colors.hpp>
#include <iostream>

using namespace std;

enum Challenge
{
    HURRY_WITH_MY_DESSERT
};

constexpr Challenge current_challenge = Challenge::HURRY_WITH_MY_DESSERT;

int main()
{
    ConsoleColors::setColor(cout, ConsoleColors::Color::RED, ConsoleColors::Color::WHITE);
    ConsoleColors::setDecoration(cout, ConsoleColors::Decoration::BOLD);
    cout << "=-=-= GetSi Challenges =-=-=" << endl;
    ConsoleColors::resetColor(cout);
    ConsoleColors::resetDecoration(cout);

    string challenge_output = "";
    switch (current_challenge)
    {
    case Challenge::HURRY_WITH_MY_DESSERT:
        challenge_output += HurryWithMyDessert::run();
        break;
    default:
        cout << "Invalid challenge!" << endl;
        return 1;
    }

    cout << challenge_output << endl;

    return 0;
}