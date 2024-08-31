#ifndef QUEUE_HPP_
#define QUEUE_HPP_

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int length;

    bool isEmpty();
    void clear();

public:
    Queue();
    ~Queue();

    int getLength();
    void enqueue(T data);
    T dequeue();
    T peek();
};

template <typename T>
bool Queue<T>::isEmpty()
{
    return this->front == nullptr;
}

template <typename T>
void Queue<T>::clear()
{
    while (!this->isEmpty())
        this->dequeue();
}

template <typename T>
Queue<T>::Queue()
{
    this->front = nullptr;
    this->rear = nullptr;
    this->length = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    this->clear();
}

template <typename T>
int Queue<T>::getLength()
{
    return this->length;
}

template <typename T>
void Queue<T>::enqueue(T data)
{
    Node<T> *new_node = new Node<T>;
    new_node->data = data;
    new_node->next = nullptr;

    if (this->isEmpty())
    {
        this->front = new_node;
        this->rear = new_node;
    }
    else
    {
        this->rear->next = new_node;
        this->rear = new_node;
    }

    this->length++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (this->isEmpty())
        throw "Queue is empty";

    Node<T> *to_be_removed = this->front;
    T data = to_be_removed->data;

    this->front = this->front->next;
    delete to_be_removed;
    this->length--;

    return data;
}

template <typename T>
T Queue<T>::peek()
{
    if (this->isEmpty())
        throw "Queue is empty";

    return this->front->data;
}

#endif // QUEUE_HPP_
