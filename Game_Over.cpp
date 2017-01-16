#include "Game_Over.h"

Game_Over::Game_Over(sf::RenderWindow& w) : w(w)
{
     fondo.loadFromFile("game_over.jpg");
     fuente.loadFromFile("letra.ttf");
    //ctor
}


void Game_Over::game_o(Juego j){

    t.setPosition(400,700);
    t.setCharacterSize(50);
    t.setString("RESTART --PRECIONE SPACE--");



    s.setPosition(0,0);
    s.setTexture(fondo);
    s.setScale(0.8, 0.8);

    while(w.isOpen()){

        w.draw(s);
        w.draw(t);
        w.display();
        sf::Event event;
        while (w.pollEvent(event))
        {
            if(event.type==sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space)
                {
                  return j.loop();                }
                }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::F1){}
            }
        }
    }
}

