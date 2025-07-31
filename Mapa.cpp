/**
* @file Mapa.cpp
* @brief Declaracion de los metodos de la clase Mapa para la lectura del laberinto 
*
* @details 
* - Se importan las librerias necesarias para la manipulacion de cadenas, vectores, lectura de archivos planos y entradas/salidas.
* - se define la clase Mapa encargada de representar el laberinto, junto con sus atributos.
* - Se desarrolla "cargar_laberinto()" que se encarga de leer el archivo plano y almacenarlo en una matriz.
* - Se implementa "Obtene_valor()" que se encarga de interpretar si la posicion del avatar es un camino o un abismo.
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 1.1
*
* @comentarios: 
* - Se utilizan varios ciclos while para leer el archivo plano y almacenarlo en una matriz.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include  "Mapa.h"

void Mapa::cargar_laberinto(){
  std::ifstream file(fileName);
  std::vector<std::vector<int>> matriz;
  std::string linea;

  while (getline(file, linea)) { // leer cada linea del archivo
    std::vector<int> fila;
    std::stringstream ss(linea);
    std::string valor; 

    while (getline(ss, valor, ',')) { // divide la linea en valores separados por comas
      fila.push_back(stoi(valor));  // convierte string a int
    }
  matriz.push_back(fila);
  }
  laberinto = matriz;
}

bool Mapa::obtener_valor(std::vector<int> &ubicacion){
  if (laberinto [ubicacion[0]][ubicacion[1]] == 1){
    return true;
  }
  else {
    return false;
  }
}




  
