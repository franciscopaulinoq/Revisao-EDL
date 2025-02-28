#include <iostream>
#include "List.h"

template <class T>
class CircularList : public List<T>
{
public:
    void make_circular();
    T josephus(int k);
};

template <class T>
void CircularList<T>::make_circular()
{
    if (!this->head)
        return;

    typename List<T>::Node *current = this->head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = this->head;
}

template <class T>
T CircularList<T>::josephus(int k)
{
    if (!this->head)
        throw std::runtime_error("List is empty");

    typename List<T>::Node *current = this->head;
    typename List<T>::Node *prev = nullptr;

    while (current->next != this->head)
    {
        prev = current;
        current = current->next;
    }

    while (current->next != current)
    {
        for (int i = 0; i < k; ++i)
        {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        std::cout << "Eliminando pessoa " << current->data << std::endl;
        delete current;
        current = prev->next;
    }

    T survivor = current->data;
    delete current;
    this->head = nullptr;
    return survivor;
}

int main()
{
    CircularList<int> circle;
    int N, K;

    std::cout << "Digite o numero de pessoas (N): ";
    std::cin >> N;
    std::cout << "Digite o numero de passos (K): ";
    std::cin >> K;

    for (int i = 1; i <= N; ++i)
    {
        circle.push_back(i);
    }

    circle.make_circular();

    int survivor = circle.josephus(K);
    std::cout << "A pessoa sobrevivente e: " << survivor << std::endl;

    return 0;
}