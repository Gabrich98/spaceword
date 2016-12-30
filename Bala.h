#ifndef BALA_H
#define BALA_H

#include <Entidad.h>

class Juego;

class Bala : public Entidad
{
    public:
        Bala(sf::Vector2f& pos_ini);
        void procesar_evento(sf::Event);
        void accion(Juego&);
        void pintar(sf::RenderWindow&);


    protected:
        //Segundos que le quedan a la bala antes de ser destrihida
       // float seg_v;
       // bool b_viva;
    private:
};

#endif // BALA_H
