#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Nave.h"
#include "AST.h"
#include "Bala.h"
#include <vector>
#include <list>
#include "Entidad.h"
using namespace std;
class Juego
{
    public:
        Juego(sf::RenderWindow&);
        void loop();
        void disparar(sf::Vector2f);
        AST* colision_con_asteroide(sf::FloatRect);
        AST* colision_con_nave(sf::FloatRect);
        void game_over();
        bool vivo;


    protected:

    private:
        int contador;
        string cadena;
        int puntaje;
        Nave nave;
        sf::RenderWindow& window;
        void pintar(sf::RenderWindow&);
        sf::Font fuente;
        typedef list<Bala*>::iterator ibalas;
        list<Bala*> balas;
        typedef list <AST*>::iterator iast;
        list<AST*> AST_V;

        /*
            void cargar_highscores();
            void ugardar_highscores();
        public:
            void sumar_puntaje(int );
            void terminar_partida();

            void guardar_archivo() {
            ostream archivo("perro.dat");

            //archivo.read((char*)&high_score, sizeof(int));
            archivo.write((char*)&high_score, sizeof(int));
            }
        */


};




#endif // JUEGO_H
