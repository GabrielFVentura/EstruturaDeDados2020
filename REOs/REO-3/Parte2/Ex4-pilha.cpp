/*Em Linguagens Formais e Autômatos um reconhecedor é um meio formal de verificar se uma dada sentença pertence ou não a uma determinada linguagem. Pilhas são estruturas usadas com frequência em reconhecedores.

Uma linguagem pode ser definida com um subconjunto de S*, a partir de um alfabeto S, onde S é um conjunto finito, não vazio, de símbolos. Considere o alfabeto S = {A,B,C} e a linguagem L = {A*i B C*2i | i > 0}, ou seja, as sequências ABCC, AABCCCC, AAABCCCCCC são todas pertencentes ao conjunto de sentenças válidas de L. Faça um programa utilizando somente a estrutura de dado pilha, respeitando todas as suas propriedades e não utilizando a STL, que, dada uma sequência w de caracteres A, B e C, verifique se w faz parte ou não do conjunto de sentenças de L. O valor X indica fim da leitura.

O processamento deve ser interrompido assim que for possível dizer se w faz parte ou não do conjunto.

Ao final, o programa deve escrever se o padrão da linguagem foi reconhecido e os tamanhos das pilhas.

Sugestão: Usando duas pilhas, seu programa deve ler As e a cada A lido, empilhar um A numa e dois Cs na outra. Após ler um B, cada A desempilhado faz com que dois C sejam desempilhados. Ao final da iteração, a sentença foi reconhecida se todas as letras foram processadas e todos os desempilhamentos foram bem sucedidos e se as duas pilhas estão vazias.

Entradas:

Palavra a ser verificada.
Saídas:

A palavra sim ou nao (sem acento), indicando se a sentença foi reconhecida.
O tamanho da pilha de As.
O tamanho da pilha de Cs.
Exemplo de Entrada:

A A B C C C C X
Exemplo de Saída:

sim 0 0
Exemplo de Entrada:

A A B C C X
Exemplo de Saída:

nao 1 0

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/
#include <iostream>
using namespace std;
    

struct Noh{
    char letra;
    Noh* nohProximo;
    Noh(char l){
        letra = l;
    }
};

class Pilha{
    private:
        int tamanho;
        Noh* nohTopo;
    public:
        Pilha(){
            tamanho = 0;
            nohTopo = NULL;
        }
        ~Pilha(){
            delete nohTopo;
        }
        void empilharNoh(char c){
            Noh* novoNoh = new Noh(c);
            
            novoNoh->nohProximo = nohTopo;
            nohTopo = novoNoh;
            tamanho++;
        }
        char desempilharNoh(){
            if (tamanho == 0){
                nohTopo = NULL;
                return '\0';
            }
            Noh* nohTemp = nohTopo;
            nohTopo = nohTopo->nohProximo;
            char letraDesempilhada = nohTemp->letra;
            tamanho--;
            delete nohTemp;
            return letraDesempilhada;
        }
        char espiaTopo(){
            return nohTopo->letra;
        }
        bool pilhaVazia(){
            return tamanho == 0;
        }
};

string comparaPilhas(Pilha p1, int& numeroP1, Pilha p2, int& numeroP2){
    for (int i = 0; i <= numeroP1;i++){
        p1.desempilharNoh();
        
        for (int i = 0; i < 2; i++){
            if (numeroP2 == 0)
                return "nao ";
            p2.desempilharNoh();
            numeroP2--;
        }
        numeroP1--;
    }
    return (p1.pilhaVazia() && p2.pilhaVazia() ? "sim " : "nao ");
}

int main(){
    Pilha PilhaAs;
    Pilha PilhaCs;
    int numeroCs = 0;
    int numeroAs = 0;
    char i;
    do
    {
        cin >> i;
        switch (i){
        case 'A':{
            PilhaAs.empilharNoh('A');
            numeroAs++;
            break;
        }
        case 'B':{
            break;
        }
        case 'C':{
            PilhaCs.empilharNoh('C');
            numeroCs++;
            break;
        }

        default:
            break;
        }
    } while (i != 'X');
    

    cout << comparaPilhas(PilhaAs,numeroAs,PilhaCs,numeroCs);
    cout << numeroAs << " " << numeroCs;

    return 0;
}


