/* Código base para estrutura de dados Fila
 * 
 * by Juliana Galvani Greghi
 *                                nov/2018
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