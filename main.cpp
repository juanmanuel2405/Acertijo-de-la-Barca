/*
  Archivo: main.cpp
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-06-11
  Licencia: GNU-GPL

*/
#include "Jugador.h"
#include "Individuo.h"
#include "Lugar.h"
#include "Barca.h"
#include "Orilla.h"
#include <array>


int main  ()
{

  //Construcion de los Individuos, de la siguiente manera, Nombre (Nombre, tipo)
  Individuo zorro ("Zorro ","Zorro"); 
  Individuo robot("Robot","Robot") ;
  Individuo conejo("Conejo","Conejo");
  Individuo lechuga("Lechuga","Verdura");
  Individuo fox( "Fox", "Zorro");
  Individuo deisi("Deisi","Conejo");
  Individuo mazinger("Mazinger", "Robot");
  Individuo tomate ("Tomate","Verdura");


  // Se designa la comida de cada Individuo
  zorro.darComida("Conejo");
  conejo.darComida("Verdura");
  fox.darComida("Conejo");
  deisi.darComida("Verdura");


  //Creamos los lugares del juego 
  Barca barca;
  Orilla izquierda("IZQUIERDA");
  Orilla derecha ("DERECHA");
  Lugar rio;

  // De esta manera se crea el array del escenario y su orden 
  array <Lugar*,4> escenario = {&izquierda , &barca, &rio , &derecha};

  //Se define los vecinos 
  izquierda.definirVecino(&barca);
  barca.definirVecino(&izquierda);

  //Este va a ser el vector de los individuos, asi que si se va a agregar o quitar algun Individuo hay que hacer lo mismo aqui
  izquierda.agregarIndividuos((vector<Individuo *> ) {&zorro, &robot, &conejo, &lechuga, &fox ,&deisi, &mazinger,&tomate} );

  //Esta funcion le da al jugador el control sobre el entorno del juego 
  Jugador participante( &escenario, &izquierda, &derecha,  &barca);
  participante.jugar();


  return 0;
}