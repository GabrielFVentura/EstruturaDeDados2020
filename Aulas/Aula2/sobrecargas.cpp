#include <iostream>
#include <string>
using namespace std;

int Func(int x){
    return x;
}

int Func(int x, int y){
    return x+y;
}

int Func(int x, int y, int z){
    return x+y+z;
}

string Func(string s){
    return s;
}

string Func(string s1, string s2){
    return s1 + s2;
}

class Ponto {
    private:
        int x, y;
    public:
    Ponto(int i = 0, int j = 0){
        x = i;
        y = j;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    Ponto operator+ (Ponto &ponto){
        return Ponto(x + ponto.x, y + ponto.y);
    }

    friend ostream &operator <<(ostream& os, Ponto &pt){
        os << "X " << pt.x << " " << "Y " << pt.y;
        return os;
    }

    Ponto operator ++(int){
        Ponto temp;
        temp.x = x++;
        temp.y = y++;
        return temp;
    }
};

int main(){
    cout << Func(1) << endl;
    cout << Func(1,2) << endl;
    cout << Func(1,2,3) << endl;
    cout << Func("1") << endl;
    cout << Func("1","2") << endl;

    Ponto lf(1, 3);
    Ponto ls(4, 5);
    Ponto el = lf + ls;

    cout << el << endl;
    el++;
    cout << el << endl;
    
    return 0;
    return 0;
}