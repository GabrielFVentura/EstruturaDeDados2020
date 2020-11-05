#include <iostream>
#include <cstring>
using namespace std;

typedef int Dado;

// void copiarBlocoMemoria(Dado& dadoDestino, Dado& dadoFonte, int tamanhoBloco){
//     cout << dadoFonte << endl;
//     cout << dadoDestino << endl;
//     memcpy(dadoDestino, dadoFonte, sizeof(Dado));
// }

int main(){
    int v1 = 5;
    int v2 = 10;

    cout << "ENDERECO V1: " << &v1 << endl;
    cout << "ENDERECO V2: " << &v2 << endl;

    cout << "VALOR V1: " << v1 << endl;
    cout << "VALOR V2: " << v2 << endl;
    
    memcpy(&v1, &v2, sizeof(Dado));

    // copiarBlocoMemoria(&v1,&v2,sizeof(Dado));

    cout << "ENDERECO V1: " << &v1 << endl;
    cout << "ENDERECO V2: " << &v2 << endl;

    cout << "VALOR V1: " << v1 << endl;
    cout << "VALOR V2: " << v2 << endl;
    return 0;
}