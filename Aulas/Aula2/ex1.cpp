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
#include <cstring>
#include <cstdlib>
using namespace std;

string derefStr(string* ptr){
    return *ptr;
}

string refStr(string& ptr){
    return ptr;
}

int main(){
    string st = "Gabriel";
    string* ptrSt = &st;
    string** ptrPtrStr = &ptrSt;
    
    char* ch = &st[2];

    cout << st[0] << endl;
    cout << ch << endl;

    cout << "valor ponteiro: " << ptrSt << endl;    
    cout << "valor armazenado no ponteiro: " << *ptrSt << endl;

    cout << "valor ponteiro do ponteiro: " << ptrPtrStr << endl; 
    cout << "valor armazenado no ponteiro do ponteiro: " << *ptrPtrStr << endl;
    cout << "valor armazenado no ponteiro do ponteiro: " << **ptrPtrStr << endl;

    cout << "valor referenciado por funcao: " << derefStr(ptrSt) << endl;
    cout << "valor dereferenciado por funcao: " << refStr(st) << endl;

    int a = 20;
    cout << &a << endl;

    int v[5];
    cout << v << endl;
    cout << &v << endl;
    cout << &v[0]<< endl;

    int vetor[5] = {0, 1, 2, 3, 4};
    int *ptr = vetor;

    for (int i = 0; i < 5; i++){    
        cout << *(ptr+i) << endl;
    }
    int vetor1[20] = {0,3,11,61,8,7,-6,2,13,47,
                  91,12,5,4,-1,12,41,53,9,33};
    int vetor2[10];

    memcpy(vetor2,vetor1,sizeof(int)*10);
    cout << "Após cópia" << endl;
    for (int i=1; i<10; i++){
        cout << vetor2[i] << endl;
    }
    vetor2[0] = 99;
    string n = "94";
    cout << stoi(n);
    return 0;
}