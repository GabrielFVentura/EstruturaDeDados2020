/*____________________________________________________________________________________
|                                                                                   |
|                                                                                   |
|                        Estruturas de Dados, 2020/2                                |
|                                                                                   |
|                                                                                   |
|                    Solução de: GABRIEL FRANCO VENTURA SANTOS                      |
|                                                                                   |
|                                                                                   |
|___________________________________________________________________________________|/*

using namespace std;
#include <iostream>

class Animal{
    private:
        int NumeroPatas;
        string NomeAnimal;
        int* ptrNumeroPatas;
        string* ptrNomeAnimal;
    public:
        Animal(string n,int p){
            NomeAnimal = n;
            NumeroPatas = p;
            ptrNomeAnimal = &NomeAnimal;
        };
        void setNumeroPatas(int numero){
            NumeroPatas = numero;
        }
        int getNumeroPatas(){
            return NumeroPatas;
        }
        string getNomeAnimal(){
            return NomeAnimal;
        }
        string* getPtrNomeAnimal(){
            return ptrNomeAnimal;
        }
};

int main(){
    Animal AnimalUm("zebra",4);

    Animal AnimalDois("cavalo",4);
    AnimalDois.setNumeroPatas(4);
    
    string Nome = "Gabriel";
    string* ptrNome = &Nome; 

    Animal* ptrAnimal;
    ptrAnimal = &AnimalUm;

    Animal* ptrAnimal2;
    ptrAnimal2 = &AnimalDois;

    // cout << "Nome " << Nome << endl;
    // cout << "Memoria " << &Nome << endl;
    // cout << "Memoria 2 " << ptrNome << endl;
    // cout << "Nome pelo Ponteiro " << *ptrNome << endl;

    cout << "Animal 1 " << ptrAnimal->getNomeAnimal() << endl;
    cout << "Animal 1 Numero Patas " << ptrAnimal->getNumeroPatas() << endl;
    cout << "Ponteiro Nome Animal 1 " << ptrAnimal->getPtrNomeAnimal() << endl;

    cout << "Animal 2 " << ptrAnimal2->getNomeAnimal() << endl;
    cout << "Animal 2 Numero Patas " << ptrAnimal2->getNumeroPatas() << endl;
    cout << "Ponteiro Nome Animal 2 " << ptrAnimal2->getPtrNomeAnimal() << endl;

    // cout << AnimalUm.getNomeAnimal();


    return 0;
}