/*Uma organização não governamental (ONG) que acolhe cães e gatos abandonados tem recebido, ao longo dos anos, várias doações, de várias pessoas e instituições,
 que ficam sensibilizadas com o trabalho desenvolvido. Entretanto, caso fosse necessário indicar qual instituição que mais apoiou a ONG em valores reais
(maior montante recebido), seus dirigentes não teriam como fornecer essa informação. Dessa forma, além do registro dos animais, que armazena o nome dado ao animal,
a espécie, o local e a data em que foi resgatado, eles também passaram a fazer o cadastro de seus benfeitores, armazenando o nome, o tipo (se pessoa física ou jurídica), 
e o valor da doação (caso a doação seja em material de limpeza, ração ou outros produtos, é registrado o valor estimado da doação).
Agora é possível cadastrar novos animais, cadastrar novas doações e procurar pelas doações feitas por um determinado benfeitor.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado 
(os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação deve ser orientada a objetos,
com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de cada classe e um 
pequeno programa (main) que as utilize para solucionar o problema apresentado. Você deve tomar as decisões de projeto que achar adequada 
(definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do código. Você deverá entregar o planejamento realizado 
(atividade manual) e o código desenvolvido (atividade prática)
*/

#include <iostream>
using namespace std;
class ONG;
class DateTime{
    private:
        string _dia;
        string _mes;
        string _ano;
        string _hora;
        string _minuto;
        string _segundo;

    public:
    DateTime(string d, string m, string a, int MM){
        _dia = d;
        _mes = MM < 10 ? "0"+ m: m;
        _ano = a;
    }
    DateTime(){
        _dia = "00";
        _mes = "00";
        _ano = "0000";
    }
    string setDateTime(string d, string m, string a, int MM){
        _dia = d;
        _mes = MM < 10 ? "0"+ m: m;
        _ano = a;
    }
    string getDateTime(){
        return _dia+"/"+_mes+"/"+_ano;
    }

    friend ostream& operator<<(ostream& os, DateTime &date){
        os << date._dia <<"/" << date._mes <<"/" << date._ano << endl;
    }

    void criarInputDateTime(){
        string d;
        string m;
        string a;
        int MM;
        cin >> d >> m >> a >> MM;
        _dia = d;
        _mes = m;
        _ano = a;
    }
};

class Animal{
    private:
        string _nomeAnimal;
        string _especie;
        string _localResgate;
        DateTime _dataResgate;

    public:
        Animal(string n, string e, string l, DateTime d){
            _nomeAnimal = n;
            _especie = e;
            _localResgate = l;
            _dataResgate = d;
        }
        Animal(){};
        string getNomeAnimal(){
            return _nomeAnimal;
        }
        string getEspecie(){
            return _especie;
        }
        string getLocalResgate(){
            return _localResgate;
        }
        DateTime& getDateTime(){
            return _dataResgate;
        }
        friend ostream& operator<<(ostream& os, Animal &anim){
            os << "Nome do Animal: " << anim.getNomeAnimal() << 
            " Especie: " << anim.getEspecie() << 
            " Local de Resgate: " << anim.getLocalResgate() << 
            " Data do Resgate " << anim.getDateTime();
        }
};

class Benfeitor{
    private:
        string _nomeBenfeitor;
        bool _tipoPessoaJuridica;
        int _qtdDoacao;
        int _valorDoacao[50];
        int _valorTotalDoacaoBenfeitor;

    public:
        Benfeitor(string n){
            _nomeBenfeitor = n;
            _qtdDoacao = 0;
        }
        Benfeitor(string n, int v, bool pj = false){
            _tipoPessoaJuridica = pj;
            _nomeBenfeitor = n;
            _valorDoacao[0] = v;
            _valorTotalDoacaoBenfeitor += v;
            _qtdDoacao++;
        }
        Benfeitor(){}

        void incrementaQtdDoacao(){
            _qtdDoacao++;
        }

        void decrementaQtdDoacao(){
            _qtdDoacao--;
        }

        void adicionarDoacao(int v, ONG* ong);

        string getNomeBenfeitor(){
            return _nomeBenfeitor;
        }

        bool getTipoPessoaJuridica(){
            return _tipoPessoaJuridica;
        }

        int getQtdDoacao(){
            return _qtdDoacao;
        }
        
        int getValorTotalDoacao(){
            return _valorTotalDoacaoBenfeitor;
        }

        void getValoresDoacao(){
            for (int i = 0; i < getQtdDoacao(); i++){
                cout << _valorDoacao[i] << " ";
            }
        }

        bool procurarValorDoacaoBenfeitor(int v){
            for (int i = 0; i < getQtdDoacao(); i++){
                if (_valorDoacao[i] == v){
                    return 1;
                }
            }
            return 0;
        }

        string resultadoProcurarValorDoacaoPorBenfeitor(int v){
            return procurarValorDoacaoBenfeitor(v) == 1 ? "Valor da Doacao encontrado" : "Valor nao encontrado para esse Benfeitor";
        }
};

