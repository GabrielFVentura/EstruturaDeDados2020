/*
Um sistema em desenvolvimento permite controlar as músicas que são tocadas em uma
rádio. No momento, ele só permite a inserção e busca de músicas. 
Falta implementar, inclusive, o redimensionamento do vetor de músicas. 
O redimensionamento ocorrerá de acordo com a estratégia que foi sorteada 
para você. Além disso, foi desenvolvida uma função externa à classe para 
verificar as músicas mais pedidas. A função já está testada e não pode ser 
alterada. Entretanto, o uso dessa função gera falha de segmentação.
A interface do programa (a função main()) também não pode ser alterada,
bem como os atributos privados da classe. Sua tarefa é corrigir o problema
com essa função externa, bem como implementar o redimensionamento do vetor
de músicas.


/---------------------------------------------------------------------------------/

            biblioteca.cpp - aplicação para trabalho com marcas
                        de Tipo Abstrado de Dados

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/

#include <iostream>

using namespace std;

struct paciente {
    string nomeDoPaciente;
    float resultadosDosExames[4];
    paciente();       
};

paciente::paciente() {
    nomeDoPaciente.clear();
    // 0 é um resultado válido, então atribuimos valor negativo (inválido)
    resultadosDosExames[0] = -1;
    resultadosDosExames[1] = -1;
    resultadosDosExames[2] = -1;
    resultadosDosExames[3] = -1;
}


class clinica {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        paciente* listaDePacientes;
        int quantidadeDePacientes;
        int capacidadeMaxima;
    public:
        clinica(int capacidade);
        ~clinica();
        void inserirNovoPaciente(const paciente& umPaciente);
        bool buscarPaciente(const string& nome, paciente& umPaciente);
        void redimensionarCapacidade();
        friend void verificarResultados(clinica umaClinica, int exame);
};

clinica::clinica(int capacidade) {
    quantidadeDePacientes = 0;
    capacidadeMaxima = capacidade;
    listaDePacientes = new paciente[capacidadeMaxima];
}

clinica::~clinica() {
    delete [] listaDePacientes;
}

void clinica::inserirNovoPaciente(const paciente& umPaciente) {
    if (quantidadeDePacientes == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDePacientes[quantidadeDePacientes] = umPaciente;
    quantidadeDePacientes++;
}

bool clinica::buscarPaciente(const string& nome, paciente& umPaciente) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDePacientes and 
           listaDePacientes[posicaoAtual].nomeDoPaciente != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de produtos, é porque não encontrou
    if (posicaoAtual < quantidadeDePacientes) {
        umPaciente = listaDePacientes[posicaoAtual];
        return true;
    }

    return false;
}

void clinica::redimensionarCapacidade() {
    cout << "expandi array" << endl;
    int novaCapacidade = capacidadeMaxima+3;
    paciente* listaTemp = new paciente[novaCapacidade];
    cout << "cap max antes: " << capacidadeMaxima << endl;
    for (int i = 0; i < capacidadeMaxima; i++){
        listaTemp[i] = listaDePacientes[i];
    }
    capacidadeMaxima = novaCapacidade;
    delete [] listaDePacientes;
    listaDePacientes = listaTemp;
    cout << "cap max dps: " << capacidadeMaxima << endl;
#warning implemente este metodo!
}

void verificarResultados(clinica umaClinica, int exame) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umaClinica.quantidadeDePacientes; i++) {
        if (umaClinica.listaDePacientes[i].resultadosDosExames[exame] >= 0)
            cout << umaClinica.listaDePacientes[i].nomeDoPaciente << " " 
                 << umaClinica.listaDePacientes[i].resultadosDosExames[exame]  << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Clinica - Aplicativo para Exames Laboratoriais\n" 
         << "Entre com capacidade máxima inicial de pacientes: ";
    cin >> capacidadeInicial;

    clinica umaClinica(capacidadeInicial);

    cout << "Clinica - Escolha a Opção:\n"
         << "i - inserir novo paciente\n"
         << "b - buscar por dados de um paciente a partir do nome\n"
         << "v - verificar resultados de exames\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    paciente umPaciente;
    string nome;
    int exameDesejado;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do paciente - nome e resultados de quatro exames" << endl
                     << "(use -1 para indicar que um exame não foi realizado):" << endl;
                cin >> umPaciente.nomeDoPaciente 
                    >> umPaciente.resultadosDosExames[0] >> umPaciente.resultadosDosExames[1] 
                    >> umPaciente.resultadosDosExames[2] >> umPaciente.resultadosDosExames[3];
                umaClinica.inserirNovoPaciente(umPaciente);
                break;

            case 'b' :
                cout << "Entre com nome do paciente para busca: ";
                cin >> nome;
                
                if (umaClinica.buscarPaciente(nome, umPaciente)) 
                    cout << umPaciente.nomeDoPaciente << " "
                    << umPaciente.resultadosDosExames[0] << umPaciente.resultadosDosExames[1] 
                    << umPaciente.resultadosDosExames[2] << umPaciente.resultadosDosExames[3] 
                    << endl << endl;
                else 
                    cout << "paciente não encontrado!" << endl << endl;
                break;

            case 'v' : 
                cout << "Entre exame desejado: ";
                cin >> exameDesejado;
                if (exameDesejado >= 0 and exameDesejado <=3) 
                    verificarResultados(umaClinica,exameDesejado);
                else 
                    cout << "Exame não disponível (use 0, 1, 2 ou 3)!" << endl;
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Clinica - Escolha a Opção:\n"
            << "i - inserir novo paciente\n"
            << "b - buscar por dados de um paciente a partir do nome\n"
            << "v - verificar resultados de exames\n"
            << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}
