#include "algorithm.hpp"
#include <iostream>
#include <string>

using namespace std;

/* Data */
string HurryWithMyDessert::name = "Hurry With My Dessert";

vector<Tester::Test> HurryWithMyDessert::tests = {
    Tester::Test(1, "3\n1 (2 5) (7 6) (8 5) (9 10) (10 7) (29 9) (3 7) (12 4)\n2 (5 9) (7 5) (8 3) (9 4) (29 5) (14 7)\n3 (7 4) (8 4) (9 5) (29 6) (14 7)", "28 12 13 "),
    Tester::Test(2, "5\n1 (3 6) (29 5) (6 8) (11 5) (13 9) (15 7) (20 10) (7 8) (25 6) (30 4)\n2 (4 8) (6 7) (29 6) (7 5) (11 4) (13 6) (20 5) (25 9)\n3 (6 5) (29 2) (11 3) (8 6) (7 8) (25 6)\n4 (29 4) (11 6) (13 5) (15 7) (20 8) (25 6) (7 5)\n5 (7 4) (11 5) (13 7) (15 8) (20 6) (25 5) (29 6)", "24 44 19 5 35 ")};

/* ATENÇÃO: Para facilitar sua implementação, as linhas de ônibus foram fornecidas utilizando a estrutura de dados vector.
Cada linha é representada pela struct BusLine, definida no arquivo Header deste desafio.
Você deve, para cada linha, ler a string que lista os pontos de ônibus, salvá-los em alguma estrutura de dados adequada para o problema, e então utilizá-la como apoio para calcular o tempo total de viagem de cada linha.

Lembre-se de que o ônibus pode chegar até o final da linha, e, dessa forma, continuar o trajeto para o primeiro ponto listado.
A resposta deve ser retornada como uma string, indicando tempos decorridos nos percursos em cada uma.

DICA: não utilize o parâmetro input! Ele apresenta a entrada de forma não trivial de se separar. Utilize a função parseInputToBusLines para obter as linhas de ônibus. Ao ler cada bus_line, obtenha sua lista de pontos por: bus_line.bus_stops
*/

/* Implementation */
constexpr int aliceHouse = 7;
constexpr int club = 29;

struct BusStop
{
    int identifier;
    int time_to_next;
};

void insertPairIntoCollection(string pair, DoublyCircularLinkedList<BusStop> &list)
{
    size_t space_index = pair.find(" ");
    string bus_identifier_string = pair.substr(0, space_index);
    string time_to_next = pair.substr(space_index + 1, pair.length());

    BusStop bus_stop = {stoi(bus_identifier_string), stoi(time_to_next)};
    list.insertAtEnd(bus_stop);
}

string HurryWithMyDessert::main(string input)
{
    vector<BusLine> bus_lines = parseInputToBusLines(input);
    string output = "";

    for (auto bus_line : bus_lines)
    {
        DoublyCircularLinkedList<BusStop> doubly_circular_linked_list;
        string bus_stops_string = bus_line.bus_stops;

        // Create list with bus stops
        string separator = ") ";
        size_t start = 1;
        size_t end = bus_stops_string.find(separator);
        while (end != string::npos)
        {
            string pair = bus_stops_string.substr(start, end - start);
            insertPairIntoCollection(pair, doubly_circular_linked_list);

            start = end + separator.length() + 1;
            end = bus_stops_string.find(separator, start);
        }
        string last_pair = bus_stops_string.substr(start, end - start);
        insertPairIntoCollection(last_pair, doubly_circular_linked_list);

        // Find one of the important stops
        int list_length = doubly_circular_linked_list.getLength();
        int time_spent = 0;
        int important_stop_index = -1;
        bool travel_in_reverse_order = false;

        DoublyCircularLinkedList<BusStop>::Node<BusStop> *head = doubly_circular_linked_list.getNode(0);
        DoublyCircularLinkedList<BusStop>::Node<BusStop> *current = head;
        do
        {
            BusStop bus_stop = current->data;
            if (bus_stop.identifier == aliceHouse)
            {
                time_spent = 0;
                break;
            }
            else if (bus_stop.identifier == club)
            {
                travel_in_reverse_order = true;
                break;
            }
            time_spent += bus_stop.time_to_next;
            current = current->next;
        } while (current != head);

        if (travel_in_reverse_order)
        {
            current = head;
            while (current->data.identifier != aliceHouse)
            {
                current = current->previous;
                time_spent += current->data.time_to_next;
            }
        }
        else
        {
            while (current->data.identifier != club)
            {
                time_spent += current->data.time_to_next;
                current = current->next;
            }
        }

        output += to_string(time_spent) + " ";
    }

    return output;
}
