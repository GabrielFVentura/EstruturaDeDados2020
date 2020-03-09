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
//7 3 4 6 2 9 0 1
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
			for (int j = 0; j <= i-1; j++)
			{
				if (arrayDeNumeros[j] > inputNumero)
				{
					arrayDeNumeros[j+1] = arrayDeNumeros[j];
					arrayDeNumeros[j] = inputNumero;
				}
				//TODO VERIFICAR INSERÇÔES NO COMECO E NO FIM
			}
		}
		for (int j = 0; j <= i; j++)
		cout << arrayDeNumeros[j] << " ";
		
		cout << endl;
	}
}
