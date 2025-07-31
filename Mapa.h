#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Mapa{
private:
  const std::string fileName = "laberinto.txt";
  std::vector<std::vector<int>> laberinto;

public:
  void cargar_laberinto();
  bool obtener_valor(std::vector<int> &ubicacion);

};
#endif