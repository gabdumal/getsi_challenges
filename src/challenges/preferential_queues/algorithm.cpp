#include "algorithm.hpp"
#include <iostream>
#include <string>

using namespace std;

/* Data */
string PreferentialQueues::name = "Preferential Queues";

vector<Tester::Test> PreferentialQueues::tests = {
    Tester::Test(1, "6\n49 0 5\n89 0 10\n67 15 6\n16 21 3\n29 22 4\n80 22 8", "89 49 67 16 80 29"),
    Tester::Test(2, "12\n49 0 5\n89 0 10\n67 15 6\n16 21 3\n29 22 4\n80 22 8\n49 30 5\n89 30 10\n67 45 6\n16 51 3\n29 52 4\n80 52 8", "89 49 67 16 80 89 29 67 80 49 16 29"),
};

/* ATENÇÃO: Para facilitar sua implementação, os clientes que chegam à loja foram fornecidos utilizando a estrutura de dados vector.
Cada entrada é representada pela struct Client, definida no arquivo Header deste desafio.

DICA: não utilize o parâmetro input! Ele apresenta a entrada de forma não trivial de se separar. Utilize a função parseInputToClients para obter os clientes.
*/

/* Implementation */
constexpr int shift_duration = 180;
constexpr int urgent_queue_age = 80;
constexpr int preferential_queue_age = 60;

string PreferentialQueues::main(string input)
{
    vector<Client> clients = parseInputToClients(input);
    string output = "";

    Queue<Client> attended_clients;
    Queue<Client> regular;
    Queue<Client> preferential;
    Queue<Client> urgent;

    int remaining_time_for_current_client = 0;
    int minute = 0;
    while (minute <= shift_duration && attended_clients.getLength() <= clients.size())
    {
        // Arriving clients go to their respective queues
        /* Your code here */

        // When there are no clients being attended, select one if there are any waiting
        /* Your code here */

        remaining_time_for_current_client--;
        minute++;
    }

    int total_clients = attended_clients.getLength();
    for (int i = 0; i < total_clients; i++)
    {
        Client client = attended_clients.dequeue();
        output += to_string(client.age) + " ";
    }

    return output;
}

vector<PreferentialQueues::Client> PreferentialQueues::get_clients_that_arrived_at(int minute, vector<Client> all_clients)
{
    /* Your code here */
    return {};
}

void PreferentialQueues::enqueue_client(Client client, Queue<Client> &regular, Queue<Client> &preferential, Queue<Client> &urgent)
{
    /* Your code here */
    return;
}

PreferentialQueues::Client PreferentialQueues::dequeue_client(Queue<Client> &regular, Queue<Client> &preferential, Queue<Client> &urgent)
{
    /* Your code here */
    throw "No clients to dequeue";
}
