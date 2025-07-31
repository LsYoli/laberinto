/**
* @file main.cpp
* @brief Programa principal con selección de tipo de avatar
*
* @details 
* - Permite al usuario elegir entre AvatarOriginal y AvatarInnovador
* - Utiliza polimorfismo para manejar diferentes tipos de avatar
* - AvatarOriginal: movimiento aleatorio en 4 direcciones
* - AvatarInnovador: movimiento en forma de L (como caballo de ajedrez)
* 
* @bug_fixer [Daniel Andres Micolta Gongora]
* @mail [micolta.daniel@correounivalle.edu.co]
* @author [Luis Santiago Arenas Hincapie] 
* @mail [luis.arenas@correounivalle.edu.co]
* @date 2025-09-02
* @version 2.0
*/
#include "Avatar.h"
#include "Mapa.h"
#include "Print.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>

int main() {
  Mapa mapa;
  Print print;
  std::unique_ptr<Avatar> avatar;
  
  std::cout << "=== SIMULADOR DE LABERINTO ===" << std::endl;
  std::cout << "Selecciona el tipo de avatar:" << std::endl;
  std::cout << "1. Avatar Original (movimiento aleatorio)" << std::endl;
  std::cout << "2. Avatar Innovador (movimiento en L como caballo de ajedrez)" << std::endl;
  
  int eleccion;
  do {
    std::cout << "Ingresa tu eleccion (1 o 2): ";
    std::cin >> eleccion;
  } while (eleccion != 1 && eleccion != 2);
  
  // Crear el avatar según la elección del usuario
  if (eleccion == 1) {
    avatar = std::make_unique<AvatarOriginal>();
    std::cout << "\n¡Avatar Original seleccionado!" << std::endl;
    std::cout << "Se movera aleatoriamente en 4 direcciones." << std::endl;
  } else {
    avatar = std::make_unique<AvatarInnovador>();
    std::cout << "\n¡Avatar Innovador seleccionado!" << std::endl;
    std::cout << "Se movera en forma de L como el caballo de ajedrez." << std::endl;
    std::cout << "Podras elegir manualmente cada movimiento." << std::endl;
  }
  
  std::cout << "\nCargando laberinto..." << std::endl;
  std::cout << "Los 1 representan caminos seguros, los 0 son abismos mortales." << std::endl;
  std::cout << "\n=== INICIANDO SIMULACION ===" << std::endl;
  
  mapa.cargar_laberinto();
  avatar->posicion_inicial(print, mapa);
  
  if (avatar->get_vivo()) {
    int movimientos = 0;
    do {
      movimientos++;
      std::cout << "\n--- Movimiento " << movimientos << " ---" << std::endl;
      avatar->mover_avatar(print);
      
      // Mostrar el mapa después de cada movimiento para Avatar Innovador
      if (eleccion == 2) {
        std::cout << "\n=== MAPA ACTUAL DEL RECORRIDO ===" << std::endl;
        print.imprimir_recorrido();
        std::cout << "==================================" << std::endl;
      }
      
      if (!avatar->sobrevivencia(mapa, print)) {
        std::cout << "\n¡OH NO! El avatar ha caido en un abismo y ha muerto." << std::endl;
        break;
      }
      
      // Para el avatar innovador, preguntar si quiere continuar
      if (eleccion == 2) {
        char continuar;
        std::cout << "¿Deseas continuar? (s/n): ";
        std::cin >> continuar;
        if (continuar == 'n' || continuar == 'N') {
          std::cout << "Simulacion terminada por el usuario." << std::endl;
          break;
        }
      }
      
    } while (avatar->get_vivo());
  } else {
    std::cout << "¡El avatar inicio en un abismo! Juego terminado." << std::endl;
  }
  
  std::cout << "\n**************RECORRIDO DEL AVATAR**************" << std::endl;
  print.imprimir_recorrido();
  std::cout << "************************************************" << std::endl;
  
  return 0;
}