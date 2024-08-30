#ifndef _CONSOLE_COLORS_HPP
#define _CONSOLE_COLORS_HPP

#include <iostream>

namespace ConsoleColors
{
    using namespace std;

    constexpr const char *tab = "    ";

    enum Color
    {
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37,
        DEFAULT = 39,
        BRIGHT_BLACK = 90,
        BRIGHT_RED = 91,
        BRIGHT_GREEN = 92,
        BRIGHT_YELLOW = 93,
        BRIGHT_BLUE = 94,
        BRIGHT_MAGENTA = 95,
        BRIGHT_CYAN = 96,
        BRIGHT_WHITE = 97,
        BRIGHT_DEFAULT = 99
    };

    enum Decoration
    {
        NONE = 0,
        BOLD = 1,
        DIM = 2,
        UNDERLINED = 4,
        BLINK = 5,
        REVERSE = 7,
        HIDDEN = 8
    };

    void setColor(ostream &outputStream, Color color = Color::DEFAULT, Color backgroundColor = Color::DEFAULT);
    void resetColor(ostream &outputStream);

    void setDecoration(ostream &outputStream, Decoration decoration);
    void resetDecoration(ostream &outputStream);

    void printInformation(string header, string information, ostream &outputStream, Color headerColor = Color::DEFAULT, Color headerBackgroundColor = Color::DEFAULT, Color informationColor = Color::DEFAULT, Color informationBackgroundColor = Color::DEFAULT);
}

#endif // _CONSOLE_COLORS_HPP