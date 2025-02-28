#include <iostream>
#include <string>
#include <stdexcept>
#include "Queue.h"

struct Cliente {
    int numero;
    Cliente(int num) : numero(num) {}

    friend std::ostream& operator<<(std::ostream& os, const Cliente& cliente) {
        os << "Cliente " << cliente.numero;
        return os;
    }
};

struct Documento {
    std::string nome;
    bool urgente;

    Documento(std::string nome, bool urgente) : nome(nome), urgente(urgente) {}

    friend std::ostream& operator<<(std::ostream& os, const Documento& doc) {
        os << doc.nome << " (" << (doc.urgente ? "Urgente" : "Normal") << ")";
        return os;
    }
};

void atenderDocumentosUrgentes(Queue<Documento>& fila) {
    Queue<Documento> filaTemporaria;

    while (!fila.empty()) {
        Documento doc = fila.top();
        if (doc.urgente) {
            std::cout << "Imprimindo documento urgente: " << doc << std::endl;
        } else {
            filaTemporaria.enqueue(doc);
        }
        fila.dequeue();
    }

    while (!filaTemporaria.empty()) {
        Documento doc = filaTemporaria.top();
        std::cout << "Imprimindo documento normal: " << doc << std::endl;
        filaTemporaria.dequeue();
    }
}

int main() {
    // Questão 8: Simulação de Atendimento
    Queue<Cliente> filaAtendimento;

    filaAtendimento.enqueue(Cliente(1));
    filaAtendimento.enqueue(Cliente(2));
    filaAtendimento.enqueue(Cliente(3));

    std::cout << "Clientes na fila de atendimento: ";
    filaAtendimento.display();

    if (!filaAtendimento.empty()) {
        std::cout << "Atendendo cliente: " << filaAtendimento.top() << std::endl;
        filaAtendimento.dequeue();
    } else {
        std::cout << "Nenhum cliente na fila para atender." << std::endl;
    }

    std::cout << "Clientes restantes na fila: ";
    filaAtendimento.display();

    // Questão 9: Fila de Impressão de Documentos
    Queue<Documento> filaImpressao;

    filaImpressao.enqueue(Documento("Relatorio1", false));
    filaImpressao.enqueue(Documento("Relatorio2", true));
    filaImpressao.enqueue(Documento("Relatorio3", false));

    std::cout << "Documentos na fila de impressao: ";
    filaImpressao.display();

    atenderDocumentosUrgentes(filaImpressao);

    return 0;
}