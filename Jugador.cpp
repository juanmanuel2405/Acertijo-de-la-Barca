/*
  Archivo: Jugador.cpp
  Autores:
    -Daniel F Rosero Z - daniel.zemanate@correounivalle.edu.co

    -Juan Manuel Cuellar R - juan.manuel.cuellar@correounivalle.edu.co

    -Kevin Stuard Marin C. - kevin.concha@correounivalle.edu.co

  Fecha creación: 2020-03-4
  Fecha última modificación: 2020-06-11
  Licencia: GNU-GPL
*/

#include<string>
#include"Jugador.h"
#include <vector>
#include <array>
#include <string>
using namespace std;

Jugador::Jugador (array <Lugar*, 4> *escenario, Orilla* orillaIzquierda, Orilla* orillaDerecha, Barca* barca): escenario(escenario), orillaIzquierda(orillaIzquierda), orillaDerecha(orillaDerecha), barca(barca) 
{
  //Esta funcion designa el tamano de las filas con la cantidad de individuos
  tamanoFilas = (*escenario) [0] -> cantidadDeIndividuos();
}

Jugador::~Jugador()
{
  //No hace nada  
}

/*
Esta funcion pide el nombre de la persona que va a jugar 
*/
string Jugador::pedirNombre()
{
  
  cout<< "Por favor ingresa tu nombre antes de empezar y lee atentamente las instrucciones "<<"\033[38;5;197m"<<endl ; //los numeros "\033[" son los colores de las letras que se ingresan 
  getline(cin, nombreDelJugador  ); 

  /*
  De la misma manera para hacer mas estetico el nombre del participante/jugador, ponemos su inicial en mayusculas en caso de que no la ponga en mayusculas 
  */
  nombreDelJugador[0] = toupper(nombreDelJugador [0]);
  return nombreDelJugador ;

}


/*
Esta funcion genera las graficas del juego, la interfaz y las instrucciones  
*/
void Jugador::pantallaDeJuego()
{
  //Limpia la pantalla para que no aparezca lo que se escribio antes 
  cout << "\033c";

  /*
  Descripcion del juego y ayudas
  */
  cout<< "\033[38;5;255mBienvenido " <<"\033[38;5;197m"+ nombreDelJugador + "\033[0m "<< "al" << "\033[38;2;255;0;0m Acertijo Del Granjero y la Barca \033[0m. "<< endl<<endl
  
  << "El juego consiste en lo siguiente..."<< endl 

  << "Un Robot necesita transportar sus animales y su cosecha desde un lado del río hasta la otra orilla, usando una barca. El problema es que en la Barca solo caben"<<"\033[38;5;76m  DOS INDIVIDUOS \033[0m " <<"y para mover la barca tiene que estar un Robot en ella "<<endl 

  << "TU OBJETIVO SI DECIDES ACEPTAR ESTA MISSION, "<< "\033[38;5;197m"+ nombreDelJugador + "\033[0m ."<<endl

  <<"Es pasar a todo sanos y salvos teniendo en cuenta lo siguiente..."<<endl

  <<"\033[38;5;76m--\033[0m Los Zorros (Zorro y Fox) se puede comer a cualquier individuo de carne."<<endl

  <<"\033[38;5;76m--\033[0m Los conejos (Conejo y Deise) se puede comer a cualquier individuo vegetal."<<endl 

  <<"\033[38;5;76m--\033[0m Los Robots (Robot y Mazinger) son los unicos que puede evitar que se coman entre si y mueven el barco."<<endl

  <<"\033[38;5;214m  PARA MOVER A LOS INDIVIDUOS USA SUS INICIALES, EJEMPLO: ZORRO (Z) \033[0m "<< endl<< endl ;

  /*
  Interfaz grafica del juego, esta funcion es la que junto a los nombres de lugar debe dibujar las diviciones del juego con sus respectivos nombres
  */
  for(int i= 0; i < (*escenario).size(); i++ )
  {
    string nombre = (*escenario)[i] -> nombreDelLugar();

    if((*escenario)[i] == barca)
    {
      cout << "\033[1;36m|\033[0m" + nombre  + string(tamanoColumas - nombre.size(), ' ');
      
    } 
    else
    {
      cout << "\033[1;36m|\033[0m"+ nombre +  string(tamanoColumas - nombre.size(), ' ');
    }

  }
  cout<<"\033[1;36m|\033[0m"<<endl;

  /*
  esta funcion es la que debe imprimir el nombre de los individuos y dibujar en pantalla las diviciones
  */
 for (int p = 0; p < tamanoFilas; p++)
 {
    for (int l = 0; l < (*escenario).size(); l++)
    {
      Individuo *individuo = (*escenario)[l]->devolverIndividuo(p);

      if (individuo)
      {
        string nombre = individuo -> devolverNombre();
        cout << "\033[1;38;2;185;255;0m|\033"  <<"\033[38;5;98m"+nombre+ "\033[0m"  << string(tamanoColumas - nombre.size(), ' ');
                
      }
      else
      {
        cout << "\033[1;36m|\033[0m" << string(tamanoColumas, ' ');
      }
    }
     cout << "\033[1;36m|\033[0m" << endl;

  }

  cout << endl;
}


