/*Considere os TADs e métodos estudados para a implementação de uma pilha. Implemente uma função acessarElemento(pilha,elemento) que, dada uma pilha, acessa o dado escolhido, retirando-o da estrutura. Os demais elementos da pilha devem continuar armazenados após a remoção do elemento.

Após a remoção, a função deve retornar a posição do elemento na pilha, considerando o topo como elemento de posição 1. Caso o elemento não esteja na pilha o programa deve retornar o valor -1. A pilha só irá armazenar valores naturais.

Ao término do programa, a pilha contendo os demais elementos deve ser impressa em seguida. Você pode utilizar o código fornecido como base para sua implementação, lembrando-se de não desrespeitar as propriedades da estrutura pilha.

Dica: utilize estruturas auxiliares (como uma pilha auxiliar) para implementar a função de acesso.

Entradas:

Número de elementos a serem inseridos na pilha.
Elementos da pilha em ordem de inserção
Elemento a ser acessado na pilha
Saídas:

Posição do elemento na pilha
Impressão dos elementos da pilha (por desempilhamento)
Exemplo de Entrada 1:

5
3 6 8 1 9 
8
Exemplo de Saída:

3
9 1 6 3
Exemplo de Entrada 2:

10
5 1 2 3 8 6 1 9 12 19
81
Exemplo de Saída:

-1
19 12 9 1 6 8 3 2 1 5
Exemplo de Entrada 3:

7
3 6 8 1 9 20 21
8
Exemplo de Saída:

5
21 20 9 1 6 3 

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

Classe pilha, um pilha (LIFO) implementada usando encadeamento
 *
 * by Joukim, 2017, Estruturas de Dados
 *
 */

#include <iostream>

using namespace std;

class noh {
friend class pilha;
private:
    int dado; // poderia ser outro tipo de variÃ¡vel
    noh* prox;
};

// pilha dinamicamente encadeada
class pilha {
private:
    noh* topo;
    int tamanho;

public:
    pilha(){
        topo = NULL;
        tamanho = 0;
    };
    ~pilha(){
        delete topo;
    };
    void push(int d) { empilha(d); }
    void empilha(int d){
        noh* nohTemp = new noh();
        nohTemp->dado = d;
        nohTemp->prox = topo;
        topo = nohTemp;
        tamanho++;
    };
    int pop() { return desempilha(); }
    int desempilha(){
        if (tamanho == 0){
            topo = NULL;
            return -1;
        }
        noh* nohTemp = topo;
        int removido = nohTemp->dado;
        topo = topo->prox;
        delete nohTemp;
        tamanho--;

        return removido;
    }; // retorna o topo da pilha

    int espia(){
        return topo->dado;
    }; // espia o topo da pilha
    bool vazia(){
        return tamanho == 0;
    };
    void limpaPilha(){
        while (!vazia()){
            desempilha();
        }
    }; //limpa a pilha
};

/* implementar os métodos da pilha */


//  Implementar aqui
int acessaElemento(pilha& p1, int elemento){
    int indice = 0;
    int indiceResp = 1;
    pilha pilhaAux;
    while (!p1.vazia()){
        int valorDesempilhado = p1.desempilha();
        if (valorDesempilhado == elemento){
            indiceResp += indice;
        } else { 
            pilhaAux.empilha(valorDesempilhado);
            indice++;
        }
    }
    if (indiceResp == 1)
        indiceResp = -1;

    while (!pilhaAux.vazia()){
        int valorDesempilhadoAux = pilhaAux.desempilha();
        p1.empilha(valorDesempilhadoAux);
    }
    return indiceResp;
//  Implementar aqui
}

int main() {
    pilha p1;
    int n, numero, elemento;
    cin >> n;

    while (n > 0) {
        cin >> numero;
        p1.empilha(numero);
        n--;
    }

    cin >> elemento;
    cout << acessaElemento(p1,elemento) << endl;

    while (not p1.vazia()) {
        cout << p1.desempilha() << " ";
    }

    cout << endl;

    return 0;
}