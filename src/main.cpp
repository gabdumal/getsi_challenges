#include "challenges/hurry_with_my_dessert/algorithm.hpp"
#include "challenges/preferential_queues/algorithm.hpp"
#include "challenges/cinephiles_on_vacations/algorithm.hpp"
#include <iostream>
#include <vector>

using namespace std;

enum Challenge
{
    HURRY_WITH_MY_DESSERT,
    PREFERENTIAL_QUEUES,
    CINEPHILES_ON_VACATIONS
};

constexpr Challenge current_challenge = Challenge::CINEPHILES_ON_VACATIONS;

int main()
{
    cout << "=-=-= GetSi Challenges =-=-=" << endl;

    string challenge_output = "";
    switch (current_challenge)
    {
    case Challenge::HURRY_WITH_MY_DESSERT:
        challenge_output += HurryWithMyDessert::run(vector<int>({1, 2}));
        break;
    case Challenge::PREFERENTIAL_QUEUES:
        challenge_output += PreferentialQueues::run(vector<int>({1, 2}));
        break;
    case Challenge::CINEPHILES_ON_VACATIONS:
        challenge_output += CinephilesOnVacations::run(vector<int>({1, 2, 3}));
        break;
    default:
        cout << "Invalid challenge!" << endl;
        return 1;
    }

    cout << challenge_output << endl;

    return 0;
}