string Jugador::recibirOrdenDelJugador()
{

  string letra = "" ;

  cout<<"¿Cual es tu siguiente moviento ? ";
  getline(cin,letra);

  //Esta funcion analiza el tamano del string que manda el usuario
  if (letra.size() == 0)
  {
    //Si da enter sin escribir nada este mensaje aparecera
    throw "Por Favor ingresa la primera letra del individuo/barca para poder moverlos" + letra ;
  }
  else if (letra.size() > 1)
  {
    //Si entra mas de un caracter, devolvera este mensaje 
    throw "¡Lo siento! solo puedes mover un individuo a la vez, intenta ingresar una sola letra por favor " + letra ;
  }
  
  /*
  Puesto que todos los individuos estan con iniciales mayusculas, el parametro que ingrese el usuario tambien debe ser en mayusculas y para evitar que el usuario lo ingrese asi , pues simplemente esta funcion tranforma la inicial a mayuscula para que sea compatible el programa 
  */
  letra[0] = toupper(letra  [0]);
  return letra;
}


/*
esta funcion es la que recibe los comandos del jugador y la que los pone en marcha 
*/
void Jugador::ordenesDelJugador()
{
  string letra = recibirOrdenDelJugador(); 

  //Las condiciones de las entradas definiran la accion que se realiza
  if(letra == "B")
  {
    barca -> moverBarca (escenario);
  }
  else if(letra == "P")
  {
    reiniciarJuego();
  }
  else 
  {
    //Si no es ninguna de las anteriores movera a los individuos
    for(int i = 0; i < (*escenario).size(); i++ )
    {
      if ((*escenario)[i] -> moverIndividuo(letra))
      {
        return;
      }
    }
    throw "el individuo al que intentas acceder no existe " + letra ; 
  }

}

/*
Esta funcion reincia el juego 
*/
void Jugador::reiniciarJuego()
{
  //Devuelve la barca a la orilla  Izquierda
  if ((*escenario)[2]==barca)
  {
    barca -> moverBarca(escenario, false );
  }

  //Devuelve todos los individuos a la orilla orillaIzquierda
  for (int i = 1 ; i < (*escenario).size(); i++ )
  {
    (*escenario)[i] -> moverTodosLosIndividuos(orillaIzquierda);
  }

  
}


bool Jugador::estadoDelJuego()
{
  //Pantalla si pierde ! verifica si un individuo fue comido 
  for(int i = 0; i < (*escenario).size(); i++)
  {
    Individuo *individuoComido = (*escenario)[i] -> algunIndividuoComido();

    if(individuoComido)
    {
      pantallaDeJuego();
      
      // Mensaje de perdida del juego 
      cout<<"Perdiste... individuo Comido -> "<< "\033[38;5;27m"+ string(individuoComido -> devolverNombre()) + "\033[0m " <<endl<< endl ;
      cout<< "¡Vamos ! Vuelve a intentarlo otra vez"<<endl;
     

      //Esta funcion nos deberia dar la opcion de volver a jugar y que el usuario reinicie el juego 
      menu(); 
    }
  }

  //Pantalla si Gana!, todos los individuos deben haber pasado al otro lado 

  int individuosTotales = tamanoFilas;

  if (orillaDerecha -> cantidadDeIndividuos() == individuosTotales)
  {
    pantallaDeJuego();

    cout<<"\033[38;5;214m ¡ FELICIDADES ERES EL GANADOR !\033[0m "<<endl;
    cout<<"Te invitamos a que vuelvas a jugar y que rompas tu record de movimientos"<<endl;
    

   menu();
  }
  
  return true;
  
}

/*
La funcion jugar es la que empieza el juego    
*/
void Jugador::jugar()
{
  while (pedirNombre() == "")
  {
    pedirNombre();
      
  }

  do 
  {
     pantallaDeJuego(); //Muestra la pantalla del juego 

     while (true)
     {
        /*
         funcion try intenta recibir una una ordenDelJugador y tambien capta un mensaje , que sera lo que lanzan los throw, de esta manera se crea una excepcion que sera en este caso que solo entren las ordenes del jugador y que se devuelvan una accion o caso contrario un mensaje que se escribira en pantalla, OJO que si no se cumple estas excepciones lanzara error de char const porque estara esperando a que llegue una accion o un mensaje  
        */
        try
        {
          ordenesDelJugador(); //Recibe las ordenes del jugador 
          break;
        }
        
        /*
        Recibe todos los mensajes que lanzan las distintas funciones y las imprime en pantalla
        */
        catch (string mensajeDelJuego) 
        {
          cout<< mensajeDelJuego <<endl;
        }

      }
     
  } while ( estadoDelJuego() ); // Comprueba el estado del juego

}

void Jugador::menu()
{
  cout<<"Recuerda! Si quieres volver a jugar preciona reiniciar \033[38;5;197m(P)\033[0m , si quieres salir del juego preciona \033[38;5;197m(O)\033[0m "<<endl;

  string letra;
  /*
  la funcion try intenta recibir una letra y capta un mensaje , que sera lo que lanzan los throw, de esta manera se crea una excepcion que sera en este caso que solo entre una letra caso contrario se cerrara el programa  
  */
  try
  {
    letra = recibirOrdenDelJugador();
  }
  catch (string mensaje)
  {
    exit(0);
  }

  if (letra == "O")
  {
    exit(0);
  }
  if (letra == "P")
  {
    reiniciarJuego();
  }

}

