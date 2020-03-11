/*Crie um programa que preencha uma primeira matriz de ordem 4 x 5 e 
uma segunda matriz 5 x 2. O programa deverá, também, calcular e mostrar a
matriz resultante do produto matricial das duas matrizes anteriores, armazenando-o 
em uma terceira matriz de ordem 4 x 2.

Entrada:

    Uma matriz 4 x 5.
    Uma matriz 5 x 2.

Saída:

    Matriz 4 x 2 resultante do produto entre as duas matrizes anteriores.
*/
using namespace std;
#include <iostream>

int main()
{
	int MatrizUm[4][5];
	int MatrizDois[5][2];
	int MatrizR[4][2];
	
	for (int i = 0;i<4;i++)
	{
		for (int j = 0;j<5;j++)
		{
			cin >> MatrizUm[i][j];
		}
	}
	for (int i = 0;i<5;i++)
	{
		for (int j = 0;j<2;j++)
		{
			cin >> MatrizDois[i][j];
		}
	}
	int m = 0;
	int n = 0;
	for (int i = 0;i<4;i++)
	{
		for (int j = 0;j<5;j++)
		{
			MatrizR[m][n] += MatrizUm[i][j] * MatrizDois[j][i];
			m++;
		}
		n++;
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << MatrizR[i][j] << " ";
		}
	}
	/*
	for (int i = 0;i<4;i++)
	{
		for (int j = 0;j<5;j++)
		{
			cout << MatrizUm[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0;i<5;i++)
	{
		for (int j = 0;j<2;j++)
		{
			cout << MatrizDois[i][j] << " ";
		}
		cout << endl;
	}*/
}
