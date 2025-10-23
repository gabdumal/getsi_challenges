#ifndef __DOUBLY_CIRCULAR_LINKED_LIST_HPP__
#define __DOUBLY_CIRCULAR_LINKED_LIST_HPP__

#include <stdexcept>
using namespace std;

template<typename T>
class DoublyCircularLinkedList {
    public:
        template<typename U>
        struct Node {
                U data;
                Node *next;
                Node *previous;

                Node(U data): data(data), next(nullptr), previous(nullptr) {}
        };

    private:
        Node<T> *head;
        int length;

    public:
        DoublyCircularLinkedList();
        ~DoublyCircularLinkedList();

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

template<typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList() {
    this->head = nullptr;
    this->length = 0;
}

template<typename T>
DoublyCircularLinkedList<T>::~DoublyCircularLinkedList() {
    if (this->head != nullptr) {
        auto current = this->head;
        auto next = current->next;
        while (next != this->head) {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
        this->head = nullptr;
        this->length = 0;
    }
}

template<typename T>
typename DoublyCircularLinkedList<T>::template Node<T> *DoublyCircularLinkedList<T>::getNode(int index) {
    auto current = this->head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        throw out_of_range("Index out of range");
    }

    return current;
}

template<typename T>
void DoublyCircularLinkedList<T>::insert(int index, T data) {
    auto new_node = new Node<T>(data);

    // Insert at the beginning
    if (index == 0) {
        if (this->head == nullptr) {
            this->head = new_node;
            this->head->previous = this->head;
            this->head->next = this->head;
            this->length++;
            return;
        }

        auto last = this->getNode(this->length - 1);
        new_node->next = this->head;
        new_node->previous = last;
        last->next = new_node;
        this->head->previous = new_node;
        this->head = new_node;
        this->length++;
        return;
    }

    // Insert at any other position
    auto before_new = this->getNode(index - 1);
    new_node->next = before_new->next;
    new_node->previous = before_new;
    before_new->next->previous = new_node;
    before_new->next = new_node;
    this->length++;
};

template<typename T>
void DoublyCircularLinkedList<T>::insertAtBeginning(T data) {
    this->insert(0, data);
}

template<typename T>
void DoublyCircularLinkedList<T>::insertAtEnd(T data) {
    this->insert(this->length, data);
}

template<typename T>
T DoublyCircularLinkedList<T>::getData(int index) {
    auto current = this->getNode(index);
    return current->data;
}

template<typename T>
void DoublyCircularLinkedList<T>::remove(int index) {
    // Remove at the beginning
    if (index == 0) {
        if (this->head == nullptr) {
            throw out_of_range("Index out of range");
        }

        if (this->length == 1) {
            delete this->head;
            this->head = nullptr;
        } else {
            auto last = this->getNode(this->length - 1);
            auto to_be_removed = this->head;
            this->head = this->head->next;
            this->head->previous = last;
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
    to_be_removed->next->previous = before_to_be_removed;
    delete to_be_removed;
    this->length--;
}

template<typename T>
void DoublyCircularLinkedList<T>::removeFirst() {
    this->remove(0);
}

template<typename T>
void DoublyCircularLinkedList<T>::removeLast() {
    this->remove(this->length - 1);
}

template<typename T>
int DoublyCircularLinkedList<T>::getLength() {
    return this->length;
}

#endif  // __DOUBLY_CIRCULAR_LINKED_LIST_HPP__
