#ifndef AVATAR_H
#define AVATAR_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Mapa.h"
#include "Print.h"

class Print;

class Avatar{
private:
  std::vector<int> ubicacion = {0,0};
  bool vivo = true;
  int dirreccion;

public:
  bool posicion_inicial(Print &print, Mapa &mapa);
  void mover_avatar(Print &print);
  bool sobrevivencia(Mapa &mapa, Print &print);
  bool verificar_movimiento(std::vector<int> ubicacion, int dirreccion, bool &vivo);
  bool get_vivo(){return vivo;};
};
#endif