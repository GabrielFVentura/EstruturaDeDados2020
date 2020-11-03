/*Faça um programa para ler vários números de um arquivo texto. Não se sabe de antemão quantos números existem no arquivo, é necessário ler até o arquivo acabar. Cada dois números consecutivos no arquivo devem ser transformados num único número pela média dos dois. Se houver quantidade ímpar de números, o último deve permanecer inalterado.

Depois do processamento, os valores devem ser escritos na saída padrão em ordem inversa.

Não é permitido criar vetores na pilha (vetores que não são alocados dinamicamente).

Procure separar o processamento e as operações de entrada/saída, pela criação de ao menos um subprograma. Um bom planejamento dos subprogramas e das passagens de parâmetros é parte da avaliação.

Entradas:

O nome do arquivo com números (não terá mais que 80 caracteres, não terá espaços).
Vários números reais (conteúdo do arquivo). Sabe-se que não há possibilidade de existirem mais do que 200 valores e que cada valor estará numa linha do arquivo.
Saídas:

Os números reduzidos, na ordem inversa do cálculo.
Exemplo de Entrada (entrada padrão):

numeros.txt
Exemplo de Entrada (arquivo numeros.txt):

2.3
8.1
5.2
-1.1
3.14
Exemplo de Saída:

3.14 2.05 5.2
Observe que a média dos dois primeiros números é 5.2, dos dois outros é 2.05 e o último (3.14) permanece inalterado. Esse valores são escritos em ordem inversa.*/
