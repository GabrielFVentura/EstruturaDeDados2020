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
class Evento{
    friend class Atividade;

    public:
        string dataInicio;
        string nomeEvento;
        string edicao;
        string atividadesOfertadas;
};

class Atividade{
    protected:
    string nomeAtividade;
    string resumoAtividade;
    int vagasDisponiveis;
    string DataRealizacao;
    string modalidade;

    public:
    void InscreverEmAtividade();
    void CancelarInscricaoEmAtividade();
    void ConsultarAtividadesInscritas();
};

class Participante{
    protected:
    string cpf;
    string nome;
};

#include <iostream>
using namespace std;

int main()
{
    Evento evento;
    evento.

}