/*
Fa�a um programa para controlar a fila de um banco, usando a estrutura heap 
(fila de prioridades). Para agilizar o desenvolvimento, use este c�digo fornecido.

No banco podem chegar 4 tipos de pessoas, na ordem de prefer�ncia de atendimento: 
os que t�m prioridade por lei (P), os clientes vip (V), os clientes normais (C) e 
os n�o-clientes (N).

Para cada tipo, deve existir um contador que vai decrementando a cada pessoa que 
chega na fila. Se um contador chega em zero (zero � um valor inv�lido), ele deve 
voltar ao valor inicial. Os valores iniciais s�o respectivamente 50, 46, 42 e 38.

O programa tem op��es para registrar a entrada de algu�m na fila e para atender 
(retirar da fila). Quando chega algu�m o programa deve ser informado o tipo da 
pessoa e produzir uma senha (n�mero positivo sequencial). A primeira senha � 1. 
Quando algu�m for atendido, o programa deve informar a senha da pessoa a ser atendida.

Entradas:

A capacidade da fila do sistema
Comandos de chegada e de atendimento
Sa�das:

A cada comando de chegada o sistema deve produzir um n�mero identificador sequencial. 
A cada comando de atendimento, o programa deve informar o identificador da pessoa 
a ser atendida.

Exemplo de Entrada:
10
c V
c V
c P
c C
a
a
c P
a
s

Exemplo de saida
1 46
2 45
3 50
4 42
3
1
5 49
5


*/


#include <iostream>
#include <cstdlib>

class Pessoa {
    public:
        int senha;
        int prioridade;
};

bool operator>(const Pessoa& p1, const Pessoa& p2) {
    return p1.prioridade > p2.prioridade;
}

std::ostream& operator<<(std::ostream& saida, const Pessoa& p) {
    saida << "(s" << p.senha << ",p" << p.prioridade << ")";
    return saida;
}

typedef Pessoa TDado;

class MaxHeap {
    friend std::ostream& operator << (std::ostream& saida, const MaxHeap& h);
    public:
        MaxHeap(int cap);
        ~MaxHeap();
        void Inserir(TDado d);
        //TDado Retirar(TDado* ptDado);@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
        bool Retirar(TDado* ptDado);
        bool Vazia();
    private:
        TDado* heap;
        int capacidade;
        int tamanho;
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        inline int Direito(int i);
        inline int Esquerdo(int i);
        inline int Pai(int i);
};

using namespace std;

MaxHeap::MaxHeap(int cap) {
	capacidade = cap ;
	heap = new TDado[cap];
	tamanho = 0;
}

MaxHeap::~MaxHeap() {
	delete[] heap;
}

void MaxHeap::ArrumarDescendo(int i) {
    // Arruma descendo a partir da posicao i.
    
	int filho_direito = Direito(i);
	int filho_esquerdo = Esquerdo(i);
	int maior = i;
	
	if( (filho_esquerdo < tamanho) and (heap[filho_esquerdo] > heap[maior])){
		maior =  filho_esquerdo;
	}
	
	if( (filho_direito < tamanho) and (heap[filho_direito] > heap[maior])){
		maior = filho_direito;
	}
	
	if(maior != i){
		swap(heap[maior],heap[i]);
		ArrumarDescendo(maior);
	}
    
}

void MaxHeap::ArrumarSubindo(int i) {
    // Arruma subindo a partir da posicao i.
    int p = Pai(i);
    
    if(heap[i] > heap[p]){
    	swap(heap[i], heap[p]);
    	ArrumarSubindo(p);
	}
}

int MaxHeap::Pai(int i) {
	return ((i-1)/2);
}

int MaxHeap::Esquerdo(int i) {
	return ((2*i)+1);
}

int MaxHeap::Direito(int i) {
	return ((2*i)+2);
}

bool MaxHeap::Retirar(TDado* ptDado) {//@@@@@@@@@@@@@@@
    // Retira e retorna o maior valor.
    if (tamanho == 0) {
    	cerr << "erro ao retirar raiz" << endl;
        return false;
	}
    
    ptDado->senha = heap[0].senha;

	swap(heap[0], heap[tamanho-1] );
	tamanho--;
	ArrumarDescendo(0);
	
    return true;//@@@@@@@@@@@@@@@@@@@@@@@@@@@
}

bool MaxHeap::Vazia() {
	// Retorna falso se a heap estiver vazia.
	bool estaVazio;
    
    if(tamanho > 0){
    	estaVazio = false;
	}else{
		estaVazio = true;
	}
    
    return estaVazio;
}

void MaxHeap::Inserir(TDado d){
    // Insere um dado na heap.
    if(tamanho == capacidade){
    	cerr << "erro insercao" << endl;
    	exit(EXIT_FAILURE);
	}
    
    heap[tamanho] = d;
    ArrumarSubindo(tamanho);
    tamanho++;
}

std::ostream& operator << (std::ostream& saida, const MaxHeap& h) {
    // Operador de escrita pode ser util para depurar a heap.
    for (int i=0; i < h.tamanho; ++i)
        saida << h.heap[i] << ' ';
    return saida;
}

unsigned Indice(char tipo) {
    // Funcao para converter tipo de pessoa na fila para indices no vetor de contadores.
    switch (tipo) {
        case 'P': return 0;
        case 'V': return 1;
        case 'C': return 2;
        case 'N': return 3;
    }
    return 0;
}

void Decrementar(unsigned& contador, char tipo) {
    // Funcao para decretar um contador de prioridades.
    --contador;
    if (contador == 0) {
        switch (tipo) {
            case 'P': contador = 50; break;
            case 'V': contador = 46; break;
            case 'C': contador = 42; break;
            case 'N': contador = 38; break;
        }
    }
}

int main() {
    unsigned capacidade;
    cin >> capacidade;
    MaxHeap heap(capacidade);
    char comando;
    unsigned indice;
    unsigned vetContadores[] = { 50, 46, 42, 38 };
    char tipo;
    unsigned senha = 0;
    Pessoa pessoa;
    do {
        cin >> comando;
        switch (comando) {
            case 'c': // chegada
                cin >> tipo;
                indice = Indice(tipo);
                pessoa.senha = ++senha;
                pessoa.prioridade = vetContadores[indice];
                heap.Inserir(pessoa);
                Decrementar(vetContadores[indice], tipo);
                cout << pessoa.senha << ' ' << pessoa.prioridade << endl;
                break;
            case 'a': // atendimento
                if (heap.Retirar(&pessoa))
                    cout << pessoa.senha << endl;
                else
                    cout << "ninguem na fila" << endl;
                break;
            case 's': //sair do programa
                break;
        }
    } while (comando != 's');
    return 0;
}
