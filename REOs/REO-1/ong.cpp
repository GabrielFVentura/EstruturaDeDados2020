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

#include<iostream>
using namespace std;

class ONG;
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

//armazenando o nome, o tipo (se pessoa física ou jurídica), e o valor da doação

class Benfeitor{
    private:
        string nomeBenfeitor;
        bool tipoPessoa; // 0 -> Pessoa Fisica // 1 -> Pessoa Juridica
        int valorDoacao;

    public:
        string getNomeBenfeitor(){return nomeBenfeitor;}
        bool getTipoPessoa(){return tipoPessoa;}
        int getValorDoacao(){return valorDoacao;}

        Benfeitor(string n, int v, bool tp = false){
            nomeBenfeitor = n;
            tipoPessoa = tp;
            valorDoacao = v;
        }
        Benfeitor(){};
};

class ONG{
    private:
        int numeroAnimaisResgatados;
        int numeroBenfeitoresCadastrados;
        int valorMontanteDoado;

    public:
        Animal animais[25];
        Benfeitor benfeitores[50];
        void incrementaNumeroAnimaisResgatados(){numeroAnimaisResgatados++;}
        void incrementaNumeroBenfeitoresCadastrados(){numeroBenfeitoresCadastrados++;}
        int getNumeroAnimaisResgatado(){return numeroAnimaisResgatados;}
        int getNumeroBenfeitoresCadastrados(){return numeroBenfeitoresCadastrados;}
        int getValorMontanteDoado(){return valorMontanteDoado;}

        ONG(){
            numeroAnimaisResgatados = 0;
            numeroBenfeitoresCadastrados = 0;
            valorMontanteDoado = 0;
        }
        
        void cadastrarAnimalResgatado(string nomeAnimal, string especieAnimal, string localResgate, string dataResgate){
             Animal animalCadastrado(nomeAnimal,especieAnimal,localResgate,dataResgate);

             animais[numeroAnimaisResgatados] = animalCadastrado;
             incrementaNumeroAnimaisResgatados();
        }
                
        void cadastrarBenfeitor(string nomeBenfeitor, int valorDoacao, bool tipoPessoa){
             Benfeitor benfeitorCadastrado(nomeBenfeitor,valorDoacao, tipoPessoa);

             benfeitores[numeroBenfeitoresCadastrados] = benfeitorCadastrado;
             incrementaNumeroBenfeitoresCadastrados();
             valorMontanteDoado += valorDoacao;
        }

};


int main(){
    ONG ong;

    ong.cadastrarAnimalResgatado("Toto","canina","ufla","21/12/2020");
    ong.cadastrarAnimalResgatado("kiko","canina","rj","21/12/2020");
    ong.cadastrarAnimalResgatado("mike","canina","maua","21/12/2020");

    for (int i = 0;i < ong.getNumeroAnimaisResgatado(); i++){
        cout << "nome animal:" << ong.animais[i].getNomeAnimal() 
        << " especie animal: " << ong.animais[i].getEspecieAnimal() 
        << " local resgate: " << ong.animais[i].getLocalResgate() 
        << " data resgate: " << ong.animais[i].getDataResgate() 
        << endl;
    }

    ong.cadastrarBenfeitor("vale", 5000, true);
    ong.cadastrarBenfeitor("petrobras", 50000, true);
    ong.cadastrarBenfeitor("alexandre", 50, false);
    cout << ong.benfeitores[0].getNomeBenfeitor() << endl;
    cout << ong.benfeitores[0].getTipoPessoa() << endl;
    cout << ong.benfeitores[0].getValorDoacao() << endl;

    cout << "VALOR TOTAL:" << ong.getValorMontanteDoado() << endl;

    return 0;
}