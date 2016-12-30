#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class Juego;

class Entidad
{
    public:
        Entidad(string nombre, int x, int y);
        virtual void procesar_evento(sf::Event) = 0;
        virtual void accion(Juego&) = 0;
        virtual void pintar(sf::RenderWindow&) = 0;
        bool vivir();
        void matar();

    protected:
        sf::Texture text;
        sf::Sprite  sprite;

    private:
        bool esta_vivo;
};

#endif // ENTIDAD_H
