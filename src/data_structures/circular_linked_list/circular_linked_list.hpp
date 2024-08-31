#ifndef CIRCULAR_LINKED_LIST_HPP_
#define CIRCULAR_LINKED_LIST_HPP_

#include <stdexcept>

using namespace std;

template <typename T>
class CircularLinkedList
{
public:
    template <typename U>
    struct Node
    {
        U data;
        Node *next;

        Node(U data) : data(data), next(nullptr) {}
    };

private:
    Node<T> *head;
    int length;

public:
    CircularLinkedList();
    ~CircularLinkedList();

    int getLength();
    Node<T> *getNode(int index);
    T getData(int index);

    void insert(int index, T data);
    void insertAtBeginning(T data);
    void insertAtEnd(T data);

    void remove(int index);
    void removeFirst();
    void removeLast();
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
    this->head = nullptr;
    this->length = 0;
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    if (this->head != nullptr)
    {
        auto current = this->head;
        auto next = current->next;
        while (next != this->head)
        {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
        this->head = nullptr;
        this->length = 0;
    }
}

template <typename T>
typename CircularLinkedList<T>::template Node<T> *CircularLinkedList<T>::getNode(int index)
{
    auto current = this->head;
    for (int i = 0; i < index && current != nullptr; ++i)
        current = current->next;

    if (current == nullptr)
        throw out_of_range("Index out of range");

    return current;
}

template <typename T>
void CircularLinkedList<T>::insert(int index, T data)
{
    auto newNode = new Node<T>(data);

    // Insert at the beginning
    if (index == 0)
    {
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->head->next = this->head;
            this->length++;
            return;
        }

        auto last = this->getNode(this->length - 1);
        newNode->next = this->head;
        last->next = newNode;
        this->head = newNode;
        this->length++;
        return;
    }

    // Insert at any other position
    auto before_new = this->getNode(index - 1);
    newNode->next = before_new->next;
    before_new->next = newNode;
    this->length++;
};

template <typename T>
void CircularLinkedList<T>::insertAtBeginning(T data)
{
    this->insert(0, data);
}

template <typename T>
void CircularLinkedList<T>::insertAtEnd(T data)
{
    this->insert(this->length, data);
}

template <typename T>
T CircularLinkedList<T>::getData(int index)
{
    auto current = this->getNode(index);
    return current->data;
}

template <typename T>
void CircularLinkedList<T>::remove(int index)
{
    // Remove at the beginning
    if (index == 0)
    {
        if (this->head == nullptr)
            throw out_of_range("Index out of range");

        if (this->length == 1)
        {
            delete this->head;
            this->head = nullptr;
        }
        else
        {
            auto last = this->getNode(this->length - 1);
            auto to_be_removed = this->head;
            this->head = this->head->next;
            last->next = this->head;
            delete to_be_removed;
        }
        this->length--;
        return;
    }

    // Remove at any other position
    auto before_to_be_removed = this->getNode(index - 1);
    auto to_be_removed = before_to_be_removed->next;
    before_to_be_removed->next = to_be_removed->next;
    delete to_be_removed;
    this->length--;
}

template <typename T>
void CircularLinkedList<T>::removeFirst()
{
    this->remove(0);
}

template <typename T>
void CircularLinkedList<T>::removeLast()
{
    this->remove(this->length - 1);
}

template <typename T>
int CircularLinkedList<T>::getLength()
{
    return this->length;
}

#endif // CIRCULAR_LINKED_LIST_HPP_
