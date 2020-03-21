/*Bonificação 1

Você foi convidado a criar um sistema para controle de inscrições em um evento. 
Neste evento serão ofertados minicursos e palestras. 
Para cada atividade são armazenados o nome da atividade,
um resumo da atividade, a quantidade de vagas disponíveis, 
a data de realização e a modalidade (minicurso ou palestra).
Para o evento é necessário armazenar a data de início e término 
do evento, o nome do evento, a edição, e as atividades ofertadas. 
Os participantes devem inscrever-se nas atividades que desejarem fornecendo seu nome e CPF.
A inscrição só pode ser feita se ainda houver vaga disponível. Deve ser possível realizar sua inscrição 
em uma atividade, cancelar sua inscrição em uma atividade ou consultar em quais atividades 
você se inscreveu através do seu CPF.

Implemente o código necessário, utilizando classes, para solucionar o problema apresentado.
*/
//TODO CRIAR ARRAY DE PARTICIPANTES NA CLASSE ATIVIDADE #1
//TODO IMPLEMENTAR ARRAY DE ATIVIDADES NA CLASSE EVENTO #2
//TODO IMPLEMENTAR MÉTODO PARA PROCURAR POR CPF BUSCANDO DENTRO DO ARRAY DE ATIVIDADES PELO CPF #3 R:#1
using namespace std;
#include <iostream>

class Evento;
//class Atividade;
class Participante;

class Atividade
{
    friend class Evento;
    friend class Participante;

public:
    void PrintDadosAtividade();
    Atividade(Evento *event,
              string nome,
              string resumo,
              int vagas,
              string DataRealizacao,
              string modalidade);

protected:
    string nomeAtividade;
    string resumoAtividade;
    int vagasDisponiveisAtividade;
    string DataRealizacaoAtividade;
    string modalidadeAtividade;
};

class Evento
{
    friend class Atividade;

protected:
    string dataInicioEvento;
    string dataTerminoEvento;
    string nomeEvento;
    string edicaoEvento;

public:
    int atividadesCadastradas = 0;
    string atividadesOfertadas[10]; //Transformar em array da classe Atividade
    Atividade *atividades[10];

    Evento(string dataInicio,
           string dataTermino,
           string nome,
           string edicao);
    void PrintDadosEvento();
    void CadastrarAtividade(string nomeAtividade); // Transformar isso para receber como parametro uma Atividade e registrar no array de Atividades de Evento
};

class Participante
{
    friend class Atividade;

protected:
    //Como criar um array da classe Atividades[5]?
    int atividadesInscritas = 0;
    //Atividade *atividadesParticipante[5]; //Atividades em que o Participante está inscrito,
    string atividadesParticipante[5];
    string cpfParticipante;
    string nomeParticipante;

public:
    Participante(string nome, string cpf);
    void InscreverEmAtividade(Atividade ativ);
    void CancelarInscricaoEmAtividade(Atividade ativ);
    void ConsultarAtividadesInscritas();
    void PrintDadosParticipante();
};

//METODOS EVENTO//

Evento::Evento(string dataInicio,
               string dataTermino,
               string nome,
               string edicao)
{
    nomeEvento = nome,
    dataInicioEvento = dataInicio,
    dataTerminoEvento = dataTermino,
    edicaoEvento = edicao;
}


void Evento::PrintDadosEvento()
{
    cout << nomeEvento << endl;
    cout << edicaoEvento << endl;
    cout << dataInicioEvento << endl;
    cout << dataTerminoEvento << endl;
}
void Evento::CadastrarAtividade(string nomeAtividade)
{
    atividadesOfertadas[atividadesCadastradas] = nomeAtividade;
    atividadesCadastradas++;
}

//METODOS ATIVIDADE//

Atividade::Atividade(Evento *event,
                     string nome,
                     string resumo,
                     int vagas,
                     string DataRealizacao,
                     string modalidade)
{
    nomeAtividade = nome,
    resumoAtividade = resumo,
    vagasDisponiveisAtividade = vagas,
    DataRealizacaoAtividade = DataRealizacao,
    modalidadeAtividade = modalidade;

    event->CadastrarAtividade(nomeAtividade); //Como cadastrar esse proprio objeto que tá sendo criado?
};

