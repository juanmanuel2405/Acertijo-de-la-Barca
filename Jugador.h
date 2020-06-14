/*
  Archivo: Jugador.h
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-06-11
  Licencia: GNU-GPL
*/

/*
  Clase: Jugador

  Atributos:
    -String nombreDelJugador
    -referencias a los lugares que se van a crear , orrillas derecha-izquierda, barca
    -tamanos de las filas y las colunmas

    -JUGADOR CONOCE A LA BARCA, LAS ORILLAS Y LOS LUGARES Y 

  Funcionalidades:
    -pedirNombre: Retorna el nombre del jugador, para utilizarlo en los en pantalla.
    -ordenesDelJugador:Recibe una tecla dada por el jugador, y dependiendo de la tecla  presionada, da una orden distinta al programa.
    -interfazJugador:Imprime en pantalla el programa como tal, con los movimientos  dados por el jugador.
    
    -Sera la funcion que controla a las demas funciones dentro del programa y la que imprime en pantalla todo lo que sucede en el juego  

  Relaciones: Es una clase base, CONOCE A los individuos.
*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include "Barca.h"
#include "Orilla.h"

#include <iostream>
#include <array>
using namespace std;


class Jugador
{
  protected:
    string nombreDelJugador; //nombre que tendra el jugador 
    
    array <Lugar*, 4> *escenario; //se usa array porque me parece mas facil de mover 

    Orilla* orillaIzquierda;
    Orilla* orillaDerecha; 
    Barca* barca;
   
    /*
    este es el tamano base que tendran la distancia de las colunmas,el numero no puede ser menor que el numero 9 porque si no, nos lanzara error de lengt, asi que si se quiere modificar tiene que se (>= 9) , tambien teniendo en cuenta el tamano de los nombres de los individuos , si los nombres son muy largos hay que aumentar el tamanoColumas
    */
    const int tamanoColumas = 13; 
    int tamanoFilas; 
    
 
   public:

    /*
    Constructor, genera el escenario del juego, basado en un array, de 4 espacios , y con sus respectivos espacios 
    */
    Jugador( array <Lugar*, 4>* escenario, Orilla* orillaIzquierda, Orilla* orillaDerecha, Barca* barca);
    
    /*
    Destructor, no hace nada
    */
    virtual ~Jugador();

    /*
    Pregunta al usuario su nombre
    */
    virtual string pedirNombre(); 

    /*
    Recibe los comandos de control que da el usuario, en este caso una tecla asociada a cada individuo,y dependiendo de la tecla, da una orden diferente,cambiando el puntero de posicion del individuo, y el puntero del vector de individuos del lugar en el que estaba y el lugar al que se mueve  , dentro de ella ira recibirOrdenDelJugador 
    */
    virtual void ordenesDelJugador(); 
      
    /*
    Recibe desde la consola las teclas dados por el usuario, es la primera funcion, la cual va ir dentro de la funcion ordenesDelJugador 
    */
    virtual string recibirOrdenDelJugador(); 

    /*
    Muestra en pantalla el cambio de posicion de los punteros de individuos y lugares , es la interfaz grafica del juego y la que lo dibuja
    */
    virtual void  pantallaDeJuego();

    /*
    Analiza despues de cada movimiento si se perdio o se gano el juego 
    */
    virtual bool estadoDelJuego();

    /*
    Reinicia el juego desde cero, volviendo todo a la posicion original 
    */
    virtual void reiniciarJuego ();

    /*
    Esta funcion permite iniciar el juego, da las instrucciones, recibe el nombre del jugador y  jugar. basicamente es el inicio de todo 
    */
    virtual void jugar();

    /*
    Esta funcion va a recibir los comandos del juego para poder reinciarlo si es que se llega a perde en el juego y evitar que se siga jugando despues de perder, dando solo la opcion de reiniciar o de cerrar el juego 
    */
    virtual void menu();
      
     
};

#else 
class Jugador; //Declaracion adelantada
#endif 