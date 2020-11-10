#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

string converte(float valor)
{
	ostringstream aux;  // Declara o string stream de saída chamado aux
	aux << "Exemplo de saida em string ";  // Escreve em aux
	aux << fixed << setprecision(10) << sqrt(valor); // idem
	return aux.str(); // Retorna a string resultante a partir do stream aux
}

int main()
{
	float v;
	cout << "Digite o valor: ";
	cin >> v;
	cout << converte(v);
}