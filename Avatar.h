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
protected:
  std::vector<int> ubicacion = {0,0};
  bool vivo = true;
  int dirreccion;

public:
  virtual ~Avatar() = default;
  bool posicion_inicial(Print &print, Mapa &mapa);
  virtual void mover_avatar(Print &print) = 0; // Método virtual puro
  bool sobrevivencia(Mapa &mapa, Print &print);
  bool verificar_movimiento(std::vector<int> ubicacion, int dirreccion, bool &vivo);
  bool get_vivo(){return vivo;};
  std::vector<int> get_ubicacion(){return ubicacion;};
};

// Avatar original que se mueve aleatoriamente
class AvatarOriginal : public Avatar {
public:
  void mover_avatar(Print &print) override;
};

// Avatar innovador que se mueve en forma de L
class AvatarInnovador : public Avatar {
private:
  std::vector<std::vector<int>> movimientos_l = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
  };
  
public:
  void mover_avatar(Print &print) override;
  void mostrar_movimientos_validos(Mapa &mapa);
  bool es_movimiento_valido(int fila, int columna);
};

#endif