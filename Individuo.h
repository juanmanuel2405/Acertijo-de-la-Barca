/*
  Archivo: Individuo.h
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co
    
  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-05-28
  Licencia: GNU-GPL
*/

/*
  Clase: Individuo
  
  Atributos:
    -Nombre 
    -Tipo de individuo
    -Tipo de comida 

  Funcionalidades:
    -Crea a los individuos y los dota de las caracteristica que tiene, como es su nombre, de que tipo son y que tipo de individuo puede comer

  Relaciones:La clase Individuos CONOCE A Lugar.
*/

#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <iostream>
#include <string>
#include <vector>
#include "Lugar.h"
using namespace std;

class Individuo
{
  protected:
    string nombre;
    string tipoDeIndividuo; // esta funcion nos define de que "TIPO " es el individuo
    string comida; // esta funcion es la que nos dice que es lo que come el individuo 
          
  public:
  
    /*
    Constructor, da valores iniciales a los atributos internos
    */
    Individuo(string nombre,  string tipoDeIndividuo  =" ");


    /*
    Destructor, no hace nada
    */
    virtual ~Individuo();


    /*
    DevolverNombre, devuelve el nombre del individuo
    */
    virtual string devolverNombre ();


    /*
    DevolverTipoDeIndividuo, devuelve el tipo de individuo que es 
    */
    virtual string devolverTipoDeIndividuo();
  
    
    /*
    Adiciona un string del tipo que el individuo puede comer el otro individuo
    */
    virtual void darComida(string comida ); 


    /*
    devuelve verdadero si un individuo se puede comer a otro individuo
    */
    virtual bool sePuedeComer(Individuo* individuo );
};

#else 
class Individuo; //Declaracion adelantada
#endif