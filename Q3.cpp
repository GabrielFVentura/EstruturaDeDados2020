/*Elabore um programa que preencha uma matriz 10 x 10 com números inteiros, execute cada operação de troca especificada a seguir na matriz original e mostre cada matriz resultante. Você vai precisar de ao menos uma matriz extra para realizar as operações.

Operações de troca a serem realizadas (considerando índices que começam em 1):

    a linha 2 com a linha 8;
    a coluna 4 com a coluna 10;
    a diagonal principal com a diagonal secundária;
    a linha 5 com a coluna 10.*/
using namespace std;
#include <iostream>


int main()
{
	for (int i = 0;i<10;i++)
	{
		for (int j = 0; j<10;j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}
