#include <iostream>
using namespace std;

class Ponto{
    private:
        int x;
        int y;
    public:
        Ponto(int _x, int _y){
            cout << "CONSTRUTOR COM PARAMETRO" << endl;
            x = _x;
            y = _y;
        }
        Ponto(Ponto &pt){
            cout << "CONSTRUTOR DE COPIA" << endl;
            x = pt.x;
            y = pt.y;
        }
        Ponto(){
            cout << "CONSTRUTOR SEM PARAMETRO" << endl;
            x = 0;
            y = 0;
        }
        void mostrarPontos(){
            cout << "ENDERECO " << this << endl;
            cout << "MOSTRAR PONTOS DA CLASSE" << endl;
            cout << "X: " << x << " ";
            cout << "Y: " << y;
            cout << endl;
        }
        friend void mostrarPontosExterno(Ponto pt);
};

void mostrarPontosExterno(Ponto pt){
    cout << "ENDERECO " << &pt << endl;
    cout << "MOSTRAR PONTOS DA FUNCAO EXTERNA" << endl;
    cout << "X: " << pt.x << " ";
    cout << "Y: " << pt.y;
    cout << endl;
}

int main(){
    Ponto pt1;
    Ponto p2(1,1);
    pt1.mostrarPontos();
    cout << "ENDERECO " << &pt1 << endl;
    mostrarPontosExterno(pt1);


    return 0;
}