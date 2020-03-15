/*Faça um programa que abra um arquivo de texto chamado "Meu_Arquivo.txt" e conta o numero de caracteres não brancos nele. Escreva o resultado da contagem na saída padrão.else

Entrada:
    1. O arquvio de texto "Meu_Arquivo.txt"

Saída:
    1. Número de caracteres não brancos dentro do arquivo.

Exemplo de arquivo:

    Vou aproveitar os exercicios do dredd para estudar muito e tirar 100 em IALG!!

Exemplo de saída:

    65
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char TextoASerTestado[200];
    int NU_Espacos = 0;
    char k;

    ofstream MeuArquivo("Meu_Arquivo.txt");
    cin.getline(TextoASerTestado,200);
    
    MeuArquivo << TextoASerTestado;
    MeuArquivo.close();

    ifstream MeuArq("Meu_Arquivo.txt");

    while (MeuArq >> k)
        NU_Espacos++;
        
    cout << NU_Espacos;
}