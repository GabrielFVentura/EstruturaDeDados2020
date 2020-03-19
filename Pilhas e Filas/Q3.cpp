/*Em Linguagens Formais e Autômatos um reconhecedor é um meio formal de verificar se uma dada sentença pertence ou não a uma determinada linguagem. Pilhas são estruturas usadas com frequência em reconhecedores.

Uma linguagem pode ser definida com um subconjunto de S*, a partir de um alfabeto S, onde S é um conjunto finito, não vazio, de símbolos. Considere o alfabeto S = {A,B,C} e a linguagem L = {Ai B C2i B Ai | i > 0}, ou seja, as sequências ABCCBA, AABCCCCBAA, AAABCCCCCCBAAA são todas pertencentes ao conjunto de sentenças válidas de L. Faça um programa baseado em pilhas que, dada uma sequência w de caracteres A, B e C, verifique se w faz parte ou não do conjunto de sentenças de L.

O processamento deve ser interrompido assim que for possível dizer se w faz parte ou não do conjunto. Por exemplo, se o segundo B for encontrado antes de todos os Cs serem encontrados, já é possível dar a resposta sem processar os As.

Ao final, o programa deve escrever se o padrão da linguagem foi reconhecido e os tamanhos das pilhas.

Você pode usar uma implementação de pilha da biblioteca padrão ou usar uma implementação feita anteriormente. Não é permitido o uso de métodos na classe pilha que sejam específicos para este problema.

Sugestão: Usando duas pilhas, seu programa deve ler As e a cada A lido, empilhar um A numa e dois Cs na outra. Após ler um B, o programa adota a seguinte estratégia: a cada C lido, desempilhar um C. Finalmente, depois do segundo B, cada A lido faz com que um A seja desempilhado. Ao final da iteração, a sentença foi reconhecida se todas as letras foram processadas e todos os desempilhamentos foram bem sucedidos e se as duas pilhas estão vazias.

Entradas:

Palavra a ser verificada.
Saídas:

A palavra sim ou nao (sem acento), indicando se a sentença foi reconhecida.
O tamanho da pilha de As.
O tamanho da pilha de Cs.
Exemplo de Entrada:

AABCCCCBAA
Exemplo de Saída:

sim 0 0
Exemplo de Entrada:

AABCCCCAA
Exemplo de Saída:

nao 2 0
Exemplo de Entrada:

AABCCCBAA
Exemplo de Saída:

nao 2 1*/