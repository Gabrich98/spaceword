#include "Entidad.h"

Entidad::Entidad(string nombre, int x, int y)
{
    esta_vivo=true;
    text.loadFromFile(nombre);
    sprite.setTexture(text);

    sprite.setPosition(x,y);
}

bool Entidad::vivir(){
    return esta_vivo;
}
void Entidad::matar(){
    esta_vivo=false;
}
