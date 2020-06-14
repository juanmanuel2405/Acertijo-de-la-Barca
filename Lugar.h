/*
  Archivo: Lugar.h
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-05-28
  Licencia: GNU-GPL
*/

/*
  Clase: Lugar
  Atributos:
    -String nombre, que nos permitira darle un nombre a los lugares 
    -Vector de los individuos que estan en el lugar.
    -Un lugar Vecino que determina el lugar de al lado.
    -Const de guia, que nos permitira mover la barca solo cuando el "guia" este en la barca
    
    -ES LA FUNCION PADRE.
    -LUGAR CONOCE A INDIVIDUO 

  Funcionalidades:
    -ValidarIndividuos:Varía dependiendo del lugar.
    -Validar si se gano o se perdio el juego 
    -Agrega los individuos y su vector individuos
    -Mueve a los individous
    -Analiza si un individuo dentro del lugar se puede comer a otro 
    -Define al vecino 
  
*/

#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <vector>
#include "Individuo.h"
using namespace std;

class Lugar
{
  protected:
    string nombre;
    const string Guia = "Robot";
    vector <Individuo*> individuos;
      /*  
      Lugar CONOCE A un vecino, que tambien es un Lugar
      */
    Lugar *vecino;
    int espacioLugar;    

  public:

    /*
    Constructor, da valores iniciales a los atributos internos
    */
    Lugar(string nombre = "", int espacioLugar = -1);

    /*
    Destructor, no hace nada
    */
    virtual ~Lugar();
  
    /*
    Esta funcion agrega un individuo si su retorno es true , caso contrario no se agragara nada 
    */
    virtual bool agregarIndividuo(Individuo* individuo);
    
    /*
    Esta funcion agrega el vector de individuos a un lugar , si su retorno es true , caso contrario no se agregar el vector  
    */
    virtual bool agregarIndividuos(vector <Individuo*> individuos);
    

    /*
    Esta funcion nos devuelve la cantidad de individuos que hay en un lugar 
    */
    virtual int cantidadDeIndividuos();

    /*
    Esta funcion nos da el nombre de los lugares 
    */
    virtual string nombreDelLugar();
      
    /*
    Esta funcion nos devuelve el vector de individuos        
    */
    virtual Individuo* devolverIndividuo(int auxiliar);

    /*
    Esta funcion mueve a un individuo de un lugar a otro, con la primera leta de su nombre       
    */
    virtual bool moverIndividuo(string primeraLetra);
      
    /*
    Esta funcion nos devuelve un booleano en caso de que haya un individuo del tipo que se requiere, en este caso para ser comido
    */
    virtual bool hayUnIndividuoDeEseTipo (string tipoDeIndividuo);

    /*
    Esta funcion nos permite mover a todos los individuos a un lugar especifico, en el caso de que querramos 
    */
    virtual void moverTodosLosIndividuos(Lugar* lugarDeDestino );

    /*
    Esta funcion analiza si algun individuo fue comido , dentro del vector 
    */
    virtual Individuo* algunIndividuoComido();
      
    /*
    Esta funcion define el vecino 
    */
    virtual void definirVecino (Lugar* vecino );

    /*
    Esta funcion nos permite buscar por la letra a un individuo y devolver la posicion en la que se encuentra 
    */
    virtual int buscarIndividuo (string primeraLetra);
    
};


#else 
class Lugar; //Declaracion adelantada
#endif