#include <iostream>
using namespace std;

class Ponto{
    private:
        int coordenadaX;
        int coordenadaY;
    public:
        int getCoordenadaX(){return coordenadaX;}
        int getCoordenadaY(){return coordenadaY;}
        Ponto(){
            cout << "CONSTRUTOR PADRAO" << endl;
            coordenadaX = 0;
            coordenadaY = 0;
        }
        Ponto(Ponto& pt){
            cout << "CONSTRUTOR DE COPIA" << endl;
            coordenadaX = pt.coordenadaX;
            coordenadaY = pt.coordenadaY;
        }
        Ponto(int x,int y){
            cout << "CONSTRUTOR COM PARAMETRO" << endl;
            coordenadaX = x;
            coordenadaY = y;
            
        }
};

class Mapa{
    public:
        Ponto* pontosRegistrados;
        int numeroPontos;
        Mapa(int n){
            pontosRegistrados = new Ponto[n];
        }
        friend void DisplayRegistrosPontos(Mapa* map);

};

void DisplayRegistrosPontos(Mapa* map){
    for (int i = 0; i < map->numeroPontos; i++){
        cout << "X :" << map->pontosRegistrados[i].getCoordenadaX() << "Y :" << map->pontosRegistrados[i].getCoordenadaY() << endl;
    }
} 

int main(){
    Mapa map(5);
    map.pontosRegistrados = new Ponto[5];
    map.pontosRegistrados[0] = Ponto();
    DisplayRegistrosPontos(&map);

    Ponto pt1();
    Ponto pt2(int x,int y);
    return 0;
}