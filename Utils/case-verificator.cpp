#include <iostream>
#include <cstring>
#include <bits/stdc++.h> 
using namespace std;

bool verificarLowerCaseInput(string str, string vStr){
    transform(str.begin(), str.end(), str.begin(), ::tolower); 
    transform(vStr.begin(), vStr.end(), vStr.begin(), ::tolower); 
    return (str == vStr);
}

bool verificarUpperCaseInput(string str, string vStr){
    transform(str.begin(), str.end(), str.begin(), ::toupper); 
    transform(vStr.begin(), vStr.end(), vStr.begin(), ::toupper); 
    return (str == vStr);
}

string textoCaseInput(string str, string vStr,bool lowercase = false){
    if (lowercase){
        return verificarLowerCaseInput(str,vStr) ? "string iguais" : "string diferente";
    }
    return verificarUpperCaseInput(str,vStr) ? "string iguais" : "string diferente";
}

int main(){

    cout << textoCaseInput("SIM","SiM") << endl;
    cout << textoCaseInput("sim","SiMS",true) << endl;

    return 0;
}