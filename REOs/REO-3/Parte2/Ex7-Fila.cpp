/*
Uma nova copiadora irá abrir na sua cidade. Você foi contratado para fazer o programa que gerencia as senhas de utilização dos serviços. As instruções passadas a você são: existem dois tipos de senha, as prioritárias e as normais; as senhas são chamadas de modo a serem chamadas 3 prioritárias para então uma normal. Não havendo prioridades, as pessoas com senha normal podem ser atendidas normalmente. Sempre que um atendimento normal for realizado, os próximos três devem ser prioritários, se possível. Se estiver na hora de realizar um atendimento de cliente normal mas não houver nenhum cliente normal, deve ser chamado um nome do atendimento preferencial, se houver.

Este é um problema de uso de fila. Você deverá usar uma estrutura de dados do tipo fila, sendo que a classe fila não deve conter nenhum método que tenha características do problema. Em outras palavras, a classe fila não pode ter mecanismos indevidos de acessos a seus dados. Também não é permitido o uso da STL ou similares.

O programa deve ler comandos representados por palavras e seus respectivos argumentos assim:

O comando "normal" seguido de um nome (sem espaços) representa retirada de uma senha normal.
O comando "prioridade" seguido de um nome (sem espaços) representa retirada de uma senha prioritária.
O comando "atender" representa uma senha sendo chamada.
O comando "fim" solicita o fim da execução do programa.
Para cada comando de atendimento, o programa deverá escrever o nome da pessoa que deve ser atendida, de acordo com as regras de atendimento vistas. Caso não haja cliente a ser chamado, o programa deve escrever "AGUARDE" (letras maiúsculas). A cada atendimento normal, a contagem para prioritários deve ser reiniciada.

Entradas:

Sequência de comandos, seguindo as instruções acima.
Saídas:

Somente o comando "atender" gera saída, conforme instruções acima.
Exemplo de Entrada:

normal Abner
prioridade Ackson
normal Adilson
normal Adriana
normal Adriano
normal Adriel
prioridade Adrielle
atender
atender
atender
atender
prioridade Adriene
prioridade Adson
prioridade Afonso
prioridade Agatha
atender
atender
atender
atender
atender
fim
Exemplo de Saída:

Ackson
Adrielle
Abner
Adilson
Adriene
Adson
Afonso
Adriana
Agatha

/---------------------------------------------------------------------------------/

                 Atividade de  GCC216 - Estruturas de Dados, 2020

                    Solução de: GABRIEL FRANCO VENTURA SANTOS

/---------------------------------------------------------------------------------/
*/
#include <iostream>
#include <string>

using namespace std;

    class Noh {
        friend class Fila;
        private:
            string dado; // poderia ser outro tipo de variável
            Noh *proximo;
        public:
            Noh(string info){
                dado = info;
                proximo = NULL;
            }
            ~Noh(){
                proximo = NULL;
                delete proximo;
            }
    };

// fila dinamicamente encadeada
    class Fila {
    private:
        Noh* inicio;
        Noh* fim;
        int tamanho;
    
    public:
        Fila();
        ~Fila();
        void enfileira(string info);
        string desenfileira();
        bool estaVazia(); // verifica se existem elementos na fila     
};


Fila::Fila() {
    tamanho = 0;
    fim = NULL;
    inicio = NULL;
// IMPLEMENTE O CONSTRUTOR
}

Fila::~Fila() { 
    while (!estaVazia())
        desenfileira();
// IMPLEMENTE O DESTRUTOR

}


void Fila::enfileira(string info) {
    Noh* novoNoh = new Noh(info);
    if (estaVazia()){
        inicio = novoNoh;
        fim = novoNoh;
    } else {
        fim->proximo = novoNoh;
        fim = novoNoh;
    }
    tamanho++;
    //IMPLEMENTAR A INSERÇÃO DE UM ELEMENTO NA FILA
}

string Fila::desenfileira() {
    if (estaVazia())
        return "AGUARDE";
    else{
        Noh* nohTemp = inicio;
        string removido = nohTemp->dado;
        inicio = inicio->proximo;
        delete nohTemp;
        tamanho--;
        return removido;
    }
    
    //IMPLEMENTAR A RETIRADA DE UM ELEMENTO NA FILA
}
    
bool Fila::estaVazia() {
    return tamanho == 0;
    //IMPLEMENTAR A VERIFICAÇÃO SE A FILA ESTÁ VAZIA
}

int main() {
    Fila filaPrioritaria;
    Fila filaComum;
    string command = "";
    char c;
    int numeroAtendimentoPrioritario = 0;

    //IMPLEMENTAR PROGRAMA PARA CONTROLAR ATENDIMENTO

     do {
         cin >> command;
         if (command == "normal"){
             c = 0;
         } else if (command == "prioridade"){
             c = 1;
         } else if (command == "atender"){
             c = 2;
         } else {
             c = 3;
         }
         switch(c){
             case 0:{
                 string nome;
                 cin >> nome;
                 filaComum.enfileira(nome);
                 break;
             }
             case 1:{
                 string nome;
                 cin >> nome;
                 filaPrioritaria.enfileira(nome);
                 break;
             }
             case 2:{
                if (filaComum.estaVazia() && !filaPrioritaria.estaVazia()){
                    // cout << "FILA COMUM VAZIA E FILA PRIORITARIA NAO VAZIA" << endl;
                    cout << filaPrioritaria.desenfileira() << endl;
                } else if (filaPrioritaria.estaVazia()){
                    // cout << "FILA PRIORITARIA VAZIA" << endl;
                    cout << filaComum.desenfileira() << endl;
                    numeroAtendimentoPrioritario = 0;    
                } else if (numeroAtendimentoPrioritario < 3){
                    numeroAtendimentoPrioritario++;
                    cout << filaPrioritaria.desenfileira() << endl;
                    // cout << "NUMERO ATENDIMENTOS PRIORITARIOS: " << numeroAtendimentoPrioritario << endl;
                } else {
                    cout << filaComum.desenfileira() << endl;
                    numeroAtendimentoPrioritario = 0;    
                }
                 break; 
             }
             default:{
                 cerr << "Comando invalido" << endl;
             }
         }
     } while (c != 3);
}