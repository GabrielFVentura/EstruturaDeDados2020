/*Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões da matriz deverão ser lidas do usuário.Em seguida, escreva uma função que receba um valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no caso contrário.

Entradas:

Quantidade de linhas e colunas(int).
Elementos presentes na Matriz(int).
Elemento a ser procurado na Matriz(int).
Saídas:

1, caso o valor esteja na matriz, ou 0, no caso contrário.
Exemplo de Entrada:

3 3
3 5 8
1 2 9
6 7 10
2
Exemplo de Saída:

1*/
#include <iostream>
using namespace std;

int main(){

    int ROWS;
    int COLS;

    cin >> ROWS >> COLS;

    int** matriz = new int*[ROWS];

    for (int i = 0; i < ROWS; i++){
        matriz[i] = new int[COLS];
    }

    for (int i = 0; i< ROWS;i++){
        for (int j = 0; j<COLS;j++){
            cin >> matriz[i][j];
        }
    }

    int verf;
    cin >> verf;
    bool conf = false;

    for (int i = 0; i< ROWS;i++){
        for (int j = 0; j<COLS;j++){
            if (matriz[i][j] == verf){
                conf = true;
            }
        }
    }
    cout << conf;






    return 0;
}