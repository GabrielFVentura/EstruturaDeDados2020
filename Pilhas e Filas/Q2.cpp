
/*Usando o código com as especificações de métodos e atributos mais um programa que usa a classe Pilha, crie uma classe pilha com armazenamento dinâmico.
O método Desempilhar deve escrever alguma mensagem de erro na saída de erros quando não for possível desempilhar.

Entradas:

O programa passado aceita os seguintes comandos:

i seguido de um valor inteiro: para inserir um item na pilha
r: para remover um item da pilha
l: para limpar (remover todos) os itens da pilha
t: para consultar o tamanho da pilha
e: para espiar o topo da pilha (escreve o topo sem removê-lo)
f: para finalizar a execução do programa

Saídas:Todas as saídas de comandos já estão implementadas na função principal. Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos, mesmo assim, o destrutor deve desalocar memória de todos os itens da pilha.

Exemplo de Entrada e Saída juntas:


i 2
i 4
i 6
r
6
t
2
l
i 8
i 10
e
10
f
10 8*/

#include <iostream>

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variÃ¡vel
        Noh* mPtProx;
};

class Pilha {
    public:
        // ConstrÃ³i pilha vazia.
        Pilha();
        // Destrutor que desaloca memÃ³ria.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se nÃ£o for possÃ­vel desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() { return mTamanho; }
        // Retorna o valor que estÃ¡ no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha estÃ¡ Vazia.
        bool Vazia() const;
    private:
        Noh* mPtTopo;
        unsigned mTamanho;
};

using namespace std;

Pilha::Pilha() {
    mPtTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha() {
    LimparTudo();
}

Dado Pilha::Desempilhar() {
    Noh* mPtAux = mPtTopo;
    Dado removido = mPtAux->mDado;
    
    mPtTopo = mPtTopo->mPtProx;
    
    delete mPtAux;
    mTamanho--;
    return removido;
}

void Pilha::Empilhar(const Dado& d) {
    Noh* novo = new Noh();
    novo->mPtProx = mPtTopo;  
    mPtTopo = novo;
    novo->mDado = d;
    mTamanho++;
}

void Pilha::LimparTudo() {
    while (mPtTopo!=NULL)
    {
        Noh* aux = mPtTopo;
        mPtTopo = mPtTopo->mPtProx;
        delete aux;
        mTamanho--;
    }
    mPtTopo = NULL;
}

Dado Pilha::Topo() const {
    return mPtTopo->mDado;
}

bool Pilha::Vazia() const {
    return mPtTopo == NULL;
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando invÃ¡lido\n";
        }
    } while (comando != 'f'); // finalizar execuÃ§Ã£o
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}