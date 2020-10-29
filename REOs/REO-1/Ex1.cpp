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
        void cadastrarOficinaLoja();
        void cadastrarAcordoParceria();
        void procurarMarcaPorOficinaLoja();

};






int main(){
    char command;
    Associacao associacao;
    Motoqueiro motoqueiro("Gabriel", "Suzuki", "GSX-750", "2020", "21972101291");
    // associacao.cadastrarMotoqueiro();
    cout << *associacao.getMotoqueirosCadastrados();
    cout << motoqueiro;

    do {
        switch (command)
        {
        case('c'):{
            break;
        }
        case('l'):{
            break;
        }
        case('e'):{
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