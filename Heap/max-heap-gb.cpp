#include <iostream>

using namespace std;

class Heap{
private:
	int vetor[100];
	int tamanho;
public:
	Heap(int vet[],int tam);
	bool removeRaiz();
	void troca(int &a, int &b);
	int pai (int i); //feito
	int esquerda (int i); //feito
	int direita (int i); //feito
	void corrigeDescendo(int i);
	void constroi();
	void imprime();
};

Heap::Heap(int vet[], int tam){
	for (int i = 0; i < tam; ++i){
		vetor[i] = vet[i];
	}
	for (int i = 0; i < tam; ++i){
		cout << vetor[i] << " ";
	}
	cout << "---" << endl;
	tamanho = tam;
	constroi();
}

int Heap::pai(int i){
    return i/2;
}

int Heap::esquerda(int i){
	return (i * 2) + 1;
}

int Heap::direita(int i){
	return (i * 2) + 2;
}

void Heap::constroi(){
	for (int i = (tamanho/2) - 1 ; i >= 0 ; --i){
		corrigeDescendo(i);
	}
}

void Heap::corrigeDescendo(int i){
	//cout << "tá corrigindo o " << vetor[i] << endl;
	int esquerda = this->esquerda(i);
	int direita = this->direita(i);
	int maior;
	if (vetor[esquerda] > vetor[direita]){
		maior = esquerda;
	}else{
		maior = direita;
	}
	if (vetor[maior] > vetor[i]){
		//cout << "vai trocar o " << vetor[i] << " pelo o " << vetor[maior] << endl;
		troca(vetor[i], vetor[maior]);
		corrigeDescendo(maior);
	}
}


void Heap::troca(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

void Heap::imprime(){
	for (int i = 0; i < tamanho; ++i){
		cout << " - " << vetor[i];
	}
	cout << endl;
}

int main(){
	int tam = 8;
	int vetor[] = {5,8,90,20,23,43,9,10};
	Heap* h = new Heap(vetor,tam);
	h->imprime();
	return 0;
}