/*Faça um programa que lê uma linha de texto e verifica se todo parênteses tem um correspondente. Assuma que cada sinal de "fecha parênteses" fecha o último "abre parênteses".

Caso não existam parênteses correspondentes em todos os casos, o programa deve escrever a posição do erro. A posição do primeiro caractere é zero. Se todos os parênteses têm correspondentes, o programa deverá escrever "correto" (letras minúsculas). A posição do erro no caso de um "fecha parênteses" sem correspondente é a dele mesmo, pois não é preciso olhar o resto do texto para saber que há erro. A posição do erro no caso de um "abre parênteses" sem correspondente é a do último "abre parênteses" visto, pois só é possível saber que ele não tem correspondente ao final do texto.

É permitido usar esse código que já tem o tipo Pilha implementado.

Este é um exercício de solução de problema usando pilha. A pilha deve ser parte importante da solução. A classe Pilha não deve ser alterada.

Entradas:

Uma linha de texto (não mais do que 254 caracteres).
Saídas:

A palavra "correto" se todos tiverem correspondentes ou então a posição do erro.
Exemplo de Entrada 1:

func(x, (y+3)*4)
Exemplo de Saída 1:

correto
Exemplo de Entrada 2:

(idw ( dpq() sho
Exemplo de Saída 2:

5
Exemplo de Entrada 3:

(12 + 3) * 4 - 2)
Exemplo de Saída 3:

16*/

#include <iostream>
#include <string>

typedef int TipoDado;

using namespace std;

class noh {
    friend class Pilha;
    private:
        TipoDado dado;
        noh* prox;
};

// Pilha dinamicamente encadeada
class Pilha {
    private:
        noh* topo;
        int tamanho;
        
    public:
        Pilha();
        ~Pilha();

        // Coloca um dado na pilha.
        void push(TipoDado d) { empilha(d); }
        void empilha(TipoDado d);

        // Retira e retorna um valor da pilha. Requer que a pilha nÃ£o esteja vazia.
        TipoDado desempilha();
        TipoDado pop() { return desempilha(); } 

        bool vazia();
};

Pilha::Pilha() {
    tamanho = 0;
    topo = NULL;
}

Pilha::~Pilha() {
    while (topo != NULL) {
        desempilha();
    }
}

void Pilha::empilha(TipoDado d) {
    // primeiro criamos o novo nÃ³
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = topo;
    topo = temp;
    tamanho++;    
}

// Retira e retorna um valor da pilha. Requer que a pilha nÃ£o esteja vazia.
TipoDado Pilha::desempilha() {
    TipoDado removido = topo->dado;
    noh* temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;    
}

bool Pilha::vazia() {
    return (topo == NULL);
}

int main() {
    return 0;
}