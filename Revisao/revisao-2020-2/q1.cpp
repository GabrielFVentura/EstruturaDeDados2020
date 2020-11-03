#include <iostream>
using namespace std;

/*Faça um programa para receber nove números inteiros positivos, armazená-los em um vetor, calcular e exibir no dispositivo de saída padrão aqueles números que são primos e suas respectivas posições no vetor. Se nenhum número primo for fornecido, nenhuma mensagem precisará ser exibida.

Entradas:

Nove números inteiros positivos a serem armazenados em um vetor.
Saídas:

Sequência de números primos e suas respectivas posições (índices no vetor). Obs.: Aqueles números que forem primos e suas respectivas posições deverão ser exibidos aos pares.
Exemplo de entrada:

7 13 49 23 6 21 78 98 3 
Exemplo de saída:

7 0
13 1
23 3
3 8*/


int main(){

    int valores[9];
    int divisores = 0;
    int indice = 0;
    bool ehPrimo;

    for (int i = 0; i < 9; i++){
        cin >> valores[i];
    }

    for (int i = 0; i < 9;i++){
        for (int j = 1; j <= valores[i]; j++){
             if (valores[i] % j == 0){
                divisores++;
            }
        }
        if (divisores == 2){
            cout << valores[i] << " " << i << endl;
        }
        divisores = 0;
        indice = 0;
    }

    return 0;
}