/*Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa não for um problema. Nesse caso, é importante controlar os índices para "dar a volta" no vetor sempre que for necessário. Uma fila assim pode ser chamada de fila circular.

O programa fornecido contém os métodos e atributos para uma implementação assim, juntamente com um programa para testar a classe fila. Complete a implementação, fazendo com que a inserção (método Enfileirar) sempre use o início do vetor (posição zero) quando a fila estiver vazia.

Entradas:

Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.

Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

t - para terminar a execução do programa
e - para enfileirar um valor - seguido do valor (número inteiro)
d - para desenfileirar um valor
p - para escrever o próximo valor na fila (sem desenfileirar)
i - para escrever as informações da fila (atributos e conteúdo)
Saídas:

Os comandos d, p e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo. Note que o comando “i”, que usa o método EscreverConteudo não informa quais são os valores que “estão na fila”, mas sim qual o conteúdo de todo o espaço de memória alocado para o armazenamento de valores de fila, começando da posição zero.

Exemplo de Entrada e Saída juntos:

3
e 1
e 2
e 3
i
tamanho=3 capacidade=3 inicio=0 fim=2
1 2 3 
d
1
e 4
i
tamanho=3 capacidade=3 inicio=1 fim=0
4 2 3 
d
2
d
3*/

#include <iostream>

typedef int Dado;

class Fila {
    public:
        Fila(unsigned cap = 80);
        ~Fila();
        // Remove e retorna o primeiro elemento da fila.
        Dado Desenfileira();
        // Insere um valor na fila. Retorna um booleano que informa se a inserÃ§Ã£o foi realmente
        // realizada.
        bool Enfileirar(const Dado& valor);
        // Escreve todo o conteÃºdo do armazenamento da fila na saÃ­da de dados.
        void EscreverConteudo(std::ostream& saida) const;
        // Retorna tamanho, capacidade, inicio e fim da fila.
        void Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const;
        // Retorna o primeiro elemento da fila, sem removÃª-lo.
        Dado Proximo() const;
        // Retorna a quantidade de elementos na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila estÃ¡ vazia.
        bool Vazia() const;
    protected:
        unsigned mCapacidade;
        Dado* mDados;
        unsigned mPosInicio; // indica a posicao do primeiro
        unsigned mPosFim;    // indica a posicao do ultimo
        unsigned mTamanho;
};

using namespace std;

Fila::Fila(unsigned cap) { // cap tem valor default
}

Fila::~Fila() {
}

// Remove e retorna o primeiro elemento da fila.
Dado Fila::Desenfileira() {
}

// Insere um valor na fila. Retorna um booleano que informa se a inserÃ§Ã£o foi realmente realizada.
bool Fila::Enfileirar(const Dado& valor) {
}

// Escreve todo o conteÃºdo do armazenamento (comeÃ§ando da posiÃ§Ã£o zero) da fila na saÃ­da de dados.
void Fila::EscreverConteudo(ostream& saida) const {
}

// Retorna tamanho, capacidade, inicio e fim da fila.
void Fila::Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const {
}

// Retorna o primeiro elemento da fila, sem removÃª-lo.
Dado Fila::Proximo() const {
}

// Consulta se a fila estÃ¡ vazia.
bool Fila::Vazia() const {
}

int main() {
    unsigned tamanho, capacidade, inicio, fim;
    cin >> capacidade;
    Fila fila(capacidade);
    Dado valor;
    char comando;
    cin >> comando;
    while (comando != 't') {
        switch (comando) {
        case 'e': // enfileirar
            cin >> valor;
            if (not fila.Enfileirar(valor))
                cout << "FILA CHEIA!\n";
            break;
        case 'd': // desenfileirar
            if (fila.Vazia())
                cout << "ERRO\n";
            else {
                valor = fila.Desenfileira();
                cout << valor << endl;
            }
            break;
        case 'p': // proximo
            if (fila.Vazia())
                cout << "ERRO\n";
            else
                cout << fila.Proximo() << endl;
            break;
        case 'i': // informaÃ§Ãµes sobre a fila
            fila.Info(&tamanho, &capacidade, &inicio, &fim);
            cout << "tamanho=" << tamanho << " capacidade=" << capacidade << " inicio=" << inicio
                 << " fim=" << fim << endl;
            fila.EscreverConteudo(cout);
            break;
        case 't':
            // vai testar novamente no while
            break;
        default:
            cout << "comando invÃ¡lido\n";
        }
        cin >> comando;
    }
    return 0;
}