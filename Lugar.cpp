/*
  Archivo: Lugar.cpp
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-06-11
  Licencia: GNU-GPL
*/

#include "Lugar.h"

Lugar::Lugar(string nombre, int espacioLugar) : nombre(nombre), espacioLugar(espacioLugar), vecino(nullptr)
{
  //No hace nada 
}

string Lugar::nombreDelLugar()
{
  return nombre;  
}

void Lugar::definirVecino (Lugar* vecino )
{
  this->vecino =vecino;
}


Lugar::~Lugar()
{
  //No hace nada  
}


bool Lugar::agregarIndividuo(Individuo* individuo )
{
  //Esta funcion analiza si puede adicionar un individuo al vector , si se puede, se adiciona , si no devuelve false
  if(individuos.size() < espacioLugar || espacioLugar == -1 )
  {
    individuos.push_back(individuo);    
  }
  else 
  {

    return false;
  }
  return true;
}


bool Lugar::agregarIndividuos(vector<Individuo *> individuos)
{
  //Esta funcion analiza si se puede adicionar un vector de individuos a lugar , si se puede lo adiciona y retorna true , si no retorna false 
  if(this -> individuos.size() + individuos.size() < espacioLugar || espacioLugar == -1)
  {
    for (int i = 0; i < individuos.size(); i++)
    {
      this -> individuos.push_back(individuos[i]);
    }
    return true;
  }
  else
  {
    return false;
  }

}


void Lugar:: moverTodosLosIndividuos(Lugar* lugarDeDestino )
{
  //Esta funcion mueve todo los individuos a un lugar y los borra del lugar en el que se encontraban  
  lugarDeDestino -> agregarIndividuos(individuos);
  individuos.clear();
}


int Lugar::cantidadDeIndividuos()
{
  return individuos.size();
}


/*
  Esta funcion va buscar al individuo por la primera letra de su nombre 
*/
int Lugar:: buscarIndividuo (string primeraLetra)
{
  //Recorre todo el vector y buscando al individuo por su inicial 
  for(int i = 0; i < individuos.size(); i++)
  {
    if( individuos[i] -> devolverNombre()[0] == primeraLetra[0] )
    {
      return i;
    } 
  }
  return -1;
}


Individuo *Lugar::devolverIndividuo(int auxiliar)
{
  //Devuelve un individuo del vector
  if(auxiliar < individuos.size() )
  {
    return individuos[auxiliar];
  }
  else
  {
    return nullptr;
  }
}

bool Lugar::hayUnIndividuoDeEseTipo(string tipoDeIndividuo)
{
  /*
  Esta funcion hace una itineracion por todo el vector buscando si hay un individuo que se pueda comer a otro individuo 
  */
  for(int i = 0; i < individuos.size(); i++)
  {
    if(individuos[i] -> devolverTipoDeIndividuo() == tipoDeIndividuo )
    {
      return true;
    }
  }
 return false;
}
    
Individuo *Lugar:: algunIndividuoComido()
{
  /*
  Esta funcion busca en el vector a ver si esta el robot, en caso que no este se procede a la funcion de abajo 
  */
  for (int j = 0; j < individuos.size(); j++)
  {
    if (individuos[j] -> devolverTipoDeIndividuo() == Guia )
    {
      return nullptr;
    }
  }

  /*
  Si el robot no se encuentra en el vector, lo analizara para ver que individuo se puede comer a que individuo 
  */
  for(int k = 0; k < individuos.size(); k++)
  {
    
    //Analizara el vector 
    for(int l = k + 1; l < individuos.size(); l++)
    {
      if(individuos[k] -> sePuedeComer(individuos[l]) )
      {
        return individuos[l];
      }
    }


    //Analizara el vector 
    for(int l = 0; l <= k - 1 ; l++)
    {
      if(individuos[k] -> sePuedeComer(individuos[l]) )
      {
        return individuos[l];
      }

    } 

    
  }
  return nullptr;
}


bool Lugar:: moverIndividuo(string primeraLetra)
{
  //Busca al individuo por su letra
  int individuoMover = buscarIndividuo ( primeraLetra);

  //Si no se encuentra retorna false
  if (individuoMover == -1)
  {
    return false;
  }
  
  //Si el vencino no esta, en este caso la barca , no podra realizar la accion y soltara el mensaje 
  if (!vecino)
  {
    throw individuos[individuoMover] -> devolverNombre() + " sin la barca no puede moverse al otro lado! ";
    
  }

  //Esta funcion agraga a los individuos a la barca
  if (vecino -> agregarIndividuo(individuos[individuoMover]))
  {
    individuos.erase(individuos.begin() + individuoMover);
    return true;
  }
  else 
  {
    /*
    Si no se puede puede agragar otro individuo a la barca sera porque esta llena, 

    nota: hay que escribir throw (string) para que indentifique que tipo de variable se esta mandando, esto evita que nos salte dos mensajes que son este y el de "no se encuentra el individuo "
    */ 
    throw (string) "La Barca ha llenado su capacidad, desocupala para poner otro individuo ";
    
  }

}

    








