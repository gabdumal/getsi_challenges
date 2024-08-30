#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data);
    ~Node();

    template <typename U>
    friend class LinkedList;
};

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::~Node() {}

#endif // NODE_HPP