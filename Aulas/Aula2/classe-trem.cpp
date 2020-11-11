/*____________________________________________________________________________________
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

const int MAX = 10;
class Vagao;
class Trem;

class Vagao {
    private:
        string _tipoVagao;
    public:
        Vagao* proximoVagao;
        Vagao(string tipoVagao){
            _tipoVagao = tipoVagao;
            proximoVagao = NULL;
        };
        ~Vagao();
        string getTipoVagao(){
            return _tipoVagao;
        }
};

class Trem {
    private:
        string _nomeTrem;
        int _tamanho;
        Vagao* _vagoes[MAX];
    public:
        Vagao* _ultimoVagao;
        Trem(string nomeTrem){
            _tamanho = 0;
            _nomeTrem = nomeTrem;
            _ultimoVagao = NULL;
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

        Vagao* getUltimoVagao(){
            return _ultimoVagao;
        }
        
        void setUltimoVaga(Vagao* vagao){
            _ultimoVagao = vagao;
        }
        
        void adicionarVagao(string tipoVagao){
            Vagao* vagaoTemp = new Vagao(tipoVagao);
            if (getUltimoVagao() == NULL){
                setUltimoVaga(vagaoTemp);
            } else {
                getUltimoVagao()->proximoVagao = getUltimoVagao(); 
                setUltimoVaga(vagaoTemp);
            }
            incrementaTamanho();
        }

        Vagao* getUltimoVagaoTrem(){
            return _vagoes[getTamanhoTrem()];
        }
};

int main(){
    Trem* trem = new Trem("Expresso Polar");
    // Vagao* vagao1 = new Vagao("Ferro", trem);

    // cout << vagao1->getTipoVagao() << endl;
    // cout << vagao1->getPtrTrem()->getNomeTrem() << endl;
    // cout << vagao1->getPtrTrem()->getTamanhoTrem() << endl;

    // vagao1->getPtrTrem()->encarrilharTrem(vagao1);

    // cout << vagao1->getPtrTrem()->getUltimoVagaoTrem()->getTipoVagao();

    // Vagao* vagao2 = new Vagao("Carvao");

    // vagao1->proximoVagao = vagao2;
    // vagao2->setPtrTrem(trem);
    // cout << vagao2->getPtrTrem()->getNomeTrem() << endl;
    
    // cout << vagao2->getPtrTrem()->getTamanhoTrem() << endl;

    // cout << vagao1->proximoVagao->getTipoVagao() << endl;

    // cout << vagao1->proximoVagao->getPtrTrem()->getNomeTrem();
    trem->adicionarVagao("Minerio");
    cout << "trem: " << trem->getUltimoVagao()->getTipoVagao() << endl;

    trem->adicionarVagao("Ferro");
    cout << "trem: " << trem->getUltimoVagao()->getTipoVagao() << endl;
6
    trem->adicionarVagao("Ferro");
    cout << "trem: " << trem->getUltimoVagao()->proximoVagao->getTipoVagao() << endl;
    return 0;
}