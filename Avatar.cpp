/**
* @file Avatar.cpp
* @brief Declaracion de los metodos de la clase Avatar para la creacion del avatar y la simulacion de su movimiento
*
* @details 
* - Se importan las librerias necesarias para la manipulacion de cadenas, vectores, numeros aleatorios y entradas/salidas.
* - se define la clase Avatar encargada de representar al avatar, junto con sus atributos.
* - Se implementa "posicion_inicial()" que se encarga de generar una posicion inicial aleatoria para el avatar.
* - desarrolla "mover_avatar()" que se encarga de escoger una direccion aleatoria y modifica la ubicacion del avatar en base a esa dirrección (de igual forma modifica la interfaz que se le mostrara al ususario).
* - Se implementa "sobrevivencia()" que se encarga de verificar si el avatar sigue vivo o no y pone una "x" en la posicion en la que murio.
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 1.1
*
* @comentarios: 
* - se utiliza la libreria cstdlib para generar numeros aleatorios.
* - se utiliza la funcion "std::srand(time(nullptr));" para generar un numero aleatorio diferente cada vez que se ejecuta el programa.
* - Se utiliza un metodo switch para modificar la ubicacion del avatar en base a la dirreccion escogida.
* - Se utiliza un metodo do while para que el avatar no se salga del laberinto.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Avatar.h"
#include "Mapa.h"

bool Avatar::posicion_inicial(Print &print, Mapa &mapa){
  std::vector<int> pos_inicial = {0,0};
  std::srand(time(nullptr)); // Generar una semilla basada en el tiempo actual (ayuda para que los numeros aleatorios sean diferentes cada vez)
  pos_inicial[0] = rand() % 10; // #fila
  pos_inicial[1] = rand() % 10; // #columna
  ubicacion = pos_inicial;
  std::cout << "La posicion inicial: " << ubicacion[0] << ", " <<   ubicacion[1] <<std::endl; 
  vivo =  mapa.obtener_valor(ubicacion);
    if (!vivo) {
      print.guardar_recorrido(ubicacion, dirreccion, vivo);
    }
  return vivo;
}

void Avatar::mover_avatar(Print &print) {
  do {
    dirreccion = rand() % 4; // 0: arriba, 1: derecha, 2: abajo, 3: izquierda
  } while (ubicacion[0] - 1 < 0 || ubicacion[0] + 1 > 9 || ubicacion[1] + 1 > 9 || ubicacion[1] - 1 < 0); // el ciclo se repite hasta que se encuentre una dirreccion valida
  print.guardar_recorrido(ubicacion, dirreccion, vivo); // Modifica la dirreccion en la que se mueve el avatar antes de moverse
  switch (dirreccion){
    case 0:
      ubicacion[0] -= 1; // el avatar se mueve hacia arriba
      break;
    case 1:
      ubicacion[1] += 1; // el avatar se mueve hacia la derecha
      break;
    case 2:
      ubicacion[0] += 1; // el avatar se mueve hacia abajo
      break;
    case 3:
      ubicacion[1] -= 1; // el avatar se mueve hacia la izquierda
      break; 
  }
  std::cout << "La posicion actual: " << ubicacion[0] << ", " <<   ubicacion[1] << std::endl;
}

bool Avatar::sobrevivencia(Mapa &mapa, Print &print){
  vivo = mapa.obtener_valor(ubicacion);
  if (!vivo) {
    print.guardar_recorrido(ubicacion, dirreccion, vivo);  // si el avatar muere, se guarda la posicion en la que murio
  }
  return vivo;
}
  


