#include <iostream>
#include "taxi.h"

using namespace Designar;

using namespace sf;
using namespace std;

//using mgra = Digraph<RectangleShape, Text>;

const int TAM_HOR = 800, TAM_VER = 600;
const int VEL_BALL = 5;
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
   if (!t_home.loadFromFile("imagenes/home.png") ||  !t_obs_1.loadFromFile("imagenes/obs_1.png") ||
       !t_destino.loadFromFile("imagenes/destino_32.png")  || !t_pasajero.loadFromFile("imagenes/user_32.png"))
    {
      // error...
      //return 1;
      std::cout << "error" << '\n';
    }

  s_pasajero.setTexture(t_pasajero);
  s_destino.setTexture(t_destino);

  
  
  s_obs_1.setTexture(t_obs_1);
  s_obs_1.setPosition(50,100);

//-----------------------------------------------------------
//
  shape.setRadius(10);
  shape.setPosition(TAM_CEL*7+40, 15);
  shape.setFillColor(c_obs);
  // linea de afuera de la pelota
  shape.setOutlineThickness(5);
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
  for (int i = 0; i < 15; ++i)
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
  obs[14].setSize(Vector2f(50, 50));
  obs[15].setSize(Vector2f(TAM_CEL*7, TAM_CEL));
  obs[16].setSize(Vector2f(TAM_CEL*7, TAM_CEL));

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
  obs[14].setPosition(TAM_CEL*3,  TAM_CEL*9);
  obs[15].setPosition(0, 0);
  obs[16].setPosition(TAM_CEL*9, 0);
  //---------------------------------------------------
  
  obs[15].setFillColor(Color(11,17,17));
  obs[16].setFillColor(Color(11,17,17));
  


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
  g_paradas[10].setPosition(TAM_CEL*3,TAM_CEL*8);
  g_paradas[11].setPosition(TAM_CEL*8,TAM_CEL*8);
  g_paradas[12].setPosition(TAM_CEL*12,TAM_CEL*8);

  g_paradas[13].setPosition(TAM_CEL*0,TAM_CEL*11);
  g_paradas[14].setPosition(TAM_CEL*4,TAM_CEL*11);
  g_paradas[15].setPosition(TAM_CEL*8,TAM_CEL*11);
  g_paradas[16].setPosition(TAM_CEL*12,TAM_CEL*11);
  g_paradas[17].setPosition(TAM_CEL*15,TAM_CEL*11);

  //descripcion del grafo

  for (int i = 0; i < 20; ++i)
  {
    g_des[i].setString("P"+char(i));

  }
  
  //creando el grafo

  for (int i = 0; i < 20; ++i)
  {
    /* code */
     gn[i] = grafo.insert_node(make_tuple( g_paradas[i], i));
  }

   //arcos del primer nodo
    grafo.insert_arc(gn[0], gn[1], 4);
    grafo.insert_arc(gn[0], gn[5], 2);
    //arcos del segundo nodo
    grafo.insert_arc(gn[1], gn[2], 4);
    grafo.insert_arc(gn[1], gn[6], 4);
    grafo.insert_arc(gn[1], gn[7], 4);
    //arcos del tercer nodo
    grafo.insert_arc(gn[2], gn[3], 2);
    grafo.insert_arc(gn[2], gn[7], 5);
    grafo.insert_arc(gn[2], gn[8], 4);
    //arcos del cuarto nodo
    grafo.insert_arc(gn[3], gn[4], 1);
    grafo.insert_arc(gn[3], gn[8], 7);
    grafo.insert_arc(gn[3], gn[9], 6);
    //arcos del quinto nodo
    grafo.insert_arc(gn[4], gn[9], 4);
    //arcos del sexto nodo
    grafo.insert_arc(gn[5], gn[6], 2);
    grafo.insert_arc(gn[5], gn[13], 6);
    grafo.insert_arc(gn[5], gn[10], 8);

    grafo.insert_arc(gn[6], gn[7], 3);
    grafo.insert_arc(gn[6], gn[10], 3);

    grafo.insert_arc(gn[7], gn[8], 4);

    grafo.insert_arc(gn[8], gn[9], 4);
    grafo.insert_arc(gn[8], gn[11], 3);
    grafo.insert_arc(gn[8], gn[12], 3);

    grafo.insert_arc(gn[9], gn[12], 4);
    grafo.insert_arc(gn[9], gn[17], 4);

    grafo.insert_arc(gn[10], gn[11], 4);
    grafo.insert_arc(gn[10], gn[13], 5);
    grafo.insert_arc(gn[10], gn[14], 3);

    grafo.insert_arc(gn[11], gn[12], 3);
    grafo.insert_arc(gn[11], gn[15], 2);

    grafo.insert_arc(gn[12], gn[16], 2);
    grafo.insert_arc(gn[12], gn[17], 5);

    grafo.insert_arc(gn[14], gn[15], 3);
    grafo.insert_arc(gn[15], gn[16], 3);
    grafo.insert_arc(gn[16], gn[17], 2);

   

 



    txt_camino.setString(ncamino);
    txt_camino.setPosition(TAM_CEL*4,15);
    txt_camino.setColor(c_obs);
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

  for (int i = 0; i < 20; ++i)
  {
    g_des[i].setFont(fuente1);
    g_des[i].setString(to_string(i));
    g_des[i].setFillColor(Color(160, 160, 160));
    
  }


}


