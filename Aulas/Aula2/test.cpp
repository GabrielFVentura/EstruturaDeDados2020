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



int main(){
    string st = "gabriel";
    string* ptrStr = &st;
    string** ptrPtrStr = &ptrStr;

    cout << st << endl;
    cout << ptrStr << endl;
    cout << &ptrStr << endl;
    cout << *ptrStr << endl;
    cout << ptrPtrStr << endl;
    cout << &ptrPtrStr << endl;
    cout << *ptrPtrStr << endl;
    cout << **ptrPtrStr << endl;


    return 0;
}