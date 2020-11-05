#include <iostream>
using namespace std;

class Ponto {
    private:
        int _x;
        int _y;
    public:
    Ponto(int x = 0, int y = 0){
        _x = x;
        _y = y;
    }

    int getX(){return _x;}
    int getY(){ return _y;}

    void setX(int x){ _x = x;}
    void setY(int y){ _y = y;}

    void incrementaX(){ _x++;}
    void incrementaY(){ _y++;}

    friend ostream &operator <<(ostream& os, Ponto &pt){
        os << "X " << pt.getX() << " " << "Y " << pt.getY();
        return os;
    }

    // ++i
    Ponto operator ++(); 

    // i++
    Ponto operator ++(int){
        Ponto temp;
        temp._x = _x++;
        temp._y = _y++;
        return temp;
    }

    // --i
    Ponto operator --(){}

    // i--
    Ponto operator --(int){
        Ponto temp;
        temp._x = _x--;
        temp._y = _y--;
        return temp;
    }

    Ponto operator +(Ponto &ponto){
        return Ponto(_x + ponto.getX(), _y + ponto.getY());
    }

    Ponto operator -(Ponto &ponto){
        return Ponto(_x - ponto.getX(), _y - ponto.getY());
    }

    Ponto operator *(Ponto &ponto){
        return Ponto(_x * ponto.getX(), _y * ponto.getY());
    }

    Ponto operator /(Ponto &ponto){
        return Ponto(_x / ponto.getX(), _y / ponto.getY());
    }

    Ponto operator %(Ponto &ponto){
        return Ponto(_x % ponto.getX(), _y % ponto.getY());
    }

    void operator =(Ponto *p){
            _x = p->_x;
            _y = p->_y;
    }
};

int main(){
    Ponto ponto1(1, 3);
    Ponto ponto2(4, 5);

    Ponto ponto3 = ponto1 + ponto2;
    cout << "PONTO 3 POS SOMA: " << ponto3 << endl;

    Ponto ponto4 = ponto3;
    cout << "PONTO 4 POS ATRIBUICAO: " << ponto4 << endl;

    cout << "PONTO 3: " << ponto3 << endl;
    ponto3++;
    cout << "PONTO 3 POS INCREMENTO: " << ponto3 << endl;

    cout << "PONTO 4: " << ponto4 << endl;
    ponto4--;
    cout << "PONTO 4 POS DECREMENTO: " << ponto4 << endl;

    ponto4 = ponto4 - ponto1;
    cout << "PONTO 4 POS SUBTRACAO: " << ponto4 << endl;

    Ponto ponto5 = ponto3*ponto4;
    cout << "PONTO 5 POS MULTIPLICACAO: " << ponto5 << endl;
    
    Ponto ponto6 = ponto2/ponto1;
    cout << "PONTO 6 POS DIVISAO: " <<  ponto6 << endl;

    Ponto ponto7 = ponto2%ponto1;
    cout << "PONTO 7 POS MODULO: " <<  ponto7 << endl;

    return 0;
}