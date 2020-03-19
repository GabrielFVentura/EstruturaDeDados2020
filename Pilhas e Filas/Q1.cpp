/*Implemente uma pilha, utilizando armazenamento dos dados em arranjos (vetores). Segue esboço da implementação:

Não é necessário tratar problemas do tipo retirada de elemento de pilha vazia ou empilhamento em pilha cheia. 
A aplicação principal deverá criar uma pilha com capacidade para 20 elementos e realizar as seguintes operações na 
ordem apresentada:

Empilhar cinco elementos
Desempilhar três elementos (imprimindo-os)
Empilhar mais quatro elementos
Desempilhar três elementos (imprimindo-os)
Imprime o topo da pilha, sem desempilhar (espia())
Imprime os elementos restantes da pilha (depura())
Imprime tamanho e posição do topo (info())
Entradas:

Cinco valores a serem empilhados
Quatro valores a serem empilhados
Saídas:

Três elementos desempilhados
Três elementos desempilhados
Topo da pilha
Elementos restantes da pilha
Tamanho e posição do topo
Exemplo de Entrada:

8 9 1 3 5
12 23 0 3
Exemplo de Saída:

5 3 1
3 0 23
12
8 9 12
3 2*/
#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        pilhav(int cap = 100);
        //~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

int pilhav::

pilhav::pilhav(int cap)
{
    dados = new Dado[cap];
    tamanho = 0;
    capacidade = cap;
    posTopo = -1;
}

int main()
{
    pilhav pilha;
    pilha.empilha(5);
    return 0;
}