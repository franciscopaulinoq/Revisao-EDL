#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool verificar_balanceamento(const string &expressao)
{
    Stack<char> pilha;
    const string abertura = "({[";
    const string fechamento = ")}]";
    
    for (char caractere : expressao)
    {
        if (abertura.find(caractere) != string::npos)
        {
            pilha.push(caractere);
        }
        else
        {
            size_t pos = fechamento.find(caractere);
            if (pos != string::npos)
            {
                if (pilha.empty() || pilha.top() != abertura[pos])
                {
                    return false;
                }
                pilha.pop();
            }
        }
    }

    return pilha.empty();
}

int main()
{
    // string input;
    // cout << "Digite uma palavra: ";
    // cin >> input;

    // Stack<char> pilha;

    // for (char c : input)
    // {
    //     pilha.push(c);
    // }

    // cout << "Palavra invertida: ";
    // while (!pilha.empty())
    // {
    //     cout << pilha.top();
    //     pilha.pop();
    // }
    // cout << endl;

    string expressoes[] = {
        "(a + b)",
        "{[a * (b + c)]}",
        "a + {b - [c * d]}",
        "a + (b",
        "{[a * b]",
        "(a + b)}",
        "a + {b - [c * d}"
    };

    for (const string &exp : expressoes)
    {
        cout << "Expressao: " << exp << endl;
        cout << (verificar_balanceamento(exp) ? "Balanceada" : "Nao Balanceada") << endl;
        cout << string(30, '-') << endl;
    }

    return 0;
}