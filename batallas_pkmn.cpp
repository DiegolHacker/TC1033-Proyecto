#include <iostream>
#include <string>
#include "pokemon.h"
#include "movimiento.h"

int main(){

  Pokemon Charizard("Charizard","Fuego","Volador",109,85,78,100);
  std::cout <<"Vida de Charizard: ";
  std::cout << Charizard.get_hp();
}
