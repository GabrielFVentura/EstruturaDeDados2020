/* 

Um sistema em desenvolvimento permite controlar os competidores inscritos em uma 
competição de bolinhas de gude. No momento, ele só permite a inserção e busca de 
competidores. Falta implementar, inclusive, o redimensionamento do vetor de competidores. 
O redimensionamento ocorrerá de acordo com a estratégia que foi sorteada para você. 
Além disso, foi desenvolvida uma função externa à classe para simular a mudança de dia 
das partidas de um competidor para evitar a aglomeração dos competidores e da plateia. 
A função já está testada e não pode ser alterada. Entretanto, o uso dessa função gera 
falha de segmentação. A interface do programa (a função main()) também não pode ser 
alterada, bem como os atributos privados da classe. Sua tarefa é corrigir o problema
 com essa função externa, bem como implementar o redimensionamento do vetor de competidores.

/---------------------------------------------------------------------------------/

            berlinde.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/

#include <iostream>

using namespace std;

struct competidor {
    string nomeDoCompetidor;
    string categoriaDoCompetidor;  //iniciante, intermediário ou avançado
    int diaDasPartidas;
    competidor();       
};

competidor::competidor() {
    nomeDoCompetidor.clear();
    categoriaDoCompetidor.clear();
    diaDasPartidas = 0;
}


class campeonato {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        competidor* listaDeCompetidores;
        int quantidadeDeCompetidores;
        int capacidadeMaxima;
    public:
        campeonato(int capacidade);
        ~campeonato();
        void inserirNovoCompetidor(const competidor& umCompetidor);
        bool buscarCompetidor(const string& umNome, competidor& umCompetidor);
        void redimensionarCapacidade();
        friend void simularMudancaDeDia(campeonato umaEquipe, int novoDia);
};

campeonato::campeonato(int capacidade) {
    quantidadeDeCompetidores = 0;
    capacidadeMaxima = capacidade;
    listaDeCompetidores = new competidor[capacidadeMaxima];
}

campeonato::~campeonato() {
    delete [] listaDeCompetidores;
}

void campeonato::inserirNovoCompetidor(const competidor& umCompetidor) {
    if (quantidadeDeCompetidores == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeCompetidores[quantidadeDeCompetidores] = umCompetidor;
    quantidadeDeCompetidores++;
}

bool campeonato::buscarCompetidor(const string& nome, competidor& umCompetidor) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeCompetidores and 
           listaDeCompetidores[posicaoAtual].nomeDoCompetidor != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de competidores, é porque não encontrou
    if (posicaoAtual < quantidadeDeCompetidores) {
        umCompetidor = listaDeCompetidores[posicaoAtual];
        return true;
    }

    return false;
}

void campeonato::redimensionarCapacidade() {
#warning implemente este metodo!
}

void simularMudancaDeDia(campeonato umCampeonato, int novoDia) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umCampeonato.quantidadeDeCompetidores; i++) {
        if (umCampeonato.listaDeCompetidores[i].diaDasPartidas % 2 == 0)
        cout << umCampeonato.listaDeCompetidores[i].nomeDoCompetidor << " " 
             << umCampeonato.listaDeCompetidores[i].categoriaDoCompetidor << " " 
             << novoDia << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Competição de Bolinha de Gude\nAplicativo para simular alteração na data das partidas\n" 
         << "\nEntre com capacidade máxima inicial do campeonato: ";
    cin >> capacidadeInicial;

    campeonato meuCampeonato(capacidadeInicial);

    cout << "Competidores - Escolha a Opção:\n"
         << "i - inserir novo competidor\n"
         << "b - buscar por dados de um competidor a partir do nome\n"
         << "r - simular alteração de data das partidas\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    competidor umCompetidor;
    string nome;
    int novoDia;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do competidor (nome, categoria e dia das partidas):" << endl;
                cin >> umCompetidor.nomeDoCompetidor
                    >> umCompetidor.categoriaDoCompetidor >> umCompetidor.diaDasPartidas;
                meuCampeonato.inserirNovoCompetidor(umCompetidor);
                break;

            case 'b' :
                cout << "Entre com nome do Competidor para busca: ";
                cin >> nome;
                
                if (meuCampeonato.buscarCompetidor(nome, umCompetidor)) 
                    cout << umCompetidor.nomeDoCompetidor<< " "
                         << umCompetidor.categoriaDoCompetidor << " " <<  umCompetidor.diaDasPartidas << endl << endl;
                else 
                    cout << "Competidor não encontrado!" << endl << endl;
                break;

            case 'r' : 
                cout << "Entre com o novo dia das partidas: ";
                cin >> novoDia;
                simularMudancaDeDia (meuCampeonato,novoDia);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Competidores - Escolha a Opção:\n"
         << "i - inserir novo competidor\n"
         << "b - buscar por dados de um competidor a partir do nome\n"
         << "r - simular alteração de data das partidas\n"
         << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}

