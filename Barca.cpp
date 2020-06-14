
/*
  Archivo: Barca.cpp
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co
    
    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-06-11
  Licencia: GNU-GPL
*/

#include "Barca.h"
using namespace std;


Barca::Barca(string nombre , int espacioLugar  , string navegante ):Lugar( nombre , espacioLugar )
{       
  this-> navegante = navegante;
  
}

Barca::~Barca()
{
  //no hace nada 
}


void Barca::moverBarca(array <Lugar *, 4> *escenario, bool verificarNavegante)
{
  //Esta funcion lo que hace es designar en que espacio del array se encuentra orillaIzquierda y orillaDerecha en este caso seria en el lugar 0, y tres respectivamente 
  Lugar *orillaIzquierda = (*escenario)[0];
  Lugar *orillaDerecha = (*escenario)[3];


  //Esta funcion verifica si hay un navegante en el barco 
  if (!this -> hayUnIndividuoDeEseTipo (navegante) & verificarNavegante )
  {
    /* 
    Si no se encuentra un navegante debe lanzar este mensaje,
    hay que ponerle this-> navegante si no el programa no funcionara adecuadamente 

    nota: si no se escribe el this-> navegante, el programa no va a volver al bucle y nos va a crashear el programa con un error 
    */
    throw "No se encuentra el "+ this->navegante + " en la Barca, recuerda que la barca se mueve solo con el Robot dentro de ella ";
  }

  /*
  Esta funcion lo que hace es un cambio de dos variables, en este caso el escenario antes era 1 (donde deberia estar la barca) y ahora es 2 (el otro tramo del tiene el rio al lado de la orillaDerecha)

  esta funcion mueve la barca de un lado del mapa al otro lado 
  */
  swap((*escenario)[1], (*escenario)[2]);

  //Esta funciono nos analiza si la orillaIzquierda tiene el vecino si es asi cambia el en vecino al puntero derecho y viceversa 
  if (vecino == orillaIzquierda)
  {
    // Si es asi cambia el puntero a nulo
    orillaIzquierda -> definirVecino (nullptr);
    //Define el vecino en la orillaDerecha derecha 
    this-> definirVecino (orillaDerecha);
    orillaDerecha -> definirVecino (this);
  }
  else
  { 
    // Si no es, definiene el vecion en la orillaIzquierda
    orillaIzquierda -> definirVecino (this);
    // Se define el vecino en la orillaIzquierda
    this -> definirVecino (orillaIzquierda);
    orillaDerecha -> definirVecino (nullptr);
  } 
  
}


string Barca::devolverNavegante()
{
  //Esta funcion devuelve el individuo de que puede conducir la barca
  return this->navegante;
}


