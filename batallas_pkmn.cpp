#include <iostream>
#include <string>
#include "pokemon.h"

void prntDatos(Pokemon poke, std::string num){

  std::cout <<"\n\n"<<num<<". " <<poke.get_nom();
  std::cout << "\nTipo 1: "<< poke.get_tipo1();
  std::cout << "\nTipo 2: "<< poke.get_tipo2();
  std::cout <<"\nVida: "<< poke.get_hp();
  std::cout <<"\nAtaque: "<< poke.get_at();
  std::cout <<"\nDefensa: "<< poke.get_def();
  std::cout <<"\nVelocidad: "<< poke.get_speed();

}
int main(){



  Movimiento Lanzallamas("Lanzallamas","Fuego",95,100);
  Movimiento Terremoto("Terremoto","Tierra",100,100);
  Movimiento GarraD("Garra Dragon","Dragon",80,100);
  Movimiento Vuelo("Vuelo","Volador",90,90);
  Movimiento AlaAcero("Ala de acero","Acero",90,90);
  Movimiento Triturar("Triturar","Siniestro",80,100);
  Movimiento ABocajarro("A bocajarro", "Lucha", 120, 75);
  Movimiento RocaAfilada("Roca Afilada", "Roca", 100, 80);
  Movimiento Zumbido("Zumbido", "Bicho", 90, 100);
  Movimiento Psiquico("Psiquico", "Psiquico", 90, 100);

  Pokemon Charizard("Charizard","Fuego","Volador",78,109,85,100);
  Charizard.set_movimiento(Lanzallamas, 0);
  Charizard.set_movimiento(Vuelo, 1);
  Charizard.set_movimiento(AlaAcero, 2);
  Charizard.set_movimiento(GarraD, 3);

  Pokemon Garchomp("Garchomp","Dragon","Tierra",108,130,95,102);
  Garchomp.set_movimiento(GarraD, 0);
  Garchomp.set_movimiento(Terremoto, 1);
  Garchomp.set_movimiento(Triturar, 2);
  Garchomp.set_movimiento(GarraD, 3);

  Pokemon Volcarona("Volcarona","Fuego","Bicho",85,135,105,105);
  Volcarona.set_movimiento(Zumbido, 0);
  Volcarona.set_movimiento(Lanzallamas, 1);
  Volcarona.set_movimiento(Psiquico, 2);
  Volcarona.set_movimiento(Vuelo, 3);

  Pokemon Lucario("Lucario","Lucha","Acero",70,115,70,90);
  Lucario.set_movimiento(ABocajarro,0);
  Lucario.set_movimiento(Psiquico,1);
  Lucario.set_movimiento(RocaAfilada,2);
  Lucario.set_movimiento(Terremoto,3);

  std::cout << "Bienvenido a esta batalla Pokemon, elige un Pokemon para comenzar:\n";

  prntDatos(Charizard,"1");
  prntDatos(Garchomp,"2");
  prntDatos(Volcarona,"3");
  prntDatos(Lucario,"4");

  int seleccion;
  std::cout<<"\n\nIngresa el numero del Pokemon de tu seleccion: ";
  std::cin >> seleccion;



}
