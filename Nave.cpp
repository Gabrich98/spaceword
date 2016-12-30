#include "Nave.h"
#include "Juego.h"
#include "Bala.h"

Nave::Nave() : Entidad("nave_mov.png", 600, 600)
{
    vidas=3;
    salud=100;
    disparando = false;
    contador = 10;
    actual = NoMov;
    //ctor
}
void Nave::descontar_vidas(){
    vidas--;
}
int Nave::mostrar_vidas(){
        return vidas;
}
void Nave::descontar_salud(){
    salud=salud-20;
}

int Nave::mostrar_salud(){
    return salud;
}


/*sf::FloatRect Nave::devolver_cuadrado_nave(){
    return sprite.getGlobalBounds();

}*/

//Aca se programa el evento de los movimientos de la nave


void Nave::procesar_evento(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            actual = Izquierda;
            break;
        case sf::Keyboard::Right:
            actual = Derecha;
            break;
        case sf::Keyboard::Up:
            actual = Arriba;
            break;
        case sf::Keyboard::Down:
            actual = Abajo;
            break;
        default:
            break;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            if (actual == Izquierda) actual = NoMov;
            break;
        case sf::Keyboard::Right:
            if (actual == Derecha) actual = NoMov;
            break;
        case sf::Keyboard::Up:
            if (actual == Arriba) actual = NoMov;
            break;
        case sf::Keyboard::Down:
            if (actual == Abajo) actual = NoMov;
            break;
        default:
            break;
        }
    }

    if(event.type==sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Space)
        {
            disparando = true;
        }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            disparando = false;
        }
    }

}


void Nave::accion(Juego& j) {
        //comparar nave con asteroides
        AST* a = j.colision_con_nave(sprite.getGlobalBounds());

        if(a != NULL){
            a->matar();
            matar();
            descontar_salud();
            if (salud==0){
                descontar_vidas();
                salud=100;

            }

        }


        if(disparando){
            if (contador <= 0) {
                j.disparar(sprite.getPosition() + sf::Vector2f(text.getSize().x / 2-4, -50));
                contador = 10;
            }
            contador--;
        }
        switch (actual) {
            case Izquierda:
               if(sprite.getPosition().x>=3) sprite.move(-10, 0);
            break;
            case Derecha:
                if(sprite.getPosition().x<=1228)sprite.move(10, 0);
            break;
            case Arriba:
                if(sprite.getPosition().y>=3)sprite.move(0, -10);
            break;
            case Abajo:
                if(sprite.getPosition().y<=650)sprite.move(0, 10);
            break;
            case NoMov:

            break;
        }

}

void Nave::pintar(sf::RenderWindow& w) {

    //Este es para pintar la nave
    w.draw(sprite);
}
