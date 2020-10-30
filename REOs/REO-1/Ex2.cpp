/*Enunciado 2
Depois de muito tempo trabalhando com tecnologia e sistemas computacionais Morgana conseguiu se mudar para uma pequena chácara no interior e passou a cultivar flores, 
hortaliças e frutas. Agora ela levanta com o raiar do Sol e pára suas atividades ao entardecer. Entretanto, para facilitar um pouco seu trabalho, ela decidiu cadastrar
todas as espécies que cultiva, registrando o nome, período de plantio e tempo de produção. Em seguida, passou a registrar os nomes dos fornecedores de cada um dos
produtos que utiliza - sementes, ferramentas, insumos, etc. registrando o nome do fornecedor, o produto de interesse e o telefone de contato.
Agora ela pode registrar novas espécies de cultivo, pode registrar novos fornecedores e pode buscar por todos os fornecedores de um determinado produto.
Analise a descrição acima, identifique quais são as entidades a serem tratadas como classes, quais os atributos de cada uma delas e qual o comportamento esperado
(os métodos) de cada entidade. Com base nesse planejamento feito, implemente uma solução para esse problema. Sua implementação deve ser orientada a objetos,
com a definição de cada uma das classes, utilizando as diretivas de visibilidade adequadas, os métodos que representem o comportamento de cada classe e um pequeno
programa (main) que as utilize para solucionar o problema apresentado.
Você deve tomar as decisões de projeto que achar adequada (definição de tamanho de arranjos, tipo da variável, etc.) e indicar essas decisões no cabeçalho do código.
Você deverá entregar o planejamento realizado (atividade manual) e o código desenvolvido (atividade prática)*/

#include <iostream>
using namespace std;

int main(){

    int* arr = new int[5];

    for (int i = 0; i < 5; i++){
        *(arr+i) = i+2;
        cout << arr[i] << endl;
    }

    return 0;
}