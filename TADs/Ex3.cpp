/*Números em ponto flutuante são representados computacionalmente por meio de aproximações. Isso os torna inconvenientes para uma série de tarefas onde números decimais
 são utilizados. Várias linguagens de programação disponibilizam um tipo decimal, para resolver este problema, o que não é o caso de C/C++. Sua tarefa, portanto, 
 é implementar um TAD em C++ para representar um número decimal, utilizando dois inteiros:

class decimal {
	int left;
	int right;  
    int precision;
};

Nesse caso left e right representam os dígitos posicionados à esquerda e à direita do ponto decimal, respectivamente. Para resolver o problema de zeros à esquerda na 
parte direita do decimal (2.5 ≠ 2.05 ≠ 2.005 ≠ 2.0005), você deverá implementar também a precisão adotada. A precisão indicará exatamente o número de dígitos utilizados
 na parte direita do decimal (a parte fracionária). Assim, um decimal d com os seguintes atributos

d.left = 20;
d.right = 101;
d.precision = 5;
representa o valor 20.00101.

Após implementar as operações básicas em decimais, sobrescreva operadores para imprimir, somar, multiplicar e negar (inverter) decimais. 

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


#include <bits/stdc++.h> 
using namespace std;

class Decimal{
    private:
        int left;
        int right;
        int precision;
    public:
        int getLeft(){return left;}
        int getRight(){return right;}
        int getPrecision(){return precision;}

    Decimal(int l, int r, int p){
        left = l;
        right = r;
        precision = p;
    }
    string ToString(){
        ostringstream  aux;
        int digits = getDigits(getRight());
        int precision = getPrecision();
        string t(precision-digits,'0');

        aux << left << '.' << t << right;

        return aux.str();
    }
    int getDigits(int r){
        unsigned int number_of_digits = 0;

        do {
            ++number_of_digits; 
            r /= 10;
        } while (r);
        return number_of_digits;
    }
    const double StrToDouble(const string& s){
        return atof(s.c_str());
    }
};



int main(){
    Decimal dec(20,125,5);
    cout << dec.ToString() << endl;
    double r = dec.StrToDouble(dec.ToString());
    cout << r;
    return 0;
}