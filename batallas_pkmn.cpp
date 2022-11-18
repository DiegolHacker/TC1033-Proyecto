#include <iostream>
#include <string>
#include "pokemon.h"
#include "movimiento.h"

int main(){

  Pokemon Charizard("Charizard","Fuego","Volador",78,109,85,100);
  std::cout << "\nVida de Charizard: ";
  std::cout << Charizard.get_hp();
  std::cout << "\nTipo 1: ";
  std::cout << Charizard.get_tipo1();
  std::cout << "\nTipo 2: ";
  std::cout << Charizard.get_tipo2();

  Pokemon Garchomp("Garchomp","Dragon","Tierra",108,130,95,102);
  std::cout << "\n\nVida de Garchomp: ";
  std::cout << Garchomp.get_hp();
  std::cout << "\nTipo 1: ";
  std::cout << Garchomp.get_tipo1();
  std::cout << "\nTipo 2: ";
  std::cout << Garchomp.get_tipo2();

  Pokemon Volcarona("Volcarona","Fuego","Bicho",85,135,105,105);
  Pokemon Zoroark("Zoroark","Siniestro","",60,120,60,105);
  Pokemon Lucario("Lucario","Lucha","Acero",70,115,70,90);

  Movimiento Lanzallamas("Lanzallamas","Fuego",95,100);
  Movimiento Terremoto("Terremoto","Tierra",100,100);
  Movimiento GarraD("Garra Dragon","Dragon",80,100);
  Movimiento Vuelo("Vuelo","Volador",90,90);
  Movimiento AlaAcero("Ala de acero","Acero",90,90);
  Movimiento Triturar("Triturar","Siniestro",80,100);
  Movimiento ABocajarro("A bocajarro", "Lucha", 120, 75)

}
