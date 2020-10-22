using namespace std;
#include <iostream>

class noh{
    private:
        int val;
    public:
        noh(int v){
            val = v;
        }
        noh* prox = NULL;
        int getValor(){
            return val;
        }
        void setValor(int n){
            val = n;
        }
        int getUltimoValorNoh(noh* no){
             if (no->prox != NULL){
                getUltimoValorNoh(no->prox);
             } else {
                return no->getValor();
             }
        }
        
        void IncrementarValoresNoh(noh* no){
            no->setValor(no->getValor()+1);
            
            cout << no->getValor() << endl;

            if (no->prox != NULL){
                IncrementarValoresNoh(no->prox);
            }
        }
};

int main(){
    noh no1(1);
    noh no2(2);
    noh no3(3);

    no1.prox = &no2;
    no2.prox = &no3;

    // cout << no1.getValor() << endl;
    // cout << no1.prox->getValor() << endl;

    // no1.prox->setValor(no1.prox->getValor()+2);
    // cout << no1.prox->getValor() << endl;

    // cout << no2.getValor() << endl;

    // cout << no1.prox->prox->getValor();

    // cout << no1.getUltimoValorNoh(&no1);

    no1.IncrementarValoresNoh(&no1);



    


}