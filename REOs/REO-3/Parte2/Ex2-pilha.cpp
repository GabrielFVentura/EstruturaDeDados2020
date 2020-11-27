/*Suponha que um dado problema requer o uso de duas pilhas (identificadas pelo números 1 e 2), onde cada pilha suporta no máximo 50 elementos e em nenhum momento as duas pilhas terão juntas mais do que os mesmos 50 elementos. Sendo assim, é possível implementar as duas pilhas em um único vetor usando apenas 50 posições ao invés de 100. Utilizando a estrutura sugerida no código fornecido, implemente as operações de empilhar() e desempilhar(). As operações de empilhar (identificada pela letra E) e desempilhar (identificada pela letra D) devem ser descritas da seguinte forma:

Operação a ser realizada, seguida da identificação da pilha. No caso da operação empilhar, deve ser informado, ainda, o dado a ser armazenado. T é usado para terminar o programa.
Utilize um arranjo de 50 posições para armazenar estas duas pilhas.
Caso seja solicitada uma operação de desempilhar e a respectiva pilha esteja vazia, deve ser impressa a palavra "VAZIA".
Caso seja solicitada a inserção de mais de 50 elementos em uma das pilha, deve ser impressa a palavra "INVALIDO" (sem acentos).
Obs: sinta-se a vontade para modificar o código caso prefira utilizar outra estrutura. A única restrição é que as duas pilhas devem ser armazenadas em um mesmo ARRANJO de 50 posições.

Dica: utilize o início do arranjo para armazenar uma das pilhas e final do arranjo para armazenar a outra pilha.

Entradas:

Conjunto de operações de inserção e remoção de dados em cada uma das pilhas
Saídas:

Resultado das remoções em cada uma das pilhas.
Exemplos de Entrada e Saída:
Entrada

E 1 7
E 2 4
E 1 2
E 1 15
E 2 21
D 1
D 2
E 2 5
E 2 7
D 2
D 1
D 1
T
Exemplo de Saída:

15 21 7 2 7
Entrada

E 1 71
E 2 45
E 1 20
E 2 21
D 1
D 1
E 2 5
E 2 7
D 2
D 1
D 2
T
Exemplo de Saída:

20 71 7 VAZIA 5
/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/

/* Classe pilha dupla, duas pilhas usando um armazenamento 
 * compartilhado em um vetor com 50 posições
 *
 * by Joukim, 2019, Estruturas de Dados
 *
 */

#include <iostream>

using namespace std;

// pilha dupla em vetor de 50 elementos
// não é permitido alterar a estrutura da classe
// inserindo ou retirando métodos
// classe não precisa de destrutor, já que não 
// aloca dados dinamicamente
class pilhaDupla {
private:
    int topo1;
    int topo2;
    int tamanho1;
    int tamanho2;
    int dados[50];
public:
    pilhaDupla();
    // escolha é um inteiro para indicar qual pilha sendo usada:
    // 1 -> pilha 1 (início do arranjo)
    // 2 -> pilha 2 (final do arranjo)
    void empilha(int escolha, int valor); // empilha valor na pilha escolhida
    int desempilha(int escolha); // retorna o topo da pilha escolhida
    bool vazia(int escolha); // verifica se pilha escolhida é vazia
};


pilhaDupla::pilhaDupla() {
    tamanho1 = 0;
    topo1 = -1;
    tamanho2 = 0;
    topo2 = 50; 
}

void pilhaDupla::empilha(int escolha, int valor) {
    if (tamanho1 >= 50 || tamanho2 >= 50){
        cout << "INVALIDO" << endl;
    }
    if (escolha == 1){
        dados[tamanho1] = valor;
        tamanho1++;
    }
    else if (escolha == 2){
        dados[topo2 - tamanho2] = valor;
        tamanho2++;
    }
}

int pilhaDupla::desempilha(int escolha) {
    if (escolha == 1){
        tamanho1--;
        int aux1 = dados[tamanho1];
        return aux1;
    }
    else if (escolha == 2){
        tamanho2--;
        int aux2 = dados[topo2 - tamanho2];
        return aux2;
    }
}


bool pilhaDupla::vazia(int escolha) {
    if (escolha == 1) 
        return (tamanho1 == 0);
    else if (escolha == 2)
        return (tamanho2 == 0);
    return true;
}


int main() {
    pilhaDupla PP;
    char opcao;
    int escolha;
    int valor;
    
    do {
        cin >> opcao;
        switch (opcao) {
        case 'E': 
            cin >> escolha >> valor;
            PP.empilha(escolha,valor);  
            break;      
        case 'D':
            cin >> escolha;
            if ( PP.vazia(escolha) ) cout << "VAZIA" << endl;
            else cout << PP.desempilha(escolha) << " ";  
            break;      
        }
    } while (opcao != 'T');

    return 0;
}