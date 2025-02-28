#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> buffer(5);

    // Adiciona elementos ao buffer
    buffer.enqueue(10);
    buffer.enqueue(20);
    buffer.enqueue(30);
    buffer.enqueue(40);
    buffer.enqueue(50);

    cout << "Buffer apos adicionar 5 elementos: ";
    buffer.display();

    buffer.enqueue(60);
    cout << "Buffer apos adicionar sexto elemento (sobrescreve o 10): ";
    buffer.display();

    cout << "Elemento removido: " << buffer.dequeue() << endl;
    cout << "Buffer apos remover um elemento: ";
    buffer.display();

    buffer.enqueue(70);
    buffer.enqueue(80);
    cout << "Buffer apos adicionar 70 e 80: ";
    buffer.display();

    while (!buffer.empty()) {
        cout << "Elemento removido: " << buffer.dequeue() << endl;
    }

    cout << "Buffer apos remover todos os elementos: ";
    buffer.display();

    return 0;
}