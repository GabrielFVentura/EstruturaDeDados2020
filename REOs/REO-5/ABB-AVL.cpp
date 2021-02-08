#include <chrono>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std; 
using namespace std::chrono;

typedef int Dado;

class NohABB{
    friend class ABB;
        public:
            NohABB(Dado v){
                valor = v;
                pai = NULL;
                filhoDireito = NULL;
                filhoEsquerdo = NULL;
            }
            ~NohABB(){
                delete filhoEsquerdo;
                delete filhoDireito;
            }
            void PrintNoh(){
                cout << "VALOR DO NOH: " << valor << endl;
                if (pai != NULL){
                    cout << "VALOR PAI: " << pai->valor << endl;
                }
                else {
                    cout << "SEM PAI" << endl;
                }
                if (filhoDireito != NULL){
                    cout << "VALOR FILHO DIREITO: " << filhoDireito->valor << endl;
                }
                else {
                    cout << "SEM FILHO A DIREITA" << endl;
                }
                if (filhoEsquerdo != NULL){
                    cout << "VALOR FILHO ESQUERDO: " << filhoEsquerdo->valor << endl;
                }
                else {
                    cout << "SEM FILHO A ESQUERDA " << endl;
                }
                cout << endl;
            }
        private:
            NohABB* pai;
            NohABB* filhoEsquerdo;
            NohABB* filhoDireito;
            Dado valor;
};

class ABB {
    private:
        NohABB* raiz;
    public:
        ABB(){
            raiz = NULL;
        }
        ~ABB(){
            delete raiz;
        }
        void Inserir(Dado d){
            int nohCount = 0;
            NohABB* novoNoh = new NohABB(d);
            if (raiz == NULL){
                raiz = novoNoh;
                nohCount++;
            } else {
                NohABB* atual = raiz;
                NohABB* anterior;
                while (atual != NULL){
                    anterior = atual;
                    if (atual->valor > d){
                        atual = atual->filhoEsquerdo;
                    } else {
                        atual = atual->filhoDireito;
                    }
                    novoNoh->pai = anterior;
                    nohCount++;
                }
                if (anterior->valor > d){
                        anterior->filhoEsquerdo = novoNoh;
                    } else {
                        anterior->filhoDireito = novoNoh;
                    }
                }
                // cout << "NUMEROS DE NOHs PERCORRIDOS: " << nohCount << endl;
            }
        void Remover(Dado d){

        }
        NohABB* Buscar(Dado d){
            NohABB* atual = raiz;
            int count = 0;
            while (atual != NULL){
                if (atual->valor == d){
                    cout << "[ABB] NUMERO DE NOHs PERCORRIDOS: " << count << endl;
                    return atual;
                } else if (atual->valor > d){
                    atual = atual->filhoEsquerdo;
                } else {
                    atual = atual->filhoDireito;
                }
                count++;
            }
            
            cout << "[ABB] VALOR NAO ENCONTRADO NUMERO DE NOHs PERCORRIDOS: " << count << endl;
            return atual;
        }
        void PercorrerEmOrdem(NohABB *nohRaiz){
            NohABB *atual = nohRaiz;
            if (atual != NULL){
                PercorrerEmOrdem(atual->filhoEsquerdo);
                cout << '[' << atual->valor << ']' << " ";
                PercorrerEmOrdem(atual->filhoDireito);
            }
        }

        void Print(){
            cout << "ABB: " << endl;
            PercorrerEmOrdem(raiz);
            cout << endl;
        }

        void InserirBulk (int count, Dado v[]){
            for (int i = 0; i < count; i++){
                Inserir(v[i]);
            }
        }

        void BuscarDadosNoh(Dado d){
            NohABB* noh = Buscar(d);
            noh->PrintNoh();
        }
};

