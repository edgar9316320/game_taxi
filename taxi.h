#ifndef TAXI_H
#define TAXI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <random>

using namespace sf;

class taxi
{
    private:

      bool dirr{false};

      RenderWindow window;
      Event evee, evento_main;

      bool isPlay{true};
      int fps;
      //variables de TEXTO
      Font fuente1;
      Text txt_titulo;

      CircleShape shape;
      //obstaculos
      RectangleShape obs[8];
      int i=0;
      //variables de prueba

      void inic();

      void eventos();
      void update();
      void render();

      void cleared();
      

    public:
      taxi();
      void run();
      void mover(int a,int b);

};

#endif
