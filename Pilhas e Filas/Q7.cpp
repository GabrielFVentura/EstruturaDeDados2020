Implemente, a partir deste código, o construtor de cópia, o operador de atribuição (=) e a sobrecarga do operador de soma (+) em uma fila. A soma deverá ter o significado de mesclar duas filas de números inteiros previamente ordenadas e retornar uma nova fila totalmente ordenada. Não é necessário verificar se as filas estavam ordenadas, simplesmente suponha que estavam.

O programa tem duas filas (A e B) e pode inserir elementos em qualquer uma, copiar os valores de qualquer uma para a outra, escrever os dados de qualquer uma ou mesclar A com B numa fila temporária.

Entradas:

Uma sequência de comandos para o programa executar, a saber:

i: seguido de um identificador de fila (a ou b), seguida de um número inteiro, insere a palavra na fila
e: seguido de um identificador de fila (a ou b), escreve o conteúdo da fila
a=b: copia a fila b para a fila a (note a ausência de espaços no comando)
b=a: copia a fila a para a fila b (note a ausência de espaços no comando)
s: soma (mescla) a fila a com a fila b numa fila temporária e escreve o seu conteúdo
t: termina a execução do programa
Saídas:

O comando e escreve o conteúdo de uma das listas. O comando s escreve o resultado de mesclar a com b.

Exemplo de Entrada:

i a 1
i a 3
i a 5
i b 2
i b 4
i b 6
e a
e b
s
a=b
e a
e b
t
Exemplo de Saída:

1 3 5
2 4 6
1 2 3 4 5 6
2 4 6
2 4 6

/* Classe fila, um fila (FIFO) implementada usando encadeamento
 * 
 * by Joukim, 2017, Estruturas de Dados
 * adaptada por Valéria, 2018
 */

#include <iostream>

using namespace std;

class noh {
	friend class fila;
	private:
		int dado; // poderia ser outro tipo de variável
		noh* prox;
};

// pilha dinamicamente encadeada
class fila {
	private:
		noh* primeiro;
		noh* ultimo;
		int tamanho;
    
	public:
		fila();
		fila(const fila& umaFila);
		~fila();
		void insere(int d) { enfileira(d); }
		void enfileira(int d); // insere no final da fila 
		int desenfileira(); // retorna o primeiro elemento da fila
		int espia(); // espia o primeiro elemento da fila
		bool vazia();
		void imprime();  
		fila operator+(const fila& umaFila) const;
                fila& operator=(const fila& umaFila);
};

fila::fila() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

fila::~fila() { 
    while (primeiro != NULL) {
        desenfileira();
    }
}

void fila::enfileira(int d) {
    // primeiro criamos o novo nó
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = NULL;
    if (ultimo != NULL) {
        ultimo->prox = temp;
    }
    ultimo = temp;
    if (vazia()) {
        primeiro = temp;
    }    
    tamanho++; 
}

int fila::desenfileira() {
    int removido;
    noh* temp;
    removido = primeiro->dado;
    temp = primeiro;
    primeiro = primeiro->prox;
    if (vazia()){
        ultimo = NULL;
    }
    delete temp;
    tamanho--;
    return removido;    
}

int fila::espia(){
    return primeiro->dado;
}
    
bool fila::vazia() {
    return (primeiro == NULL);
}

void fila::imprime(){
    noh* temp = primeiro;
    while (temp != NULL) {
	cout << temp->dado << " ";
        temp = temp->prox;
    }
    cout << endl;
}

//mesclar filas
fila fila::operator+(const fila& umaLista) const {
	// IMPLEMENTAR

}

// sobrecarga do operador de atribuição
fila& fila::operator=(const fila& umaFila){
	// IMPLEMENTAR
}

// construtor de cópia
fila::fila(const fila& umaFila) {
	// IMPLEMENTAR
}

int main() {
    fila filaA;
    fila filaB;
    string opcao;
    int dado;
    char idFila;
    do {
        cin >> opcao;
        if (opcao == "i") {
            cin >> idFila >> dado;
            if (idFila == 'a')
                filaA.enfileira(dado);
            else
                filaB.enfileira(dado);
        }
 	else if (opcao == "a=b") {
            filaA = filaB;
        }
        else if (opcao == "b=a") {
            filaB = filaA;
        }
        else if (opcao == "s") {
            fila filaM = filaA + filaB;
            filaM.imprime();
        }
        else if (opcao == "e") {
            cin >> idFila;
            if (idFila == 'a')
                filaA.imprime();
            else
                filaB.imprime();
        }
    } while (opcao != "t");
    return 0;
}