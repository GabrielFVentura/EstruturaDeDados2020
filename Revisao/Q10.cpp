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
    string TextoASerTestado;
    ofstream MeuArquivo("Meu_Arquivo.txt");
    cin >> TextoASerTestado;

    MeuArquivo << "Vou aproveitar os exercicios do dredd para estudar muito e tirar 100 em IALG!!";

    MeuArquivo.close();

}