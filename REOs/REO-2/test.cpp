#include <iostream>
#include <cmath>
using namespace std;

class Ponto{
    private:
        int _x;
        int _y;
    public:
        Ponto(int x, int y){
            cout << this << endl;
            this->_x = x;
            this->_y = y;
            cout << this->_x;
            cout << endl;
            cout << this->_y;
        }
        ~Ponto(){
            cout << "DESTRUI PONTO" << endl;
        }
};

int main(){
    Ponto* pt1 = new Ponto(5,4);
    int x = ceil(2.25);
    cout << x;
    delete pt1;
    return 0;
}