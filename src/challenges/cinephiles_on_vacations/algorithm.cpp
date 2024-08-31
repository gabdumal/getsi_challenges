#include "algorithm.hpp"
#include <iostream>

using namespace std;

/* Data */
string CinephilesOnVacations::name = "Preferential Queues";

vector<Tester::Test> CinephilesOnVacations::tests = {
    Tester::Test(1, "7\nO_Poderoso_Chefao 5 5 5 5 5\nTitanic 5 4 5 4 5\nO_Rei_Leao 5 5 5 5 5\nO_Poderoso_Chefao 5 3 5 4 5\nO_Poderoso_Chefao 5 5 5 5 5\nTitanic 5 5 5 5 5\nE_o_Vento_Levou 5 3 5 5 5", "E_o_Vento_Levou 5.00 3.00 5.00 5.00 5.00\nO_Rei_Leao 5.00 5.00 5.00 5.00 5.00\nTitanic 5.00 4.50 5.00 4.50 5.00\nO_Poderoso_Chefao 5.00 4.33 5.00 4.66 5.00"),
    Tester::Test(2, "5\nInception 4 5 5 4 5\nAvatar 5 4 4 5 4\nInception 5 5 5 5 5\nThe_Dark_Knight 5 5 5 5 5\nAvatar 4 4 4 4 4", "The_Dark_Knight 5.00 5.00 5.00 5.00 5.00\nAvatar 4.50 4.00 4.00 4.50 4.00\nInception 4.50 5.00 5.00 4.50 5.00"),
    Tester::Test(3, "20\nInception 1 2 4 5 2\nAvatar 2 4 5 1 2\nThe_Dark_Knight 4 5 1 2 4\nTitanic 5 1 2 4 5\nInception 2 4 5 1 2\nAvatar 4 5 1 2 4\nThe_Dark_Knight 5 1 2 4 5\nTitanic 1 2 4 5 1\nInception 4 5 1 2 4\nAvatar 5 1 2 4 5\nThe_Dark_Knight 1 2 4 5 1\nTitanic 2 4 5 1 2\nInception 5 1 2 4 5\nAvatar 1 2 4 5 1\nThe_Dark_Knight 2 4 5 1 2\nTitanic 4 5 1 2 4\nInception 1 2 4 5 2\nAvatar 2 4 5 1 2\nThe_Dark_Knight 4 5 1 2 4\nTitanic 5 1 2 4 5", "The_Dark_Knight 3.20 3.40 2.60 2.80 3.20\nTitanic 3.40 2.60 2.80 3.20 3.40\nAvatar 2.80 3.20 3.40 2.60 2.80\nInception 2.60 2.80 3.20 3.40 3.00"),
};

/* ATENÇÃO: Para facilitar sua implementação, as notas dos filmes depositadas na urna são representadas pela struct Score, definida no arquivo Header deste desafio.
DICA: não utilize o parâmetro input! Ele apresenta a entrada de forma não trivial de se separar. Utilize a função parseInputToScores para obter as notas.

ATENÇÃO: Disponibilizamos também a estrutura Movie para você armazenar a soma das notas dos filmes, para facilitar o cálculo da média.
Utilize a função printMovies para imprimir os filmes e suas médias de notas.
Ambas estão implementadas no arquivo Header deste desafio.
*/

/* Implementation */
string CinephilesOnVacations::main(string input)
{
    vector<Score> scores = parseInputToScores(input);
    string output = "";

    UnorderedMap<string, Movie> movies;

    for (Score score : scores)
    {
        if (movies.contains(score.movie_name))
        {
            Movie movie = movies.at(score.movie_name);
            movie.quantity++;
            movie.plot_sum += score.plot;
            movie.acting_sum += score.acting;
            movie.direction_sum += score.direction;
            movie.soundtrack_sum += score.soundtrack;
            movie.special_effects_sum += score.special_effects;
            movies.update(score.movie_name, movie);
        }
        else
        {
            Movie movie = {1, score.plot, score.acting, score.direction, score.soundtrack, score.special_effects};
            movies.insert(score.movie_name, movie);
        }
    }

    output += printMovies(movies);

    return output;
}
