#include <iostream>
using namespace std;

class Noh{
    private:
        int _valorNoh;
    public:
        Noh* nohProximo;
        Noh(int v){
            _valorNoh = v;
            nohProximo = NULL;
        }
        int getValorNoh(){return _valorNoh;}
};

class Pilha{
    private:
        int _tamanhoPilha;
    public:
        Noh* nohTopo;
        Pilha(){
            nohTopo = NULL;
            _tamanhoPilha = 0;
        }
        int getTamanhoPilha(){return _tamanhoPilha;}
        void adicionarNoh(int v){
            Noh* nohTemp = new Noh(v);
            if (getTamanhoPilha() == 0){
                nohTopo = nohTemp;
            } else {
                nohTemp->nohProximo = nohTopo;
                nohTopo = nohTemp;
            }
            _tamanhoPilha++;
        }

        void printValorNohTopo(){
            cout << nohTopo->getValorNoh() << endl;
        }

        void removerNoh(){
            if (getTamanhoPilha() != 0){
                Noh* nohTemp = nohTopo;
                nohTopo = nohTopo->nohProximo;
                cout << "VALOR REMOVIDO: " << nohTemp->getValorNoh() << endl;
                _tamanhoPilha--;
                delete nohTemp;
            } else {
                cout << "PILHA VAZIA" << endl;
            }
        }

        void esvaziarNoh(){
            while (getTamanhoPilha() != 0){
                removerNoh();
            }
            delete nohTopo;
        }

        void inverterPilha(){
            Pilha* pilhaTemp;
            Noh* nohTemp = nohTopo;
            while (nohTopo != NULL){
                this->removerNoh();
                pilhaTemp->adicionarNoh(nohTemp->getValorNoh());
            }
            this = *pilhaTemp;
        }
};

int main(){
    Pilha pilha;
    pilha.adicionarNoh(5);
    pilha.printValorNohTopo();

    pilha.adicionarNoh(15);
    pilha.printValorNohTopo();

    pilha.adicionarNoh(25);
    pilha.printValorNohTopo();
    pilha.esvaziarNoh();
    pilha.adicionarNoh(25);
    pilha.removerNoh();
    pilha.adicionarNoh(25);
    pilha.adicionarNoh(35);
    pilha.adicionarNoh(45);
    pilha.inverterPilha();
    pilha.printValorNohTopo();
    return 0;
}