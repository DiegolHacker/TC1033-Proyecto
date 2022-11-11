#include<string>

class Movimiento{
private:
  std::string nombre;
  int potencia;
  int precision;


public:
  Movimiento(std::string nom, int pot, int prec): nombre(nom), potencia(pot), precision(prec){};
};
