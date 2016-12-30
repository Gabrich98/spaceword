#include "AST.h"


AST::AST(/*int tam*/) : Entidad("ast.png", rand()%1366, rand()%50)
{
    vel=4 + rand()%4;
//constructor de asteroide
}

void AST::procesar_evento(sf::Event){


}

sf::FloatRect AST::devolver_cuadrado(){
    return sprite.getGlobalBounds();
}

void AST::accion(Juego&)
{
    sprite.move(0,vel);
    if (sprite.getPosition().y>768) sprite.setPosition(rand()%1366, rand()%100);
}

void AST::pintar(sf::RenderWindow& w)
{
    w.draw(sprite);
}
