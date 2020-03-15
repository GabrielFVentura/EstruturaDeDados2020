/*Faça um programa que transpõe uma matriz. Transpor uma matriz significa 
 * trocar as linhas pelas colunas da matriz. Escrever a matriz transposta é suficiente,
 *  não sendo necessário criar antes uma matriz transposta.

Entradas:

    o número de linhas da matriz e o número de colunas da matriz, na mesma linha
    os elementos da matriz (números inteiros).

Saídas: O programa deverá escrever a matriz transposta.*/

using namespace std;
#include <iostream>

int main()
{
	int NU_LINHA,NU_COL;
	cin >> NU_LINHA >> NU_COL;
	int matriz[NU_LINHA][NU_COL];
	
	for (int i = 0; i < NU_LINHA; i++)
	{
		for (int j = 0; j < NU_COL; j++)
		{
			cin >> matriz[i][j];
		}
	}
	
	for (int i = 0; i < NU_COL ; i++)
	{
		for (int j = 0; j < NU_LINHA; j++)
		{
			cout << matriz[j][i] << " ";
		}
		cout << endl;
	}
}
