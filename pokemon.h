
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
  int vida_total;
  int velocidad;

  bool seleccionado = false;


public:
  Movimiento movimientos[4];
  Pokemon(std::string nom, std::string ti1, std::string ti2, int hp, int at, int def, int vel): nombre(nom), tipo1(ti1), tipo2(ti2), vida(hp), ataque(at), defensa(def), velocidad(vel), vida_total(hp){};

  std::string get_nom_mov();

  std::string get_nom();
  int get_hp();
  int get_hp_total();
  int get_at();
  int get_def();
  int get_speed();
  bool get_selec();
  //void get_mov();

  std::string get_tipo1();
  std::string get_tipo2();

  void set_hp(int, int, int, float, float, float); //(int at, int def, int hp, int pot)

  void set_movimiento(Movimiento,int);

  void set_seleccion(bool);

};

//std::string Pokemon::get_nom_mov(int n){
//  return movimiento[n].get_nombreM();}


std::string Pokemon::get_nom(){
  return nombre;
}

int Pokemon::get_hp(){
  return vida;
}

int Pokemon::get_hp_total(){
  return vida_total;
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

bool Pokemon::get_selec(){
  return seleccionado;
}

//void Pokemon::get_mov(int n){
//  return movimientos[n]}



void Pokemon::set_hp(int at, int def, int pot, float var, float efec, float bon){ //var = varianza bon = bonificacion efec = efectividad
  vida = vida - efec*bon*var*(((((((0.2*100)+1)*at*pot)/25)*def)+2));
}

void Pokemon::set_movimiento(Movimiento mov, int posicion){
  movimientos[posicion] = Movimiento(mov.get_nombreM(), mov.get_tipoM(), mov.get_pot(), mov.get_prec());
}


void Pokemon::set_seleccion(bool sel){
  seleccionado = sel;
}
