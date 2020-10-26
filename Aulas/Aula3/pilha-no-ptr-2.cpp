#include <iostream>
using namespace std;

class Noh{
    private:
        int _valor;
    public:
        Noh* proximoNoh;
        Noh(int v){
            _valor = v;
        }
        int getValor(){
            return _valor;
        }
};

class Pilha{
    private:
        int _tamanho;
    public:
        Pilha(){
            nohTopo = NULL;
            _tamanho = 0;
        }
        void incrementaTmaanho(){
            _tamanho++;
        }
        void decrementaTamanho(){
            _tamanho--;
        }
        int getTamanho(){
            return _tamanho;
        }
        Noh* nohTopo;
        void empilharNoh(int v){
            Noh* nohAdicionado = new Noh(v);
            if (nohTopo == NULL){
                nohTopo = nohAdicionado;
            } else {
                nohAdicionado->proximoNoh = nohTopo;
                nohTopo = nohAdicionado;
            }
            incrementaTmaanho();            
            cout << "VALOR ADICIONADO: " << nohAdicionado->getValor() << endl;
        }
        void desempilharNoh(bool procurando = false){
            if (getTamanho() > 0){
                Noh* nohRemovido = nohTopo;
                cout << "VALOR REMOVIDO: " << nohRemovido->getValor() << endl;

                nohTopo = nohTopo->proximoNoh;
                delete nohRemovido;
                decrementaTamanho();
            } 
            if (getTamanho() == 0 && !procurando){
                cout << "PILHA VAZIA" << endl;
            }        
        }
        void esvaziarPilha(){
            while(getTamanho() > 0){
                desempilharNoh();
            }
        }
        int procurarValorPilha(int v){
            if (nohTopo->getValor() == v){
                cout << "ENCONTRADO NO TAMANHO DA PILHA IGUAL A: " << getTamanho() << endl;
                return getTamanho();
            } else if (getTamanho() > 0) {
                desempilharNoh(true);
                procurarValorPilha(v);
                return -1;
            } 
            if (getTamanho() == 0){
                cout << "VALOR NAO ENCONTRADO" << endl;
            }
        }
};

int main(){
    Pilha pilha;
    pilha.empilharNoh(5);
    pilha.empilharNoh(10);
    pilha.desempilharNoh();
    pilha.desempilharNoh();
    pilha.empilharNoh(15);
    pilha.desempilharNoh();
    pilha.desempilharNoh();
    pilha.empilharNoh(20);
    pilha.desempilharNoh();
    pilha.empilharNoh(150);
    pilha.empilharNoh(200);
    pilha.empilharNoh(250);
    // pilha.esvaziarPilha();
    pilha.procurarValorPilha(300);
    return 0;
}