class ONG{
    private:
        int _numeroAnimais;
        int _numeroBenfeitores;
        int _valorTotalDoado;

    public:
        ONG(){
            _numeroBenfeitores = 0;
            _numeroAnimais = 0;
            _valorTotalDoado = 0;
        }

        Benfeitor* _benfeitores[10];
        Animal* _animaisResgatados[30];

        int getNumeroBenfeitores(){
            return _numeroBenfeitores;
        }

        void adicionarValorTotalDado(int v){
            _valorTotalDoado += v;
        }

        void cadastrarBenfeitor(string nome, int v = 0, bool pj = false){
            Benfeitor* benf = new Benfeitor(nome, v, pj);
            _benfeitores[_numeroBenfeitores] = benf;
            _numeroBenfeitores++;
            adicionarValorTotalDado(v);
        }

        void cadastrarAnimalResgatado(string nome, string especie, string local, DateTime data){
            Animal* anim = new Animal(nome, especie, local, data);
            _animaisResgatados[_numeroAnimais] = anim;
            _numeroAnimais++;
        }

        void procurarAnimalPorEspecie(string especie){
            for (int i = 0;i < _numeroAnimais; i++){
                if (_animaisResgatados[i]->getEspecie() == especie){
                    cout << "NOME DO ANIMAL: " << _animaisResgatados[i]->getNomeAnimal() <<
                      " ESPECIE DO ANIMAL: " << _animaisResgatados[i]->getEspecie() << 
                      " LOCAL DO RESGATE: " << _animaisResgatados[i]->getLocalResgate() << 
                      " DATA DO RESGATE: " << _animaisResgatados[i]->getDateTime(); 
                }
            }
        }

        friend ostream& operator<<(ostream& os, ONG &ONG){
            os << "Animais Resgatados: " << endl;
            for (int i = 0; i < ONG._numeroAnimais ; i++){
                os << "NOME DO ANIMAL: " << ONG._animaisResgatados[i]->getNomeAnimal() <<
                      " ESPECIE DO ANIMAL: " << ONG._animaisResgatados[i]->getEspecie() << 
                      " LOCAL DO RESGATE: " << ONG._animaisResgatados[i]->getLocalResgate() << 
                      " DATA DO RESGATE: " << ONG._animaisResgatados[i]->getDateTime();
            }
            os << endl;
            os << "Benfeitores Cadastrados: " << endl;
            for (int i = 0; i < ONG._numeroBenfeitores ; i++){
                os << "NOME DO BENFEITOR: " << ONG._benfeitores[i]->getNomeBenfeitor() << " ";
                os << "VALORES DOADOS: ";
                ONG._benfeitores[i]->getValoresDoacao();
                os << " VALOR TOTAL: " << ONG._benfeitores[i]->getValorTotalDoacao() << " " << endl;
            }
            os << endl;
            os << "VALOR TOTAL ARRECADADO: " << ONG._valorTotalDoado << endl;
        }

        void procurarValoresPorBenfeitores(int v){
            for (int i = 0; i < getNumeroBenfeitores(); i++){
                if (_benfeitores[i]->procurarValorDoacaoBenfeitor(v)){
                    cout << "VALOR ENCONTRADO PARA O BENFEITOR: " << _benfeitores[i]->getNomeBenfeitor() << endl;
                }
            }
            cout << endl;
        }

        void adicionarDoacaoPorBenfeitor(string nomeBenfeitor, int valorDoacao){
            for (int i = 0;i < getNumeroBenfeitores();i++){
                if (_benfeitores[i]->getNomeBenfeitor() == nomeBenfeitor){
                    _benfeitores[i]->adicionarDoacao(valorDoacao, this);
                }
            }
        }

        void procurarDoacaoPorBenfeitorInput(){
            int valorDoacao;
            cout << "VALOR DOACAO A SER PROCURADO: " << endl;
            cin >> valorDoacao;
            procurarValoresPorBenfeitores(valorDoacao);
        }

        void adicionarDoacaoPorBenfeitorInput(){
            string nomeBenfeitor;
            int valorDoacao;
            cout << "NOME DO BENFEITOR REALIZADOR DA DOACAO: " << endl;
            cin >> nomeBenfeitor;
            cout << "VALOR DA DOACAO: " << endl;
            cin >> valorDoacao;
            adicionarDoacaoPorBenfeitor(nomeBenfeitor,valorDoacao);
        }

