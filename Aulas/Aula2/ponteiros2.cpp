#include <iostream>
using namespace std;

const int MAX = 10;
class Vagao;

class Trem {
    private:
        string _nomeTrem;
        int _tamanho;
        Vagao* _vagoes[MAX];
        Vagao* _primeiroVagao;
    public:
        Trem(string nomeTrem){
            _tamanho = 0;
            _nomeTrem = nomeTrem;
        };
        ~Trem();
        string getNomeTrem(){
            return _nomeTrem;
        }

        int getTamanhoTrem(){
            return _tamanho;
        }

        void incrementaTamanho(){
            _tamanho++;
        }
        void decrementaTamanho(){
            _tamanho--;
        }
        void encarrilharTrem(Vagao* vagao){
            _vagoes[getTamanhoTrem()] = vagao;
        }
        Vagao* getFrenteTrem(){
            return _vagoes[getTamanhoTrem()];
        }
};

class Vagao {
    private:
        string _tipoVagao;
        Trem* _ptrTrem;
    public:
        Vagao* proximoVagao;
        Vagao(string tipoVagao, Trem* ptrTrem){
            _ptrTrem = ptrTrem;
            _tipoVagao = tipoVagao;
            proximoVagao = NULL;
            ptrTrem->incrementaTamanho();
        };
        Vagao(string tipoVagao){
            _tipoVagao = tipoVagao;
            proximoVagao = NULL;
        };
        ~Vagao();
        string getTipoVagao(){
            return _tipoVagao;
        }
        Trem* getPtrTrem(){
            return _ptrTrem;
        }
        void setPtrTrem(Trem* ptrTrem){
            _ptrTrem = ptrTrem;
            ptrTrem->incrementaTamanho();
        }
        void testVagao(){
            cout << this->getTipoVagao();
        }
};

int main(){
    Trem* trem = new Trem("Expresso Polar");

    Vagao* vagao1 = new Vagao("Ferro", trem);
    cout << vagao1->getTipoVagao() << endl;
    cout << vagao1->getPtrTrem()->getNomeTrem() << endl;
    cout << vagao1->getPtrTrem()->getTamanhoTrem() << endl;

    vagao1->getPtrTrem()->encarrilharTrem(vagao1);

    cout << vagao1->getPtrTrem()->getFrenteTrem()->getTipoVagao();

    Vagao* vagao2 = new Vagao("Carvao");
    vagao1->proximoVagao = vagao2;
    vagao2->setPtrTrem(trem);
    cout << vagao2->getPtrTrem()->getNomeTrem() << endl;
    
    cout << vagao2->getPtrTrem()->getTamanhoTrem() << endl;

    cout << vagao1->proximoVagao->getTipoVagao() << endl;

    cout << vagao1->proximoVagao->getPtrTrem()->getNomeTrem();
    vagao1->testVagao(); 
    vagao2->testVagao();
    return 0;
}