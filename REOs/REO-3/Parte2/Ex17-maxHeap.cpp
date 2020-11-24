#include <iostream>
using namespace std;

class Noh{
    public:
        Noh* NohEsquerdo;
        Noh* NohDireita;
        int valor;
}

class MaxHeap{
    private:
        int capacidade;
        int tamanho;
        void arrumaDescendo(int i);
        void arrumaSubindo(int i);
        int filhoEsquerdo(int i){ return (i * 2) + 1;}
        int filhoDireito(int i){ return (i * 2) + 2;}
        int pai(int i){return i/2;}
        MaxHeap(int vet[], int cap){
            capacidade = cap;
            for (int i = 0; i < cap; i++){
                vetor[i] = vet[i];
            }
            for (int i = 0; i < cap; i++){
                cout << vetor[i] << " ";
            }
            cout << "---------------------" << endl;
            constroiHeap();
        }
    public:
    
};



int main(){
    return 0;
}