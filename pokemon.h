#include <string>
#include <iostream>
#include <cstdlib>
#include "movimiento.h"


class Pokemon{
private:
  std::string nombre;
  std::string tipo1;
  std::string tipo2;
  int ataque;
  int defensa;
  int vida;
  int velocidad;
  Movimiento




public:
  Pokemon(std::string nom, std::string ti1, std::string ti2, int hp, int at, int def, int vel): nombre(nom), tipo1(ti1), tipo2(ti2), vida(hp), ataque(at), defensa(def), velocidad(vel){};

  std::string get_nom();
  int get_hp();
  int get_at();
  int get_def();
  int get_speed();
  std::string get_tipo1();
  std::string get_tipo2();

  void set_hp(int, int, int, float, float, float); //(int at, int def, int hp, int pot)



};

std::string Pokemon::get_nom(){
  return nombre;
}

int Pokemon::get_hp(){
  return vida;
}

int Pokemon::get_at(){
  return ataque;
}

int Pokemon::get_def(){
  return defensa;
}

int Pokemon::get_speed(){
  return velocidad;
}

std::string Pokemon::get_tipo1(){
  return tipo1;
}

std::string Pokemon::get_tipo2(){
  return tipo2;
}

void Pokemon::set_hp(int at, int def, int pot, float var, float efec, float bon){ //var = varianza bon = bonificacion efec = efectividad
  vida = vida - efec*bon*var*(((((((0.2*100)+1)*at*pot)/25)*def)+2));
}
