#ifndef HURRY_WITH_MY_DESSERT_HPP_
#define HURRY_WITH_MY_DESSERT_HPP_

#include <iostream>

using namespace std;

class HurryWithMyDessert
{
private:
    static string header()
    {
        return "=-= Hurry With My Dessert =-=";
    }

    static string footer()
    {
        return "=-= END =-=";
    }

    static string main();

public:
    static string run()
    {
        return header() + "\n" + main() + "\n" + footer() + "\n";
    }
};

#endif // HURRY_WITH_MY_DESSERT_HPP_
