/*
  Archivo: Barca.h
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-05-31
  Licencia: GNU-GPL
*/

/*
  Clase: Barca

  Atributos:
    -Un lugar Vecino que determina el lugar de al lado.
    -navegante
    
  Funcionalidades:
    -Revisa si la barca puede moverse, dependiendo de la cantidad de  individuos que hay en ella.
    -MoverBarca: si la barca puede moverse estando el navegante en ella ,modifica el arreglo 


  Relaciones:
   Es una clase "hija" de la clase Lugar, CONOCE A los individuos
*/

#ifndef BARCA_H
#define BARCA_H

#include <iostream>
#include <array>
#include "Lugar.h"
using namespace std;

/*
  La clase Barca hereda los atributos y metodos de la clase Lugar, pero ademas esta puede moverse, es decir, la Barca ES PARECIDA A Lugar.
*/

class Barca : public Lugar 
{
  protected :
    
    // Es el individuo que puede mover la barca 
    string navegante ; 

  public:
    /*
    Constructor, da valores iniciales a los atributos internos
    */
    Barca(string nombre = " BARCA", int espacioLugar = 2 , string navegante = "Robot");

    /*
    Destructor, no hace nada
    */
    virtual ~Barca();

    /*
    MoverBarca , resive un arreglo que puede moverse y verifica si el individuo que puede mover la barca esta dentro de ella, en este caso el navegante que es el robot , si es true, se procede a mover la barca en el arreglo
    */  
    virtual void moverBarca(array <Lugar * , 4 >* escenario, bool verificarNavegante = true  );  

    /*
    Esta funcion nos devuelve el individuo que maneja la barca 
    */
    virtual string devolverNavegante ();

};

#else
class Barca; // Declaracion adelantada 
#endif