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
      RectangleShape obs[15];
      RectangleShape lineas_v[20];
      RectangleShape lineas_h[20];
      int i=0;
      //variables de prueba

      //texturas------
      Texture t_home;
      Sprite s_home;

      void inic();

      void eventos();
      void update();
      void render();

      void cleared();
      

    public:
      taxi();
      void run();
      void mover_h(int a,int b);
      void mover_v(int a,int b);

};

#endif