class NohAVL{
    friend class AVL;
    public:
            NohAVL(Dado v){
                valor = v;
                altura = 0;
                pai = NULL;
                filhoDireito = NULL;
                filhoEsquerdo = NULL;
            }
            ~NohAVL(){
                delete filhoEsquerdo;
                delete filhoDireito;
            }
            void PrintNoh(){
                cout << "VALOR DO NOH: " << valor << endl;
                if (pai != NULL){
                    cout << "VALOR PAI: " << pai->valor << endl;
                }
                else {
                    cout << "SEM PAI" << endl;
                }
                if (filhoDireito != NULL){
                    cout << "VALOR FILHO DIREITO: " << filhoDireito->valor << endl;
                }
                else {
                    cout << "SEM FILHO A DIREITA" << endl;
                }
                if (filhoEsquerdo != NULL){
                    cout << "VALOR FILHO ESQUERDO: " << filhoEsquerdo->valor << endl;
                }
                else {
                    cout << "SEM FILHO A ESQUERDA " << endl;
                }
                cout << "ALTURA: " << altura << endl;
                cout << endl;
            }
        private:
            NohAVL* pai;
            NohAVL* filhoEsquerdo;
            NohAVL* filhoDireito;
            int altura;
            Dado valor;
};

class AVL{
    private:
        NohAVL* raiz;
    public:
        AVL(){
            raiz = NULL;
        }

        ~AVL(){
            delete raiz;
        }

        int CalcularAltura(NohAVL* noh){
            if (noh == NULL){
                return 0;
            } else {
                return noh->altura;
            }
        }

        void AtualizarAltura(NohAVL* noh){
            int alturaEsquerda = CalcularAltura(noh->filhoEsquerdo);
            int alturaDireita = CalcularAltura(noh->filhoDireito);
            noh->altura = max(alturaEsquerda, alturaDireita) + 1;
            // cout << " MAX: " << max(alturaEsquerda, alturaDireita);
            // cout << " ALT ESQ: " << alturaEsquerda << " ALT DIR: " << alturaDireita;
            // cout << " ALTURA: " << noh->altura << endl;
        }

        int FatorBalanceamento(NohAVL* noh){
            int alturaEsquerda = CalcularAltura(noh->filhoEsquerdo);
            int alturaDireita = CalcularAltura(noh->filhoDireito);
            int fatorBalanceamento = alturaEsquerda - alturaDireita;
            return fatorBalanceamento;
        }

        NohAVL* RotacaoEsquerda(NohAVL* noh){
            NohAVL* nohAux = noh->filhoDireito;
            noh->filhoDireito = nohAux->filhoEsquerdo;
            if (nohAux->filhoEsquerdo != NULL){
                nohAux->filhoEsquerdo->pai = noh;
            } 
            nohAux->pai = noh->pai;
            if (noh == raiz){
                raiz = nohAux;
            } else if (noh == noh->pai->filhoEsquerdo){
                noh->pai->filhoEsquerdo = nohAux;
            } else {
                noh->pai->filhoDireito = nohAux;
            } 
            nohAux->filhoEsquerdo = noh;
            noh->pai = nohAux;
            
            AtualizarAltura(noh);
            AtualizarAltura(nohAux);

            return nohAux;
        }

        NohAVL* RotacaoDireita(NohAVL* noh){
            NohAVL* nohAux = noh->filhoEsquerdo;
            noh->filhoEsquerdo = nohAux->filhoDireito;
            if (nohAux->filhoDireito != NULL){
                nohAux->filhoDireito->pai = noh;
            }
            nohAux->pai = noh->pai;
            if (noh == raiz){
                raiz = nohAux;
            } else if (noh == noh->pai->filhoEsquerdo){
                noh->pai->filhoEsquerdo = nohAux;
            } else {
                noh->pai->filhoDireito = nohAux;
            }
            nohAux->filhoDireito = noh;
            noh->pai = nohAux;

            AtualizarAltura(noh);
            AtualizarAltura(nohAux);

            return nohAux;
        }

        NohAVL* RotacaoEsquerdaDireita(NohAVL* noh){
            noh->filhoEsquerdo = RotacaoEsquerda(noh->filhoEsquerdo);
            return RotacaoDireita(noh);
        }

        NohAVL* RotacaoDireitaEsquerda(NohAVL* noh){
            noh->filhoDireito = RotacaoDireita(noh->filhoDireito);
            return RotacaoEsquerda(noh);
        }

        void Inserir(Dado v){
            raiz = InserirRecursivamenteAuxiliar(raiz, v);
        }

        NohAVL* InserirRecursivamenteAuxiliar(NohAVL* noh, Dado valorInserido, NohAVL* nohAnterior = NULL){
            NohAVL* novoNoh = new NohAVL(valorInserido);
            if (noh == NULL){
                novoNoh->pai = nohAnterior;
                return novoNoh;
            } else {
                if (valorInserido < noh->valor){
                    noh->filhoEsquerdo = InserirRecursivamenteAuxiliar(noh->filhoEsquerdo, valorInserido, noh);
                    // noh->PrintNoh();
                } else {
                    noh->filhoDireito = InserirRecursivamenteAuxiliar(noh->filhoDireito, valorInserido, noh);
                    // noh->PrintNoh();
                }
            }
            return ArrumarBalanceamento(noh);
        }

