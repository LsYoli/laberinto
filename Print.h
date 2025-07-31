#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include <vector>
#include "Avatar.h"

class Print{
private:
  std::vector<std::vector<std::string>> recorrido;

public:
  Print();
  void imprimir_recorrido();
  void guardar_recorrido(std::vector<int> &ubicacion, int &dirreccion, bool &vivo);

};
#endif

