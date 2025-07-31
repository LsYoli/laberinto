/**
* @file Avatar.cpp
* @brief Implementación de las clases Avatar, AvatarOriginal y AvatarInnovador
*
* @details 
* - Clase base Avatar con métodos comunes
* - AvatarOriginal: movimiento aleatorio (implementación original)
* - AvatarInnovador: movimiento en forma de L como caballo de ajedrez
* - Uso de polimorfismo para diferentes tipos de movimiento
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 2.0
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Avatar.h"
#include "Mapa.h"

// Métodos de la clase base Avatar
bool Avatar::posicion_inicial(Print &print, Mapa &mapa){
  std::vector<int> pos_inicial = {0,0};
  std::srand(time(nullptr));
  pos_inicial[0] = rand() % 10;
  pos_inicial[1] = rand() % 10;
  ubicacion = pos_inicial;
  std::cout << "La posicion inicial: " << ubicacion[0] << ", " << ubicacion[1] << std::endl; 
  vivo = mapa.obtener_valor(ubicacion);
  if (!vivo) {
    print.guardar_recorrido(ubicacion, dirreccion, vivo);
  }
  return vivo;
}

bool Avatar::sobrevivencia(Mapa &mapa, Print &print){
  vivo = mapa.obtener_valor(ubicacion);
  if (!vivo) {
    print.guardar_recorrido(ubicacion, dirreccion, vivo);
  }
  return vivo;
}

// Implementación AvatarOriginal (movimiento aleatorio)
void AvatarOriginal::mover_avatar(Print &print) {
  do {
    dirreccion = rand() % 4; // 0: arriba, 1: derecha, 2: abajo, 3: izquierda
  } while ((dirreccion == 0 && ubicacion[0] - 1 < 0) || 
           (dirreccion == 1 && ubicacion[1] + 1 > 9) ||
           (dirreccion == 2 && ubicacion[0] + 1 > 9) ||
           (dirreccion == 3 && ubicacion[1] - 1 < 0));
  
  print.guardar_recorrido(ubicacion, dirreccion, vivo);
  
  switch (dirreccion){
    case 0:
      ubicacion[0] -= 1; // arriba
      break;
    case 1:
      ubicacion[1] += 1; // derecha
      break;
    case 2:
      ubicacion[0] += 1; // abajo
      break;
    case 3:
      ubicacion[1] -= 1; // izquierda
      break; 
  }
  std::cout << "La posicion actual: " << ubicacion[0] << ", " << ubicacion[1] << std::endl;
}

// Implementación AvatarInnovador (movimiento en L)
bool AvatarInnovador::es_movimiento_valido(int fila, int columna) {
  return (fila >= 0 && fila < 10 && columna >= 0 && columna < 10);
}

void AvatarInnovador::mostrar_movimientos_validos(Mapa &mapa) {
  std::cout << "\nMovimientos validos en forma de L:" << std::endl;
  int contador = 1;
  
  for (int i = 0; i < movimientos_l.size(); i++) {
    int nueva_fila = ubicacion[0] + movimientos_l[i][0];
    int nueva_columna = ubicacion[1] + movimientos_l[i][1];
    
    if (es_movimiento_valido(nueva_fila, nueva_columna)) {
      std::cout << contador << ". Mover a (" << nueva_fila << "," << nueva_columna << ")" << std::endl;
      contador++;
    }
  }
}

void AvatarInnovador::mover_avatar(Print &print) {
  std::vector<std::vector<int>> movimientos_validos;
  
  // Obtener movimientos válidos (dentro del tablero)
  for (int i = 0; i < movimientos_l.size(); i++) {
    int nueva_fila = ubicacion[0] + movimientos_l[i][0];
    int nueva_columna = ubicacion[1] + movimientos_l[i][1];
    
    if (es_movimiento_valido(nueva_fila, nueva_columna)) {
      movimientos_validos.push_back({nueva_fila, nueva_columna, i});
    }
  }
  
  if (movimientos_validos.empty()) {
    std::cout << "No hay movimientos válidos disponibles. El avatar está atrapado." << std::endl;
    vivo = false;
    return;
  }
  
  // Mostrar opciones al usuario
  Mapa mapa_temp; // Para verificar si es camino o abismo
  mapa_temp.cargar_laberinto();
  mostrar_movimientos_validos(mapa_temp);
  
  // Pedir al usuario que elija
  int eleccion;
  do {
    std::cout << "Elige un movimiento (1-" << movimientos_validos.size() << "): ";
    std::cin >> eleccion;
    eleccion--; // Convertir a índice base 0
  } while (eleccion < 0 || eleccion >= movimientos_validos.size());
  
  // Mapear la dirección para el sistema de impresión
  int movimiento_original = movimientos_validos[eleccion][2];
  switch (movimiento_original) {
    case 0: case 1: dirreccion = 0; break; // Movimientos hacia arriba
    case 2: case 4: dirreccion = 3; break; // Movimientos hacia izquierda
    case 3: case 5: dirreccion = 1; break; // Movimientos hacia derecha
    case 6: case 7: dirreccion = 2; break; // Movimientos hacia abajo
  }
  
  print.guardar_recorrido(ubicacion, dirreccion, vivo);
  
  // Realizar el movimiento
  ubicacion[0] = movimientos_validos[eleccion][0];
  ubicacion[1] = movimientos_validos[eleccion][1];
  
  std::cout << "La posicion actual: " << ubicacion[0] << ", " << ubicacion[1] << std::endl;
}