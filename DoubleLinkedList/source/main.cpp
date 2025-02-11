#include <iostream>
#include "List.h"

int main() {

    List<int> lista;
    lista.push(2);
    lista.push(1);
    lista.push(5);
    lista.push(10);
    lista.push(7);
    lista.show_all();

    lista.remove(5);
    lista.remove(7);
    lista.remove(1);
    lista.remove(10);
    lista.show_all();
    lista.remove(2);
    lista.show_all();

    return 0;
}