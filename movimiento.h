#include <string>

class Movimiento{
private:
  std::string nombre;
  std::string tipo;
  int potencia;
  int precision;


public:
  Movimiento(std::string nom, std::string tip, int pot, int prec): nombre(nom), tipo(tip), potencia(pot), precision(prec){};
  std::string get_nombre();
  std::string get_tipo();
  int get_pot();
  int get_prec();
};


std::string Movimiento::get_nombre(){
  return nombre;
}

std::string Movimiento::get_tipo(){
  return tipo;
}

int Movimiento::get_pot(){
  return potencia;
}

int Movimiento::get_prec(){
  return precision;
}
