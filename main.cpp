/**
* @file main.cpp
* @brief El programa principal que se encarga de ejecutar los metodos para la ejecucion del laberinto.
*
* @details 
* - Se importan las librerias necesarias para el funcionamiento del programa.
* - Se importan los archivos .h de las clases Avatar, Mapa y Print.
* - Se inicializan los objetos "mapa", "print" y "avatar".
* - Se crea un ciclo do while para iniciar el movimiento del avatar.
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 1.1
*
* @comentarios: 
* el avatar reconoce los 0 como abismos y los 1 como caminos.
* Aveces en los bordes el avatar se queda atorado, esto se debe a que no hay caminos disponibles para moverse y al escoger la dirreccion aleatoriamente da la causalida que se queda escogiendo la misma.
* En este proyecto no se utilizaron punteros ya que no se considero necesario para la ejecucion del programa, puesto que con las relaciones entre objetos y clases basto para no tener que usar punteros hacia atributos privados (esto implicarian metodos getters adicionales y por ende mas linea de codigo), aun asi se utilizaron varias referencias.
*/
#include "Avatar.h"
#include "Mapa.h"
#include "Print.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main() {
  Avatar avatar;
  Mapa mapa;
  Print print;
  std::cout << "movimientos del avatar:" << std::endl;
  mapa.cargar_laberinto();
  avatar.posicion_inicial(print,mapa);
  if (avatar.get_vivo() == true){
    do{
      avatar.mover_avatar(print);
    } while (avatar.sobrevivencia(mapa, print)); // mientras el avatar este vivo, se ejecutara el ciclo do while
  }
  std::cout << "**************RECORRIDO DEL AVATAR**************" << std::endl;
  print.imprimir_recorrido();
}