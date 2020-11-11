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

int f1(float n){
    return n;
}

int main(){
   float n = 5.5;
    cout << f1(n);
    return 0;
}