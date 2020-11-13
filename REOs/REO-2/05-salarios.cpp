/*
Um sistema em desenvolvimento permite controlar os salários de uma empresa.
 No momento, ele só permite a inserção e busca de funcionários. 
 Falta implementar, inclusive, o redimensionamento do vetor de funcionários. 
O redimensionamento ocorrerá de acordo com a estratégia que foi sorteada para você.
Além disso, foi desenvolvida uma função externa à classe para simular o 
reajuste salarial. A função já está testada e não pode ser alterada. 
Entretanto, o uso dessa função gera falha de segmentação. A interface do
programa (a função main()) também não pode ser alterada, bem como os 
atributos privados da classe. Sua tarefa é corrigir o problema com essa 
função externa, bem como implementar o redimensionamento do vetor de funcionários.

/---------------------------------------------------------------------------------/

            salarios.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

*/

#include <iostream>

using namespace std;

struct funcionario {
    string nome;
    string cargo;
    float salario;
    funcionario();       
};

funcionario::funcionario() {
    nome.clear();
    cargo.clear();
    salario = 0;
}


class equipe {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        funcionario* listaDeFuncionarios;
        int quantidadeDeFuncionarios;
        int capacidadeMaxima;
    public:
        equipe(int capacidade);
        ~equipe();
        void inserirNovoFuncionario(const funcionario& umFuncionario);
        bool buscarFuncionario(const string& umNome, funcionario& umFuncionario);
        void redimensionarCapacidade();
        friend void simularReajusteSalarial(equipe umaEquipe, float reajuste);
};

equipe::equipe(int capacidade) {
    quantidadeDeFuncionarios = 0;
    capacidadeMaxima = capacidade;
    listaDeFuncionarios = new funcionario[capacidadeMaxima];
}

equipe::~equipe() {
    delete [] listaDeFuncionarios;
}

void equipe::inserirNovoFuncionario(const funcionario& umFuncionario) {
    if (quantidadeDeFuncionarios == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeFuncionarios[quantidadeDeFuncionarios] = umFuncionario;
    quantidadeDeFuncionarios++;
}

bool equipe::buscarFuncionario(const string& nome, funcionario& umFuncionario) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeFuncionarios and 
           listaDeFuncionarios[posicaoAtual].nome != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDeFuncionarios) {
        umFuncionario = listaDeFuncionarios[posicaoAtual];
        return true;
    }

    return false;
}

void equipe::redimensionarCapacidade() {
#warning implemente este metodo!
}

void simularReajusteSalarial(equipe umaEquipe, float reajuste) {
    // *** AVISO: Não altere esta função *** 
    float valorTotalSemReajuste = 0;
    float valorTotalComReajuste = 0;
    float novoSalario;
    for (int i = 0; i < umaEquipe.quantidadeDeFuncionarios; i++) {
        valorTotalSemReajuste += umaEquipe.listaDeFuncionarios[i].salario;
        novoSalario = umaEquipe.listaDeFuncionarios[i].salario * (1 + reajuste/100);
        valorTotalComReajuste += novoSalario;
        cout << umaEquipe.listaDeFuncionarios[i].nome << " " 
             << umaEquipe.listaDeFuncionarios[i].salario << " " 
             << novoSalario << endl;
    }
    cout << valorTotalSemReajuste << " " << valorTotalComReajuste << endl;
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Salarios - Aplicativo para Calcular Reajustes\n" 
         << "Entre com capacidade máxima inicial da equipe: ";
    cin >> capacidadeInicial;

    equipe minhaEquipe(capacidadeInicial);

    cout << "Salários - Escolha a Opção:\n"
         << "i - inserir novo funcionário\n"
         << "b - buscar por dados de um funcionário a partir do nome\n"
         << "r - simular reajuste salarial de todos os funcionários\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    funcionario umFuncionario;
    string nome;
    float reajuste;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do funcionário (nome, cargo e salário):" << endl;
                cin >> umFuncionario.nome 
                    >> umFuncionario.cargo >> umFuncionario.salario;
                minhaEquipe.inserirNovoFuncionario(umFuncionario);
                break;

            case 'b' :
                cout << "Entre com nome do funcionário para busca: ";
                cin >> nome;
                
                if (minhaEquipe.buscarFuncionario(nome, umFuncionario)) 
                    cout << umFuncionario.nome << " "
                         << umFuncionario.cargo << " " <<  umFuncionario.salario << endl << endl;
                else 
                    cout << "Funcionário não encontrado!" << endl << endl;
                break;

            case 'r' : 
                cout << "Entre com valor do reajuste (em porcentagem): ";
                cin >> reajuste;
                simularReajusteSalarial(minhaEquipe,reajuste);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Salários - Escolha a Opção:\n"
            << "i - inserir novo funcionário\n"
            << "b - buscar por dados de um funcionário a partir do nome\n"
            << "r - simular reajuste salarial de todos os funcionários\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
