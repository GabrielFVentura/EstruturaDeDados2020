/*Um sistema em desenvolvimento permite controlar os livros em uma biblioteca. 
No momento, ele só permite a inserção e busca de livros. Falta implementar, 
inclusive, o redimensionamento do vetor de livros. O redimensionamento 
ocorrerá de acordo com a estratégia que foi sorteada para você. Além disso,
foi desenvolvida uma função externa à classe para verificar se existe 
disponibilidade de um determinado livros. A função já está testada e não 
pode ser alterada. Entretanto, o uso dessa função gera falha de segmentação.
A interface do programa (a função main()) também não pode ser alterada, 
bem como os atributos privados da classe. Sua tarefa é corrigir o problema 
com essa função externa, bem como implementar o redimensionamento do vetor 
de bilhetes.

/---------------------------------------------------------------------------------/

            biblioteca.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct livro {
    string nomeDoProduto;
    int quantidadeEmEmprestimo;
    int quantidadeDeExemplares;
    livro();
};

livro::livro() {
    nomeDoProduto.clear();
    quantidadeEmEmprestimo = 0;
    quantidadeDeExemplares = 0;
}

class biblioteca {
    private:
        // *** AVISO: Não altere os atributos privados da classe ***
        livro* listaDeLivros;
        int quantidadeDeItens;
        int capacidadeMaxima;
    public:
        biblioteca(int capacidade);
        biblioteca(const biblioteca&);
        ~biblioteca();
        void inserirNovolivro(const livro& umlivro);
        bool buscarlivro(const string& nome, livro& umlivro);
        void redimensionarCapacidade();
        friend void verificarDisponibilidadeLivros(biblioteca umbiblioteca, int quantidade);
};

biblioteca::biblioteca(int capacidade) {
    quantidadeDeItens = 0;
    capacidadeMaxima = capacidade;
    listaDeLivros = new livro[capacidadeMaxima];
}

biblioteca::biblioteca(const biblioteca& biblioteca) {
    cout << "CONSTRUTOR DE COPIA CHAMADO" << endl;
    quantidadeDeItens = biblioteca.quantidadeDeItens;
    capacidadeMaxima = biblioteca.capacidadeMaxima;
    listaDeLivros = new livro[capacidadeMaxima];
    
    for (int i = 0; i < quantidadeDeItens;i ++){
        listaDeLivros[i] = biblioteca.listaDeLivros[i];
    }
}

biblioteca::~biblioteca() {
    delete [] listaDeLivros;
}

void biblioteca::inserirNovolivro(const livro& umlivro) {
    if (quantidadeDeItens == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeLivros[quantidadeDeItens] = umlivro;
    quantidadeDeItens++;
}

bool biblioteca::buscarlivro(const string& nome, livro& umlivro) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeItens and
           listaDeLivros[posicaoAtual].nomeDoProduto != nome)
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeItens) {
        umlivro = listaDeLivros[posicaoAtual];
        return true;
    }

    return false;
}

void biblioteca::redimensionarCapacidade() {
    cout << "EXPANDI ARRAY" << endl;
    int novaCapacidade = ceil(capacidadeMaxima*1.2);
    livro* listaTemp = new livro[novaCapacidade];
    cout << "CAP MAX ANTES: " << capacidadeMaxima << endl;
    copy(&listaDeLivros[0],&listaDeLivros[capacidadeMaxima],&listaTemp[0]);
    capacidadeMaxima = novaCapacidade;
    delete [] listaDeLivros;
    listaDeLivros = listaTemp;
    cout << "CAP MAX DEPOIS: " << capacidadeMaxima << endl;
#warning implemente este metodo!
}

void verificarDisponibilidadeLivros(biblioteca umbiblioteca, int quantidade) {
    // *** AVISO: Não altere esta função ***
    for (int i = 0; i < umbiblioteca.quantidadeDeItens; i++) {
        if ((umbiblioteca.listaDeLivros[i].quantidadeDeExemplares - umbiblioteca.listaDeLivros[i].quantidadeEmEmprestimo) > quantidade)
            cout << umbiblioteca.listaDeLivros[i].nomeDoProduto << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() ***
    int capacidadeInicial;

    cout << "biblioteca - Aplicativo para Empréstimos de Livros\n"
         << "Entre com capacidade máxima inicial: ";
    cin >> capacidadeInicial;

    biblioteca meubiblioteca(capacidadeInicial);

    cout << "biblioteca - Escolha a Opção:\n"
         << "i - inserir novo livro\n"
         << "b - buscar por um dado livro a partir do nome\n"
         << "v - verificar livros com disponibilidade de empréstimo\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    livro umlivro;
    string nome;
    int quantidade;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' :
                cout << "Entre com dados do livro (nome, quantidade em empréstimos, quantidade de exemplares):" << endl;
                cin >> umlivro.nomeDoProduto
                    >> umlivro.quantidadeEmEmprestimo
                    >> umlivro.quantidadeDeExemplares;
                meubiblioteca.inserirNovolivro(umlivro);
                break;

            case 'b' :
                cout << "Entre com nome do livro para busca: ";
                cin >> nome;

                if (meubiblioteca.buscarlivro(nome, umlivro))
                    cout << umlivro.nomeDoProduto << " "
                         << umlivro.quantidadeEmEmprestimo << " "
                         << umlivro.quantidadeDeExemplares << endl << endl;
                else
                    cout << "livro não encontrado!" << endl << endl;
                break;

            case 'v' :
                cout<< "informe a quantidade de exemplares desejadas:";
                cin>>quantidade;
                verificarDisponibilidadeLivros(meubiblioteca,quantidade);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "biblioteca - Escolha a Opção:\n"
            << "i - inserir novo livro\n"
            << "b - buscar por um dado livro a partir do nome\n"
            << "v - verificar livros com disponibilidade de empréstimo\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
