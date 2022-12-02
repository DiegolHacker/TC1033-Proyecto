
#include <string>
#include <iostream>
#include <cstdlib>
#include "movimiento.h"


class Pokemon{ //Creación de la clase Pokémon.
private:
  std::string nombre; //Definición de los atributos privados de la clase Movimiento.
  std::string tipo1;
  std::string tipo2;
  int ataque;
  int defensa;
  int vida;
  int vida_total;
  int velocidad;

  bool seleccionado = false; //Establecimiento del atributo de seleccion para cada objeto de la clase Pokemon. false por defecto.


public:
  Movimiento movimientos[4]; //Creación de una lista de 4 movimientos vacíos por cada pokémon.
  Pokemon(std::string nom, std::string ti1, std::string ti2, int hp, int at, int def, int vel): nombre(nom), tipo1(ti1), tipo2(ti2), vida(hp), ataque(at), defensa(def), velocidad(vel), vida_total(hp){}; //Constructor de la clase Pokémon.


  std::string get_nom(); //Getter para el atributo de nombre.
  int get_hp(); //Getter para el atributo de vida.
  int get_hp_total(); //Getter para el atributo de vida_total.
  int get_at(); //Getter para el atributo de ataque.
  int get_def(); //Getter para el atributo de defensa.
  int get_speed(); //Getter para el atributo de velocidad.
  bool get_selec(); //Getter para el atributo de seleccion.

  std::string get_tipo1(); //Getter para el atributo de tipo1.
  std::string get_tipo2(); //Getter para el atributo de tipo2.

  void set_hp(int, int, int, float, float); //(int at, int def, int hp, int pot) Setter para la vida del pokémon después de recibir un ataque.
  void set_hpEz(int); //Setter para la vida del pokémon de forma directa.

  void set_movimiento(Movimiento,int); //Setter para definir los movimientos con los que el pokémon cuenta, dando el nombre del objeto movimiento y su lugar, o index, dentro de la lista de movimientos.

  void set_seleccion(bool); //Setter para la selección de un pokémon.

};


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



void Pokemon::set_hp(int at, int def, int pot, float var, float efec){ //var = varianza, efec = efectividad
  vida = vida - (((42*pot*(at/def))/50)+2);  //Fórmula para el cálculo del daño según las características de ambos pokémon involucrados y del movimiento usado.
}

void Pokemon::set_hpEz(int hp){
  vida = hp;
}

void Pokemon::set_movimiento(Movimiento mov, int posicion){
  movimientos[posicion] = Movimiento(mov.get_nombreM(), mov.get_tipoM(), mov.get_pot(), mov.get_prec(), mov.get_efec()); //Clonación de los datos del movimiento elegido dentro de los movimientos vacíos que se encuentran en la lista por defecto.
}


void Pokemon::set_seleccion(bool sel){
  seleccionado = sel;
}
