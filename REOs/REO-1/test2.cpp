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
(atividade manual) e o código desenvolvido (atividade prática)*/

#include <iostream>
using namespace std;

class Animal{
    private:
        string nomeAnimal;
        string especieAnimal;
        string localResgate;
        string dataResgate;
    public:
        string getNomeAnimal(){return nomeAnimal;}
        string getEspecieAnimal(){return especieAnimal;}
        string getLocalResgate(){return localResgate;}
        string getDataResgate(){return dataResgate;}

        Animal(string n, string e, string l, string d){
            nomeAnimal = n;
            especieAnimal = e;
            localResgate = l;
            dataResgate = d;
        }
        Animal(){}
};

class Benfeitor{
    private:
        string nomeBenfeitor;
        bool pessoaJuridica;
        int valorDoacao;
        int doacoesFeitas[100];
    public:
        string getNomeBenfeitor(){return nomeBenfeitor;}
        bool getPessoaJuridica(){return pessoaJuridica;}
        int getvalorDoacao(){return valorDoacao;}
        Benfeitor(string _nomeBenfeitor, int _valorDoacao, bool _pessoaJuridica){
            nomeBenfeitor = _nomeBenfeitor;
            valorDoacao = _valorDoacao;
            pessoaJuridica = _pessoaJuridica;
        }
        Benfeitor(){}
};

class ONG{
    private:
        int numeroAnimaisResgatados;
        int numeroBenfeitoresCadastrados;
    public:
        ONG(){
            numeroBenfeitoresCadastrados = 0;
            numeroAnimaisResgatados = 0;
        }

        int getNumeroAnimaisResgatados(){return numeroAnimaisResgatados;}
        int getNumeroBenfeitoresCadastrados(){return numeroBenfeitoresCadastrados;}
        void incrementaNumeroAnimaisResgatados(){numeroAnimaisResgatados++;}
        void incrementaBenfeitoresCadastrados(){numeroBenfeitoresCadastrados++;}
        Animal animaisResgatados[25];
        Benfeitor benfeitoresCadastrados[50];
        void cadastrarAnimalResgatado(string n, string e, string l, string d){
            Animal animalTemp(n,e,l,d);

            animaisResgatados[getNumeroAnimaisResgatados()] = animalTemp;
            incrementaNumeroAnimaisResgatados();
        }
        void cadastrarBenfeitor(string n, int v, bool pf = false){
            Benfeitor benfeitorTemp(n,v,pf);

            benfeitoresCadastrados[getNumeroBenfeitoresCadastrados()] = benfeitorTemp;
            incrementaBenfeitoresCadastrados();
        }
};


int main(){
    // Animal animal1("Toto","canina","ufla","01/11/2020");

    // cout << "NOME ANIMAL: " <<  animal1.getNomeAnimal() << endl
    // << "ESPECIE ANIMAL: " << animal1.getEspecieAnimal() << endl
    // << "LOCAL RESGATE: " << animal1.getLocalResgate() << endl 
    // << "DATA RESGATE:" << animal1.getDataResgate() << endl;

    ONG ong;

    ong.cadastrarAnimalResgatado("Toto","canina","ufla","01/11/2020");
    ong.cadastrarAnimalResgatado("toto2","canina","ufla","01/11/2020");
    ong.cadastrarAnimalResgatado("toto3","canina","ufla","01/11/2020");


    for (int i = 0; i < ong.getNumeroAnimaisResgatados(); i++){
        cout << "NOME ANIMAL: " <<  ong.animaisResgatados[i].getNomeAnimal() << endl
        << "ESPECIE ANIMAL: " << ong.animaisResgatados[i].getEspecieAnimal() << endl
        << "LOCAL RESGATE: " << ong.animaisResgatados[i].getLocalResgate() << endl 
        << "DATA RESGATE:" << ong.animaisResgatados[i].getDataResgate() << endl;
    }
    cout << endl;

    ong.cadastrarBenfeitor("bef1",50);
    ong.cadastrarBenfeitor("vale",5000,true);
    ong.cadastrarBenfeitor("petrobras",50000,true);
    ong.cadastrarBenfeitor("SADIA",100000,true);

    int maiorValor = 0;
    int indiceMaiorValor = 0;
    for (int i = 0; i < ong.getNumeroBenfeitoresCadastrados(); i++){
        if (ong.benfeitoresCadastrados[i].getPessoaJuridica() == true){
            if (maiorValor == 0){
                maiorValor = ong.benfeitoresCadastrados[i].getvalorDoacao();
            } else if (maiorValor < ong.benfeitoresCadastrados[i].getvalorDoacao()) {
                maiorValor = ong.benfeitoresCadastrados[i].getvalorDoacao();
                indiceMaiorValor = i;
            }
        }
    }

    cout << "NOME INSTITUICAO: " <<  ong.benfeitoresCadastrados[indiceMaiorValor].getNomeBenfeitor() << endl
         << "MAIOR VALOR DOADO: " << ong.benfeitoresCadastrados[indiceMaiorValor].getvalorDoacao() << endl;


    return 0;
}