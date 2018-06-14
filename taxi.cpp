#include <iostream>
# include <graphalgorithms.H>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

const int TAM_HOR = 800, TAM_VER = 600, radioo = 15;

taxi::taxi():window{VideoMode{TAM_HOR,TAM_VER},"taxi"}
{

}

void taxi::inic()
{



  fps = 60;
  window.setPosition(Vector2i(100,100));
  //para que el juego corra a 60 frame en todas las pcs
  window.setFramerateLimit(fps);
  //al dejar apretado un boton no se repita
  window.setKeyRepeatEnabled(true);
  //Para que parpadee lo menos posible
  window.setVerticalSyncEnabled(true);

//-----------------------------------------------------------
//CARGA DE IMAGENES

  shape.setRadius(10);
  shape.setPosition(10, 50);
  shape.setFillColor(Color(246, 246, 246));

  // set a 10-pixel wide orange outline
  shape.setOutlineThickness(10);
  shape.setOutlineColor(sf::Color(246, 246, 246,80));
  
}


void taxi::eventos()
{
  /*  while (window.pollEvent(evee))
    {
      if (evee.type == Event::Closed)
          isPlay = false;



      if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::W)
          jump = true;

      if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::Space)
          patear = true;

      //----Caminar hacia adelante-----------------
      if (evee.type == Event::KeyPressed && evee.key.code == Keyboard::D)
          caminar = true;
      if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::D)
          caminar = false;

      //----Caminar hacia atras-----------------
      if (evee.type == Event::KeyPressed && evee.key.code == Keyboard::A)
          atras = true;
      if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::A)
          atras = false;


    }
    */
}



void taxi::update()
{

  //---------------------------------------------------------



  
}



void taxi::render()
{
  window.clear(sf::Color(130,130,130));



  window.draw(shape);
  

  window.display();

}

void taxi::cleared()
{

  window.close();
}

void taxi::run()
{

  inic();



      while (isPlay)
      {
        //tiempo = reloj1.getElapsedTime();

        //if (tiempo.asSeconds() > (1/fps))
        //{
     
          eventos();
          update();

          render();
        
        //}

      }





  cleared();
}