        void cadastrarAnimalInput(){
            string nome;
            string especie;
            string local;
            DateTime data;
            string d,m,a;
            int _m;
            cout << "NOME DO ANIMAL RESGATADO: " << endl;
            cin >> nome;
            cout << "ESPECIE DO ANIMAL RESGATADO :" << endl;
            cin >> especie;
            cout << "LOCAL DO RESGATE: " << endl;
            cin >> local;
            cout << "DATA DO RESGATE (DD/MM/AAAA): " << endl;
            cout << "DIA: ";
            cin >> d;
            cout << "MES: ";
            cin >> m;
            cout << "ANO: ";
            cin >> a;
            
            cadastrarAnimalResgatado(nome,especie,local,DateTime(d,m,a,_m));
        }
        void cadastrarBenfeitorInput(){
                string nomeBenfeitor;
                int doacaoInicial;
                string temDoacaoInicial;
                string indicadorPessoaJuridica;
                cout << "NOME DO BENFEITOR" << endl;
                cin >> nomeBenfeitor;
                cout << "PESSOA JURIDICA? " << endl;
                cin >> indicadorPessoaJuridica;
                cout << "TEM DOACOA INICIAL? " << endl;
                cin >> temDoacaoInicial;
                if (temDoacaoInicial == "Sim" || temDoacaoInicial == "sim"){
                    cout << "VALOR DA DOACAO INICIAL: " << endl;
                    cin >> doacaoInicial;
                    cadastrarBenfeitor(nomeBenfeitor,doacaoInicial, indicadorPessoaJuridica == "sim");
                } else {
                    cadastrarBenfeitor(nomeBenfeitor, 0, indicadorPessoaJuridica == "sim");
                }
        }
        
        void procurarAnimalPorEspecieInput(){
            string especie;
            cout << "ESPECIE A SER PROCURADO " << endl;
            cin >> especie;
            procurarAnimalPorEspecie(especie);
        }

        void procurarBenfeitorPorValorInput(){
            int valor;
            cout << "VALOR A SER PROCURADO NOS BENFEITORES " << endl;
            cin >> valor;         
        }

        void procurarEmpresasBenfeitorasInput(){
             for (int i = 0; i < getNumeroBenfeitores(); i++){
                if (_benfeitores[i]->getTipoPessoaJuridica()){
                    cout << "NOME DA EMPRESA BENFEITORA: " << _benfeitores[i]->getNomeBenfeitor() << " " << endl;
                    cout << "MONTANTE DOADO: " << _benfeitores[i]->getValorTotalDoacao() << " " << endl;
                    cout << "QUANTIDADES DE VEZES DOADAS: " << _benfeitores[i]->getQtdDoacao() << " " << endl;
                }
            }
            cout << endl;
        }
};

void Benfeitor::adicionarDoacao(int v, ONG* ong){
    _valorDoacao[getQtdDoacao()] = v;
    _valorTotalDoacaoBenfeitor += v;
    incrementaQtdDoacao();
    ong->adicionarValorTotalDado(v);
}

// date._dia <<"/" << date._mes <<"/" << date._ano << endl;
int main(){
    DateTime date("27","3","2020",3);
    char command;
    
    ONG ong;

    ong.cadastrarBenfeitor("Joao");
    ong.cadastrarBenfeitor("Amanda", 50);
    ong.cadastrarBenfeitor("Gabriel", 250);
    ong.cadastrarBenfeitor("Petrobras", 25000, true);
    ong.adicionarDoacaoPorBenfeitor("Gabriel",1000);
    
    ong._benfeitores[0]->adicionarDoacao(1000, &ong);
    ong._benfeitores[1]->adicionarDoacao(100, &ong);
    ong._benfeitores[2]->adicionarDoacao(50, &ong);

    ong.cadastrarAnimalResgatado("Seju","Felino","Rua Jorge Duarte", DateTime("27","3","2020",3));
    ong.cadastrarAnimalResgatado("Kiko","Canino","Estrada dos Bandeirantes", DateTime("10","2","2016",2));
    ong.cadastrarAnimalResgatado("Mike","Canino","Rua da UFLA", DateTime("15","10","2012",10));

    cout << ong._benfeitores[0]->resultadoProcurarValorDoacaoPorBenfeitor(55) << endl;

    ong.procurarValoresPorBenfeitores(50);
    ong.procurarAnimalPorEspecie("Canino");

    cout << ong << endl;
    do {
        cout << "Opcoes: " << endl;
        cout << "b -> Cadastrar Benfeitor" << endl;
        cout << "c -> Cadastrar Animal Resgatado" << endl;
        cout << "d -> Realizar Doacao por Nome Benfeitor" << endl;
        cout << "p -> Procurar Doacao em Benfeitores" << endl;
        cout << "e -> Procurar Animais por Especie" << endl;
        cout << "v -> Visualizar Registros" << endl;
        cout << "j -> Procurar Empresas Benfeitoras" << endl;
        cout << "f -> Finalizar Secao" << endl;
        cin >> command;
        switch(command){
            case 'b':{
                ong.cadastrarBenfeitorInput();
                break;
            }
            case 'c':{
                ong.cadastrarAnimalInput();
                break;
            }
            case 'd':{
                ong.adicionarDoacaoPorBenfeitorInput();
                break;
            }
            case 'p':{
                ong.procurarBenfeitorPorValorInput();
                break;
            }
            case 'e':{
                ong.procurarAnimalPorEspecieInput();
                break;
            }
            case 'j':{
                ong.procurarEmpresasBenfeitorasInput();
                break;
            }
            case 'v':{
                cout << ong << endl;
                break;
            }
            case 'f':{
                break;
            }
            default:{
                cerr << "Comando invalido" << endl;
            }
        }

    } while (command != 'f');
    
    return 0;
}