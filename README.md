# Acertijo-de-la-Barca
Acertijo del Granjero y la barca , Programación Orientada a Objeto 
Este programa fue hecho como proyecto final para la materia de programacion orientada a objetos 

El Juego o Acertijo de la Barca consiste en lo siguiente 

Objetivo:
Implementar un juego de lógica usando C++ con metodología de programación orientada a objetos. El juego consiste en lo siguiente: hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y el conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar que órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos. 


Las órdenes que puede dar el jugador son (usando el teclado):

B. La Barca se mueve a la otra orilla

R. El Robot salta de/a la barca

Z. El Zorro salta de/a la barca

C. El Conejo salta de/a la barca

L. La Lechuga salta de/a la barca

Después de cada orden el Jugador debe mostrar en pantalla el nuevo estado del juego,usando 4 columnas. 


Requerimientos:

•Debe usar las relaciones “es un”, “es parecido a un” y “conoce un”.

•Debe haber una clase Jugador que lea el teclado, dé ordenes a los individuos y muestre en pantalla el resultado. El Jugador es el único que puede usar cin y cout.

•Si logra polimorfismo (típicamente sobre la clase Lugar), tiene 0.2 de premio en la nota final.

•Al finalizar, cambiando solo  main.cpp  y la clase  Jugador  se debe poderse implementar otra variante del juego, por ejemplo con 2 conejos, 1 lechuga y 1 zorro y 2 robots (si lo logra, tiene un premio de 0.1 en la nota final). 

•Si logra lo anterior sin modificar  Jugador  (modificando únicamente main.cpp),tiene un premio de 0.2 en la nota final.


Ayudas:

Diseñe las clases:

•Jugador

•Orilla

•Barca

•Individuo

•Lugar


Diseñe estas relaciones:

•Orilla es unLugar. 

•Barca es parecido a unLugar (porque también puede moverse). 

•Debe haber 2 objetos de clase Orilla y un objeto de clase Barca. 

•La clase Lugar debe poseer un vector de punteros a Individuo.

•Los demás objetos (robot, zorro, conejo, lechuga) deben ser de la claseIndividuo.

•La clase Individuo debe contener un vector de punteros a Individuo que puede comer (el zorro puede comer conejo; y el conejo puede comer lechuga).


Diseñe estas responsabilidades:

•La clase Lugar es la que debe determinar si se perdió (si en el mismo Lugar hay un individuo que puede comerse a otro, a la vez que no está el robot).

Polimorfismo:

•Para lograr el polimorfismo se sugiere que cada Lugar tenga un puntero apuntando al Lugar que sea vecino. Por ejemplo, inicialmente la orillaIzquierda debe tener como vecino a la barca. La barca debe tener como vecino a la orillaIzquierda. Y la orillaDerecha no debe tener ningún
vecino (puntero nulo). Cada vez que la  barca  se mueva, cambian esos vecinos. 

•Que lo anterior no le confunda: la barca debe conocer a la orillaIzquierda y a la orillaDerecha siempre, pero en cada momento solo tiene una vecina.

•El polimorfismo se puede lograr entonces en la función Jugador::jugar() teniendo  en  la  parte  privada  de  Jugador  un  vector<Lugar *>  de  3posiciones, apuntando respectivamente a la orillaIzquierda, barca y orillaDerecha. Sin  polimorfismo esta función  saldrá  muy  larga  y  con muchos condicionales.
