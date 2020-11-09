/*Números em ponto flutuante são representados computacionalmente por meio de aproximações. Isso os torna inconvenientes para uma série de tarefas onde números decimais são utilizados.
 Várias linguagens de programação disponibilizam um tipo decimal, para resolver este problema, o que não é o caso de C/C++. Sua tarefa, portanto, é implementar um TAD em C++ para 
 representar um número decimal, utilizando dois inteiros:

class decimal {
	int left;
	int right;  
    int precision;
};

Nesse caso left e right representam os dígitos posicionados à esquerda e à direita do ponto decimal, respectivamente. Para resolver o problema de zeros à esquerda na parte direita do 
decimal (2.5 ≠ 2.05 ≠ 2.005 ≠ 2.0005), você deverá implementar também a precisão adotada. A precisão indicará exatamente o número de dígitos utilizados na parte direita do decimal 
(a parte fracionária). Assim, um decimal d com os seguintes atributos

d.left = 20;
d.right = 101;
d.precision = 5;
representa o valor 20.00101.

Após implementar as operações básicas em decimais, sobrescreva operadores para imprimir, somar, multiplicar e negar (inverter) decimais. */

#include <iostream>
using namespace std;

class Decimal{
    private:
        int left;
        int right;
        int precision;
    public:
    Decimal(int l, int r, int p){
        left = l;
        right = r;
        precision = p;
    }
};

int main(){
    int n = 5;
    int p = 0.05*10;
    double r = n+p;
    cout << r;
    
    return 0;
}