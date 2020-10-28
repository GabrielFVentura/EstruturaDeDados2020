#include <iostream>
using namespace std;

class Fila{
    private:
        int _tamanho;
        int _capacidade;
        int _array[50];
    public:
        Fila(int cap){
            _capacidade = cap;
            _tamanho = 0;
            setFila();
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
        int getCapacidade(){
            return _capacidade;
        }
        void setFila(){
            for (int i = 0;i < getCapacidade(); i++){
                _array[i] = -1;
            }
        }
        void setFilaProxima(){
            for (int i = 1; i < getTamanho(); i++){
                _array[i] = 1;
            }
        }
        void adicionarValorFila(int v){
            for (int i = 0; i < getTamanho(); i++){

            }
            _array[getTamanho()] = v;
        }
};

int main(){
    int a1[] = {1,2,3};
    int a2[] = a1;

    return 0;
}