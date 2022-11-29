
#include <string>
#include <sstream>

class Movimiento{
private:
  std::string nombreM;
  std::string tipoM;
  int potencia;
  int precision;


public:
  Movimiento(): nombreM("a"), tipoM("o"),potencia(0),precision(0){};
  Movimiento(std::string nom, std::string tip, int pot, int prec): nombreM(nom), tipoM(tip), potencia(pot), precision(prec){};
  std::string get_nombreM();
  std::string get_tipoM();
  int get_pot();
  int get_prec();
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
