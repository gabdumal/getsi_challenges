#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include "node.hpp"
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class LinkedList
{
private:
    shared_ptr<Node<T>> head;

public:
    LinkedList();
    ~LinkedList();

    void insert(int index, T data);
    T get(int index);
    void remove(int index);
    void print();
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr)
{
}

template <typename T>
LinkedList<T>::~LinkedList() {}

template <typename T>
void LinkedList<T>::insert(int index, T data)
{
    auto newNode = make_shared<Node<T>>(data);
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    auto current = head;
    for (int i = 0; i < index - 1 && current != nullptr; ++i)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        throw out_of_range("Index out of range");
    }

    newNode->next = current->next;
    current->next = newNode;
};

template <typename T>
T LinkedList<T>::get(int index)
{
    auto current = head;
    for (int i = 0; i < index && current != nullptr; ++i)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        throw out_of_range("Index out of range");
    }

    return current->data;
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    if (index == 0)
    {
        if (head == nullptr)
        {
            throw out_of_range("Index out of range");
        }
        head = head->next;
        return;
    }

    auto current = head;
    for (int i = 0; i < index - 1 && current != nullptr; ++i)
    {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr)
    {
        throw out_of_range("Index out of range");
    }

    current->next = current->next->next;
}

template <typename T>
void LinkedList<T>::print()
{
    auto current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

#endif // LINKED_LIST_HPP_
