/*
    MaxHeap, para alteração de prioridade
    by joukim & bruno, 2019
*/

#include <iostream>
#include <utility> // para usar swap
#include <stdexcept> // para usar exceção com runtime_error

using namespace std;

struct dado {
    int prioridade;
    int valor;
};

bool operator>(dado d1, dado d2) {
    return d1.prioridade > d2.prioridade;
}

bool operator<(dado d1, dado d2) {
    return d1.prioridade < d2.prioridade;
}

ostream& operator<<(ostream& output,const dado& d) {
    output << "[" << d.valor << "/" << d.prioridade << "]"; 
    return output;
}

class MaxHeap {
private:
    dado* heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i); 
    void corrigeDescendo(int i); 
    void corrigeSubindo(int i);
public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    void alteraPrioridade(int umValor, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap) {
// implemente este método

}

MaxHeap::~MaxHeap() {
// implemente este método

}

int MaxHeap::pai(int i) {
// implemente este método

}
    
int MaxHeap::esquerdo(int i) {
// implemente este método

}
    
int MaxHeap::direito(int i) {
// implemente este método

}
    
void MaxHeap::corrigeDescendo(int i) {
// implemente este método

}

void MaxHeap::corrigeSubindo(int i) {
// implemente este método

}
        
void MaxHeap::imprime() {
// implemente este método

}

dado MaxHeap::retiraRaiz() {
// implemente este método

}


void MaxHeap::insere(dado d){
// implemente este método

}

void MaxHeap::alteraPrioridade(int umValor, int novaPrioridade) {
#error falta implementar o método alteraPrioridade!
    // 1. primeira tarefa: encontrar o dado no vetor de dados


    // 2. segunda tarefa: altera prioridade do dado encontrado, 
    // armazenando prioridade antiga para comparação


    // 3. terceira tarefa: sobe ou desce o dado, de acordo com 
    // a mudança de prioridade   

}

int main () {
    int capacidade;
    cin >> capacidade;
    MaxHeap meuHeap(capacidade);
   
    char opcao;
    cin >> opcao;
    
    dado umDado;
    int valor, novaPrioridade;

    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> umDado.valor;
                cin >> umDado.prioridade;
                meuHeap.insere(umDado);
                break;
            case 'R':
                cout << meuHeap.retiraRaiz().valor << endl;
                break;
            case 'A':
                cin >> valor >> novaPrioridade;
                meuHeap.alteraPrioridade(valor,novaPrioridade); 
                break;               
            case 'P':
                meuHeap.imprime();
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
        cin >> opcao;
    }
    
    return 0;
}