/*
Na teoria de sistemas define-se como elemento minimax de uma matriz o menor 
* elemento da linha onde se encontra o maior elemento da matriz. Escreva um programa 
* que receba uma matriz quadrada de inteiros, 10x10, e retorne seu elemento minimax, 
* seguido de sua posição. Em caso de números iguais considere o que aparece primeiro.

Entradas:

    Um matriz de inteiros de tamanho 10x10.

Saídas:

O menor elemento da linha que tem o maior elemento da matriz.
A linha e a coluna onde está o elemento do item anterior.*/


#include <iostream>
using namespace std;

int main()
{
	int matriz[10][10];
	
	int maior;
	int posMaior_i = 0;
		
	int menor;
	int posMenor_i = 0;
	int posMenor_j = 0;
	
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> matriz[i][j];
		}
	}
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (matriz[i][j] > maior)
			{
				maior = matriz[i][j];
				posMaior_i = i;
			}
		}
	}
	for (int j = 0;j < 10; j++)
	{
		if (matriz[posMaior_i][j] < menor)
		{
			posMenor_i = posMaior_i;
			posMenor_j = j;
		}
		menor = matriz[posMaior_i][posMenor_j];
	}
	menor = matriz[posMaior_i][posMenor_j];
	cout << menor << endl;
	cout << posMenor_i << " " << posMenor_j << endl;
}
