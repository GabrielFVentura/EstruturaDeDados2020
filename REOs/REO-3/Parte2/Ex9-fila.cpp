/*

Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2 para outras operações. As propriedades de fila devem ser estritamente respeitadas, ou seja: não é permitido o acesso aleatório aos elementos da fila.

Entradas:

Número de elementos a serem inseridos em F1.
Elementos de F1 em ordem de inserção (inserção no fim da fila).
Número de elementos a serem inseridos em F2.
Elementos de F2 em ordem de inserção (inserção no fim da fila).
Saídas:

Elementos restantes em F1 após a remoção.
Exemplo de Entrada:

11

4 6 9 10 1 9 2 13 7 3 5

4

9 2 7 3
Exemplo de Saída:

4 6 10 1 13 5

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/

#include <iostream>
using namespace std;

struct Noh{
    int valor;
    Noh* nohProximo;
    Noh(int v){
        valor = v;
        nohProximo = NULL;
    };
};

class Fila{
    private:
        int tamanho;
    public:
        Noh* primeiroNoh;
        Noh* ultimoNoh;
        Fila(){
            tamanho = 0;
            primeiroNoh = NULL;
            ultimoNoh = NULL;
        }
        bool filaVazia(){
            return tamanho == 0;
        }
        void enfileiraNoh(int v){
            Noh* novoNoh = new Noh(v);
            if (filaVazia()){
                primeiroNoh = novoNoh;
                ultimoNoh = novoNoh;
            } else {
                ultimoNoh->nohProximo = novoNoh;
                ultimoNoh = novoNoh;
            }
            tamanho++;
        }
        int desinfileiraNoh(){
            if (filaVazia()){
                cout << "FILA VAZIA" << endl;
            } else {
                Noh* nohTemp = primeiroNoh;
                int valorRemovido = nohTemp->valor;
                delete nohTemp;
                tamanho--;
                return valorRemovido;
            }
        }
};

void percorrerDisplayNoh(Noh* noh){
    if(noh->nohProximo != NULL){
        cout << noh->valor << " ";
    } else {
        cout << noh->valor << " ";
        return;
    }
    percorrerDisplayNoh(noh->nohProximo);
}

void encontrarIntersecaoFilas(Fila &f1, Fila &f2){
    


}


int main(){
    Fila F1;
    Fila F2;

    int tamanhoF1;
    int tamanhoF2;
    int valorInserido;
    cin >> tamanhoF1;
    for (int i = 0; i < tamanhoF1; i++){
        cin >> valorInserido;
        F1.enfileiraNoh(valorInserido);
    }
    percorrerDisplayNoh(F1.primeiroNoh);
    cin >> tamanhoF2;
    for (int i = 0; i < tamanhoF2; i++){
        cin >> valorInserido;
        F2.enfileiraNoh(valorInserido);
    }
    percorrerDisplayNoh(F2.primeiroNoh);

    return 0;
}