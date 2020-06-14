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

Después de cada orden el Jugador debe mostrar en pantalla el nuevo estado del juego,usando 4 columnas. Por ejemplo, el estado 
inicial es:
|IZQUIERDA   |   BARCA|        |   DERECHA |
|Robot       |        |        |           |
|Zorro       |        |        |           |
|Conejo      |        |        |           |
|Lechuga     |        |        |           |


Y el estado final debe ser:
|  IZQUIERDA|       |   BARCA   |   DERECHA|
|           |       |           |     Robot|  
|           |       |           |     Zorro|
|           |       |           |    Conejo|
|           |       |           |   Lechuga|


Requerimientos:

•Debe usar las relaciones “es un”, “es parecido a un” y “conoce un”.
•Debe haber una clase Jugador que lea el teclado, dé ordenes a los individuos ymuestre en pantalla el resultado. El Jugador es el único que puede usar cin y cout.
•Si logra polimorfismo (típicamente sobre la clase Lugar), tiene 0.2 de premio en lanota final.
•Al finalizar, cambiando solo  main.cpp  y la clase  Jugador  se debe poderse implementar otra variante del juego, por ejemplo con 2 conejos, 1 lechuga y 1 zorro y 2 robots (si lo logra, tiene un premio de 0.1 en la nota final). 
•Si logra lo anterior sin modificar  Jugador  (modificando únicamente main.cpp),tiene un premio de 0.2 en la nota final.
