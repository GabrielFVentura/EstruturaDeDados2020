/*Implemente uma classe FFR que calcula os n primeiros termos das séries de Fibonacci, Fettuccine ou Ricci de acordo com o tipo definido pelo usuário durante a 
criação do objeto (utilize a interface da classe definida a seguir). Implemente uma aplicação principal que exemplifique o uso da classe em todos os seus recursos.
O cálculo dos termos da série de Ricci é semelhante ao cálculo dos termos da série de Fibonacci, sendo que na série de Ricci os dois primeiros termos são fornecidos 
pelo usuário. 
A série de Fetuccine difere da série de Fibonacci porque os dois primeiros termos são fornecidos pelo usuário e os termos subsequentes são gerados com a soma ou 
subtração dos dois termos anteriores, 
ou seja:

          Fi = Fi-1 + Fi-2 para i ímpar
          Fi = Fi-1 - Fi-2 para i par

Interface a ser utilizada: 

enum tipo {fib, fet, ric};

class FFR {
    private:
   	 tipo meuTipo;
   	 int termo1, termo2;
   	 long calculaFib (int n);
   	 long calculaFet (int n);
   	 long calculaRic (int n);
   	 long* calculaSeqFib (int n);
   	 long* calculaSeqFet (int n);
   	 long* calculaSeqRic (int n);
    public:    
   	 FFR (tipo t); // construtor para Fibonacci
   	 FFR (tipo t, int t1, int t2); // construtor para Fettuccine e Ricci
   	 long calculaTermo (int n); //calcula o n-esimo termo
   	 long* calculaSequencia (int n); // retorna um vetor com os 
    // n primeiros termos
};*/

#include <iostream>
using namespace std;

enum tipo {fib, fet, ric};

class FFR {
    private:
   	 tipo meuTipo;
   	 int termo1, termo2;
   	 long calculaFib (int n){
            if (n == 0){
                return 0;
            }
            if (n == 1){
                return 1;
            } else if (n >= 2){
                return calculaFib(n-1)+calculaFib(n-2);
            }
            
        };
   	 long calculaFet (int n){

        };
   	 long calculaRic (int n){
            if (n == 0){
                return termo1;
            }
            if (n == 1){
                return termo2;
            } else if (n >= 2){
                return calculaRic(n-1)+calculaRic(n-2);
            }
        };
   	 long* calculaSeqFib (int n){
            long* arr = new long[n];
            for (int i = 0;i <= n; i++){
                arr[i] = calculaFib(i);
            }
            for (int i = 0; i <= n; i++){
                cout << arr[i] << " ";
            }
            return arr;
        };
   	 long* calculaSeqFet (int n){
        
        };
   	 long* calculaSeqRic (int n){
            long* arr = new long[n];
            for (int i = 0; i <= n; i++){
                arr[i] = calculaRic(i);
            }
            for (int i = 0; i <= n; i++){
                cout << arr[i] << " ";
            }
            return arr;
        };
    public:    
   	 FFR (tipo t){
            meuTipo = t;
        }; // construtor para Fibonacci
   	 FFR (tipo t, int t1, int t2){
            meuTipo = t;
            termo1 = t1;
            termo2 = t2;
        }; // construtor para Fettuccine e Ricci
   	 long calculaTermo (int n){
            if (meuTipo == 0){
                return calculaFib(n);
            } else if (meuTipo == 1){
                return calculaFet(n);
            } else {
                return calculaRic(n);
            }
        }; //calcula o n-esimo termo
   	 long* calculaSequencia (int n){
            if (meuTipo == 0){
                return calculaSeqFib(n);
            } else if (meuTipo == 1){
                return calculaSeqFet(n);
            } else {
                return calculaSeqRic(n);
            }
        }; // retorna um vetor com os 
    // n primeiros termos
};

int main(){
    int tipoInput;
    int termo1;
    int termo2;

    cin >> tipoInput;
    int n;
    tipo tipoEscolhido = (tipo)tipoInput;

    if (tipoEscolhido == 0){
        cout << "Sequencia de fibonnacci escolhida " << endl;
        FFR ffr(tipoEscolhido);
        cin >> n;
        ffr.calculaSequencia(n);
    } else {
        if (tipoEscolhido == 1)
        cout << "Sequencia de Fettuccini escolhida" << endl;
        else 
        cout << "Sequencia de Ricci escolhida" << endl;
        
        cout << "PRIMEIRO TERMO: " << endl;
        cin >> termo1;
        cout << "SEGUNDO TERMO: " << endl;
        cin >> termo2;
        cout << "ATE QUAL TERMO: " << endl;
        cin >> n;
        FFR ffr(tipoEscolhido,termo1,termo2);
        ffr.calculaSequencia(n);
    }
    return 0;
}