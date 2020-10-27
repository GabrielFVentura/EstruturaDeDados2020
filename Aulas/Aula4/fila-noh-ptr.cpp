#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Noh{
    private:
        int _valor;
    public:
        Noh* nohProximo;
        Noh(int v){
            _valor = v;
        }
        int getValor(){
            return _valor;
        }
};

class Fila{
    private:
        int _tamanho;
    public:
        Noh* ultimoNoh;
        Noh* primeiroNoh;
        Fila(){
            cout << "Construtor Chamado" << endl;
            _tamanho = 0;
            ultimoNoh = NULL;
            primeiroNoh = NULL;
        }
        ~Fila(){
            cout << "Destrutor Chamado" << endl;
            delete ultimoNoh;
            delete primeiroNoh;
        }
        void incrementaTamanho(){
            _tamanho++;
        }
        void decrementaTamanho(){
            _tamanho--;
        }
        int getTamanho(){
            return _tamanho;
        }
        int getPrimeiroNohValor(){
            return primeiroNoh->getValor();
        }
        int getUltimoNohValor(){
            return ultimoNoh->getValor();
        }
        void enfileirarNoh(int v){
            Noh* nohAdicionado = new Noh(v);
            if (getTamanho() == 0){
                ultimoNoh = nohAdicionado;
                primeiroNoh = nohAdicionado;
            } else {
                ultimoNoh->nohProximo = nohAdicionado;
                ultimoNoh = nohAdicionado;
            }
            incrementaTamanho();
            cout << "TAMANHO: " << getTamanho() << endl;
            cout << "VALOR ADICIONADO: " << nohAdicionado->getValor() << endl;
            cout << endl;
        }

        void desenfileirarNoh(){
            if (getTamanho() > 0) {
                Noh *nohRemovido = primeiroNoh;
                if (getTamanho() == 1) { 
                    cout << "TAMANHO: " << getTamanho() << endl;
                    cout << "VALOR REMOVIDO: " << nohRemovido->getValor() << endl;
                    primeiroNoh = NULL;
                    ultimoNoh = NULL;
                    decrementaTamanho();
                } else {
                    primeiroNoh = primeiroNoh->nohProximo;
                    cout << "TAMANHO: " << getTamanho() << endl;
                    cout << "VALOR REMOVIDO: " << nohRemovido->getValor() << endl;
                    decrementaTamanho();
                }
                delete nohRemovido;

                cout << endl;
            } else {
                cout << "PILHA VAZIA" << endl;
            }
        }

        Fila* getFila(){
            return this;
        }

        void infoValoresNoh(){
            cout << "VALOR NO PRIMEIRO NO: " << primeiroNoh->getValor() << endl;
            cout << "VALOR NO ULTIMO NO: " << ultimoNoh->getValor() << endl;
            cout << endl;
        }
        void esvaziarFila(){
            while(ultimoNoh != NULL)
                desenfileirarNoh();
            desenfileirarNoh();
        }
        friend ostream& operator<<(ostream& os, Fila &fila){
            os << "Primeiro Valor : " << fila.getPrimeiroNohValor() << " " << "Ultimo Valor : " << fila.getUltimoNohValor() << endl;
        }
};

int main(){
    Fila fila;
    fila.enfileirarNoh(5);
    fila.infoValoresNoh();
    
    fila.enfileirarNoh(15);
    fila.infoValoresNoh();
    
    fila.desenfileirarNoh();
    fila.infoValoresNoh();

    fila.enfileirarNoh(25);

    fila.infoValoresNoh();
    fila.desenfileirarNoh();
    
    fila.infoValoresNoh();
    fila.desenfileirarNoh();
    fila.desenfileirarNoh();

    fila.enfileirarNoh(100);
    fila.enfileirarNoh(125);
    fila.esvaziarFila();

    Noh* no1 = new Noh(5);
    Noh* no2 = new Noh(10);

    memcpy(no2,no1,sizeof(Noh*));
    cout << no2->getValor() << endl;
    cout << fila << endl;
    return 0;
}   