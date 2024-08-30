#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int length;

public:
    LinkedList();
    ~LinkedList();

    void insert(int index, T data);
    void insertAtBeginning(T data);
    void insertAtEnd(T data);
    Node<T> *getNode(int index);
    T getData(int index);
    void remove(int index);
    void removeFirst();
    void removeLast();
    int getLength();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    auto current = this->head;
    while (current != nullptr)
    {
        auto next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
Node<T> *LinkedList<T>::getNode(int index)
{
    auto current = this->head;
    for (int i = 0; i < index && current != nullptr; ++i)
        current = current->next;

    if (current == nullptr)
        throw out_of_range("Index out of range");

    return current;
}

template <typename T>
void LinkedList<T>::insert(int index, T data)
{
    auto newNode = new Node<T>(data);

    // Insert at the beginning
    if (index == 0)
    {
        newNode->next = this->head;
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
void LinkedList<T>::insertAtBeginning(T data)
{
    this->insert(0, data);
}

template <typename T>
void LinkedList<T>::insertAtEnd(T data)
{
    this->insert(this->length, data);
}

template <typename T>
T LinkedList<T>::getData(int index)
{
    auto current = this->getNode(index);
    return current->data;
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    // Remove at the beginning
    if (index == 0)
    {
        if (this->head == nullptr)
            throw out_of_range("Index out of range");

        this->head = this->head->next;
        this->length--;
        return;
    }

    // Remove at any other position
    auto before_to_be_removed = this->getNode(index - 1);
    before_to_be_removed->next = before_to_be_removed->next->next;
    this->length--;
}

template <typename T>
void LinkedList<T>::removeFirst()
{
    this->remove(0);
}

template <typename T>
void LinkedList<T>::removeLast()
{
    this->remove(this->length - 1);
}

template <typename T>
int LinkedList<T>::getLength()
{
    return this->length;
}

#endif // LINKED_LIST_HPP_
