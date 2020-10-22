#include <iostream>
#include <string>
using namespace std;

int somar(int x){
    return x;
}

int somar(int x, int y){
    return x+y;
}

int somar(int x, int y, int z){
    return x+y+z;
}

string somar(string s){
    return s;
}

string somar(string s1, string s2){
    return s1 + s2;
}

int main(){
    string r = "123";

    cout << somar(1) << endl;
    cout << somar(1,2) << endl;
    cout << somar(1,2,3) << endl;
    cout << somar("1") << endl;
    cout << somar("1","2") << endl;

    return 0;
}