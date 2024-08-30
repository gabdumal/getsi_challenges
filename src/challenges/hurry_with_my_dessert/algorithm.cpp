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
    /* ATENÇÃO: Para facilitar sua implementação, as linhas de ônibus foram fornecidas utilizando a estrutura de dados vector.
    Cada linha é representada pela struct BusLine, definida no arquivo Header deste desafio.
    Você deve, para cada linha, ler a string que lista os pontos de ônibus, salvá-los em alguma estrutura de dados adequada para o problema, e então utilizá-la como apoio para calcular o tempo total de viagem de cada linha.
    Lembre-se de que o ônibus pode chegar até o final da linha, e, dessa forma, continuar o trajeto para o primeiro ponto listado.
    A resposta deve ser retornada como uma string, indicando o número da linha com o menor tempo total de viagem e este tempo total percorrido nela.
    */

    vector<BusLine> bus_lines = parseInputToBusLines(input);

    return "Linha Tempo";
}
