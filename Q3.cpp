/*Elabore um programa que preencha uma matriz 10 x 10 com números inteiros, execute cada operação de troca especificada a seguir na matriz original e mostre cada matriz resultante. Você vai precisar de ao menos uma matriz extra para realizar as operações.
Operações de troca a serem realizadas (considerando índices que começam em 1):
1    a linha 2 com a linha 8;
2   a coluna 4 com a coluna 10;
3   a diagonal principal com a diagonal secundária;
4   a linha 5 com a coluna 10.
1.
[linha][coluna]*/

using namespace std;
#include <iostream>


int main()
{
	int n[10][10];
	
	for (int i = 0;i<10;i++)
	{
		for (int j = 0;j<10;j++)
		{
			cin >> n[i][j];
		}
		cout << endl;
	}
	//#1 a linha 2 com a linha 8;
		for (int i = 0;i<10;i++)
		{
			for (int j = 0;j<10;j++)
			{
				if (i == 1)
					cout << n[1][j] << " ";
				else if (i == 7)
					cout << n[7][j] << " ";
				else
					cout << n[i][j] << " ";
			}
		cout << endl;
		}
	//#2 a coluna 4 com a coluna 10;
		cout << endl;
		for (int i = 0;i<10;i++)
		{
			for (int j = 0;j<10;j++)
			{
				if (j == 3)
					cout << n[i][9] << " ";
				else if (j == 9)
					cout << n[i][3] << " ";
				else
					cout << n[i][j] << " ";
			}
		cout << endl;
		}
	//#3 a diagonal principal com a diagonal secundaria
		cout << endl;
		int m = 9;
		for (int i = 0;i<10;i++)
		{
			for (int j = 0;j<10;j++)
			{
				if (i == j)
				{
					cout << n[m][m] << " ";
					m--;
				}
				else
				{
				cout << n[i][j] << " ";
				}
			}
		cout << endl;
		}
		
}
