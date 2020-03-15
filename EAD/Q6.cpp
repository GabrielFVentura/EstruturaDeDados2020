/*Faça um programa que guarda números num vetor dinâmico. Não se sabe quantos números deverão ser armazenados até que se saiba quais são os números.

A estratégia de alocação de memória deve ser a seguinte:

o vetor é criado inicialmente com capacidade 5,
conforme é feito o armazenamento de números no vetor, novos espaços de memória vão sendo alocados, sempre com 5 elementos a mais do que antes.
O programa deverá ler números inteiros positivos de um arquivo binário chamado dados.bin e depois da entrada padrão. O último número em cada entrada de dados será um número não positivo, indicando o fim dos números. Considera-se que o zero não é positivo, conforme pode ser visto no exemplo de entrada.

Ao final da entrada de dados, o programa deverá:

Escrever todos os números (não negativos) armazenados.
Escrever qual a capacidade atual do vetor.
Escrever o número de transformações (realocações na memória) necessárias.
Atualizar o arquivo, gravando as alterações (os valores devem ser escritos em formato binário.).
Exemplo de Entrada:

(dados.bin):

10 18 15 71 42 41 0
(entrada padrão):

20 18 35 14 13 0
Exemplo de Saída:

10 18 15 71 42 41 20 18 35 14 13 
15
2*/