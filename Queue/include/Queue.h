#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    Queue();
    ~Queue();

    void enqueue(T value);
    T top();
    void dequeue();
    bool empty();
    void display();
};

template <class T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template <class T>
Queue<T>::~Queue()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void Queue<T>::enqueue(T value)
{
    Node *newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

template <class T>
void Queue<T>::dequeue()
{
    if (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        // Se a fila ficar vazia, atualiza tail para nullptr
        if (!head)
        {
            tail = nullptr;
        }
    }
}

template <class T>
bool Queue<T>::empty()
{
    return head == nullptr;
}

template <class T>
T Queue<T>::top()
{
    if (empty())
    {
        throw std::runtime_error("Fila vazia: não é possível acessar o topo.");
    }
    return head->data;
}

template <class T>
void Queue<T>::display()
{
    if (empty())
    {
        std::cout << "Fila vazia." << std::endl;
        return;
    }

    Node *current = head;
    while (current->next)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << current->data << std::endl;
}

#endif