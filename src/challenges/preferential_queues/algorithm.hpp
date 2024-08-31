#ifndef PREFERENTIAL_QUEUES_HPP_
#define PREFERENTIAL_QUEUES_HPP_

#include "../../data_structures/queue/queue.hpp"
#include <tester.hpp>
#include <vector>

using namespace std;

class PreferentialQueues
{
public:
    struct Client
    {
        int age;
        int arrival_time;
        int service_time;
    };

private:
    static string name;
    static vector<Tester::Test> tests;

public:
    static vector<Client> parseInputToClients(string input)
    {
        try
        {
            size_t start = 0;
            size_t end = input.find("\n");
            string quantity_string = input.substr(start, end);
            int quantity = stoi(quantity_string);

            vector<Client> clients(quantity);
            start = start + end + 1;
            end = input.find("\n", end + 1);
            for (int i = 0; i < quantity; i++)
            {
                string client = input.substr(start, end - start);
                string age = client.substr(0, client.find(" "));
                client = client.substr(age.length() + 1, client.length());
                string arrival_time = client.substr(0, client.find(" "));
                client = client.substr(arrival_time.length() + 1, client.length());
                clients[i] = {stoi(age), stoi(arrival_time), stoi(client)};
                start = end + 1;
                end = input.find("\n", start);
            }
            return clients;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return {};
    }

    static vector<Client> get_clients_that_arrived_at(int minute, vector<Client> all_clients);

    static void enqueue_client(Client client, Queue<Client> &regular, Queue<Client> &preferential, Queue<Client> &urgent);

    static bool are_there_any_clients_to_dequeue(Queue<Client> &regular, Queue<Client> &preferential, Queue<Client> &urgent)
    {
        return !urgent.isEmpty() || !preferential.isEmpty() || !regular.isEmpty();
    }

    static Client dequeue_client(Queue<Client> &regular, Queue<Client> &preferential, Queue<Client> &urgent);

    static vector<Tester::Test> getTests()
    {
        return tests;
    }

    static string run(vector<int> input_identifiers)
    {
        vector<Tester::Test> selected_tests = Tester::pickTests(getTests(), input_identifiers);
        return Tester::runTests(name, selected_tests, main);
    }

    static string main(string input);
};

#endif // PREFERENTIAL_QUEUES_HPP_
