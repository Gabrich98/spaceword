#include "Juego.h"
#include "Bala.h"
#include "Nave.h"
#include "AST.h"
#include <string>
#include <sstream>



using namespace std;


void Juego::game_over(){

    sf::Texture bg_t;
    bg_t.loadFromFile("game_over.png");

   sf::Sprite bg;
    bg.setPosition(0,0);
    bg.setTexture(bg_t);
    bg.setScale(0.8, 0.8);
    window.clear();
    for(int i=1000;i<0;i--){
    window.draw(bg);
    window.display();
    }

}

template <typename T>
std::string to_string(T pNumber)
{
 std::ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

Juego::Juego(sf::RenderWindow& window) : window(window)
{
    puntaje=10;
    for (int i=0; i<15; i++) {
        AST_V.push_back(new AST());
    }
    fuente.loadFromFile("letra.ttf");


}



void Juego::disparar(sf::Vector2f v){
    balas.push_back(new Bala(v));

}

void Juego::loop()
{

    sf::Texture bg_t;
    bg_t.loadFromFile("fondo.jpg");
    sf::Sprite bg;

    bg.setPosition(0,0);
    bg.setTexture(bg_t);
    bg.setScale(0.9, 0.9);
    sf::Text txt;
    sf::Text txt1;
    txt.setFont(fuente);
    txt.setString(cadena);
    txt.setCharacterSize(24);
    txt.setPosition(32,40);;
  // run the program as long as the window is open
    while (window.isOpen())
    {
        cadena="SALUD: "+to_string(nave.mostrar_vidas());
        txt.setString(cadena);
             // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            nave.procesar_evento(event);



            /**/

        }



        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
            if (!(*i)->vivir()) {
                    delete *i;
                    i = AST_V.erase(i);
                    AST_V.push_back(new AST());
            }
        }
        for(ibalas i=balas.begin(); i!=balas.end();i++){
            if (!(*i)->vivir()) {
                delete *i;
                i = balas.erase(i);
            }

        }


        nave.accion(*this);
         for(ibalas i=balas.begin(); i!=balas.end();i++){
            (*i)->accion(*this);
        }



        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
            (*i)->accion(*this);
        }

       // clear the window with black colorç
        window.clear(sf::Color::Black);

        window.draw(bg);


        nave.pintar(window);
          for(ibalas i=balas.begin(); i!=balas.end();i++){
            (*i)->pintar(window);
        }
        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
            (*i)->pintar(window);
        }




        if(nave.mostrar_vidas()==0){
            return game_over();

        }
        puntaje=puntaje+20;
        window.draw(txt);
        // end the current frame
        window.display();

    }

}

AST* Juego::colision_con_asteroide(sf::FloatRect l){
        for(iast i=AST_V.begin(); i!=AST_V.end();i++){
                if((*i)->devolver_cuadrado().intersects(l)){
                    return *i;
                }
            }
        return NULL;
}

AST* Juego::colision_con_nave(sf::FloatRect n){
        for(iast i=AST_V.begin();i!=AST_V.end();i++){
            if((*i)->devolver_cuadrado().intersects(n)){
                return *i;
            }

        }
    return NULL;
}
