#include<string>
#include<iostream>
#include<cstdlib>



class Pokemon{
private:
  std::string nombre;
  std::string tipo1;
  std::string tipo2;
  int ataque;
  int defensa;
  int vida;
  int velocidad;




public:
  Pokemon(std::string nom, std::string ti1, std::string ti2, int at, int def, int hp, int vel): nombre(nom), tipo1(ti1), tipo2(ti2), ataque(at), defensa(def), vida(hp), velocidad(vel){};

  int get_hp();
  void set_hp(int, int, int, float, float, float); //(int at, int def, int hp, int pot)



};

int Pokemon::get_hp(){
  return vida;
}

void Pokemon::set_hp(int at, int def, int pot, float var, float efec, float bon){ //var = varianza bon = bonificacion efec = efectividad
  vida = vida - efec*bon*var*(((((((0.2*100)+1)*at*pot)/25)*def)+2));
}
