/*Faça um programa que receba oito números inteiros e os armazene de forma ordenada em um vetor. 
 * Ou seja, assim que lidos, os números já devem ser inseridos no vetor em uma posição que mantém a ordem crescente. 
 * Eles não podem ser inseridos no final do vetor para o vetor passar por uma ordenação.
Cada vez que um número for colocado no vetor o programa deve exibir os números inseridos até então.*/

int EhMaior(int [], int N2)
{
	return 1;
}

#include <iostream>
using namespace std;

int main()
{
	int arrayDeNumeros[8];
	int inputNumero;
	
	for (int i = 0; i < 8; i++)
	{
		cin >> inputNumero;
		
		if (i == 0)
			arrayDeNumeros[i] = inputNumero;
			
		if (i == 1 && arrayDeNumeros[0] > inputNumero)
		{
			arrayDeNumeros[1] = arrayDeNumeros[0];
			arrayDeNumeros[0] = inputNumero;
		}
		
		else
		{
			if (arrayDeNumeros[i-1] > inputNumero)
			{
				arrayDeNumeros[i] = arrayDeNumeros[i-1];
				arrayDeNumeros[i-1] = inputNumero;
			}
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (arrayDeNumeros[j] > inputNumero)
					{
						arrayDeNumeros[j+2] = arrayDeNumeros[j+1];
						arrayDeNumeros[j+1] = arrayDeNumeros[j];
						arrayDeNumeros[j] = inputNumero;
					}
				}
			}
		}
		for (int j = 0; j <= i; j++)
		cout << arrayDeNumeros[j] << " ";
		
		cout << endl;
	}
}
