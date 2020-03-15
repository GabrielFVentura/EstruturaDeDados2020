/*Faça um programa para receber nove números inteiros positivos, armazená-los em um vetor, 
 * calcular e exibir no dispositivo de saída padrão aqueles números que são primos e suas 
 * respectivas posições no vetor. Se nenhum número primo for fornecido, nenhuma mensagem precisará 
 * ser exibida.*/
/*#cout << endl << EhPrimo[i] << " " << ArrayDeNumeros[i];*/

#include <iostream>
using namespace std;

int main()
{
	int ArrayDeNumeros[9];
	int inputNumero = 0;
	int numeroDeDivisores = 0;

	for (int i = 0;i < 9;i++)
	{
		cin >> inputNumero;
		ArrayDeNumeros[i] = inputNumero;
	}
	
	for (int i = 0; i < 9; i++)
	{
		for (int div = 1; div <= ArrayDeNumeros[i]; div++)
		{	
			if (ArrayDeNumeros[i]%div == 0)
			{
				numeroDeDivisores++;
			}
		}
			if (numeroDeDivisores == 2)
			{
				cout << ArrayDeNumeros[i] << " " << i << endl;
			}
			numeroDeDivisores = 0;
	}
}
