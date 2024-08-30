#include <console_colors.hpp>
#include <sstream>

using namespace std;

void ConsoleColors::setColor(ostream &outputStream, Color color, Color backgroundColor)
{
    outputStream << "\033[" << color << ";" << backgroundColor + 10 << "m";
}

void ConsoleColors::resetColor(ostream &outputStream)
{
    setColor(outputStream, Color::DEFAULT, Color::DEFAULT);
}

void ConsoleColors::setDecoration(ostream &outputStream, Decoration decoration)
{
    outputStream << "\033[" << decoration << "m";
}

void ConsoleColors::resetDecoration(ostream &outputStream)
{
    setDecoration(outputStream, Decoration::NONE);
}

void ConsoleColors::printInformation(string header, string information, ostream &outputStream, Color headerColor, Color headerBackgroundColor, Color informationColor, Color informationBackgroundColor)
{
    ostringstream intermediateStream;
    setColor(intermediateStream, headerColor, headerBackgroundColor);
    intermediateStream << header;
    resetColor(intermediateStream);
    intermediateStream << endl;

    setColor(intermediateStream, informationColor, informationBackgroundColor);
    std::istringstream informationStream(information);
    std::string line;
    while (std::getline(informationStream, line))
        intermediateStream << tab << line << endl;
    resetColor(intermediateStream);
    intermediateStream << endl;

    outputStream << intermediateStream.str();
}
