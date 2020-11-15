#include <iostream>
using namespace std;

class Ponto{
    private:
        int x;
        int y;
    public:
    Ponto(int _x,int _y){
        x = _x;
        y = _y;
    };
    Ponto(int _x){
        x = _x;
    }
    Ponto(Ponto& pt){
        x = pt.x;
        y = pt.y;
    }
};

int main(){
    string nome = "gabriel";
    string* ptrNome = &nome;

    string* Nomes = new string[5];

    int capacidade = 5;
    for (int i = 0 ; i < 5; i++){
        Nomes[i] = "abc";
    }

    capacidade = 2 * 5;
    string* NomesTemp = new string[capacidade];

    for (int i = 0; i < 5; i++){
        NomesTemp[i] = Nomes[i];
    }

    cout << "ANTES: " << &Nomes << " " << &NomesTemp;
    Nomes = NomesTemp;
    cout << "DPS: " <<  &Nomes << " " << &NomesTemp;
    for (int i = 0; i<5;i++){
        cout << NomesTemp[i] << " ";
    }

    // for (int i = 0; i < 10; i++){
    //     cout << Nomes[i] << " ";
    // }

    cout << "VARIAVEL " << nome << endl;
    cout << "ENDERECO DA VARIAVEL " <<  ptrNome << endl;
    cout << "NOME ARMAZENADO "  << *ptrNome << endl;
    cout << sizeof(string) << endl;

    Ponto pt1(2,2);

    cout << sizeof(Ponto) << endl;

    return 0;
}