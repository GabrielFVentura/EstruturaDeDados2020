/*O código fornecido implementa uma lista duplamente encadeada armazenando os dados em arranjo, faltando os métodos de inserção e remoção apenas. Você deverá justamente implementá-los.

A implementação disponibilizada controla as posições vazias disponíveis no arranjo por meio de uma lista encadeada de posições vazias. Para obter a próxima posição vazia, basta utilizar o método alocaPosicao().

A função principal encontra-se implementada e não pode ser alterada. Você poderá modificar e adicionar métodos na lista, a seu critério.

Entradas:

O programa lê códigos de comandos a executar. Sempre um caractere identificando o comando, seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

I: para inserir um elemento no início da lista;
i: para inserir um elemento no fim da lista;
R: para remover um elemento no início da lista;
r: para remover um elemento no fim da lista;
p: para imprimir os elementos da lista, seguindo o encadeamento do primeiro ao último;
d: para imprimir os vetor de dados da lista, para depuração;
s: para sair da aplicação.
Saídas:

Apenas os comandos de impressão e depuração possuem saída, sendo que já foram implementados.

Exemplo de Entrada:

4
i 2
i 4
r
i 5
R
I 0
p
d
i 6
I 7
p
d
r
R
r
R
I 8
p
d
s
Exemplo de Saída:

0 5 
5 0 
2/{0-1}/2:(-1,[0],1)(0,[5],-1)(-1,[-1],3)(-1,[-1],-1)
7 0 5 6 
6 5 0 7 
4/{3-2}/-1:(3,[0],1)(0,[5],2)(1,[6],-1)(-1,[7],0)
8 
8 
1/{0-0}/1:(-1,[8],-1)(0,[5],3)(1,[6],-1)(-1,[7],2)
Exemplo de Entrada:

10
i 20 i 30 i 50 i 70 i 90 i 100 i 1 i 2 i 3 i 4
p
d
r r R R
I 5 I 6
i 7 i 8
p 
d
r r R R
r r R R
i 200 i 300
I 9 I 10
p
d
s
Exemplo de Saída:

20 30 50 70 90 100 1 2 3 4 
4 3 2 1 100 90 70 50 30 20 
10/{0-9}/-1:(-1,[20],1)(0,[30],2)(1,[50],3)(2,[70],4)(3,[90],5)(4,[100],6)(5,[1],7)(6,[2],8)(7,[3],9)(8,[4],-1)
6 5 50 70 90 100 1 2 7 8 
8 7 2 1 100 90 70 50 5 6 
10/{0-9}/-1:(-1,[6],1)(0,[5],2)(1,[50],3)(2,[70],4)(3,[90],5)(4,[100],6)(5,[1],7)(6,[2],8)(7,[7],9)(8,[8],-1)
10 9 90 100 200 300 
300 200 100 90 9 10 
6/{7-2}/1:(-1,[6],8)(-1,[5],0)(3,[300],-1)(5,[200],2)(6,[90],5)(4,[100],3)(7,[9],4)(-1,[10],6)(7,[7],9)(8,[8],-1)

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/
/*
 * Classe listarranjo, uma lista dinamicamente duplamente encadeada em arranjo
 *
 * by Joukim, 2019, Estruturas de Dados
 *
 */

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// para facilitar a troca de int para outro tipo
// estamos criando um apelido para int chamado dado
// - com isso, destaca-se que a lista pode ser uma
// lista de qualquer objeto, não apenas inteiros...
// ou seja: é uma lista de dados
typedef int dado; // typedef permite criar novos tipos a partir de outros
typedef int posicao;

const posicao INVALIDO = -1;
const dado VALOR_PADRAO = -1;

class noh {
    friend class listarranjo;
    private:
        dado elemento; // poderia ser outro tipo de variável
        posicao proximo;
        posicao anterior;
        noh() : elemento(VALOR_PADRAO), proximo(INVALIDO), anterior(INVALIDO) {}
};


// lista dinamicamente encadeada
class listarranjo {
    private:
        noh* vetorDados; // vetor para armazenamento da lista
        posicao primeiro;
        posicao ultimo;
        unsigned tamanho;
        posicao primeiroApagado;
        unsigned capacidade;
        // "Aloca" para uso, se houver. Retorna a posicao alocada e informa se foi possível alocar.
        bool alocaPosicao(posicao* ptPosAlocada);
    public:
        listarranjo(unsigned cap);
        ~listarranjo();
        // inserção, remoção e procura
        bool insereNoInicio(dado d);
        bool insereNoFim(dado d);
        bool removeNoInicio();
        bool removeNoFim();
        void imprime();
        void depura();
};


// constrói uma lista inicialmente vazia
listarranjo::listarranjo(unsigned cap) {
    capacidade = cap;
    vetorDados = new noh[cap];
    tamanho = 0;
    primeiro = INVALIDO;
    ultimo = INVALIDO;
    primeiroApagado = 0;
    unsigned ult = cap - 1;
    for (unsigned i = 0; i < ult; ++i)
        vetorDados[i].proximo = i + 1;
    vetorDados[ult].proximo = INVALIDO;
}

// destrutor da lista
listarranjo::~listarranjo( ) {
    delete[] vetorDados;
}

