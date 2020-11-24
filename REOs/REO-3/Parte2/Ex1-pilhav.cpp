#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class pilhav {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;

    public:
        pilhav(int cap = 100);
        ~pilhav();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

pilhav::pilhav(int cap)
{
    dados = new Dado[cap];
    tamanho = 0;
    capacidade = cap;
    posTopo = -1;
}
pilhav::~pilhav()
{
    while (posTopo != -1)
        desempilha();
    posTopo = -1;
    delete dados;
}
void pilhav::empilha(Dado ValorInserido)
{
    dados[posTopo+1] = ValorInserido;
    tamanho++;
    posTopo++;
    capacidade--;
}

Dado pilhav::desempilha()
{
    Dado removido = dados[posTopo];
    tamanho--;
    posTopo--;
    return removido;
}

Dado pilhav::espia()
{
    return dados[posTopo];
}

void pilhav::depura()
{
    for (int i = 0; i < tamanho; i++)
        cout << dados[i] << " ";

    cout << endl;
}

void pilhav::info()
{
    cout << tamanho << " " << posTopo << endl;
}

int main()
{
    pilhav pilha(20);
    Dado valorInserido;
    
    for (int i = 0; i < 5; i++)
    {
        cin >> valorInserido;
        pilha.empilha(valorInserido);
    }

    for (int i = 0; i < 3; i++)
        cout << pilha.desempilha() << " ";
        
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cin >> valorInserido;
        pilha.empilha(valorInserido);
    }

    for (int i = 0; i < 3; i++)
        cout << pilha.desempilha() << " ";

    cout << endl;

    cout << pilha.espia() << endl;

    pilha.depura();

    pilha.info();

    return 0;
}