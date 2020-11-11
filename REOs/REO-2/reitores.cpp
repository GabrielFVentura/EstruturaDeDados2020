/*
Um sistema em desenvolvimento permite controlar o processo eleitoral de uma
 Universidade para a escolha do seu reitor. No momento, ele só permite a 
 inserção e busca de candidatos. Falta implementar, inclusive, o redimensionamento
do vetor de candidatos. O redimensionamento ocorrerá de acordo com a estratégia
que foi sorteada para você. Além disso, foi desenvolvida uma função externa à
classe para verificar o candidato vencedor, de acordo com a proporcionalidade 
adotada: votos discentes valem 20%, votos docentes valem 70% e votos dos 
técnicos valem 10%. A função já está testada e não pode ser alterada. 
Entretanto, o uso dessa função gera falha de segmentação. A interface do programa
(a função main()) também não pode ser alterada, bem como os atributos privados da 
classe. Sua tarefa é corrigir o problema com essa função externa, bem como 
implementar o redimensionamento do vetor de candidatos. 

/---------------------------------------------------------------------------------/

            reitores.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/

#include <iostream>

using namespace std;

struct candidato {
    string nomeDoCandidato;
    int votosDiscentes;
    int votosDocentes;
    int votosTecnicos;
    candidato();       
};

candidato::candidato() {
    nomeDoCandidato.clear();
    votosDiscentes = 0;
    votosDocentes = 0;
    votosTecnicos = 0;
}


class eleicao {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        candidato* listaDeCandidatos;
        int quantidadeDeCandidatos;
        int capacidadeMaxima;
    public:
        eleicao(int capacidade);
        ~eleicao();
        void inserirNovoCandidato(const candidato& umCandidato);
        bool buscarCandidato(const string& nome, candidato& umCandidato);
        void redimensionarCapacidade();
        friend void verificarResultado(eleicao umaEleicao);
};

eleicao::eleicao(int capacidade) {
    quantidadeDeCandidatos = 0;
    capacidadeMaxima = capacidade;
    listaDeCandidatos = new candidato[capacidadeMaxima];
}

eleicao::~eleicao() {
    delete [] listaDeCandidatos;
}

void eleicao::inserirNovoCandidato(const candidato& umCandidato) {
    if (quantidadeDeCandidatos == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeCandidatos[quantidadeDeCandidatos] = umCandidato;
    quantidadeDeCandidatos++;
}

bool eleicao::buscarCandidato(const string& nome, candidato& umCandidato) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeCandidatos and 
           listaDeCandidatos[posicaoAtual].nomeDoCandidato != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeCandidatos) {
        umCandidato = listaDeCandidatos[posicaoAtual];
        return true;
    }

    return false;
}

void eleicao::redimensionarCapacidade() {
#warning implemente este metodo!
}

void verificarResultado(eleicao umaEleicao) {
    // *** AVISO: Não altere esta função *** 
    int totalDiscentes = 0;
    int totalDocentes = 0;
    int totalTecnicos = 0;

    for (int i = 0; i < umaEleicao.quantidadeDeCandidatos; i++) {
        totalDiscentes += umaEleicao.listaDeCandidatos[i].votosDiscentes;
        totalDocentes += umaEleicao.listaDeCandidatos[i].votosDocentes;
        totalTecnicos += umaEleicao.listaDeCandidatos[i].votosTecnicos;        
    }

    string nomeVencedor; 
    float votosVencedor = 0;

    for (int i = 0; i < umaEleicao.quantidadeDeCandidatos; i++) {
        float votosProporcionais  = 
              (umaEleicao.listaDeCandidatos[i].votosDiscentes / (float) totalDiscentes) * 0.2 
            + (umaEleicao.listaDeCandidatos[i].votosDocentes / (float) totalDocentes) * 0.7
            + (umaEleicao.listaDeCandidatos[i].votosTecnicos / (float) totalTecnicos) * 0.1;
        
        votosProporcionais *= 100; // para representar em termos percentuais

        cout << umaEleicao.listaDeCandidatos[i].nomeDoCandidato 
             << " " << votosProporcionais << endl;

        if (votosProporcionais > votosVencedor) 
            nomeVencedor =  umaEleicao.listaDeCandidatos[i].nomeDoCandidato;      
    }

    cout << "Vencedor: " << nomeVencedor << endl;
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Reitores - Aplicativo para Apurar Resultado da Eleição\n" 
         << "Entre com capacidade máxima inicial de candidatos: ";
    cin >> capacidadeInicial;

    eleicao umaEleicao(capacidadeInicial);

    cout << "Reitores - Escolha a Opção:\n"
         << "i - inserir novo candidato\n"
         << "b - buscar por dados de um candidato a partir do nome\n"
         << "a - apurar o resultado da eleição\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    candidato umCandidato;
    string nome;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do candidato (nome, voto discente, voto docente e voto dos técnicos):" << endl;
                cin >> umCandidato.nomeDoCandidato 
                    >> umCandidato.votosDiscentes >> umCandidato.votosDocentes >> umCandidato.votosTecnicos;
                umaEleicao.inserirNovoCandidato(umCandidato);
                break;

            case 'b' :
                cout << "Entre com nome do candidato para busca: ";
                cin >> nome;
                
                if (umaEleicao.buscarCandidato(nome, umCandidato)) 
                    cout << umCandidato.nomeDoCandidato << " "
                         << umCandidato.votosDiscentes << " " <<  umCandidato.votosDocentes << " "
                         << umCandidato.votosTecnicos << endl << endl;
                else 
                    cout << "Candidato não encontrado!" << endl << endl;
                break;

            case 'a' : 
                verificarResultado(umaEleicao);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Reitores - Escolha a Opção:\n"
            << "i - inserir novo candidato\n"
            << "b - buscar por dados de um candidato a partir do nome\n"
            << "a - apurar o resultado da eleição\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
