/*____________________________________________________________________________________
|                                                                                   |
|                                                                                   |
|                        Estruturas de Dados, 2020/2                                |
|                                                                                   |
|                                                                                   |
|                    Solução de: GABRIEL FRANCO VENTURA SANTOS                      |
|                                                                                   |
|                                                                                   |
|___________________________________________________________________________________|
*/

#include <iostream>
using namespace std;

int Func(int x){
    return x;
}

int Func(int x, int y){
    return x+y;
}

int Func(int x,int y, int z){
    return x+y+z;
}

string Func(string s){
    return s;
}


string Func(string s1,string s2){
    return s1+s2;
}

class Ponto{
    private:
        int x;
        int y;
    public:
        Ponto(int i = 0,int j = 0){
            x = i;
            y = j;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
        Ponto operator+(Ponto &ponto){
            return Ponto(x + ponto.x, y + ponto.y);
        }
        // ++i
        Ponto operator++(){} 
         // i++
        Ponto operator++(int){
            Ponto ponto;
            ponto.x = x++;
            ponto.y = y++;
            return ponto;
        }
        friend ostream& operator<<(ostream& os, Ponto &ponto){
            os << "X :" << ponto.x << " " << "Y :" << ponto.y;
        }
    
};

int main(){

    cout << Func(1) << endl;
    cout << Func(1,2) << endl;
    cout << Func(1,2,3) << endl;
    cout << Func("10") << endl;
    cout << Func("10","10") << endl;
    
    Ponto lf(1,3);    
    Ponto ls(4,5);

    cout << "PONTO X: " << lf.getX() << " PONTO Y :" << lf.getY() << endl;
    lf++;
    cout << "PONTO X: " << lf.getX() << " PONTO Y :" << lf.getY() << endl;

    Ponto el = lf+ls;
    cout << "PONTO X: " << el.getX() << " PONTO Y :" << el.getY() << endl;

    cout << el << endl;

    return 0;
}