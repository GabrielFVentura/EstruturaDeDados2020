/*Implemente uma estrutura de dados do tipo fila, utilizando para isso duas pilhas, sendo que a fila em si não possui nenhuma forma de armazenamento (os dados são armazenados utilizando as pilhas apenas). Dessa maneira, as operações de enfileiramento e desenfileiramento deverão ser implementadas usando métodos das pilhas em si. Você deve utilizar para isso, o código fornecido pelos professores como base para a implementação.

Entradas:

Número de elementos a serem enfileirados
Lista de números para inserção na fila
Número de elementos a serem desenfileirados
Número de elementos a serem enfileirados
Lista de números para inserção na fila
Número de elementos a serem desenfileirados
Número de elementos a serem desenfileirados
Saídas:

Elementos desenfileirados
Elementos desenfileirados
Elementos desenfileirados
Número de elementos ainda existentes na fila
Exemplo de Entrada:

10
1 2 3 4 5 6 7 8 9 10
5
10
1 2 3 4 5 11 12 13 14 15
5
5
Exemplo de Saída:

1 2 3 4 5 
6 7 8 9 10 
1 2 3 4 5 
5
Exemplo de Entrada:

12
1 2 3 4 5 6 7 8 9 10 11 12
8
10
21 22 23 24 25 26 12 13 14 15
5
9
Exemplo de Saída:

1 2 3 4 5 6 7 8 
9 10 11 12 21 
22 23 24 25 26 12 13 14 15 
0*/

/* Classe fila em pilhas, uma fila implementada usando simulaÃ§Ã£o em pilha 
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
    pilha();
    ~pilha();
    void push(int d) { empilha(d); }
    void empilha(int d);
    int pop() { return desempilha(); } 
    int desempilha(); // retorna o topo da pilha
    int espia(); // espia o topo da pilha
    bool vazia();
    void limpaPilha(); //limpa a pilha    
};


pilha::pilha() {
    tamanho = 0;
    topo = NULL;
}

pilha::~pilha() { // idÃªntica Ã  limpaPilha, mas sem impressÃ£o
    while (topo != NULL) {
        desempilha();
    }
}

void pilha::empilha(int d) {
    // primeiro criamos o novo nÃ³
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = topo;
    topo = temp;
    tamanho++;    
}

int pilha::desempilha() {
    int removido;
    noh* temp;
    removido = topo->dado;
    temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;    
}

int pilha::espia(){
    return topo->dado;
}

void pilha::limpaPilha(){
    while (topo != NULL) {
        cout << desempilha() << endl;
    }
}
    
bool pilha::vazia() {
    return (topo == NULL);
}


// fila implementada em pilha
class fila {
private:
    pilha p1;
    pilha p2;
    int tamanho;    
public:
    fila();
    ~fila();
    void enqueue(int d) { enfileira(d); }
    void insere(int d) { enfileira(d); }
    void enfileira(int d); // insere no final da fila
    int dequeue() { return desenfileira(); } 
    int retira() { return desenfileira(); } 
    int desenfileira(); // retorna o primeiro elemento da fila
    bool vazia();
    void limpaFila(); //limpa a pilha  
    int getTamanho();  
};


fila::fila() {
    tamanho = 0;
}

fila::~fila() { // idÃªntica Ã  limpaFila, mas sem impressÃ£o
    while (tamanho != 0) {
        desenfileira();
    }
}

void fila::enfileira(int d) {
/* perdida nos mares do sul */
}


int fila::desenfileira() {
/* perdida nos mares do norte */ 
}


void fila::limpaFila(){
    while (tamanho != 0) {
        cout << desenfileira() << endl;
    }
}
    
bool fila::vazia() {
    return (tamanho == 0);
}
  
int fila::getTamanho() {
    return tamanho;
}
    
int main() {
    fila f1;
    
    int num;
    int valor;
    
    // enfileira num elemntos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> valor;
        f1.enfileira(valor);
    }
    
    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;
    
    // enfileira num elemntos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cin >> valor;
        f1.enfileira(valor);
    }

    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;
    
    // desenfileira num elementos
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        cout << f1.desenfileira() << " ";
    }
    cout << endl;    

    // imprime o tamanho
    cout << f1.getTamanho() << endl;

    return 0;
}