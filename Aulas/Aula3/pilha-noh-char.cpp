#include <iostream>
using namespace std;

class NohStr{
    private:
        char _ch;
    public:
        NohStr* nohProx;

        void setChar(char ch){
            _ch = ch;
        }

        char getChar(){
            return _ch;
        }

        NohStr(char ch){
            _ch = ch;
            nohProx = NULL;
        }
};

class PilhaStr{
    private:
        unsigned int _tamanho;
        unsigned int _capacidade;
    public:
        NohStr* nohTopo;

        PilhaStr(unsigned int cap){
            _capacidade = cap;
            _tamanho = 0;
            nohTopo = NULL;
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
        void adicionaNoh(char ch){
            NohStr* nohTemp = new NohStr(ch);

            if (nohTopo == NULL){
                nohTopo = nohTemp;
            } else {
                nohTemp->nohProx = nohTopo;
                nohTopo = nohTemp;
            }
            incrementaTamanho();
        }

        void removerNoh(){
            NohStr* nohRemovido = nohTopo;
            nohTopo = nohTopo->nohProx;
            decrementaTamanho();
            cout << nohRemovido->getChar();
            delete nohRemovido;
        }

        void displayTopoPilha(){
            cout << nohTopo->getChar();
        }

        void displayInfoPilha(){
            while(nohTopo->nohProx != NULL){
                cout << nohTopo->getChar() << endl;
                displayInfoPilha();
            }
            cout << nohTopo->getChar() << endl;
        }
};

int main(){
    string nome = "Gabriel";
    PilhaStr pilha(nome.length());

    for (int i = 0; i < nome.length(); i++){
        pilha.adicionaNoh(nome[i]);
    }
    pilha.removerNoh();

    for (int i = 0; i < nome.length(); i++){
        pilha.removerNoh();
    }

    return 0;
}