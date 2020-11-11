/*Os motociclistas da região decidiram se reunir em uma associação para estabelecer parcerias com oficinas mecânicas especializadas e fornecedores de peças e acessórios 
de modo a conseguir vantagens para todos: os serviços em preço mais em conta e a fidelização dos clientes para as oficinas e lojas. A primeira atitude foi realizar o 
levantamento de todos que gostariam de participar da associação registrando seu nome, marca, modelo e ano da motocicleta, e telefone para contato. A partir desse 
primeiro cadastro, os dirigentes da associação buscaram por oficinas especializadas e lojas de peças e acessórios das marcas identificadas no cadastro inicial.
A associação precisa realizar o cadastro das oficinas e lojas, registrar os acordos de parceria identificando o nome da oficina ou loja, as marcas atendidas por ela e o
tipo de benefício que será dado (desconto por serviço, brinde ou revisão gratuita após 5 serviços realizados). A associação também poderá, sempre que solicitado,
consultar o nome das oficinas ou lojas que atendem  uma determinada marca.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado 
(os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação deve ser orientada a objetos, 
com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de cada classe e um pequeno 
programa (main) que as utilize para solucionar o problema apresentado.
Você deve tomar as decisões de projeto que achar adequada (definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do código.
Você deverá entregar o planejamento realizado (atividade manual) e o código desenvolvido (atividade prática)

____________________________________________________________________________________
|                                                                                   |
|                                                                                   |
|                        Estruturas de Dados, 2020/2                                |
|                                                                                   |
|                                                                                   |
|                    Solução de: GABRIEL FRANCO VENTURA SANTOS                      |
|                                                                                   |
|                                                                                   |
|___________________________________________________________________________________|

*/

#include <iostream>
using namespace std;

class Motoqueiro{
    private:
        string _nomeMotoqueiro;
        string _marcaMoto;
        string _modeloMoto;
        string _anoFabrica;
        string _telefoneContato;
    public:
        string getNomeMotoqueiro(){return _nomeMotoqueiro;}
        string getMarcaMoto(){return _marcaMoto;}
        string getModeloMoto(){return _modeloMoto;}
        string getAnoFabrica(){return _anoFabrica;}
        string getTelefoneContato(){return _telefoneContato;}
        Motoqueiro(string n,string m, string mod, string a, string t){
            _nomeMotoqueiro = n;
            _marcaMoto = m;
            _modeloMoto = mod;
            _anoFabrica = a;
            _telefoneContato = t;
        }
        Motoqueiro(){

        };
        friend ostream& operator<<(ostream& os, Motoqueiro &moto){
             os << "NOME DO MOTOQUEIRO: " << moto.getNomeMotoqueiro() << endl;
             os << "MARCA DA MOTO: " << moto.getMarcaMoto() << endl;
             os << "MODELO DA MOTO: " << moto.getModeloMoto() << endl;
             os << "ANO DE FABRICACAO: " << moto.getAnoFabrica() << endl;
             os << "TELEFONE DE CONTATO: " << moto.getTelefoneContato() << endl;
        }
};

class OficinaLoja{
    private:
        string _nomeOficina;
        string* _marcasAtendidas;
        int _tipoBeneficio;
        int _numeroMarcasAtendidas;
    public:
        OficinaLoja(string n, int t){
            _numeroMarcasAtendidas = 0;
            _marcasAtendidas = new string[15];
        }
        OficinaLoja(){};
};

class Associacao{
    private:
        OficinaLoja* _oficinaLojasCadastradas;
        Motoqueiro* _motoqueirosCadastrados;
        int _numeroMotoqueirosCadastrados;
        int _numeroOficinaLojasCadastradas;

    public:
        Associacao(){
            _oficinaLojasCadastradas = new OficinaLoja[50];
            _motoqueirosCadastrados = new Motoqueiro[100];
            _numeroMotoqueirosCadastrados = 0;
            _numeroOficinaLojasCadastradas = 0;
        }

        int getNumeroMotoqueirosCadastrados(){ return _numeroMotoqueirosCadastrados;}
        void incrementarNumeroMotoqueirosCadastrados(){ _numeroMotoqueirosCadastrados++;}
        void decrementarNumeroMotoqueirosCadastrados(){ _numeroMotoqueirosCadastrados--;}
        Motoqueiro* getMotoqueirosCadastrados(){return _motoqueirosCadastrados;}
        void cadastrarMotoqueiro(){
            string _nomeMotoqueiro;
            string _marcaMoto;
            string _modeloMoto;
            string _anoFabrica;
            string _telefoneContato;
            cout << "NOME DO MOTOQUEIRO: " << endl;
            cin >> _nomeMotoqueiro;
            cout << "MARCA DA MOTO: " << endl;
            cin >> _marcaMoto;
            cout << "MODELO DA MOTO: " << endl;
            cin >> _modeloMoto;
            cout << "ANO DE FABRICA DA MOTO: " << endl;
            cin >> _anoFabrica;
            cout << "TELEFONE DE CONTATO: " << endl;
            cin >> _telefoneContato;
            Motoqueiro* motoqueiro = new Motoqueiro(_nomeMotoqueiro, _marcaMoto, _modeloMoto, _anoFabrica, _telefoneContato);
            _motoqueirosCadastrados[getNumeroMotoqueirosCadastrados()] = *motoqueiro;
            incrementarNumeroMotoqueirosCadastrados();
        };
        void cadastrarOficinaLoja(){

        };
        void registrarAcordoParceria(){};
        void procurarMarcaPorOficinaLoja(){};
        void consultarOficinaLojasPorMarca(){};
        void printOpcoes(){
            cout << "Opcoes: " << endl;
            cout << "c -> Cadastrar Motoqueiro" << endl;
            cout << "a -> Cadastrar Oficina/Loja" << endl;
            cout << "d -> Registrar Acordo/Parceria" << endl;
            cout << "e -> Consultar Oficinas/Lojas por Marcas" << endl;
        }

};

int main(){
    char command;
    Associacao associacao;
    Motoqueiro motoqueiro("Gabriel", "Suzuki", "GSX-750", "2020", "21972101291");
    // associacao.cadastrarMotoqueiro();
    cout << *associacao.getMotoqueirosCadastrados();
    cout << motoqueiro;

    do {
        associacao.printOpcoes();
        cin >> command;
        switch (command)
        {
        case('c'):{
            associacao.cadastrarMotoqueiro();
            break;
        }
        case('a'):{
            associacao.cadastrarOficinaLoja();
            break;
        }
        case('d'):{
            associacao.registrarAcordoParceria();
            break;
        }
        case('e'):{
            associacao.consultarOficinaLojasPorMarca();
            break;
        }
        case('f'):{
            break;
        }
        default:
            break;
        }
    } while (command != 'f');
    
    
    return 0;
}