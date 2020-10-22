#include <iostream>
using namespace std;

class Pilha{
    private:
        int _capacidade;
        int _pilha[25];
        int _tamanho;
        int _primeiroValor;
        int _ultimoValor;
    public:
        Pilha(int cap){
            _tamanho = 0;
            _capacidade = cap;
            setPilha();
        }

        int getCapacidade(){
            return _capacidade;
        }

        int getTamanho(){
            return _tamanho;
        }

        void incrementaTamanho(){
            _tamanho++;
        }

        void decrementaTamanho(){
            _tamanho--;
        }

        void setPilha(){
            for (int i = 1; i <= getCapacidade(); i++){
                _pilha[i] = -1;       
            }
        }

        void setValorPilha(int valor){
            _pilha[getTamanho()] = valor;
        }

        int getValorTopoPilha(){
            return _pilha[getTamanho()];
        }

        void empilhaValor(int v){
            if (getTamanho() <= getCapacidade()){
                incrementaTamanho();    
                setValorPilha(v);
            } else {
                cout << "PILHA CHEIA" << endl;
            }
        }

        void imprimirValoresPilha(){
            if (getTamanho() > 0){
                for (int i = 1; i <= getTamanho(); i++){
                    cout << "INDICE " << i << " VALOR: " << _pilha[i] << endl;
                }
            } else {
                cout << "PILHA VAZIA" << endl;
            }
        }

        void imprimirValoresPilhaPelaCapacidade(){
                for (int i = 1; i <= getCapacidade(); i++){
                    cout << "INDICE: " << i << " VALOR: " << _pilha[i] << endl;
                }
        }

        void desempilhaValor(){
            setValorPilha(-1);
            decrementaTamanho();
        }

        void limparPilha(){
            while(getTamanho() != 0){
                desempilhaValor();
            }
        }
};

int main(){
    Pilha pilha(10);

    // pilha.empilhaValor(5);
    // pilha.empilhaValor(10);
    // pilha.empilhaValor(15);

    // pilha.imprimirValoresPilha();
    // pilha.desempilhaValor();

    // pilha.imprimirValoresPilha();
    // pilha.limparPilha();


    for (int i = 1; i <= pilha.getCapacidade(); i ++){
        pilha.empilhaValor(i);
    }
    
    pilha.imprimirValoresPilha();

    for (int i = 1; i <= pilha.getTamanho(); i++){
         cout << "Indice pilha: " << i << " " << "Valor Pilha: " << pilha.getValorTopoPilha() << endl ;

         pilha.desempilhaValor();
    }

    return 0;
}