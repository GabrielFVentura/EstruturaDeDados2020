#include <iostream>
using namespace std;

class Pilha{
    private:
        int _capacidade;
        int _tamanho;
    public:
        int pilha[50];
        Pilha(int cap){
            _tamanho = 0;
            _capacidade = cap-1;
            setPilha();
        };

        void setPilha(){
            for (int i = 0; i < getCapacidade(); i++){
                pilha[i] = -1;
            }
        
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

        int getCapacidade(){
            return _capacidade;
        }

        void adicionarValor(int val){
            if (getTamanho() <= getCapacidade()){
                pilha[getTamanho()] = val;
                cout << "Valor adicionado:" << visualizarTopoPilha() << endl;
                cout << "Valor Tamanho:" << getTamanho() << endl;
                incrementaTamanho();
            } else {
                cout << "PILHA CHEIA" << endl;
            }
        }
        
        int removerValor(){
            if (getTamanho() >= 0){
                decrementaTamanho();

                int valorRemovido = pilha[getTamanho()];
                pilha[getTamanho()] = -1;
                cout << "Valor removido: " << valorRemovido << endl;
                return valorRemovido;
            } else {
                cout << "PILHA VAZIA" << endl;
                return -1;
            }
        }

        int visualizarTopoPilha(){
            if (getTamanho() == 0){
                cout << "PILHA VAZIA" << endl;
            }
            return pilha[getTamanho()];
        }

        void esvaziarPilha(){
            while(getTamanho() > 0){
                removerValor();
            }
        }

        int procuraValorPilha(int v){
            int valoresEncontrados[getCapacidade()];

            for (int i = getTamanho();i > 0;i--){
                if (pilha[i] == v){
                    return i;
                }
            }
        }
        
        int procuraValorPilhaCorreto(int v){
            Pilha pilhaTemp(getTamanho());

            for (int i = pilhaTemp.getCapacidade();i >= 0; i--){
                cout << pilhaTemp.getCapacidade();
                pilhaTemp.adicionarValor(pilha[i]);
                cout << "NOVA PILHA: " <<  pilhaTemp.visualizarTopoPilha() << endl;
            }

            for (int i = pilhaTemp.getCapacidade(); i > -1; i--){
                if (pilhaTemp.removerValor() == v){
                    cout << "VALOR ENCONTRADO NO INDICE: " << i << endl;
                    return i;
                } else {
                    cout << "VALOR NAO ENCONTRADO" << endl;
                    return -1;
                }
            }
        }
};

int main(){
    Pilha pilha(5);
    pilha.visualizarTopoPilha();

    pilha.adicionarValor(1);
    pilha.adicionarValor(5);
    pilha.adicionarValor(10);
    pilha.adicionarValor(15);
    pilha.adicionarValor(20);
    pilha.adicionarValor(25);
    pilha.removerValor();
    pilha.adicionarValor(35);
    pilha.esvaziarPilha();
    cout << "VALOR ACHADO NO INDICE: " << pilha.procuraValorPilha(10);    

    // pilha.removerValor();
    // pilha.removerValor();
    // pilha.removerValor();

    // cout << pilha.procuraValorPilhaCorreto(1);
    // int t[] = {1,2,3};

    // cout << t[0];
    // t[0] = 150;
    // cout <<  t[0];

    return 0;
} 