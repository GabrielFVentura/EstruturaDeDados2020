/*Em Linguagens Formais e Autômatos um reconhecedor é um meio formal de verificar se uma dada sentença 
pertence ou não a uma determinada linguagem. Pilhas são estruturas usadas com frequência em reconhecedores.

Uma linguagem pode ser definida com um subconjunto de S*, a partir de um alfabeto S, onde S é um conjunto finito, 
não vazio, de símbolos. Considere o alfabeto S = {A,B,C} e a linguagem L = {Ai B C2i B Ai | i > 0}, ou seja, 
as sequências ABCCBA, AABCCCCBAA, AAABCCCCCCBAAA são todas pertencentes ao conjunto de sentenças válidas de L. 
Faça um programa baseado em pilhas que, dada uma sequência w de caracteres A, B e C, verifique se w faz parte ou não 
do conjunto de sentenças de L.

O processamento deve ser interrompido assim que for possível dizer se w faz parte ou não do conjunto. 
Por exemplo, se o segundo B for encontrado antes de todos os Cs serem encontrados, já é possível dar a resposta 
sem processar os As.

Ao final, o programa deve escrever se o padrão da linguagem foi reconhecido e os tamanhos das pilhas.

Você pode usar uma implementação de pilha da biblioteca padrão ou usar uma implementação feita anteriormente. 
Não é permitido o uso de métodos na classe pilha que sejam específicos para este problema.

Sugestão: Usando duas pilhas, seu programa deve ler As e a cada A lido, empilhar um A numa e dois Cs na outra. 
Após ler um B, o programa adota a seguinte estratégia: a cada C lido, desempilhar um C. Finalmente, depois do 
segundo B, cada A lido faz com que um A seja desempilhado. Ao final da iteração, a sentença foi reconhecida se 
todas as letras foram processadas e todos os desempilhamentos foram bem sucedidos e se as duas pilhas estão vazias.

Entradas:

Palavra a ser verificada.
Saídas:

A palavra sim ou nao (sem acento), indicando se a sentença foi reconhecida.
O tamanho da pilha de As.
O tamanho da pilha de Cs.
Exemplo de Entrada:

AABCCCCBAA
Exemplo de Saída:

sim 0 0
Exemplo de Entrada:

AABCCCCAA
Exemplo de Saída:

nao 2 0
Exemplo de Entrada:

AABCCCBAA
Exemplo de Saída:

nao 2 1*/
#include <iostream>
using namespace std;
typedef char Letra;

class Noh
{
    friend class Pilha;

private:
    Noh *nohProximo;
    Letra w;
};

class Pilha
{
public:
    Pilha();
    void Empilhar(Letra w);
    Letra Desempilhar();
    int Tamanho() { return tamanho; };
    bool Vazio() { return tamanho == 0; };

private:
    Noh *nohTopo;
    unsigned tamanho;
};

Pilha::Pilha()
{
    nohTopo = NULL;
    tamanho = 0;
}

void Pilha::Empilhar(Letra l)
{
    Noh *novo = new Noh();
    novo->nohProximo = nohTopo;
    novo->w = l;
    nohTopo = novo;
    tamanho++;
}

Letra Pilha::Desempilhar()
{
    Noh *deletarNoh = nohTopo;
    Letra removido = deletarNoh->w;
    nohTopo = nohTopo->nohProximo;

    delete deletarNoh;
    tamanho--;

    return removido;
}

void PilhasVazias(Pilha pil1, Pilha pil2)
{
    //cout << pil1.Vazio()<< endl;
    //cout << pil2.Vazio()<< endl;
    if (pil1.Vazio() && pil2.Vazio())
        cout << "sim" << " ";
    else
        cout << "nao";
}

bool CompararMetades(int A1,int B1, int C1,int A2, int B2, int C2)
{
    return (A1 == A2 && B1 == B2 && C1 == C2);
}

int main()
{
    Pilha PilhaAs;
    Pilha PilhaCs;
    bool primeiroB = false;
    bool segundoB = false;
    int contadorDeAsAntes = 0;
    int contadorDeBsAntes = 0;
    int contadorDeCsAntes = 0;

    int contadorDeAsDps = 0;
    int contadorDeBsDps = 0;
    int contadorDeCsDps = 0;

    string N;
    cin >> N;
    int i = 0;
    for (int i = 0;i<N.size()/2;i++)
    {
        if (N[i] == 'A')
            contadorDeAsAntes++;
        if (N[i] == 'B')
            contadorDeBsAntes++;
        else if (N[i] == 'C')
            contadorDeCsAntes++;
    }
    for (int i = N.size()/2;i<N.size();i++)
    {
        if (N[i] == 'A')
            contadorDeAsDps++;
        if (N[i] == 'B')
            contadorDeBsDps++;
        else if (N[i] == 'C')
            contadorDeCsDps++;
    }
    for (int i = 0;i<contadorDeAsAntes;i++)
    {
        PilhaAs.Empilhar('A');
        PilhaAs.Empilhar('C');
        PilhaAs.Empilhar('C');
    }

    cout << contadorDeAsAntes << " " << contadorDeBsAntes << " " << contadorDeCsAntes << endl;
    cout << contadorDeAsDps << " " << contadorDeBsDps << " " << contadorDeCsDps << endl;
    
    cout << CompararMetades(contadorDeAsAntes,contadorDeBsAntes,contadorDeCsAntes,contadorDeAsDps,contadorDeBsDps,contadorDeCsDps);

    //cout << PilhaAs.Tamanho() << " " << PilhaCs.Tamanho();
    //PilhasVazias(PilhaAs, PilhaCs);
}