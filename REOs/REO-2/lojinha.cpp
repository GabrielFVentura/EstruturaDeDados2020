/*
Um sistema em desenvolvimento permite controlar o estoque de uma dada lojinha. No momento, 
ele só permite a inserção e busca de produtos. Falta implementar, inclusive, o 
redimensionamento do vetor de produtos. O redimensionamento ocorrerá de acordo com a 
estratégia que foi sorteada para você. Além disso, foi desenvolvida uma função externa à classe 
para simular a aplicação de um desconto a todos os produtos. A função já está testada e não pode 
ser alterada. Entretanto, o uso dessa função gera falha de segmentação. A interface do programa 
(a função main()) também não pode ser alterada, bem como os atributos privados da classe. 
Sua tarefa é corrigir o problema com essa função externa, bem como implementar o 
redimensionamento do vetor de produtos. 

/---------------------------------------------------------------------------------/

            lojinha.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/

#include <iostream>

using namespace std;

struct produto {
    string nomeDoProduto;
    float valorParaVenda;
    int quantidadeEmEstoque;
    produto();
};

produto::produto() {
    nomeDoProduto.clear();
    valorParaVenda = 0;
    quantidadeEmEstoque = 0;
}

class estoque {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        produto* listaDeProdutos;
        int quantidadeDeProdutos;
        int capacidadeMaxima;
    public:
        estoque(int capacidade);
        ~estoque();
        void inserirNovoProduto(const produto& umProduto);
        bool buscarProduto(const string& nome, produto& umProduto);
        void redimensionarCapacidade();
        friend void simularDescontoEmTodosOsProdutos(estoque umEstoque, float desconto);
};

estoque::estoque(int capacidade) {
    quantidadeDeProdutos = 0;
    capacidadeMaxima = capacidade;
    listaDeProdutos = new produto[capacidadeMaxima];
}

estoque::~estoque() {
    delete [] listaDeProdutos;
}

void estoque::inserirNovoProduto(const produto& umProduto) {
    if (quantidadeDeProdutos == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeProdutos[quantidadeDeProdutos] = umProduto;
    quantidadeDeProdutos++;
}

bool estoque::buscarProduto(const string& nome, produto& umProduto) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeProdutos and 
           listaDeProdutos[posicaoAtual].nomeDoProduto != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeProdutos) {
        umProduto = listaDeProdutos[posicaoAtual];
        return true;
    }

    return false;
}

void estoque::redimensionarCapacidade() {
    cout << "expandi array" << endl;
    produto* listaTemp = new produto[1+capacidadeMaxima*2];
    cout << "cap max antes:" << capacidadeMaxima << endl;
    for (int i = 0; i < capacidadeMaxima; i++){
    listaTemp[i] = listaDeProdutos[i];
    }
    capacidadeMaxima = capacidadeMaxima*2 + 1;
    delete [] listaDeProdutos;
    listaDeProdutos = listaTemp;
    cout << "cap max: dps" << capacidadeMaxima << endl;
#warning implemente este metodo!
}

void simularDescontoEmTodosOsProdutos(estoque umEstoque, float desconto) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umEstoque.quantidadeDeProdutos; i++) {
        umEstoque.listaDeProdutos[i].valorParaVenda = 
            (1 - (desconto/100)) * umEstoque.listaDeProdutos[i].valorParaVenda;
        cout << umEstoque.listaDeProdutos[i].nomeDoProduto << " "
             << umEstoque.listaDeProdutos[i].valorParaVenda << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Lojinha - Aplicativo para Controlar Estoque\n" 
         << "Entre com capacidade máxima inicial: ";
    cin >> capacidadeInicial;

    estoque estoqueDaLojinha(capacidadeInicial);

    cout << "Lojinha - Escolha a Opção:\n"
         << "i - inserir novo produto\n"
         << "b - buscar por um dado produto a partir do nome\n"
         << "d - simular desconto em todos os produtos\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    produto umProduto;
    string nome;
    float desconto;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do produto (nome, preço, quantidade em estoque):" << endl;
                cin >> umProduto.nomeDoProduto 
                    >> umProduto.valorParaVenda
                    >> umProduto.quantidadeEmEstoque;
                estoqueDaLojinha.inserirNovoProduto(umProduto);
                break;

            case 'b' :
                cout << "Entre com nome do produto para busca: ";
                cin >> nome;
                
                if (estoqueDaLojinha.buscarProduto(nome, umProduto)) 
                    cout << umProduto.nomeDoProduto << " "
                         << umProduto.valorParaVenda << " "
                         << umProduto.quantidadeEmEstoque << endl << endl;
                else 
                    cout << "Produto não encontrado!" << endl << endl;
                break;

            case 'd' : 
                cout << "Entre com valor do desconto (em porcentagem): ";
                cin >> desconto;
                simularDescontoEmTodosOsProdutos(estoqueDaLojinha,desconto);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Lojinha - Escolha a Opção:\n"
             << "i - inserir novo produto\n"
             << "b - buscar por um dado produto a partir do nome\n"
             << "d - simular desconto em todos os produtos\n"
             << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
