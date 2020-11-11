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

string refStr(string* ptr){
    return *ptr;
}

string* ptrStr(string ptr){
    return &ptr;
}

string derefPtr(string& ptr){
    return ptr;
}

int main(){
    string st = "Gabriel";
    string* ptrSt = &st;
    string** ptrPtrSt = &ptrSt;

    cout << "Valor da funcao refStr: " << refStr(ptrSt) << endl;
    cout << "Valor da funcao ptrStr: " << ptrStr(st) << endl;
    cout << "Valor da funcao derefPtr: " << derefPtr(st) << endl;
    cout << endl;

    cout << "Valor da Variavel: " << st << endl;
    cout << "Valor da Memoria da Variavel: " << &st << endl;
    cout << endl;

    cout << "Valor do Ponteiro: " << ptrSt << endl;
    cout << "Valor Armazenado do Ponteiro: " << *ptrSt << endl;
    cout << "Valor da Memoria do Ponteiro: " << &ptrSt << endl;
    cout << endl;

    cout << "Valor da Memoria do Ponteiro de Ponteiro: " << &ptrPtrSt << endl;
    cout << "Valor do Ponteiro de Ponteiro: " << ptrPtrSt << endl;    
    cout << "Valor Armazenado do Ponteiro do Ponteiro: " << *ptrPtrSt << endl;
    cout << "Valor Armazenado do Ponteiro do Ponteiro Dereferenciado: " << **ptrPtrSt << endl;
    
}
