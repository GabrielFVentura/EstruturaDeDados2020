/*Faça um programa que receba oito números inteiros e os armazene de forma ordenada em um vetor. 
 * Ou seja, assim que lidos, os números já devem ser inseridos no vetor em uma posição que mantém a ordem crescente. 
 * Eles não podem ser inseridos no final do vetor para o vetor passar por uma ordenação.

Cada vez que um número for colocado no vetor o programa deve exibir os números inseridos até então.*/

/*if (arrayDeNumeros[i-1] > inputNumero)
			{
			arrayDeNumeros[i] = arrayDeNumeros[i-1];
			arrayDeNumeros[i-1] = inputNumero;
			}
			
						if (arrayDeNumeros[i-1] > inputNumero)
			{
				for (int j = 8 ;j > 0;j--)
				{
					arrayDeNumeros[j-1] = arrayDeNumeros[j];
				}
				arrayDeNumeros[i] = inputNumero;
			}
			else
				arrayDeNumeros[i] = inputNumero;*/

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
		else
		{
			if (inputNumero < arrayDeNumeros[i-1] && i < 2)
			{
				arrayDeNumeros[i] = arrayDeNumeros[i-1];
				arrayDeNumeros[i-1] = inputNumero;
			}
			else
			{
				if (inputNumero < arrayDeNumeros[i])
					arrayDeNumeros[i+1] = arrayDeNumeros[i];
					
				else
				{
					arrayDeNumeros[i+1] = arrayDeNumeros[i+2];
					arrayDeNumeros[i] = inputNumero;
				}
			}
		}
		for (int j = 0; j <= i; j++)
		cout << arrayDeNumeros[j] << " ";
		
		cout << endl;
	}
}
