/*
Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa não for um problema. Nesse caso, é importante controlar os índices para "dar a volta" no vetor sempre que for necessário. Uma fila assim pode ser chamada de fila circular.

Faça a implementação de uma fila circular fazendo com que a inserção (método Enfileirar) sempre use o início do vetor (posição zero) quando a fila estiver vazia.

Entradas:

Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.

Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

t - para terminar a execução do programa
e - para enfileirar um valor - seguido do valor (número inteiro)
d - para desenfileirar um valor
i - para escrever as informações da fila (atributos e conteúdo)
Saídas:

Os comandos d e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo.

Exemplo de Entrada e Saída juntos:

3
e 1
e 2
e 3
i
tamanho=3 capacidade=3 inicio=0 fim=2
1 2 3 
d
1
e 4
i
tamanho=3 capacidade=3 inicio=1 fim=0
4 2 3 
d
2
d
3
i
tamanho=1 capacidade=3 inicio=0 fim=0
4
t

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/


#include <iostream>
using namespace std;

class FilaCircular{
    private:
        int tamanho;
        int capacidade;
        int comecoFila;
        int fimFila;
    public:
        int* arrFila;
        FilaCircular(int c){
            capacidade = c;
            tamanho = 0;
            arrFila = new int[c];
            for (int i = 0; i < c; i++){
                arrFila[i] = -1;
            }
            comecoFila = -1;
            fimFila = -1;
        }
        ~FilaCircular(){
            delete arrFila;
        }
        void enfileira(int v){
            if ((comecoFila == 0 && fimFila == capacidade-1) || (comecoFila == fimFila + 1)) {
                    cout << "FILA CHEIA" << endl;
                    return;
                }
                else if (comecoFila == -1){
                    comecoFila = fimFila = 0;
                    arrFila[fimFila] = v;
                } else if (fimFila == capacidade - 1 && comecoFila != 0){
                    fimFila = 0;
                    arrFila[fimFila] = v;
                } else {
                    fimFila++;
                    arrFila[fimFila] = v;
                }
                tamanho++;
        }
        int desenfileirar(){
            if (comecoFila == -1){
                cout << "FILA VAZIA" << endl;
                return -1;
            }
            int data = arrFila[comecoFila];
            arrFila[comecoFila] = -1;
            tamanho--;
            if (comecoFila == fimFila){
                comecoFila = -1;
                fimFila = -1;
            } else if (comecoFila == capacidade - 1){
                comecoFila = 0;
            } else {
                comecoFila++;
            }
            return data;
        }
        void displayFila(){
            if (comecoFila == -1){
                cout << "FILA VAZIA" << endl;
            } else {
                cout << "tamanho=" << tamanho << 
                        " capacidade=" << capacidade <<
                        " inicio=" << comecoFila << 
                        " fim=" << fimFila << endl;
                for (int i = 0; i < tamanho; i++){
                    cout << arrFila[i] << " ";
                }
                cout << endl;
            }
        }
};


int main(){
    int tamanhoFila;
    cin >> tamanhoFila;
    FilaCircular fila(tamanhoFila);
    char opt;
    do
    {
        cin >> opt;
        switch (opt)
        {
        case 'e':
            int v;
            cin >> v;
            fila.enfileira(v);
            break;
        case 'i':
            fila.displayFila();
            break;
        case 'd':
            cout << fila.desenfileirar() << endl;
            break;
        default:
            break;
        }
    } while (opt != 't');
    
    return 0;
}