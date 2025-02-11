#include <iostream>
#include "List.h"

int main() {
    List<int> lista;

    lista.push_front(4);
    lista.push_front(3);
    lista.push_front(4);
    lista.push_front(2);
    lista.show_all();

    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(5);
    lista.push_back(7);
    lista.show_all();

    lista.remove(6);
    lista.show_all();

    lista.remove_duplicate();
    lista.show_all();

    return 0;
}