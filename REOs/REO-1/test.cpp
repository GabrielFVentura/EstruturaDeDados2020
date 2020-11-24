#include <iostream>
#include <cstring>

using namespace std;

class Ponto{
    private:
        int _x;
        int _y;
    public:
        Ponto(int x, int y){
            _x = x;
            _y = y;
        }
        int getX(){ return _x;}
        int getY(){ return _y;}

        void operator =(Ponto *p){
            _x = p->_x;
            _y = p->_y;
        }
        friend ostream& operator<<(ostream& os, Ponto &p){
            os << "X: " << p.getX() << endl;
            os << "Y: " << p.getY() << endl;
        }
};

int main(){
    Ponto p1(1,1);
    Ponto p2(2,5);
    Ponto* ptrPonto = &p2;
    ptrPonto->getX()

    cout << "P1 X: " << p1.getX()<< endl;
    cout << "P1 Y: " << p1.getY()<< endl;

    cout << "P2 X: " << p2.getX()<< endl;
    cout << "P2 Y: " << p2.getY()<< endl;

    memcpy(&p1, &p2, sizeof(Ponto));

    cout << "P1 X: " << p1.getX()<< endl;
    cout << "P1 Y: " << p1.getY()<< endl;
    cout << "END MEMORIA P1:" << &p1 << endl;

    cout << "P2 X: " << p2.getX()<< endl;
    cout << "P2 Y: " << p2.getY()<< endl;
    cout << "END MEMORIA P2:" << &p2 << endl;

    Ponto p3 = p2;

    cout << "P3 X: " << p2.getX()<< endl;
    cout << "P3 Y: " << p2.getY()<< endl;
    cout << "END MEMORIA P3:" << &p3 << endl;

    cout << p3;

    return 0;
}