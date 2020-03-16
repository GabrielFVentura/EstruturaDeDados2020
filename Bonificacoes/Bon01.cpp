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
//TODO CRIAR ARRAY DE PARTICIPANTES #1
//TODO IMPLEMENTAR ARRAY DE ATIVIDADES #2
//TODO IMPLEMENTAR MÉTODO PARA PROCURAR POR CPF #3 R:#1
using namespace std;
#include <iostream>

class Atividade{
    friend class Participante;
    friend class Evento;

    protected:
        string nomeAtividade;
        string resumoAtividade;
        int vagasDisponiveisAtividade;
        string DataRealizacaoAtividade;
        string modalidadeAtividade;

    public:
        Atividade(string nome,
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

            //Não funciona, Pq? CadastrarAtividade(string nome);
        };

    void DadosAtividade()
        {
            cout << nomeAtividade << endl;
            cout << resumoAtividade << endl;
            cout << vagasDisponiveisAtividade << endl;
            cout << DataRealizacaoAtividade << endl;
            cout << modalidadeAtividade << endl;
        }
};

class Evento{
    friend class Atividade;

    protected:
        string dataInicioEvento;
        string dataTerminoEvento;
        string nomeEvento;
        string edicaoEvento;
        int atividadesCadastradas = 0;
        string atividadesOfertadas[10]; //Transformar em array da classe Atividade

    public:
        Evento(string dataInicio,
        string dataTermino,
        string nome,
        string edicao)
        {
            dataInicioEvento = dataInicio,
            dataTerminoEvento = dataTermino,
            nomeEvento = nome,
            edicaoEvento = edicao;
        }

        void DadosEvento(){
        cout << dataInicioEvento << endl;
        cout << dataTerminoEvento << endl;
        cout << nomeEvento << endl;
        cout << edicaoEvento << endl;
        for (int i = 0; i < atividadesCadastradas; i++)
                 cout << atividadesOfertadas[i] << endl;
        }

        void CadastrarAtividade(Atividade ativ)
        {
            atividadesOfertadas[atividadesCadastradas] = ativ.nomeAtividade;    
            atividadesCadastradas++;
        }
};

class Participante{
    friend class Atividade;

    protected:
    //Como criar um array da classe Atividades[5]?
        int atividadesInscritas = 0;
        string atividades[5];
        string cpfParticipante;
        string nomeParticipante;

    public:
    Participante(string nome,
    string cpf)
    {
        nomeParticipante = nome,
        cpfParticipante = cpf;
    }

    void CancelarInscricaoEmAtividade(Atividade ativ)
    {
        for (int i = 0;i < atividadesInscritas;i++)
        {
            if (atividades[i] == ativ.nomeAtividade)
            {
                atividades[i] == "";
                atividadesInscritas--;
                cout << "Inscricao em " << atividades[i] << " Cancelada" << endl;
            }
        }
        cout << endl;
    }

    void InscreverEmAtividade(Atividade ativ)
    {
        if (ativ.vagasDisponiveisAtividade > 0)
        {
            atividades[atividadesInscritas] = ativ.nomeAtividade;
            atividadesInscritas++;
            ativ.vagasDisponiveisAtividade--;;
        }
        else
            cout << "Não há mais vagas nesse curso";
        
    };

    void ConsultarAtividadesInscritas();

    void DadosParticipante(){
        cout << nomeParticipante << endl;
        cout << cpfParticipante << endl;
        cout << atividadesInscritas << endl;
        for (int i = 0;i<atividadesInscritas;i++)
            cout << atividades[i] << " ";
        cout << endl;
     }
};

int main()
{
    Evento OIT8("07/07","08/08","OIT8","Quarta Edicao");

    Atividade MiniCurso("Minicurso","Um breve curso de algo", 15, "07/07","Minicurso");
    OIT8.CadastrarAtividade(MiniCurso); // Passar esse método para dentro do construtor da classe Atividade
    cout << endl;
    MiniCurso.DadosAtividade();

    Atividade Palestra("Palestra","Um breve palestra de algo", 20, "07/07","Palestra");
    OIT8.CadastrarAtividade(Palestra);
    cout << endl;
    Palestra.DadosAtividade();
 
    Atividade Oficina("Oficina","Uma breve oficina de algo", 25, "07/07","Minicurso");
    OIT8.CadastrarAtividade(Oficina);
    cout << endl;
    Oficina.DadosAtividade();

    Participante Gabriel("Gabriel","151851937-78");

    cout << endl;
    Gabriel.DadosParticipante();

    Gabriel.InscreverEmAtividade(MiniCurso);

    cout << endl;
    Gabriel.DadosParticipante();

    Gabriel.InscreverEmAtividade(Oficina);

    cout << endl;
    Gabriel.DadosParticipante();

    cout << endl;
    Gabriel.CancelarInscricaoEmAtividade(Oficina);
    Gabriel.DadosParticipante();

    cout << endl;
    Oficina.DadosAtividade();
    
    cout << endl;
    OIT8.DadosEvento();
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

        Inscricao em Oficina Cancelada

        Gabriel
        151851937-78
        1
        Minicurso

        Oficina
        Uma breve oficina de algo
        25
        07/07
        Minicurso

        07/07
        08/08
        OIT8
        Quarta Edicao
        Minicurso
        Palestra
        Oficina
*/