/*
Um homem decidiu aproveitar um espaço existente em uma das ruas do bairro em que mora para estacionar carros e complementar sua renda oferecendo o serviço de vallet. Para aumentar a renda, o homem estaciona os carros em 45o, o que não permite que um carro sai do estacionamento sem que os carros estacionados à sua frente também tenham que sair. O serviço oferecido tem sido bem sucedido e ele decidiu contratá-lo para implementar um aplicativo que simule a operação do estacionamento de modo que ele saiba quantos carros terá que deslocar para que um determinado carro possa ser removido. Os carros deslocados são conduzidos por uma rua paralela e depois estacionados novamente.

Defina a estrutura de dados adequada para simular o funcionamento do negócio e implemente essa estrutura (não é permitido o uso da STL ou similares). Lembrando-se que você deve respeitar as regras da estrutura para acesso aos dados, implemente:

o método que permita simular a operação de estacionar (E);
o método que permita simular a operação de retirar um carro do estacionamento (D);
o método que permita ao dono do negócio saber quantos carros foram removidos para a retirada de um determinado carro e imprima a configuração do estacionamento após a remoção.
a execução é encerrada quando a opção de saída é selecionada (S);
Os carros estacionados são caracterizados pela sua placa. Para executar uma operação, o usuário deve indicar a operação desejada e informar a placa do carro. Caso seja solicitada a operação de retirado de um carro e este não seja encontrado no estacionamento, deve ser emitida a mensagem "NAO ENCONTRADO". Sempre que um carro é retirado, deve ser impresso o número de carros retirados e a nova configuração do estacionamento.
Entradas:

Conjunto de operações de estacionar e retirar carros do estacionamento
Saídas:

Número de carros retirados.
Configuração dos carros no estacionamento a cada retirada do carro desejado.




/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/

Entrada

E abc1234
E def4567
E poi0987
E zxc5687
D poi0987
D abc1234
S
Exemplo de Saída:

3
zxc5687
abc1234
def4567
2
def4567
zxc5687
Entrada

D poi0987
E abc1234
E def4567
E zxc5687
D abc1234
S
Exemplo de Saída:

NAO ENCONTRADO
1
def4567
zxc5687
Entrada

E VFT1010
D VFT1010
S
Exemplo de Saída:

1

*/

#include <iostream>
#include <string>

using namespace std;

class Noh{
    friend class Fila;
    string placa;
    Noh* NohProximo;
    Noh(string pl){
        placa = pl;
        NohProximo = NULL;
    }
};

class Fila{
    private:
        int tamanho;
        Noh* primeiroNoh;
        Noh* ultimoNoh;
    public:
        Fila(){
            tamanho = 0;
            primeiroNoh = NULL;
            ultimoNoh = NULL;
        }
    
        bool filaVazia(){
            return tamanho == 0;
        }
        void enfileira(string pl){
            Noh* novoNoh = new Noh(pl);
            if (tamanho == 0){
                primeiroNoh = novoNoh;
                ultimoNoh = novoNoh;
            } else {
                ultimoNoh->NohProximo = novoNoh;
                ultimoNoh = novoNoh;
            }
            tamanho++;
        }
        string desinfileira(){
            string ValorRetornado;
            if (filaVazia()){
                ValorRetornado = "FILA VAZIA";
            } else {
                Noh* nohTemp = primeiroNoh;
                ValorRetornado = nohTemp->placa;
                primeiroNoh = primeiroNoh->NohProximo;
                delete nohTemp;
                tamanho--;
            }
            return ValorRetornado;
        }

        void procurarCarroPorPlaca(string pl){
            Fila filaAux;
            string placaRemovida;
            int carrosRemovidos = 0;
            int indiceResp = 0;
            if (filaVazia()){
                cout << "NAO ENCONTRADO" << endl;
            } else {
                while(!filaVazia()){
                    placaRemovida = desinfileira();
                    carrosRemovidos++;
                    if (placaRemovida == pl){
                        indiceResp = carrosRemovidos;
                    } else {
                        filaAux.enfileira(placaRemovida);
                    }
                }
                string placas[carrosRemovidos];
                int numeroPlacas = 0;
                string placaInfileirada;
                if (indiceResp == 0){
                    cout << "NAO ENCONTRADO" << endl;
                } else {
                    cout << indiceResp;
                }
                while (!filaAux.filaVazia()){
                    placaInfileirada = filaAux.desinfileira();
                    placas[numeroPlacas] = placaInfileirada;
                    numeroPlacas++;
                    this->enfileira(placaInfileirada);
                }
                for (int i = numeroPlacas; i > -1; i--){
                    cout << placas[i] << endl;
                }
            }
        }
};

int main(){
    Fila filaCarros;
    char opt;
    do
    {
        cin >> opt;
        switch (opt){
        case 'E':{
            string placaEnfileirada;
            cin >> placaEnfileirada;
            filaCarros.enfileira(placaEnfileirada);
            break;
        }
        case 'D':{
            string placaRemovida;
            cin >> placaRemovida;
            filaCarros.procurarCarroPorPlaca(placaRemovida);
            break;
        }
        default:
            break;
        }
    } while (opt != 'S');
    


    return 0;
}