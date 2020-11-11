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
        Set(){}
        int* getArrayElementos(){return _arrayElementos;}
        int getNumeroElementos(){return _numeroElementos;}
        void setNumeroElementos(int* arr){_arrayElementos = arr;}

        void incrementaNumeroElementos(){ _numeroElementos++;}

        bool membro(Set* s, int x){
            for (int i = 0; i < s->getNumeroElementos(); i++){
                if (s->getArrayElementos()[i] == x){
                    return true;
                }
            }
            return false;
        }
        void adiciona(Set* s, int x){
            if (!(s->membro(s,x))){
                s->getArrayElementos()[getNumeroElementos()] = x;
                s->incrementaNumeroElementos();
            } else {
                cout << "ELEMENTA JA INSERIDO" << endl;
            }
        }
        void remove(Set* s, int x){
            for (int i = 0; i < s->getNumeroElementos(); i++){
                if (s->getArrayElementos()[i] == x){
                    s->getArrayElementos()[i] = 0;
                }
            }
        }
        void imprimi(Set* s){
            if (s->getNumeroElementos() > 0){
                for (int i = 0; i < s->getNumeroElementos();i++){
                    cout << s->getArrayElementos()[i] << " ";
                }
            } else {
                cout << "{}" << endl;
            }
            
        }
        int* uniao(Set* A, Set* B){
            int tamanhoConjuntoUniao = A->getNumeroElementos() + B->getNumeroElementos();
            int* arrTemp = new int[tamanhoConjuntoUniao];
            for (int i = 0; i < A->getNumeroElementos();i++){
                arrTemp[i] = A->getArrayElementos()[i];
            }
            for (int i = A->getNumeroElementos(); i < B->getNumeroElementos(); i++){
                arrTemp[i] = B->getArrayElementos()[i];
            }
            return arrTemp;
        }

        Set operator+(Set& s){
            Set setTemp(_numeroElementos + s.getNumeroElementos());

            for (int i = 0; i < getNumeroElementos(); i++){
               setTemp._arrayElementos[i] = getArrayElementos()[i];
               cout << "arrayElementos[" << i << "]: " << getArrayElementos()[i] << " ";
            }
            cout << endl;
            for (int i = getNumeroElementos(); i < _numeroElementos+s.getNumeroElementos();i++){
                setTemp._arrayElementos[i] = s._arrayElementos[i];
                cout << "s.arrayElementos[" << i << "]: " << s._arrayElementos[i] << " ";
            }
            cout << endl;

            return setTemp;
        }
};

int main(){
    int n;
    cout << "TAMANHO DO CONJUNTO" << endl;
    cin >> n;
    int k;
    Set setA(n);
    for (int i = 0; i < n; i++){
        cout << "setA[" << i << "] ";
        cin >> k;
        setA.adiciona(&setA, k);
    }

    setA.imprimi(&setA);
    cout << endl;

    Set setB(n);
    for (int i = 0; i < n; i++){
        cout << "setB[" << i << "] ";
        cin >> k;
        setB.adiciona(&setB, k);
    }
    cout << endl;

    setB.imprimi(&setB);

    setA.setNumeroElementos(setA.uniao(&setA,&setB));
    setA.imprimi(&setA);

    Set setC;
    setC = setA+setB;
    setC.imprimi(&setC);

    return 0;
}