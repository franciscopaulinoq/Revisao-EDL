#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Queue {
private:
    int capacity;
    T* data;
    int head;
    int tail;
    int currentSize;

public:
    Queue(int capacity = 10);
    ~Queue();

    void enqueue(T value);
    T dequeue();
    T top() const;
    bool empty() const;
    bool full() const;
    void display() const;
};

template <class T>
Queue<T>::Queue(int capacity) : capacity(capacity), head(0), tail(0), currentSize(0) {
    data = new T[capacity];
}

template <class T>
Queue<T>::~Queue() {
    delete[] data;
}

template <class T>
void Queue<T>::enqueue(T value) {
    if (full()) {
        head = (head + 1) % capacity;
        currentSize--;
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    currentSize++;
}

template <class T>
T Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("Fila vazia: nao e possivel remover elementos.");
    }
    T value = data[head];
    head = (head + 1) % capacity;
    currentSize--;
    return value;
}

template <class T>
T Queue<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Fila vazia: nao e possível acessar o topo.");
    }
    return data[head];
}

template <class T>
bool Queue<T>::empty() const {
    return currentSize == 0;
}

template <class T>
bool Queue<T>::full() const {
    return currentSize == capacity;
}

template <class T>
void Queue<T>::display() const {
    if (empty()) {
        std::cout << "Fila vazia." << std::endl;
        return;
    }

    int index = head;
    for (int i = 0; i < currentSize; i++) {
        std::cout << data[index] << " ";
        index = (index + 1) % capacity;
    }
    std::cout << std::endl;
}

#endif