/*
De acordo com a geometria básica, podemos definir três figuras simples: um círculo, 
* um triângulo e um retângulo. A dimensão de um círculo é basicamente representada pelo seu raio, 
* um retângulo necessita de dois parâmetros, base e altura, e um triângulo é representado por três valores,
*  um para cada um de seus lados. Munido dessas informações, pode-se calcular o perímetro e a área de qualquer 
* uma dessas figuras citadas utilizando o método matemático correto.

Faça um programa que, referente a essas 3 figuras geométricas, receba as informações de 5 figuras 
* quaisquer do usuário, sendo que cada figura será composta pelo tipo dela (adotando uma nomenclatura 
* 'C' 'R' 'T' para identificá-las) além de, de acordo com a figura indicada, receber os parâmetros geométricos 
* que as representam (suas dimensões). Por fim, exibir o nome, a área e o perímetro de cada uma dessas 5 figuras 
* fornecidas pelo usuário.

Obs.: As figura devem ser identificadas por um caracter da seguinte maneira:

    'C' = Círculo (parâmetro: raio)
    'R' = Retângulo (parâmetros: base e altura)
    'T' = Triângulo (parâmetros: 3 lados - podendo ser diferentes)

Obs.: Para o valor de PI utilize a constante M_PI disponível na biblioteca cmath.

Sugestão: O cálculo da área de um triângulo pode ser feito através do Teorema de Herão.

Entrada:

    Um caracter representando o tipo da figura geométrica.
    Os valores de suas dimensões (raio, lado, etc.) em ponto flutuante (float).

Saída:

    Nome da figura geométrica.
    Perímetro da figura.
    Área da figura.

Exemplo de entrada:

	C 5
	C 2
	T 3 4 5
	R 5 10
	R 2 2
	*/
#include <iostream>
#include <math.h>
using namespace std;
	
	
class Circulo{
		public:
		float CalcularArea(){return raio*raio*M_PI;};
		float CalcularPerimetro(){ return (2*M_PI*raio);};
		Circulo(int r){ raio = r;};
			
		private:
		int raio;
		
};

class Retangulo{
	public:
		float CalcularArea(){return x*y;};
		float CalcularPerimetro(){return (2*x)+(2*y);};
		Retangulo(int init_x, int init_y)
		{
			x = init_x, 
			y = init_y;
		};
	private:
		int x;
		int y;
};

class Triangulo{
	public:
		float CalcularArea(){return sqrt(p(x,y,z)*(p(x,y,z)-x)*(p(x,y,z)-y)*(p(x,y,z)-z));};
		float CalcularPerimetro(){return x+y+z;};
		Triangulo(int init_x, int init_y, int init_z)
		{ 
			x = init_x,
			y = init_y,
			z = init_z;
		}
	private:
		float p(int x,int y,int z){return (x+y+z)/2;};
		int x,y,z;
};
	
int main(){
	int n;
	int x,y,z;
	char c;
	for (int i = 0; i < 5; i++)
	{
		cin >> c;
		if (c == 'C')
		{
			cin >> n;
			Circulo Circ(n);
			cout << "Circulo" << " " << Circ.CalcularPerimetro() << " " << Circ.CalcularArea() << " "  << endl;
		}
		if (c == 'T')
		{
			cin >> x >> y >> z;
			Triangulo Tri(x,y,z);
			cout << "Triangulo" << " " << Tri.CalcularPerimetro() << " " << Tri.CalcularArea() << " " << endl;			
		}
		if (c == 'R')
		{
			cin >> x >> y;
			Retangulo Ret(x,y);
			cout << "Retangulo" << " " << Ret.CalcularPerimetro() << " " << Ret.CalcularArea() << " "  << endl;
		}
		else
			cout << "Por favor insire uma das letras ('C','T','R') e seus respectivos valores" << endl;
	}			
	return 0;
}
