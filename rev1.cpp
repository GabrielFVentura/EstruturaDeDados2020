#include <iostream>
using namespace std;

class Ponto{
    private:
        int x;
        int y;
    public:
        Ponto* ptrPt;
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        Ponto(int _x,int _y){
            x = _x;
            y = _y;
        }
};


int main(){
    string nome = "Gabriel";
    string* ptrNome = &nome;
    int anos = 18;
    int* ptrAnos = &anos;
    
    cout << nome << endl;
    cout << ptrNome << endl;
    cout << anos << endl;
    cout << ptrAnos << endl;    

    Ponto p1(2,3);
    Ponto* ptrPonto = &p1;
    Ponto* ptrPonto2;

    cout << "X: " << p1.getX() << endl;
    cout <<"Y: " << p1.getY() << endl;

    cout << "ptr X:" << ptrPonto->getX() << endl;
    cout << "ptr Y:" << ptrPonto->getY() << endl;
    return 0;
}