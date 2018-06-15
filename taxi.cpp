#include <iostream>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

//using mgra = Digraph<RectangleShape, Text>;

const int TAM_HOR = 800, TAM_VER = 600;
const int VEL_BALL = 8;
const Color c_obs(255, 56, 25);//anaranjado


const int TAM_CEL = 50;

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
   if (!t_home.loadFromFile("imagenes/home.png") ||  !t_obs_1.loadFromFile("imagenes/obs_1.png"))
    {
      // error...
      //return 1;
      std::cout << "error" << '\n';
    }
  /*s_home.setTexture(t_home);
  s_home.setPosition(55,105);
  s_home.setScale(0.3,0.3);
  s_home.setColor(Color(209, 198, 196));
  */
  s_obs_1.setTexture(t_obs_1);
  s_obs_1.setPosition(50,100);
  //s_home.setScale(0.3,0.3);
  //s_home.setColor(Color(209, 198, 196));

//-----------------------------------------------------------
//
  shape.setRadius(10);
  shape.setPosition(10, 50);
  shape.setFillColor(c_obs);
  // linea de afuera de la pelota
  shape.setOutlineThickness(10);
  shape.setOutlineColor(Color(144, 148, 151,80));
  int j=0, u = 0;

  for (int i = 0; i < 20; ++i)
  {
    j += 50;
    
      lineas_v[i].setPosition(j,0);

      lineas_v[i].setSize(Vector2f(1,600));
      lineas_v[i].setFillColor(Color(16,16,16));
   
  }
   for (int i = 0; i < 20; ++i)
  {
    u += 50;
    
      lineas_h[i].setPosition(0,u);
      lineas_h[i].setFillColor(Color(16,16,16));
      lineas_h[i].setSize(Vector2f(800,1));
   
  }
   
  //OBSTACULOS-----------------------------
  //colores
  for (int i = 0; i < 14; ++i)
  {
      obs[i].setFillColor(c_obs);
    
  }
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
  obs[12].setSize(Vector2f(200, 50));
  obs[13].setSize(Vector2f(100, 100));


  //Posiciones          X           Y
  obs[0].setPosition(TAM_CEL    , TAM_CEL*2);
  obs[1].setPosition(TAM_CEL*6  , TAM_CEL*2);
  obs[2].setPosition(TAM_CEL*11 , TAM_CEL*2);
  obs[3].setPosition(TAM_CEL*14 , TAM_CEL*2);
  obs[4].setPosition(TAM_CEL    , TAM_CEL*5);
  obs[5].setPosition(TAM_CEL*4  , TAM_CEL*5);
  obs[6].setPosition(TAM_CEL*8  , TAM_CEL*5);
  obs[7].setPosition(TAM_CEL*4  , TAM_CEL*7);
  obs[8].setPosition(TAM_CEL    , TAM_CEL*8);
  obs[9].setPosition(TAM_CEL    , TAM_CEL*10);
  obs[10].setPosition(TAM_CEL*5 , TAM_CEL*9);
  obs[11].setPosition(TAM_CEL*9 , TAM_CEL*9);
  obs[12].setPosition(TAM_CEL*11, TAM_CEL*7);
  obs[13].setPosition(TAM_CEL*13,  TAM_CEL*9);
  
  //---------------------------------------------------
  //Elementos del grafo------------------------------
  //tamaños
  for (int i = 0; i < 20; ++i)
  {
    g_paradas[i].setSize(Vector2f(TAM_CEL,TAM_CEL));
    g_paradas[i].setFillColor(Color(255, 56, 25,30));
    
  }
  //Posiciones               X           Y
  g_paradas[0].setPosition(0        ,TAM_CEL);
  g_paradas[1].setPosition(TAM_CEL*5,TAM_CEL);
  g_paradas[2].setPosition(TAM_CEL*10,TAM_CEL);
  g_paradas[3].setPosition(TAM_CEL*13,TAM_CEL);
  g_paradas[4].setPosition(TAM_CEL*15,TAM_CEL);

  g_paradas[5].setPosition(0,TAM_CEL*4);
  g_paradas[6].setPosition(TAM_CEL*3,TAM_CEL*4);
  g_paradas[7].setPosition(TAM_CEL*7,TAM_CEL*4);
  
  g_paradas[8].setPosition(TAM_CEL*10,TAM_CEL*6);
  g_paradas[9].setPosition(TAM_CEL*15,TAM_CEL*6);
  g_paradas[10].setPosition(TAM_CEL*2,TAM_CEL*8);
  g_paradas[11].setPosition(TAM_CEL*8,TAM_CEL*8);
  g_paradas[12].setPosition(TAM_CEL*12,TAM_CEL*8);

  g_paradas[13].setPosition(TAM_CEL*0,TAM_CEL*11);
  g_paradas[14].setPosition(TAM_CEL*4,TAM_CEL*11);
  g_paradas[15].setPosition(TAM_CEL*8,TAM_CEL*11);
  g_paradas[16].setPosition(TAM_CEL*12,TAM_CEL*11);
  g_paradas[17].setPosition(TAM_CEL*15,TAM_CEL*11);
  //---------------------------------------------------



  //TEXTO
  fuente1.loadFromFile("Fuentes/seguili.ttf");
  //variables de texto
  txt_titulo.setFont(fuente1);
  txt_titulo.setString("Life:");
  txt_titulo.setPosition(500,15);
  txt_titulo.setColor(c_obs);

  
  txt_titulo.setFont(fuente1);
  txt_titulo.setString("EDGE");
  txt_titulo.setPosition(TAM_CEL,15);
  txt_titulo.setColor(c_obs);


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
 
    for (int j = 0; j < 20; ++j)
    {
      /* code */
      window.draw(lineas_v[j]);
      window.draw(lineas_h[j]);
      
    }
  
  for (int i = 0; i < 15; ++i)
  {
    /* code */
    window.draw(obs[i]);
  }

  

  window.draw(txt_titulo);



  window.draw(s_obs_1);
  for (int i = 0; i < 20; ++i)
  {
    window.draw(g_paradas[i]);
    
  }
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
