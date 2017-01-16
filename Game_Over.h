#ifndef GAME_OVER_H
#define GAME_OVER_H
#include <SFML/Graphics.hpp>
#include <Juego.h>


class Game_Over
{
    public:
        Game_Over(sf::RenderWindow& w);
        void game_o(Juego j);

    protected:

    private:
        sf::RenderWindow& w;
        sf::Texture fondo;
        sf::Sprite s;
        sf::Font fuente;
        sf::Text t;
};

#endif // GAME_OVER_H
