#ifndef TAXI_H
#define TAXI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <random>

#include <graphalgorithms.H>

using namespace Designar;

using namespace sf;
using namespace std;

using nodog = tuple<RectangleShape, int>;
using mgra = Graph<nodog,lint_t>;


class taxi
{
    private:

      bool dirr{false}, reso{true};

       String ncamino;
       Path<mgra> path;

      RenderWindow window;
      Event evee, evento_main;

      bool isPlay{true};
      int fps;
      //variables de TEXTO
      Font fuente1;
      Text txt_titulo, txt_camino;


      CircleShape shape;
      //obstaculos
      RectangleShape obs[15];
      RectangleShape lineas_v[20];
      RectangleShape lineas_h[20];



      int inter=0;
      //grafo

      mgra grafo, auxgraf;
      mgra::Node * gn[20];
      int ii=0;

      RectangleShape g_paradas[20], aux[20];
      nodog auxg[20];
      Text g_des[20];

      int na = 0;


    bool vari{false};

      //texturas------
      Texture t_home, t_obs_1, t_pasajero, t_destino;
      Sprite s_home, s_obs_1, s_pasajero, s_destino;

      void inic();

      void eventos();
      void update();
      void render();

      void cleared();
      

      int u = 0, otra=0;
        int grilla[12][16];
    public:
      taxi();
      void run();
      void mover_h(int a,int b);
      void mover_v(int a,int b);

};

#endif
