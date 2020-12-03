/*Faça um programa que lê uma linha de texto e verifica se todo parênteses tem um correspondente. Assuma que cada sinal de "fecha parênteses" fecha o último "abre parênteses".

Caso não existam parênteses correspondentes em todos os casos, o programa deve escrever a posição do erro. A posição do primeiro caractere é zero. Se todos os parênteses têm correspondentes, o programa deverá escrever "correto" (letras minúsculas). A posição do erro no caso de um "fecha parênteses" sem correspondente é a dele mesmo, pois não é preciso olhar o resto do texto para saber que há erro. A posição do erro no caso de um "abre parênteses" sem correspondente é a do último "abre parênteses" visto, pois só é possível saber que ele não tem correspondente ao final do texto.

Este é um exercício de solução de problema usando pilha. A pilha deve ser parte importante da solução. Faça um programa utilizando somente a estrutura de dado pilha, respeitando todas as suas propriedades e não utilizando a STL.

Entradas:

Uma linha de texto (não mais do que 254 caracteres).
Saídas:

A palavra "correto" se todos tiverem correspondentes ou então a posição do erro.
Exemplo de Entrada 1:

func(x, (y+3)*4)
Exemplo de Saída 1:

correto
Exemplo de Entrada 2:

(idw ( dpq() sho
Exemplo de Saída 2:

5
Exemplo de Entrada 3:

(12 + 3) * 4 - 2)
Exemplo de Saída 3:

16

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/

#include <iostream>
#include <string>
using namespace std;

struct Noh{
    char character;
    Noh* nohProx;
    Noh(char c){
        character = c;
    }
};

class Pilha{
    private:
        int tamanho;
        Noh* nohTopo;
    public:
        Pilha(){
            nohTopo = NULL;
            tamanho = 0;
        }
        ~Pilha(){
            delete [] nohTopo;
        }
        void empilharNoh(char c){
            Noh* novoNoh = new Noh(c);
            novoNoh->nohProx = nohTopo;
            nohTopo = novoNoh;
            tamanho++;
        }
        char desempilhaNoh(){
            if (tamanho == 0){
                nohTopo = NULL;
                return '\0';
            }
            Noh* nohTemp = nohTopo;
            nohTopo = nohTopo->nohProx;
            char charDesempilhado = nohTemp->character;
            tamanho--;
            delete nohTemp;
            return charDesempilhado;
        }
        char espiaTopo(){
            return nohTopo->character;
        }
        bool pilhaVazia(){
            return tamanho == 0;
        }
};



int main(){
    string name;
    Pilha pilhaChar;
    getline(cin,name);
    int numeroAbreParenteses = 0;
    int numeroFechaParenteses = 0;
    int indiceErro;
    bool proxAbreParenteses = false;
    bool proxFechaParenteses = false;
    if (name.length() > 254){
        return 0;
    }
    cout << name.length() << endl;
    for (int i = 0; i < name.length();i++){
        if (name[i] == '('){
            numeroAbreParenteses++;
        } else if (name[i] == ')'){
            numeroFechaParenteses++;
        }
        pilhaChar.empilharNoh(name[i]);
    }
    for (int i = 0; i < name.length();i++){
        cout << pilhaChar.desempilhaNoh() << " ";
    }
    return 0;
}