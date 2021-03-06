#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef int Dado;

class MaxHeap{
    private:
        Dado* Heap;
        int capacidade;
        int tamanho;
        int pai(int i){
            return (i - 1)/2;
        };
        int esquerdo(int i){
            return (2*i)+1;
        };
        int direito(int i){
            return (2*i)+2;
        };
        void arruma(){
            int numeroArrumacoes = tamanho / 2 - 1;
            for (int i = tamanho / 2 - 1; i >= 0; i--){
                corrigeDescendo(i);
                cout << numeroArrumacoes << ": ";
                printHeap();
                numeroArrumacoes--;
            }
        };
        void corrigeDescendo(int i){
            int esq = esquerdo(i);
            int dir = direito(i);
            int maior = i;

            if ((esq < tamanho) && (Heap[esq] > Heap[maior])){
                maior = esq;
            }

            if ((dir < tamanho) && (Heap[dir] > Heap[maior])){
                maior = dir;
            } 

            if (maior != i){
                swap(Heap[i],Heap[maior]);
                corrigeDescendo(maior);
            }
        };
        void corrigeSubindo(int i){
            int p = pai(i);
            if (Heap[i] > Heap[p]){
                swap(Heap[i],Heap[p]);
                corrigeSubindo(p);
            }
        };
    public:
        MaxHeap(int cap){
            capacidade = cap;
            Heap = new Dado[cap];
            tamanho = 0;
        };
        MaxHeap(Dado vet[], int tam){
            capacidade = tam;
            tamanho = tam;

            Heap = new Dado[capacidade];
            copy(&vet[0], &vet[tam], &Heap[0]);
            arruma();
        };
        ~MaxHeap(){
            delete [] Heap;
        };
        void printHeap(){
            for (int i = 0; i < tamanho; i++){
                cout << Heap[i] << " ";
            }
            cout << endl;
        };
        Dado espiaRaiz(){
            return Heap[0];
        };
        Dado retiraRaiz(){
            if (tamanho == 0){
                cerr << "ERRO AO RETIRAR RAIZ" << endl;
                exit(EXIT_FAILURE);
            }
            Dado aux = Heap[0];
            swap(Heap[0], Heap[tamanho-1]);
            tamanho--;
            corrigeDescendo(0);
            return aux;
        };
        void insere(Dado d){
            if (tamanho == capacidade){
                cerr << "ERRO AO INSERIR" << endl;
                exit(EXIT_FAILURE);
            }
            Heap[tamanho] = d;
            corrigeSubindo(tamanho);
            tamanho++;
        };
};

int main(){
    int tamanho;
    cin >> tamanho;
    int arr[tamanho];
    for (int i = 0; i < tamanho; i++){
        cin >> arr[i];
    }    

    MaxHeap max(arr,tamanho);

    return 0;
}