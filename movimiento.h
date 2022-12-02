
#include <string>
#include <sstream>

class Movimiento{ //Creación de la clase Movimiento.
private:
  std::string nombreM; //Definición de los atributos privados de la clase Movimiento.
  std::string tipoM;
  int potencia;
  int precision;
  float efectividad;

public:
  Movimiento(): nombreM("a"), tipoM("o"),potencia(0),precision(0),efectividad(1){}; //Constructor por defecto para la clase Movimiento.
  Movimiento(std::string nom, std::string tip, int pot, int prec, float efec): nombreM(nom), tipoM(tip), potencia(pot), precision(prec), efectividad(efec){}; //Constructor con todos los atributos de la clase movimiento.
  std::string get_nombreM(); //Getter para el atributo de nombre.
  std::string get_tipoM(); //Getter para el atributo de tipo.
  int get_pot(); //Getter para el atributo de potencia.
  int get_prec(); //Getter para el atributo de precision.
  float get_efec(); //Getter para el atributo de efectividad.
  //No se definen setters pues los atributos de cada movimiento no deben ser modificados después de su creación.
};

std::string Movimiento::get_nombreM(){
  return nombreM;
}

std::string Movimiento::get_tipoM(){
  return tipoM;
}

int Movimiento::get_pot(){
  return potencia;
}

int Movimiento::get_prec(){
  return precision;
}

float Movimiento::get_efec(){
  return efectividad;
}
