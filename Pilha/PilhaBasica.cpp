#include <iostream>
using namespace std;

typedef int Dado;

class Noh{
    friend class Pilha;

    private:
        Noh* proximoNoh;
        Dado dadoNoh;
        
    public:
        Noh(Dado d){
            proximoNoh = NULL;
            dadoNoh = d;
        };
};

class Pilha{
    public:
        Pilha(){
            topoNoh = NULL,
            tamanhoPilha = 0;
        }

        ~Pilha(){
            LimparPilha();
        }

        void EmpilharNoh(Dado d){
            Noh* novoNoh = new Noh(d);

            novoNoh->proximoNoh = topoNoh;
            topoNoh = novoNoh;

            tamanhoPilha++;
        }

        Dado DesempilharNoh(){
            Noh* deletarNoh = topoNoh;
            Dado dadoRemovido = deletarNoh->dadoNoh;

            topoNoh = topoNoh->proximoNoh;

            delete deletarNoh;
            --tamanhoPilha;

            return dadoRemovido;
        }
        
    private:
        Noh* topoNoh;
        unsigned int tamanhoPilha;
        LimparPilha();

};

int main()
{
    return 0;
}