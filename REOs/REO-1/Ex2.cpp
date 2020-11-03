/*Enunciado 2
Depois de muito tempo trabalhando com tecnologia e sistemas computacionais Morgana conseguiu se mudar para uma pequena chácara no interior e passou a cultivar 
flores, hortaliças e frutas. Agora ela levanta com o raiar do Sol e pára suas atividades ao entardecer. Entretanto, para facilitar um pouco seu trabalho,
ela decidiu cadastrar todas as espécies que cultiva, registrando o nome, período de plantio e tempo de produção. Em seguida, passou a registrar os nomes 
dos fornecedores de cada um dos produtos que utiliza - sementes, ferramentas, insumos, etc. registrando o nome do fornecedor, o produto de interesse e o
telefone de contato. Agora ela pode registrar novas espécies de cultivo, pode registrar novos fornecedores e pode buscar por todos os fornecedores de um
determinado produto. Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e 
qual o comportamento esperado (os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação 
deve ser orientada a objetos, com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o 
comportamento de cada classe e um pequeno programa (main) que as utilize para solucionar o problema apresentado.
Você deve tomar as decisões de projeto que achar adequada (definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do
código. Você deverá entregar o planejamento realizado (atividade manual) e o código desenvolvido (atividade prática)*/

#include <iostream>
using namespace std;

class Especie{
    private:
        string _especie;
        string _periodoPlantio;
        string _tempoProducao;
    public:
        string getEspecie(){return _especie;}
        string getPeriodoPlantio(){return _periodoPlantio;}
        string getTempoProducao(){return _tempoProducao;}
        Especie(string e, string p, string t){
            _especie = e;
            _periodoPlantio = p;
            _tempoProducao = t;
        }
        Especie(){}
};

class Fornecedor{
    private:
        string _nomeFornecedor;
        string _produtoInteresse;
        string _telefoneContato;
    public:
        string getNomeFornecedor(){return _nomeFornecedor;}
        string getProdutoInteresse(){return _produtoInteresse;}
        string getTelefoneContato(){return _telefoneContato;}
        Fornecedor(string n, string p, string t){
            _nomeFornecedor = n;
            _produtoInteresse = p;
            _telefoneContato = t;
        }
        Fornecedor(){};
};

class Horta{
    private:
        int _numeroFornecedoresCadastrados;
        int _numeroEspeciesCultivadas;
        int _capacidadeFornecedores;
    public:
        int getNumeroFornecedoresCadastrados(){return _numeroFornecedoresCadastrados;}
        int getNumeroEspeciesCultivadas(){return _numeroEspeciesCultivadas;}
        int getCapacidadeFornecedores(){return _capacidadeFornecedores;}
        void setCapacidadeFornecedores(int v){ _capacidadeFornecedores = v;}
        void incrementaTamanhoNumeroEspeciesCultivadas(){_numeroEspeciesCultivadas++;}
        void incrementaTamanhoNumeroFornecedoresCadastrados(){_numeroFornecedoresCadastrados++;}
        Especie* especiesCultivadas[10];
        Fornecedor* fornecedoresCadastrados;
        
        Horta(int f){
            _capacidadeFornecedores = f;
            _numeroEspeciesCultivadas = 0;
            _numeroFornecedoresCadastrados = 0;
            fornecedoresCadastrados = new Fornecedor[f];
        }
        void cadastrarFornecedor(string n, string p, string t){
            if (getNumeroFornecedoresCadastrados() < getCapacidadeFornecedores()){
                Fornecedor fornecedorTemp(n,p,t);

                *(fornecedoresCadastrados+getNumeroFornecedoresCadastrados()) = fornecedorTemp;
                incrementaTamanhoNumeroFornecedoresCadastrados();
            } else {
                fornecedoresCadastrados = atualizarTamanhoArrayFornecedores(fornecedoresCadastrados, getCapacidadeFornecedores());
                Fornecedor fornecedorTemp(n,p,t);
                *(fornecedoresCadastrados+getNumeroFornecedoresCadastrados()) = fornecedorTemp;
                incrementaTamanhoNumeroFornecedoresCadastrados();
            }
        }

        Fornecedor* atualizarTamanhoArrayFornecedores(Fornecedor* arrForn, int t){
            Fornecedor* tempForn = new Fornecedor[t+5];
            setCapacidadeFornecedores(getCapacidadeFornecedores()+t);
            for (int i = 0; i < getNumeroFornecedoresCadastrados(); i++){
                *(tempForn+i) = arrForn[i];
            }
            return tempForn;
        }

};

int main(){
    Horta horta(5);
    for (int i = 0; i < 15;i++){
        horta.cadastrarFornecedor("joao","insumos","21-99999-9999");
    }
    // horta.cadastrarFornecedor("joao1","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao2","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao3","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao4","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao5","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao6","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao7","insumos","21-99999-9999");
    // horta.cadastrarFornecedor("joao8","insumos","21-99999-9999");
    for (int i = 0; i < 15; i++){
        cout << horta.fornecedoresCadastrados[i].getNomeFornecedor() << endl;
    }
    // cout << horta.fornecedoresCadastrados[1].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[2].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[3].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[4].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[5].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[6].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[7].getNomeFornecedor() << endl;
    // cout << horta.fornecedoresCadastrados[8].getNomeFornecedor() << endl;

    for (int i = 0; i < horta.getNumeroFornecedoresCadastrados();i++){
        // cout << horta.fornecedoresCadastrados->getNomeFornecedor() << endl;
    }

    return 0;
}