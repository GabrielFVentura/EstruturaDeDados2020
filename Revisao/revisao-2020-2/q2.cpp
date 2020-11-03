/*Faça um programa que receba oito números inteiros e os armazene de forma ordenada em um vetor. Ou seja, assim que lidos, os números já devem ser inseridos no vetor em uma posição que mantém a ordem crescente. Eles não podem ser inseridos no final do vetor para o vetor passar por uma ordenação.

Cada vez que um número for colocado no vetor o programa deve exibir os números inseridos até então.

Entrada:

Oito números inteiros a serem inseridos no vetor.
Saída:

Oito linhas contendo em cada uma a situação do vetor após a inserção de cada número lido.
Exemplo de entrada:

7 3 4 6 2 9 0 1
Exemplo de saída:

7
3 7
3 4 7
3 4 6 7
2 3 4 6 7
2 3 4 6 7 9
0 2 3 4 6 7 9
0 1 2 3 4 6 7 9
*/

#include <iostream>
using namespace std;

int main(){

    int valores[8] = {7, 3, 4, 6, 2, 9, 0, 1};
    int valoresDef[8];

    for (int i = 0;i < 8;i++){
        valoresDef[i] = 0;
    }

    int indiceDef = 0;
    for (int i = 0;i < 8;i++){
        if (valoresDef[0] == 0){
            valoresDef[indiceDef] = valores[i];
        } else if (valoresDef[indiceDef-1] > valores[i]){
            int temp = valoresDef[indiceDef-1];
            valoresDef[indiceDef-1] = valores[i];
            valoresDef[indiceDef] = temp;
        } 
        indiceDef++;
        for (int i = 0; i < indiceDef;i++){
            cout << valoresDef[i] << " ";
        }
        cout << endl;
    }


    // if (valoresDef[0] == 0){
    //         valoresDef[indiceDef] = valores[i];
    //     } else if (valoresDef[indiceDef-1] > valores[i]){
    //         int temp = valoresDef[indiceDef-1];
    //         valoresDef[indiceDef-1] = valores[i];
    //         valoresDef[indiceDef] = temp;
    //         cout << "indiceDef: " << indiceDef;

    //     } else {
    //         valoresDef[indiceDef] = valores[i];
    //         cout << "indiceDef: " << indiceDef;
    //     }
    //     indiceDef++;

    //     for (int i = 0; i < indiceDef;i++){
    //         cout << valoresDef[i] << " ";
    //     }
    //     cout << endl;


    return 0;
}