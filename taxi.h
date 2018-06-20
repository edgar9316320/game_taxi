#ifndef TAXI_H
#define TAXI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string.h>
#include <random>
#include <math.h>

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

      float tiempo_carrera2, tiempo_carrera;
      bool isPlay{true};
      int fps, conteo_camino=0;
      //variables de TEXTO
      Font fuente1;
      Text txt_titulo, txt_camino, num_time, txt_d_gasolina, txt_puntuacion,num_puntuacion, txt_costo,num_costo;
      int puntuacion;
      float puntuacion_total=0;

      int cg[100], kl=1, kl2=0;

      CircleShape shape;
      //obstaculos
      RectangleShape obs[17], cam_taxi[17];
      RectangleShape lineas_v[20];
      RectangleShape lineas_h[20];

      bool aviso[17];


      int inter=0;
      //grafo

      mgra grafo, auxgraf;
      mgra::Node * gn[20], * mg[20];
      int ii=0;

      RectangleShape g_paradas[20], aux[20];
      nodog auxg[20];
      Text g_des[20];

      int na = 0;


    bool vari{false};

      //texturas------
      Texture t_home, t_obs_1, t_pasajero, t_destino, t_gasolinera;
      Sprite s_home, s_obs_1, s_pasajero, s_destino, s_gasolinera;

      //variables de texto
      int gasolina = 200;

      //variables de tiempo
      Clock reloj1, reloj2;
      Time tiempo, tiempo2;

      int timer,timer2, ti3=0;
      bool semovio;

      void inic();

      void eventos();
      void update();
      void render();

      void cleared();
      

      int u = 0, otra=0;
        
    public:
      taxi();
      void run();
      void mover_h(int a,int b);
      void mover_v(int a,int b);

};

#endif
