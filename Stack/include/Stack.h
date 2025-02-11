#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <class T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node *head;
    int _size;

public:
    Stack();
    ~Stack();

    void push(T value);
    void pop();
    T top();
    bool empty();
    int size();
};

template <class T>
Stack<T>::Stack() : head(nullptr), _size(0) {}

template <class T>
Stack<T>::~Stack()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void Stack<T>::push(T value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    _size++;
}

template <class T>
void Stack<T>::pop()
{
    if (empty())
    {
        std::cerr << "Empty stack" << std::endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    _size--;
}

template <class T>
T Stack<T>::top()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return head->data;
}

template <class T>
bool Stack<T>::empty()
{
    return head == nullptr;
}

template <class T>
int Stack<T>::size()
{
    return _size;
}

#endif