void Atividade::PrintDadosAtividade()
{
    cout << nomeAtividade << endl;
    cout << resumoAtividade << endl;
    cout << vagasDisponiveisAtividade << endl;
    cout << DataRealizacaoAtividade << endl;
    cout << modalidadeAtividade << endl;
};

//METODOS PARTICIPANTE//

Participante::Participante(string nome, string cpf)
{
    nomeParticipante = nome,
    cpfParticipante = cpf;
};

void Participante::InscreverEmAtividade(Atividade ativ)
{
    if (ativ.vagasDisponiveisAtividade > 0)
    {
        atividadesParticipante[atividadesInscritas] = ativ.nomeAtividade;
        atividadesInscritas++;
        ativ.vagasDisponiveisAtividade--;
        //InscreverCpfEmAtividade(cpfParticipante);
    }
    else
        cout << "Não há mais vagas nesse curso";
}

void Participante::CancelarInscricaoEmAtividade(Atividade ativ)
{
    for (int i = 0; i < atividadesInscritas; i++)
    {
        if (atividadesParticipante[i] == ativ.nomeAtividade)
        {
            atividadesParticipante[i] == "";
            atividadesInscritas--;
            cout << "Inscricao em " << atividadesParticipante[i] << " para o participante " << nomeParticipante << " Cancelada" << endl;
        }
    }
    cout << endl;
}

void Participante::PrintDadosParticipante()
{
    cout << nomeParticipante << endl;
    cout << cpfParticipante << endl;
    cout << atividadesInscritas << endl;
    for (int i = 0; i < atividadesInscritas; i++)
        cout << atividadesParticipante[i] << " ";
    cout << endl;
}

int main()
{
    Evento OIT8("07/07", "08/08", "OIT8", "Quarta Edicao");

    Atividade MiniCurso(&OIT8, "Minicurso", "Um breve curso de algo", 15, "07/07", "Minicurso");
    cout << endl;
    MiniCurso.PrintDadosAtividade();

    Atividade Palestra(&OIT8, "Palestra", "Um breve palestra de algo", 20, "07/07", "Palestra");
    cout << endl;
    Palestra.PrintDadosAtividade();

    Atividade Oficina(&OIT8, "Oficina", "Uma breve oficina de algo", 25, "07/07", "Minicurso");
    cout << endl;
    Oficina.PrintDadosAtividade();

    Participante Gabriel("Gabriel", "151851937-78");

    cout << endl;
    Gabriel.PrintDadosParticipante();

    Gabriel.InscreverEmAtividade(MiniCurso);

    cout << endl;
    Gabriel.PrintDadosParticipante();

    Gabriel.InscreverEmAtividade(Oficina);

    cout << endl;
    Gabriel.PrintDadosParticipante();

    cout << endl;
    Gabriel.CancelarInscricaoEmAtividade(Oficina);
    Gabriel.PrintDadosParticipante();

    cout << endl;
    Oficina.PrintDadosAtividade();

    cout << endl;
    OIT8.PrintDadosEvento();

    cout << OIT8.atividadesCadastradas << endl;
    cout << OIT8.atividadesOfertadas[0]; //imprime nada
}

/*Resultado:
        Minicurso
		Um breve curso de algo
		15
		07/07
		Minicurso

		Palestra
		Um breve palestra de algo
		20
		07/07
		Palestra

		Oficina
		Uma breve oficina de algo
		25
		07/07
		Minicurso

		Gabriel
		151851937-78
		0


		Gabriel
		151851937-78
		1
		Minicurso 

		Gabriel
		151851937-78
		2
		Minicurso Oficina 

		Inscricao em Oficina para o participante Gabriel Cancelada

		Gabriel
		151851937-78
		1
		Minicurso 

		Oficina
		Uma breve oficina de algo
		25
		07/07
		Minicurso

		OIT8
		Quarta Edicao
		07/07
		08/08
		0

		*/
