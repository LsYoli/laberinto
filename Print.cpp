/**
* @file Print.cpp
* @brief Declaracion de los metodos de la clase Print para la interfaz grafica frente al recorrido del avatar
*
* @details 
* - Se importan las librerias necesarias para la manipulacion de cadenas, vectores y entradas/salidas.
* - se define la clase Print encargada de representar el recorrido del avatar
* - Se desarrolla "guardar_recorrido()" de ir modificando la matriz de recorrido en base a la dirreccion del avatar
* - Se implementa "Print()" que se encarga de construir la matriz de recorrido
* - Se desarrolla "imprimir_recorrido()" que se encarga de imprimir la matriz de recorrido
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 1.1
*
* @comentarios: N/N
*/
#include <iostream>
#include <vector>
#include <string>
#include "Print.h"
#include "Avatar.h"

Print::Print() : recorrido(10, std::vector<std::string>(10, "0")) {}

void Print::guardar_recorrido(std::vector<int> &ubicacion, int &dirreccion, bool &vivo){
  if (vivo == true){
    switch (dirreccion){
      case 0:
        recorrido[ubicacion[0]][ubicacion[1]] = "↑";
        break;
      case 1:
        recorrido[ubicacion[0]][ubicacion[1]] = "→";
        break;
      case 2:
        recorrido[ubicacion[0]][ubicacion[1]] = "↓";
        break;
      case 3:
        recorrido[ubicacion[0]][ubicacion[1]] = "←";
        break; 
    }
  }
  else {
    recorrido[ubicacion[0]][ubicacion[1]] = "X";
  }
};

void Print::imprimir_recorrido(){
  for (int i = 0; i < recorrido.size(); i++) {
      for (int j = 0; j < recorrido[i].size(); j++) {
          std::cout << recorrido[i][j] << " ";
      }
    std::cout << std::endl;
  }
};