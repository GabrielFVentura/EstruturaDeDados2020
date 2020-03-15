/*Um grupo de atletas resolveu se preparar para correr a Corrida de São Silvestre. Para auxiliar na preparação, pretende-se guardar os dados de cada corredor e suas informações dos treinamentos. Com isso, espera-se levantar informações que possam ajudar os corredores a direcionarem seus treinamentos.

Faça um programa que receba o número de atletas do grupo e permita guardar os dados de cada corredor em um registro com as seguintes informações: código do atleta, primeiro nome, idade, peso e sexo (M para masculino e F para feminino). O programa deve também guardar os dados de treinamento sabendo-se que, em cada treino, cada atleta corre uma determinada distância e é medido o tempo gasto. Portanto, o programa deve ter um registro com: dia do treino (ignore mês e ano), código do atleta, distancia percorrida (km, real) e tempo gasto (minutos). Os dados dos treinamentos devem ser lidos até que um dia -1 seja digitado.

O programa deve exibir o nome e a distância total percorrida pelo atleta mais velho do sexo masculino, o nome e a idade do atleta que participou de mais dias de treino (em caso de empate, considerar o que encontrar primeiro) e o nome e o tempo médio diário de treino de cada atleta.

Obs.1: quando for digitado dia de valor -1 não serão digitados os valores dos demais campos.

Obs.2: considere que em cada dia existe apenas um registro de treino para cada atleta.

Entrada:

A quantidade de corredores a serem registrados.
Os dados de todos os corredores (código, nome, idade, peso e sexo).
Os dados de treinamento (dia, código, distância e tempo).
Saída:

O nome e a distância total percorrida pelo atleta mais velho do sexo masculino (se nenhum homem for registrado, exibir somente -1).
O nome e a idade do atleta que participou de mais dias de treino (em caso de empate, considerar o que encontrar primeiro).
O nome e o tempo médio diário de treino de cada atleta.
Exemplo de entrada:

	3
	1 Joao	30	80	M
	2 Maria	25	68	F
	3 Pedro	40	95	M
	1 1 10.4 30
	1 2 6.2 25
	1 3 8.0 36
	2 1 12.4 32
	2 2 7.1 27
	2 3 8.1 35
	3 1 12.0 30
	3 3 9.1 38
	-1
    
    Exemplo de saída:

	Pedro 25.2
	Joao 30
	Joao 30.6667
	Maria 26
	Pedro 36.3333*/