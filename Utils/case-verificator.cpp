#include <iostream>
#include <cstring>
#include <bits/stdc++.h> 
using namespace std;

bool verificarLowerCaseInput(string str, string vStr){
    transform(str.begin(), str.end(), str.begin(), ::tolower); 
    transform(vStr.begin(), vStr.end(), vStr.begin(), ::tolower); 
    return (str == vStr);
}

string textoCaseInput(string str, string vStr){
    return verificarLowerCaseInput(str,vStr) ? "string iguais" : "string diferente";
}

int main(){

    cout << textoCaseInput("sim","SiM") << endl;
    cout << textoCaseInput("sim","SiMS") << endl;

    return 0;
}