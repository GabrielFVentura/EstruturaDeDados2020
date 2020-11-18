/* 
Um sistema em desenvolvimento permite controlar o portfólio de um escritório de publicidade. 
No momento, ele só permite a inserção e busca de produtos. Falta implementar, inclusive,
 o redimensionamento do vetor de produtos. O redimensionamento ocorrerá de acordo com a 
 estratégia que foi sorteada para você. Além disso, foi desenvolvida uma função externa 
 à classe para simular a mudança de marca de alguns produtos. A função já está testada 
 e não pode ser alterada. Entretanto, o uso dessa função gera falha de segmentação. 
 A interface do programa (a função main()) também não pode ser alterada, bem como 
 os atributos privados da classe. Sua tarefa é corrigir o problema com essa função 
 externa, bem como implementar o redimensionamento do vetor de produtos. 

/---------------------------------------------------------------------------------/

            portfolio.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/

#include <iostream>
#include <algorithm>

using namespace std;

struct produto {
    string nome;
    string marca;
    string descricao;
    produto();
};

produto::produto() {
    nome.clear();
    marca.clear();
    descricao.clear();
}

class portfolio {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        produto* listaDeProdutos;
        int quantidadeDeProdutos;
        int capacidadeMaxima;
    public:
        portfolio(int capacidade);
        portfolio(portfolio &port);
        ~portfolio();
        void inserirNovoProduto(const produto& umProduto);
        bool buscarProduto(const string& nome, produto& umProduto);
        void redimensionarCapacidade();
        friend void simularMudancaDeMarca(portfolio umPortfolio, string marcaAntiga, string novaMarca);
};

portfolio::portfolio(int capacidade) {
    quantidadeDeProdutos = 0;
    capacidadeMaxima = capacidade;
    listaDeProdutos = new produto[capacidadeMaxima];
}

portfolio::portfolio(portfolio &port){
    quantidadeDeProdutos = port.quantidadeDeProdutos;
    capacidadeMaxima = port.capacidadeMaxima;
    listaDeProdutos = new produto[capacidadeMaxima];

    for (int i = 0;i < quantidadeDeProdutos; i++){
        listaDeProdutos[i] = port.listaDeProdutos[i];
    }
}

portfolio::~portfolio() {
    delete [] listaDeProdutos;
}

void portfolio::inserirNovoProduto(const produto& umProduto) {
    if (quantidadeDeProdutos == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeProdutos[quantidadeDeProdutos] = umProduto;
    quantidadeDeProdutos++;
}

bool portfolio::buscarProduto(const string& nomeParaBusca, produto& umProduto) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeProdutos and 
           listaDeProdutos[posicaoAtual].nome != nomeParaBusca) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeProdutos) {
        umProduto = listaDeProdutos[posicaoAtual];
        return true;
    }

    return false;
}

void portfolio::redimensionarCapacidade() {
    int novaCapacidade = capacidadeMaxima + 4;    
    produto* listaTemp = new produto[novaCapacidade];
    copy(&listaDeProdutos[0], &listaDeProdutos[capacidadeMaxima], &listaTemp[0]);

    capacidadeMaxima = novaCapacidade;
    delete [] listaDeProdutos;
    listaDeProdutos = listaTemp;

#warning implemente este metodo!
}

void simularMudancaDeMarca(portfolio umPortfolio, string marcaAntiga, string novaMarca) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umPortfolio.quantidadeDeProdutos; i++) {
        if (umPortfolio.listaDeProdutos[i].marca == marcaAntiga) 
            cout << umPortfolio.listaDeProdutos[i].nome << " " << novaMarca << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Produtos - Aplicativo para Controlar Portfolio\n" 
         << "Entre com capacidade máxima inicial: ";
    cin >> capacidadeInicial;

    portfolio meuPortfolio(capacidadeInicial);

    cout << "Portfolio - Escolha a Opção:\n"
         << "i - inserir novo produto\n"
         << "b - buscar por um dado produto a partir do nome\n"
         << "m - simular mudança de marca\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    produto umProduto;
    string nome;
    string marcaAntiga, marcaNova;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do produto (nome, marca, descrição):" << endl;
                cin >> umProduto.nome 
                    >> umProduto.marca
                    >> umProduto.descricao;
                meuPortfolio.inserirNovoProduto(umProduto);
                break;

            case 'b' :
                cout << "Entre com nome do produto para busca: ";
                cin >> nome;
                
                if (meuPortfolio.buscarProduto(nome, umProduto)) 
                    cout << umProduto.nome << " "
                         << umProduto.marca << " "
                         << umProduto.descricao << endl << endl;
                else 
                    cout << "Produto não encontrado!" << endl << endl;
                break;

            case 'm' : 
                cout << "Entre com marca antiga e atual: ";
                cin >> marcaAntiga >> marcaNova;
                simularMudancaDeMarca(meuPortfolio,marcaAntiga,marcaNova);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Portfolio - Escolha a Opção:\n"
             << "i - inserir novo produto\n"
             << "b - buscar por um dado produto a partir do nome\n"
             << "m - simular mudança de marca\n"
             << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
