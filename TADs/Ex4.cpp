/*Implemente um TAD para representação de frações utilizando dois inteiros; 

class fracao  {
	int numerador;
	int denominador;
 }; 

Sobrescreva operadores para imprimir, somar, dividir, multiplicar e negar (inverter) frações. Sobrescreva também os operadores de comparação
 (>, <, >=, <= e ==). Dica: um método para verificar a igualdade é multiplicar o denominador de cada número pelo numerador do outro e testar 
 a igualdade dos dois produtos. Os operadores < e > podem ser implementadas por meio de divisão em ponto flutuante. 
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

class Fracao{
    private:
        int numerador;
        int denominador;
    public:
        Fracao(int n, int d){
            if (d > 0){
                numerador = n;
                denominador = d;
            } else {
                cout << "DENOMINADOR TEM QUE SER MAIOR QUE 0" << endl;
            }
        }
        friend ostream& operator<<(ostream& os, Fracao fr){
            os << fr.numerador << "/" << fr.denominador << endl;
            return os;
        }
        Fracao operator +(Fracao &fr){
            int denominadorComum = denominador * fr.denominador;
            int numR = numerador*fr.denominador + denominador * fr.numerador;
            return Fracao(numR, denominadorComum);
        }

        Fracao operator *(Fracao &fr){
            return Fracao(numerador * fr.numerador, 
                          denominador * fr.denominador);
        }
        
        Fracao operator -(){
            return Fracao(denominador,numerador);
        }
};

int main(){
    Fracao fr1(2,4);
    Fracao fr2(3,5);
    cout << fr1;
    Fracao fr3 = fr1*fr2;
    cout << fr3;
    Fracao fr4 = fr1+fr2;
    cout << fr4;
    Fracao fr5 = -fr4;
    cout << fr5;
    return 0;
}