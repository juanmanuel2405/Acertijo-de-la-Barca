/*
  Archivo: Orilla.h
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co
    
  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-05-28
  Licencia: GNU-GPL
*/



#ifndef ORILLA_H
#define ORILLA_H

#include <iostream>
#include <vector>
#include "Lugar.h"
using namespace std;

/*
  La clase orilla hereda los atributos de la clase lugar es decir, la Orilla ES UN lugar
*/

/*
  Clase Orilla
  Relación: es un Lugar
*/

class Orilla : public Lugar
{
  protected:

  public:
    /*
    Constructor, da valores iniciales a los atributos internos
    */
    Orilla(string nombre, int espacioLugar= -1);
    
    /*
    Destructor, no hace nada
    */
    virtual ~Orilla(); 
   
};

#else 
class Orilla; //Declaracion adelantada
#endif
