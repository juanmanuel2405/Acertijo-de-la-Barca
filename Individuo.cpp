/*
  Archivo: Individuo.cpp
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co
    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co
    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co
  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-05-31
  Licencia: GNU-GPL
*/

#include "Individuo.h"


Individuo::Individuo(string nombre, string tipoDeIndividuo):nombre(nombre),tipoDeIndividuo(tipoDeIndividuo),comida(" ")
{
  //Esta funcion va a definir el tipo de individuo que es el individuo valga la redundancia sera su mismo nombre hasta que mejoremos el programa 
  if (tipoDeIndividuo == " ")
  {
    this -> tipoDeIndividuo = nombre;
  }
  
}



Individuo::~Individuo()
{
  //No hace nada 
}


void Individuo::darComida(string comida)
{
  //Esta funcion nos define cual sera la comida que el individuo que se puede comer segun su tipo
  this -> comida = comida;
}


string Individuo::devolverNombre()
{
  // Funcion que devuelve el nombre del individuo
  return nombre;
}



string Individuo::devolverTipoDeIndividuo()
{ 
  //Funcion que devuelve el tipo de individuo
  return tipoDeIndividuo;
}




bool Individuo::sePuedeComer(Individuo *individuo)
{
  //funcion que designa si un individuo se puede comer a otro segun su tipo  

  // Si el tipo es el mismo que el individuo puede comer, devolvera un true  
  if (individuo -> devolverTipoDeIndividuo() == comida)
  {
   return true;
  }
  else 
  {
    return false;
  } 

}

