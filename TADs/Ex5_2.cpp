/*Uma estrutura de dados do tipo conjunto (set) é uma coleção de elementos. Dado os conjuntos S, A e B, e um elemento x, um conjunto geralmente implementa as seguintes operações básicas:

membro(S,x) – Retorna true se o item x for membro do conjunto S.
adiciona(S,x) – Adiciona o elemento x no conjunto S, descartando duplicatas. Se x já fizer parte de S, não é gerado erro, apenas não se modifica o conteúdo de S.
remove(S,x) – Remove o elemento x do conjunto S. Se x não fizer parte de S, não é gerado erro, apenas não se modifica o conteúdo de S.
tamanho(S) – Retorna o número de elementos de S.
imprime(S) – Imprime os elementos de S. Caso o conjunto seja vazio, imprime {}
uniao(A,B) – Retorna um novo conjunto A ∪ B, formado pela união dos elementos de A e B.
intersecao(A,B) – Retorna um novo conjunto A ∩ B, formado pela interseção dos elementos de A e B.
diferenca(A,B) – Retorna um novo conjunto A - B, formado pelos elementos de A que não fazem parte de B.

Neste exercício, você deverá implementar as operações básicas de conjuntos listadas anteriormente, armazenando os dados em um vetor. Sobrecarregue os operadores de atribuição, 
comparação, bem como o operador + (para união), o operador * (para interseção) e o operador - (para diferença de conjuntos).
____________________________________________________________________________________
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

class Set{
    private:
        int* _arrayElementos;
        int _numeroElementos;
    public:
        Set(int t){
            _arrayElementos = new int[t];
            _numeroElementos = 0;
        }
        Set(int* arr,int t){
            _arrayElementos = arr;
            _numeroElementos = t;
        }
        Set(){}
        int* getArrayElementos(){return _arrayElementos;}
        int getNumeroElementos(){return _numeroElementos;}
        void setNumeroElementos(int* arr){_arrayElementos = arr;}

        void incrementaNumeroElementos(){ _numeroElementos++;}

        //UNIAO
        Set operator+(Set& set){
            int numeroElementosConjunto1 = _numeroElementos;
            int numeroElementosConjunto2 = set.getNumeroElementos();

            Set setTemp(numeroElementosConjunto1+numeroElementosConjunto2);

            for (int i = 0; i < numeroElementosConjunto1; i++){
                cout << "_arrayElementos["<< i << "] :" << _arrayElementos[i] << endl;
                setTemp._arrayElementos[i] = _arrayElementos[i];
            }
            int k = 0;
            for (int j = numeroElementosConjunto1; j < numeroElementosConjunto1+numeroElementosConjunto2 ; j++){
                cout << "_arrayElementos["<< j << "] :" << set._arrayElementos[k] << endl;
                setTemp._arrayElementos[j] = set._arrayElementos[k];
                k++;
            }
            return setTemp;
        }
        //ADICIONAR
        Set operator+(int v){
            bool adicionado = false;
            for (int i = 0; i < _numeroElementos; i++){
                if (_arrayElementos[i] == 0 && !adicionado){
                    _arrayElementos[i] = v;
                    adicionado = true;
                    _numeroElementos++;
                }
            }
            return Set(_arrayElementos,_numeroElementos);
        }
        //REMOVER
        Set operator-(int v){
            int* tempArray = new int[_numeroElementos-1];
            int tamanhoArrayTemp = 0;

            for (int i = 0; i < _numeroElementos; i++){
                if (_arrayElementos[i] == v){
                    cout << "ELEMENTO '" << v << "' ENCONTRADO" << endl;
                    _arrayElementos[i] = 0;
                }
            }

            for (int i = 0; i< _numeroElementos; i++){
                if (_arrayElementos[i] != 0){
                    tempArray[tamanhoArrayTemp] = _arrayElementos[i];
                    tamanhoArrayTemp++;
                }
            }
            cout << "TAMANHO ARRAY TEMP: " << tamanhoArrayTemp << endl;
            for (int i = 0; i< tamanhoArrayTemp; i++){
               cout << " tempArray[" << i << "]: " << tempArray[i] << " ";
            }
            cout << endl;


            return Set(_arrayElementos,_numeroElementos);
        }

        void displaySetElementos(){
            for (int i = 0; i < _numeroElementos; i++){
                cout << "_arrayElementos["<< i << "] : " << _arrayElementos[i] << endl;
            }
            cout << endl;
        }
};

int main(){
    int n;
    cout << "TAMANHO DO ARRAY: " << endl;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i ++ ){
        cout << "arr[" << i << "]: " << " ";
        cin >> arr[i];
    }

    int* arrB = new int[3];
    arrB[0] = 5;
    arrB[1] = 10;
    arrB[2] = 0;

    Set SetA(arr,n);
    SetA.displaySetElementos();

    Set SetB(arrB,3);
    SetB.displaySetElementos();
    cout << "NOVO SetB: " << endl;

    SetB + 1;
    SetB.displaySetElementos();

    cout << "NOVO NOVO SetB: " << endl;
    SetB - 5;
    SetB.displaySetElementos();
    SetB + 3;
    SetB.displaySetElementos();
    SetB - 5;
    SetB.displaySetElementos();



    //UNIAO
    Set SetC = SetA+SetB;
    SetC.displaySetElementos();

    return 0;
}