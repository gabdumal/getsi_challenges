#ifndef STACK_HPP_
#define STACK_HPP_

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int length;

    bool isEmpty();
    void clear();

public:
    Stack();
    ~Stack();

    int getLength();
    void push(T data);
    T pop();
    T peek();
};

template <typename T>
bool Stack<T>::isEmpty()
{
    return this->front == nullptr;
}

template <typename T>
void Stack<T>::clear()
{
    while (!this->isEmpty())
        this->pop();
}

template <typename T>
Stack<T>::Stack()
{
    this->head = nullptr;
    this->length = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    this->clear();
}

template <typename T>
int Stack<T>::getLength()
{
    return this->length;
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = data;
    new_node->next = this->head;

    this->head = new_node;
    this->length++;
}

template <typename T>
T Stack<T>::pop()
{
    if (this->isEmpty())
        throw "Stack is empty";

    Node<T> *to_be_removed = this->head;
    T data = to_be_removed->data;

    this->head = this->head->next;
    delete to_be_removed;
    this->length--;

    return data;
}

template <typename T>
T Stack<T>::peek()
{
    if (this->isEmpty())
        throw "Stack is empty";

    return this->head->data;
}

#endif // STACK_HPP_
