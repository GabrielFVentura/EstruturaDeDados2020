#include <iostream>
using namespace std;

class Noh{
    private:
        int _valor;
    public:
        Noh(int valor){
            _valor = valor;
        }
        int getValor(){
            return _valor;
        }
        void setValor(int v){
            _valor = v;
        }
        Noh* proximoNoh;
};

class Pilha{
    private:
        int _tamanho;
    public:
        Noh* primeiroNoh;

        Pilha(){
            _tamanho = 0;
            primeiroNoh = NULL;
        }
        
        ~Pilha(){
            esvaziarPilha();
        }

        bool pilhaVazia(){
            return (getTamanho() == 0);
        }

        void incrementarTamanho(){
            _tamanho++;
        }

        void decrementarTamanho(){
            _tamanho--;
        }
               
        int getTamanho(){
            return _tamanho;
        }

        int getValorTopo(){
            return primeiroNoh->getValor();
        }
        
        string printTextoPilhaVazia(){
            return pilhaVazia() == 0 ? "Pilha nao esta vazia" : "Pilha esta vazia";
        }

        void printTextoTamanhoValorTopo(){
            cout << printTextoPilhaVazia() << endl;
            if (getTamanho() > 0){
                cout << "Tamanho da Pilha " << getTamanho() << endl;
                cout << "Valor do topo da pilha: " << getValorTopo() << endl;
            }
            cout << endl;
        }

        void enfileirarNoh(int valor){
            if (pilhaVazia()){
                primeiroNoh = new Noh(valor);
            } else {
                Noh* nohTemp = new Noh(valor);
                nohTemp->proximoNoh = primeiroNoh;
                primeiroNoh = nohTemp;
            }
            incrementarTamanho();
        }

        int desenfileirarNoh(){
            if (pilhaVazia()){
                cout << "PILHA VAZIA" << endl;
                return 0;
            }
            int valorRemovido = primeiroNoh->getValor();
            Noh* nohRemovido = primeiroNoh;
            primeiroNoh = primeiroNoh->proximoNoh;
            decrementarTamanho();
            delete nohRemovido;
            return valorRemovido;
        }
        void esvaziarPilha(){
            while(!pilhaVazia()){
                desenfileirarNoh();
            }
        }
};

int main(){
    Pilha pilha;
    pilha.printTextoTamanhoValorTopo();

    pilha.enfileirarNoh(1);
    pilha.printTextoTamanhoValorTopo();

    pilha.enfileirarNoh(2);
    pilha.printTextoTamanhoValorTopo();

    pilha.enfileirarNoh(3);
    pilha.printTextoTamanhoValorTopo();

    cout << "Valor removido do Topo da Pilha:" << pilha.desenfileirarNoh() << endl;
    pilha.printTextoTamanhoValorTopo();

    cout << "Valor removido do Topo da Pilha:" << pilha.desenfileirarNoh() << endl;
    pilha.printTextoTamanhoValorTopo();

    pilha.enfileirarNoh(10);

    pilha.esvaziarPilha();

    pilha.printTextoTamanhoValorTopo();

    cout << pilha.desenfileirarNoh() << endl;
    pilha.printTextoTamanhoValorTopo();

    return 0;
}