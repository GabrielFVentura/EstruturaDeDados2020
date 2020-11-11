/*Escreva uma especificação de tipos abstratos de dados (TAD) para os números complexos, a + bi, 
em que  abs(a + bi) é dado por sqrt(a2 + b2),
(a + bi) + (c + di) é (a + c) + (b + d)i,
(a + b) * (c + di) é (a * c – b * d) + (a * d + b * c)i e
–(a + bi) é (-a) + (-b)i. Então,
implemente em C/C++ números complexos, conforme especificado acima, usando estruturas com partes reais e complexas. Sobrescreva 
operadores para imprimir, somar, multiplicar e negar (inverter) tais números.

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
#include <math.h>
using namespace std;

class Complexo{
    private:
        int _real;
        int _imaginario;
    public:
        Complexo(int r, int i){
            _real = r;
            _imaginario = i;
        }
        int getReal(){
            return _real;
        }
        int getImaginario(){
            return _imaginario;
        }
        float abs(){
            return sqrt(pow(getReal(),2) +
                        pow(getImaginario(),2));
        }
        friend ostream& operator<<(ostream& os, Complexo c){
            string signal = c.getImaginario() > 0 ? " + " : " ";

            os << c.getReal() << signal << c.getImaginario() << "i" << endl;
            return os;
        }
        Complexo operator +(Complexo &c){
            return Complexo(_real+c.getReal(),
                            _imaginario+c.getImaginario());
        }
        Complexo operator *(Complexo &c){
            float ptReal = _real*c.getReal() - _imaginario*c.getImaginario();
            float ptImag = _real*c.getImaginario() + _imaginario*c.getReal();
            return Complexo(ptReal, ptImag);
        }
        Complexo operator -(){
            return Complexo(-getReal(),-getImaginario());
        }
};

int main(){
    Complexo comp1(2,5);
    Complexo comp2(1,-2);
    Complexo comp3 = comp1 + comp2;
    Complexo comp4 = comp1 * comp2;
    cout << comp1.abs() << endl;
    cout << comp1;
    cout << comp3;
    cout << comp4;
    Complexo comp5 = -comp4;
    cout << comp5;


    return 0;
}