#include <iostream>
#include <graphalgorithms.H>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

using mgra = Digraph<RectangleShape, Text>;

const int TAM_HOR = 800, TAM_VER = 600;
const int VEL_BALL = 8;

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
//---------------------------------------------------------
   //IMAGENES------------------------------------------
   if (!t_home.loadFromFile("imagenes/home.png")   )
    {
      // error...
      //return 1;
      std::cout << "error" << '\n';
    }
  s_home.setTexture(t_home);
  s_home.setPosition(50,100);



//-----------------------------------------------------------
//
  shape.setRadius(10);
  shape.setPosition(10, 50);
  shape.setFillColor(Color(255, 56, 25));
  // linea de afuera de la pelota
  shape.setOutlineThickness(10);
  shape.setOutlineColor(sf::Color(144, 148, 151,80));
  int j=0, u = 0;

  for (int i = 0; i < 20; ++i)
  {
    j += 50;
    
      lineas_v[i].setPosition(j,0);

      lineas_v[i].setSize(Vector2f(1,600));
   
  }
   for (int i = 0; i < 20; ++i)
  {
    u += 50;
    
      lineas_h[i].setPosition(0,u);

      lineas_h[i].setSize(Vector2f(800,1));
   
  }
   
  //OBSTACULOS-----------------------------
  //colores
  obs[0].setFillColor(Color(255, 56, 25));
  obs[1].setFillColor(Color(255, 56, 25));
  obs[2].setFillColor(Color(255, 56, 25));
  obs[3].setFillColor(Color(255, 56, 25));
  obs[4].setFillColor(Color(255, 56, 25));
  obs[5].setFillColor(Color(255, 56, 25));
  obs[6].setFillColor(Color(255, 56, 25));
  obs[7].setFillColor(Color(255, 56, 25));
  obs[8].setFillColor(Color(255, 56, 25));
  
  obs[9].setFillColor(Color(255, 56, 25));
  obs[10].setFillColor(Color(255, 56, 25));
  obs[11].setFillColor(Color(255, 56, 25));


  //tamaños                X    Y
  obs[0].setSize(Vector2f(200, 100));
  obs[1].setSize(Vector2f(200, 100));
  obs[2].setSize(Vector2f(100, 200));
  obs[3].setSize(Vector2f(50 , 150));
  obs[4].setSize(Vector2f(100, 150));
  obs[5].setSize(Vector2f(150, 50));
  obs[6].setSize(Vector2f(100, 150));
  obs[7].setSize(Vector2f(200, 50));
  obs[8].setSize(Vector2f(50, 50));

  obs[9].setSize(Vector2f(150, 100));
  obs[10].setSize(Vector2f(150, 100));
  obs[11].setSize(Vector2f(150, 100));

  //Posiciones        X    Y
  obs[0].setPosition(50 , 100);
  obs[1].setPosition(300, 100);
  obs[2].setPosition(550, 100);
  obs[3].setPosition(700, 100);
  obs[4].setPosition(50 , 250);
  obs[5].setPosition(200, 250);
  obs[6].setPosition(400, 250);
  obs[7].setPosition(200, 350);
  obs[8].setPosition(50,  400);
  obs[9].setPosition(50, 500);
  obs[10].setPosition(250, 450);
  obs[11].setPosition(450,  450);
  //---------------------------------------------------
  
  //TEXTO
  fuente1.loadFromFile("Fuentes/seguili.ttf");
  //variables de texto
  txt_titulo.setFont(fuente1);
  txt_titulo.setString("Life:");
  txt_titulo.setPosition(500,15);
  txt_titulo.setColor(Color(255, 56, 25));

 


}


void taxi::eventos()
{
    while (window.pollEvent(evee))
    {
      if (evee.type == Event::Closed)
          isPlay = false;



       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          mover_h(-VEL_BALL,i);
                 
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          mover_h(VEL_BALL, i);
              
      
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          mover_v(i, VEL_BALL);
              
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          mover_v(i, -VEL_BALL);
            
    }
    
}

void taxi::mover_v(int a,int b)
{

    if (shape.getGlobalBounds().intersects(obs[0].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[1].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[2].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[3].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[4].getGlobalBounds())
        )
    {
      shape.move(1, 0);
    }else
    {
      shape.move(a, b);
      
    }

}
void taxi::mover_h(int a,int b)
{

    if (shape.getGlobalBounds().intersects(obs[0].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[1].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[2].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[3].getGlobalBounds())||
        shape.getGlobalBounds().intersects(obs[4].getGlobalBounds())
        )
    {
      shape.move(0, 1);
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
  
  window.clear(sf::Color(29,29,29));
  

  window.draw(shape);
  window.draw(txt_titulo);

  
  for (int i = 0; i < 15; ++i)
  {
    /* code */
    window.draw(obs[i]);
  }

 
    for (int j = 0; j < 20; ++j)
    {
      /* code */
      window.draw(lineas_v[j]);
      window.draw(lineas_h[j]);
      
    }


  window.draw(s_home);
  
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
