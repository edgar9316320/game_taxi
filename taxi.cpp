#include <iostream>
#include <graphalgorithms.H>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

using mgra = Digraph<RectangleShape, Text>;

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
//
  shape.setRadius(10);
  shape.setPosition(10, 50);
  shape.setFillColor(Color(144, 148, 151));
  // linea de afuera de la pelota
  shape.setOutlineThickness(10);
  shape.setOutlineColor(sf::Color(144, 148, 151,80));

  //OBSTACULOS-----------------------------
  //colores
  obs[0].setFillColor(Color(255,  87, 51));
  obs[1].setFillColor(Color(86 , 101, 115));
  obs[2].setFillColor(Color(255,  87, 51));
  obs[3].setFillColor(Color(86 , 101, 115));
  obs[4].setFillColor(Color(255,  87, 51));
  obs[5].setFillColor(Color(86 , 101, 115));
  obs[6].setFillColor(Color(255,  87, 51));
  obs[7].setFillColor(Color(86 , 101, 115));


  //tamaños                X    Y
  obs[0].setSize(Vector2f(200, 100));
  obs[1].setSize(Vector2f(200, 100));
  obs[2].setSize(Vector2f(100, 230));
  obs[3].setSize(Vector2f(50 , 150));
  obs[4].setSize(Vector2f(100, 150));
  obs[5].setSize(Vector2f(200, 50));
  obs[6].setSize(Vector2f(125, 90));
  obs[7].setSize(Vector2f(125, 90));
  //Posiciones        X    Y
  obs[0].setPosition(50 , 100);
  obs[1].setPosition(300, 100);
  obs[2].setPosition(550, 100);
  obs[3].setPosition(700, 100);

  obs[4].setPosition(50 , 250);
  obs[5].setPosition(200, 250);
  obs[6].setPosition(400, 250);
  obs[7].setPosition(600, 350);
//---------------------------------------------------
  
  //TEXTO
  fuente1.loadFromFile("Fuentes/seguili.ttf");
  //variables de texto
  txt_titulo.setFont(fuente1);
  txt_titulo.setString("Life:");
  txt_titulo.setPosition(500,15);
  txt_titulo.setColor(Color::Black);


  

}


void taxi::eventos()
{
    while (window.pollEvent(evee))
    {
      if (evee.type == Event::Closed)
          isPlay = false;



       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          mover(-5,i);
                 
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          mover(5, i);
              
      
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          mover(i, 5);
              
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          mover(i, -5);
            
    }
    
}

void taxi::mover(int a,int b)
{

    if (shape.getGlobalBounds().intersects(obs[0].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[1].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[2].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[3].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[4].getGlobalBounds())
        )
    {
      shape.move(-a, -b);
    }else
    {
       shape.move(a, b);
      
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
  window.draw(txt_titulo);
  
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
