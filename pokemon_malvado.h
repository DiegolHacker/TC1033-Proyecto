#include "pokemon.h"
#include <string>
#include <iostream>
#include <cstdlib>

class PokeMalo:public Pokemon{ //Definición de la clase PokeMalo a partir de la clase Pokemon.
private:
  std::string Nivel_Maldad = "nulo"; //Atributo Nivel_Maldad exclusivo para esta clase.
public:
  PokeMalo(std::string nom, std::string ti1, std::string ti2, int hp, int at, int def, int vel):Pokemon(nom, ti1, ti2, hp, at, def, vel){}; //Utiliza la estructura de un cosntructor de un objeto de la clase Pokemon.
  std::string get_maldad(); //Getter para el nivel de maldad.
  void set_maldad(std::string); //Setter para el nivel de maldad.

};

std::string PokeMalo::get_maldad(){
  return Nivel_Maldad;
}

void PokeMalo::set_maldad(std::string maldad){
  Nivel_Maldad = maldad;
}
