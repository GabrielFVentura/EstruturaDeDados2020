/*Enunciado 3
Um curador de exposições fotográficas acumulou, ao longo de sua carreira, os dados de muitos artistas e muitos entusiastas (pessoas que adquirem as obras expostas).
Ele deseja agora separar esses dados. Para os artistas serão armazenados o nome do artista, seu telefone de contato e o endereço de seu ateliê (ou studio); 
para os entusiastas serão armazenados seu nome, o nome e o valor da última obra que ele adquiriu, seu e-mail de contato.
Dessa forma, o curador poderá, quando for organizar novas exposições, cadastrar novos artistas, registra novos entusiastas e buscar os dados de um determinado artista.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado 
(os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação deve ser orientada a objetos,
com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de cada classe e um pequeno ]
programa (main) que as utilize para solucionar o problema apresentado.
Você deve tomar as decisões de projeto que achar adequada (definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do código.
Você deverá entregar o planejamento realizado (atividade manual) e o código desenvolvido (atividade prática)*/

#include <iostream>
using namespace std;

class Artista{
    private:
        string _nomeArtista;
        string _telefoneArtista;
        string _enderecoAtelie;
    public:
        string getNomeArtista(){return _nomeArtista;}
        string getTelefoneArtista(){return _telefoneArtista;}
        string getEnderecoAtelie(){return _enderecoAtelie;}
        Artista(string n, string t, string e){
            _nomeArtista = n;
            _telefoneArtista = t;
            _enderecoAtelie = e;
        }
};

class Entusiasta{
    private:
        string _nomeEntusiasta;
        string _nomeUltimaObra;
        int _valorUltimaObra;
        string _emailContato;

    public:
        string getNomeEntusiasta(){return _nomeEntusiasta;}
        string getNomeUltimaObra(){return _nomeUltimaObra;}
        void setNomeUltimaObra(string n){_nomeUltimaObra = n;}
        int getValorUltimaObra(){return _valorUltimaObra;}
        void setValorUltimaObra(int v){ _valorUltimaObra = v;}
        string getEmailContato(){ return _emailContato;}

        Entusiasta(string n, string e){
            _nomeEntusiasta = n;
            _emailContato = e;
        }
        Entusiasta(string n, string e, int v, string nObra){
            _nomeEntusiasta = n;
            _emailContato = e;
            _valorUltimaObra = v;
            _nomeUltimaObra = nObra;
        }

};

class Curador{
    private:
        int entusiastasCadastrados;
        int artistasCadastrados;
    public:
        Entusiasta* entusiastas;
        Artista* artistas;
        Curador(){
            artistas = new Artista[100];
            entusiastas = new Entusiasta[100];
        }
        void cadastrarArtista(){
            string nomeArtista;
            string telefoneArtista;
            string enderecoAtelie;
            cout << "NOME DO ARTISTA: " << endl;
            cin >> nomeArtista;
            cout << "TELEFONE DO ARTISTA: " << endl;
            cin >> telefoneArtista;
            cout << "ENDERECO DO ATELIE: " << endl;
            cin >> enderecoAtelie;

            Artista* artTemp = new Artista(nomeArtista, string telefoneArtista, string enderecoAtelie);
        }

};

int main(){
    
    return 0;
}