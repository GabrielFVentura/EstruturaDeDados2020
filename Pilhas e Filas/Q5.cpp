/*Usando o código com as especificações de métodos e atributos mais um programa que usa a classe Fila, crie uma classe fila com armazenamento dinâmico e encadeamento simples.

Nas situações em que algum método não puder ser executado, ele deve só escrever alguma mensagem de erro na saída de erros. Não é permitido alterar o projeto que já existe (mudar os parâmetros ou a ocultação dos métodos já definidos). Métodos auxiliares que forem criados estão sujeitos a avaliação.

Entradas:

O programa passado aceita os seguintes comandos:

i seguido de um valor inteiro: para inserir um item na fila
r: para remover um item da fila
l: para limpar (remover todos) os itens da fila
t: para consultar o tamanho da fila
e: para espiar o próximo da fila (escreve o primeiro sem removê-lo)
f: para finalizar a execução do programa
Saídas:

Todas as saídas de comandos já estão implementadas na função principal. Ao terminar a execução do programa, todos os itens da fila são removidos e escritos, mesmo assim, o destrutor deve desalocar memória de todos os itens da fila.

Exemplo de Entrada e Saída juntas:

i 2
i 4
i 6
r
2
t
2
l
i 8
i 10
e
8
f
8 10*/

#include <iostream>

typedef int Dado;

class Noh {
    friend class Fila;
    private:
        Dado mDado;
        Noh* mPtProx;
};

class Fila {
    public:
        // Constroi uma fila vazia.
        Fila();
        // Desaloca memÃ³ria de todos os nÃ³s da fila.
        ~Fila();
        // Remove e retorna o primeiro item da fila.
        Dado Remover();
        // Insere um item no final da fila.
        void Inserir(const Dado& d);
        // Retorna o primeiro item da fila sem remover.
        Dado Proximo() const;
        // Remove todos os itens da fila.
        void LimparTudo();
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila estÃ¡ vaiza.
        bool Vazia() const;
    private:
        Noh* mPrimeiro;
        Noh* mUltimo;
        unsigned mTamanho;
};

using namespace std;

Fila::Fila() {
}

Fila::~Fila() {
}

void Fila::Inserir(const Dado& d) {
}

Dado Fila::Remover() {
}

Dado Fila::Proximo() const {
}

void Fila::LimparTudo() {
}

bool Fila::Vazia() const {
}

int main() {
    Fila fila;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                fila.Inserir(valor);
                break;
            case 'r': // remover
                cout << fila.Remover() << endl;
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 't': // escrever tamanho
                cout << fila.Tamanho() << endl;
                break;
            case 'e': // espiar proximo
                cout << fila.Proximo() << endl;
                break;
            case 'f': // finalizar
                // vai verificar adiante
                break;
            default:
                cerr << "comando invÃ¡lido\n";
        }
    } while (comando != 'f'); // finalizar execuÃ§Ã£o
    while (not fila.Vazia()) {
        cout << fila.Remover() << ' ';
    }
    cout << endl;
    return 0;
}