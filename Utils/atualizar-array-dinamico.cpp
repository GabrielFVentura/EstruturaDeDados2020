/*____________________________________________________________________________________
|                                                                                   |
|                                                                                   |
|                        Estruturas de Dados, 2020/2                                |
|                                                                                   |
|                                                                                   |
|                    Solução de: GABRIEL FRANCO VENTURA SANTOS                      |
|                                                                                   |
|                                                                                   |
|___________________________________________________________________________________|
*/

#include <iostream>
using namespace std;

int* atualizarTamanhoArray(int* arr, int t){
   int* temp = new int[t+5];
   for (int i = 0; i < 5; i++){
       *(temp + i) = arr[i];
   }
    for (int i = 5;i < 10; i++){
       *(temp + i) = i;
   }
   return temp;
}

int main(){

    int* arr = new int[5];

    for (int i = 0; i < 5; i++){
        *(arr+i) = i+10;
        cout << "ANTIGO ARRAY: " << *(arr+i) << endl;
    }
    cout << "ENDERECO DA MEMORIA: " << &arr << endl;

    arr = atualizarTamanhoArray(arr,5);

    for (int i = 0; i < 10; i++){
        cout << "NOVO ARRAY: " << *(arr+i) << endl;
    }
    cout << "ENDERECO DA MEMORIA: " << &arr << endl;

    return 0;
}