void taxi::eventos()
{
    
    while (window.pollEvent(evee))
    {
      if (evee.type == Event::Closed)
          isPlay = false;


      if (Keyboard::isKeyPressed(sf::Keyboard::Left) && Keyboard::isKeyPressed(sf::Keyboard::Up)   ||
          Keyboard::isKeyPressed(sf::Keyboard::Left) && Keyboard::isKeyPressed(sf::Keyboard::Down) ||
          Keyboard::isKeyPressed(sf::Keyboard::Right) && Keyboard::isKeyPressed(sf::Keyboard::Up)  ||
          Keyboard::isKeyPressed(sf::Keyboard::Right) && Keyboard::isKeyPressed(sf::Keyboard::Down)  )
      {
        shape.move(0,0);
        
      }else
      {
          for (int i = 0; i < 17; ++i)
            {
                  if ( shape.getGlobalBounds().intersects(obs[i].getGlobalBounds()) )
                  {
                      shape.setPosition(TAM_CEL*7+15, 15);

                  }
            }

        if (Keyboard::isKeyPressed(sf::Keyboard::Left))
           shape.move(-VEL_BALL,inter);
          
        if (Keyboard::isKeyPressed(sf::Keyboard::Right))
           shape.move(VEL_BALL,inter);
                    
        if (Keyboard::isKeyPressed(sf::Keyboard::Down))
           shape.move(inter,VEL_BALL);
                    
        if (Keyboard::isKeyPressed(sf::Keyboard::Up))
           shape.move(inter,-VEL_BALL);
        
        if (Mouse::isButtonPressed(sf::Mouse::Right))
           vari = true;
        

      }
            
    }
    
}




void taxi::update()
{

  //---------------------------------------------------------
        //Inicializar variables aleatorias
      //numeros aleatorios
  if (vari)
  {


      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<> dis(0, 17);

      random_device rd1;
      mt19937 gen1(rd());
      uniform_int_distribution<> dis1(0, 17);
      
                 int num1 = dis(gen);
                 int num2 = dis1(gen1);
                for (int j = 0; j < 10; ++j)
                {
        
                g_des[j].setPosition(Vector2f(0,0)); 
                
                }
                         
                for (int i = 0; i < 18; ++i)
                {
                  if ( shape.getGlobalBounds().intersects(g_paradas[i].getGlobalBounds()) )
                  {
                      num1 = i;
                  }
                }

                 cout << "el numero A es: " << num1 << endl;
                 cout << "el numero B es: " << num2 << endl;

                path = breadth_first_search_path(grafo, gn[num1], gn[num2]);

                path.for_each([&] (auto c, auto r)
                    {
                    
                        cout << "nodo:  " << get<1>(c->get_info())<< endl; 
                        aux[ii] = get<0>(c->get_info());
                        ii++;               

                         if (r != nullptr)
                        {
                        cout << "arco:  " << r->get_info()<< endl; 
                                     

                        }

                    });


             otra = ii;
             vari = false;
          
             
    }

  
}



void taxi::render()
{
  

  window.clear(sf::Color(29,29,29));
 
    for (int j = 0; j < 20; ++j)
    {
      /* code */
      window.draw(lineas_v[j]);
      window.draw(lineas_h[j]);
      window.draw(g_paradas[j]);
      window.draw(obs[j]);
      window.draw(g_des[j]);
      window.draw(aux[j]);

      
    }
    
    
    
      s_destino.setPosition(aux[otra-1].getPosition());
      window.draw(s_destino);
   
      
      s_pasajero.setPosition(aux[0].getPosition());
      window.draw(s_pasajero);
      
    
    if (Mouse::getPosition(window) == Vector2i(g_paradas[0].getPosition())) 

    {
         for (int j = 0; j < ii; ++j)
      {
        
        g_des[j].setPosition(aux[j].getPosition()); 
        window.draw(g_des[j]);
        
        
      }
    }

  window.draw(txt_camino);
  window.draw(s_obs_1);

  window.draw(shape);

  window.draw(obs[15]);
  window.draw(obs[16]);

  window.draw(txt_titulo);
  
  ii =0;



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
