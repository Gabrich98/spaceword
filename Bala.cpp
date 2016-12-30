#include "Bala.h"
#include "Juego.h"
Bala::Bala(sf::Vector2f& pos_ini):Entidad("bala.png", pos_ini.x, pos_ini.y)
{

    sprite.setPosition(pos_ini);
            //ctor
}
//void Bala::matar(){
//    esta_viva=false;
//}


void Bala::procesar_evento(sf::Event){}

//comparacion de colisiones
void Bala::accion(Juego& j){

    AST* a = j.colision_con_asteroide(sprite.getGlobalBounds());
    if(a != NULL){
        a->matar();
        matar();
    }
    sprite.move(0, -5);
}

void Bala::pintar(sf::RenderWindow& w){
      w.draw(sprite);
}