// Retorna uma posicao alocada para uso. Retorna tambem um booleano que indica
// se foi possivel fazer a alocacao.
bool listarranjo::alocaPosicao(posicao* ptPosAlocada) {
    if (tamanho == capacidade)
        return false;
    *ptPosAlocada = primeiroApagado;
    primeiroApagado = vetorDados[primeiroApagado].proximo;
    return true;
}

// Insere no início da lista. Retorna um booleano que indica se foi possivel fazer a insercao.
bool listarranjo::insereNoInicio(dado d) {
    // verifica se ainda cabe um novo elemento
    if (tamanho == capacidade){
        return false;
    }
    noh* nohNovo = new noh(); 
    nohNovo->elemento = d;
    if (tamanho == 0){
        vetorDados[tamanho] = *nohNovo;
        primeiro = 0;
        ultimo = 0;
        depura();
        tamanho++;
        return true;
    }
    noh* nohAux = &vetorDados[ultimo];
    vetorDados[tamanho] = vetorDados[tamanho - 1];
    vetorDados[ultimo + 1] = *nohAux;
    vetorDados[ultimo] = *nohNovo;    
    depura();
    primeiro = tamanho;
    tamanho++;
    return true;
    // se a lista estiver vazia, inserimos o último nó
    // já tem elementos na lista, insere no iní cio
}

// Insere no final da lista. Retorna um booleano que indica se foi possivel fazer a insercao.
bool listarranjo::insereNoFim(dado d) {
    // verifica se ainda cabe um novo elemento
    if (tamanho == capacidade){
        return false;
    }
    noh* nohNovo = new noh(); 
    nohNovo->elemento = d;
    // se a lista estiver vazia, inserimos o primeiro nó
    if (tamanho == 0){
        vetorDados[tamanho] = *nohNovo;
        primeiro = 0;
        ultimo = 0;
        tamanho++;
        return true;
    }
    ultimo = tamanho;
    vetorDados[tamanho] = *nohNovo;
    vetorDados[tamanho - 1].proximo = tamanho;
    vetorDados[tamanho].anterior = tamanho - 1;
    tamanho++;
    // se já tem elementos na lista, insere no final
}

bool listarranjo::removeNoInicio() {

    // remoção simplesmente marca a posição como inválida
    // e diminui tamanho da lista

    // precisa verificar se não está removendo o último
}

bool listarranjo::removeNoFim() {
    // remoção simplesmente marca a posição como inválida
    // e diminui tamanho da minhaLista

    // precisa verificar se não está removendo o último
}

// método básico que *percorre* a lista, imprimindo seus elementos
void listarranjo::imprime() {
    posicao aux = primeiro;

    while (aux != INVALIDO) {
        cout << "vetorDados[" << aux << "]: " << vetorDados[aux].elemento << " ";
        aux = vetorDados[aux].proximo;
    }
    cout << endl;

    // imprime reverso (para mostrar duplo encadeamento)
    aux = ultimo;
    cout << "INVERTIDO" << endl;

    while (aux != INVALIDO) {
        cout << "vetorDados[" << aux << "]: " << vetorDados[aux].elemento << " ";
        aux = vetorDados[aux].anterior;
    }
    cout << endl;
}

// método básico que imprime o vetor de dados, para depuração
void listarranjo::depura() {
    cout << tamanho << "/{"<< primeiro << "-" << ultimo << "}/" << primeiroApagado << ":";
    for (unsigned i = 0; i < capacidade; i++) {
        cout << "(" << vetorDados[i].anterior
             << ",[" << vetorDados[i].elemento << "],"
             << vetorDados[i].proximo << ")";
    }
    cout << endl;
}


int main() {
    unsigned cap;
    cin >> cap;
    listarranjo minhaLista(cap);
    char operacao;
    dado valor;
    minhaLista.insereNoInicio(2);
    minhaLista.insereNoInicio(5);
    minhaLista.insereNoInicio(7);
    minhaLista.insereNoInicio(9);
    // minhaLista.depura();

    // do {
    //     cin >> operacao;
    //     switch (operacao) {
    //          case 'I': // inserir no início
    //             cin >> valor;
    //             if (not minhaLista.insereNoInicio(valor))
    //                 cout << "Lista cheia, incapaz de inserir\n";
    //             break;
    //         case 'i': // inserir no fim
    //             cin >> valor;
    //             if (not minhaLista.insereNoFim(valor))
    //                 cout << "Lista cheia, incapaz de inserir\n";
    //             break;
    //         case 'R': // remover no início
    //             if (not minhaLista.removeNoInicio())
    //                 cout << "Lista vazia, incapaz de remover\n";
    //             break;
    //         case 'r': // remove no fim
    //             if (not minhaLista.removeNoFim())
    //                 cout << "Lista vazia, incapaz de remover\n";
    //             break;
    //         case 'p': // mostrar estrutura
    //             minhaLista.imprime();
    //             break;
    //         case 'd': // depura vetor de dados
    //             minhaLista.depura();
    //             break;
    //         case 's': // sair
    //             // será tratado no while
    //             break;
    //         default:
    //             cout << "Opção inválida!" << endl;
    //     }
    // } while (operacao != 's');

    return 0;
}