        NohAVL* ArrumarBalanceamento(NohAVL* noh){
            if (noh == NULL){
                return noh;
            }
            AtualizarAltura(noh);
            int fatorBalanceamento = FatorBalanceamento(noh);
            if ((fatorBalanceamento >= -1) && (fatorBalanceamento <= 1)){
                return noh;
            }
            if ((fatorBalanceamento > 1) && FatorBalanceamento(noh->filhoEsquerdo) >= 0){
                return RotacaoDireita(noh);
            }
            if ((fatorBalanceamento > 1) && FatorBalanceamento(noh->filhoEsquerdo) < 0){
                return RotacaoEsquerdaDireita(noh);
            }
            if ((fatorBalanceamento < -1) && FatorBalanceamento(noh->filhoDireito) <= 0){
                return RotacaoEsquerda(noh);
            }
            if ((fatorBalanceamento < -1) && FatorBalanceamento(noh->filhoDireito) > 0){
                return RotacaoDireitaEsquerda(noh);
            }
            return noh;
        }

        void InserirBulk (int count, Dado v[]){
            for (int i = 0; i < count; i++){
                Inserir(v[i]);
                // cout << "INSERI :" << v[i] << endl;
            }
        }

        void PercorrerEmOrdem(NohAVL *nohRaiz){
            NohAVL *atual = nohRaiz;
            if (atual != NULL){
                PercorrerEmOrdem(atual->filhoEsquerdo);
                cout << '[' << atual->valor << ']' << " ";
                PercorrerEmOrdem(atual->filhoDireito);
            }
        }

        void Print(){
            cout << "AVL: " << endl;
            PercorrerEmOrdem(raiz);
            cout << endl;
        }

        NohAVL* Buscar(Dado d){
            NohAVL* atual = raiz;
            int count = 0;
            while (atual != NULL){
                if (atual->valor == d){
                    cout << "[AVL] NUMERO DE NOHs PERCORRIDOS: " << count << endl;
                    // atual->PrintNoh();
                    return atual;
                } else if (atual->valor > d) {
                    atual = atual->filhoEsquerdo;
                } else {
                    atual = atual->filhoDireito;
                }
                count++;
            }
            cout << "[AVL] VALOR NAO ENCONTRADO NUMERO DE NOHs PERCORRIDOS: " << count << endl;
            return atual;
        }

        void BuscarDadosNoh(Dado d){
            NohAVL* noh = Buscar(d);
            noh->PrintNoh();
        }

};

// void Chrono(ABB &abb, int c){
//     auto start = system_clock::now();
    
//     abb.Inserir(c);
//     auto stop = system_clock::now();

//     auto duration = duration_cast<microseconds>(stop - start);

//     cout << "DURACAO:" << duration.count() << endl;
// }

int main(){
    ABB ABB;
    AVL AVL;
    Dado v[] = 
    {25,42,13,64,43,4,21,2,35,11,15,57,45,97,86,39,41,38,5,23,17,87,65,77,40,7,12,66,29,100,1,62,20,30,10,27,26,59,61,99,19,22};

    char operacao;
    Dado d;

    // auto start = high_resolution_clock::now(); 
    // auto stop = high_resolution_clock::now();     
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;     

    ABB.InserirBulk(40,v);
    AVL.InserirBulk(40,v);

    do {
            cout << "'b' : BUSCAR VALOR NAS ARVORES" << endl;
            cout << "'p' : EXIBIR EMORDEM OS VALORES INSERIDOS NAS ARVORES " << endl;
            cin >> operacao;
            switch (operacao) {
            case 'b':
                cout << "VALOR A SER BUSCADO NAS ARVORES: " << endl;
                cin >> d;
                ABB.Buscar(d);
                AVL.Buscar(d);
                break;
            case 'p':                     // Levantamento por cultivar e marca
                ABB.Print();
                AVL.Print();
                break;
            default:
                cout << "Comando invalido!\n";
            }
        } while (operacao != 'f');
    return 0;
}