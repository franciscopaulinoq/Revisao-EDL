#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class List
{
protected:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node *head;

public:
    List();
    ~List();

    void push_front(T value);
    void push_back(T value);
    bool search(T value);
    void remove(T value);
    void show_all();

    void remove_duplicate();

    Node* getHead() const { return head; }
};

template <class T>
List<T>::List() : head(nullptr) {}

template <class T>
List<T>::~List()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void List<T>::push_front(T value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template <class T>
void List<T>::push_back(T value)
{
    if (!head)
    {
        push_front(value);
        return;
    }

    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }

    Node *newNode = new Node(value);
    current->next = newNode;
}

template <class T>
bool List<T>::search(T value)
{
    Node *current = head;
    while (current)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
void List<T>::remove(T value)
{
    if (search(value))
    {
        Node *prev = nullptr, *current = head;
        while (current && current->data != value)
        {
            prev = current;
            current = current->next;
        }
        if (prev)
        {
            prev->next = current->next;
        }
        else
        {
            head = current->next;
        }
        delete current;
    }
}

template <class T>
void List<T>::show_all()
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

template <class T>
void List<T>::remove_duplicate()
{
    Node *temp1 = head;
    while (temp1)
    {
        Node *temp2 = temp1;
        while (temp2->next)
        {
            if (temp2->next->data == temp1->data)
            {
                Node *duplicate = temp2->next;
                temp2->next = temp2->next->next;
                delete duplicate;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

#endif