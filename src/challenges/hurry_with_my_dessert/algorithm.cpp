#include "algorithm.hpp"
#include <iostream>

using namespace std;

/* Data */
string HurryWithMyDessert::name = "Hurry With My Dessert";

vector<Tester::Test> HurryWithMyDessert::tests = {
    Tester::Test(1, "3\n1 (2 5) (7 6) (8 5) (9 10) (10 7) (29 9) (3 7) (12 4)\n2 (5 9) (7 5) (8 3) (9 4) (29 5) (14 7)\n3 (7 4) (8 4) (9 5) (29 6) (14 7)", "2 12"),
    Tester::Test(2, "1 (3 6) (29 5) (6 8) (11 5) (13 9) (15 7) (20 10) (7 8) (25 6) (30 4)\n2 (4 8) (6 7) (11 4) (13 6) (20 5) (25 9)\n3 (6 5) (29 2) (11 3) (8 6) (7 8) (25 6)\n4 (29 4) (11 6) (13 5) (15 7) (20 8) (25 6) (7 5)\n5 (7 4) (11 5) (13 7) (15 8) (20 6) (25 5) (29 6)", "")};

/* Implementation */
string HurryWithMyDessert::main(string input)
{
    /* ATENÇÃO: As linhas de ônibus e os paradas de cada foram fornecidas utilizando a estrutura de dados vector.
    Entretanto, essa NÃO é a estrutura ideal para o problema.
    Descubra qual é a ED que facilita a implementação do código*/
    vector<BusLine> bus_lines = parseInputToBusLines(input);
    return "";
}
