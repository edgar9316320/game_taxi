#include <iostream>
#include <graphalgorithms.H>
#include <string>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

//using mgra = Digraph<RectangleShape, string>;
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
  shape.setFillColor(Color(144, 148, 151));

  //obstaculos
  obs[0].setSize(Vector2f(200,100));
  obs[0].setFillColor(Color(255, 87, 51));

  obs[1].setSize(Vector2f(200,100));
  obs[1].setFillColor(Color(86, 101, 115));

  obs[2].setSize(Vector2f(100,230));
  obs[2].setFillColor(Color(255, 87, 51));

  obs[3].setSize(Vector2f(50,150));
  obs[3].setFillColor(Color(86, 101, 115));

  obs[4].setSize(Vector2f(100,150));
  obs[4].setFillColor(Color(255, 87, 51));

  obs[5].setSize(Vector2f(200,50));
  obs[5].setFillColor(Color(86, 101, 115));
  obs[6].setSize(Vector2f(125,90));
  obs[7].setSize(Vector2f(125,90));

  obs[0].setPosition(50 ,100);
  obs[1].setPosition(300,100);
  obs[2].setPosition(550,100);
  obs[3].setPosition(700,100);

  obs[4].setPosition(50,250);
  obs[5].setPosition(200,250);

  obs[6].setPosition(600,680);
  obs[7].setPosition(600,280);

  // set a 10-pixel wide orange outline
  shape.setOutlineThickness(10);
  shape.setOutlineColor(sf::Color(144, 148, 151,80));
  

}


void taxi::eventos()
{
    while (window.pollEvent(evee))
    {
      if (evee.type == Event::Closed)
          isPlay = false;



      //if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::D)
        //  shape.move(5,0);

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          shape.move(-5, 0);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          shape.move(5, 0);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          shape.move(0, 5);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          shape.move(0, -5);
      
      /*if (evee.type == Event::KeyReleased && evee.key.code == Keyboard::Space)
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
          atras = false;*/


    }
    
}



void taxi::update()
{

  //---------------------------------------------------------



  
}



void taxi::render()
{
  window.clear(sf::Color(244,246,246));



  window.draw(shape);
  
  for (int i = 0; i < 8; ++i)
  {
    /* code */
    window.draw(obs[i]);
  }
  
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
