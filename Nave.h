#ifndef NAVE_H
#define NAVE_H

#include <Entidad.h>
class Juego;

enum Movimiento {
        Izquierda,
        Derecha,
        Arriba,
        Abajo,
        NoMov
};

class Nave : public Entidad
{
    public:
        Nave();
        void procesar_evento(sf::Event);
        void accion(Juego&);
        void pintar(sf::RenderWindow&);
        void descontar_vidas();
        int mostrar_vidas();
        void descontar_salud();
        int mostrar_salud();

        //sf::FloatRect devolver_cuadrado_nave();
    protected:
    int contador;
    int vidas;
    int salud;
    private:
        bool disparando;
        Movimiento actual;
};

#endif // NAVE_H
