#ifndef LIST_H
#define LIST_H

template <class T>
class List
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node *head;
    Node *tail;

public:
    List();
    ~List();

    void push(T value);
    bool search(T value);
    void remove(T value);
    void show_all();
};

template <class T>
List<T>::List() : head(nullptr), tail(nullptr) {}

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
void List<T>::push(T value)
{
    Node *newNode = new Node(value);
    if (!head)
    {
        newNode->next = head;
        head = newNode;
        tail = newNode;
        return;
    }
    if (head->data > value)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next && current->next->data <= value)
        {
            current = current->next;
        }
        if (current == tail)
        {
            newNode->prev = current;
            current->next = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

template <class T>
void List<T>::show_all()
{
    if (!head)
    {
        std::cout << "Empty list" << std::endl;
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
    if (!head)
    {
        return;
    }

    if (search(value))
    {
        Node *current = head, *prev = nullptr;
        while (current->data != value)
        {
            prev = current;
            current = current->next;
        }
        if (!prev)
        {
            if (current->next)
            {
                current->next->prev = nullptr;
            }
            head = current->next;
        }
        else if (current == tail)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = current->next;
            current->next->prev = prev;
        }
        delete current;
    }
}

#endif