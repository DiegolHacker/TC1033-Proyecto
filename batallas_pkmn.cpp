#include <iostream>
#include <string>
#include "pokemon_malvado.h"
#include <stdlib.h>
#include <random> //Librería usada para la creación de números aleatorios.

#include <conio.h> //Librería usada para la función getch(), para poder esperar un input del usuario antes de continuar.

#include <time.h> //Librería usada para cambiar la semilla de generación de números aleatorios cada segundo (para poder generar diferentes números con cada ejecución).


void prntDatos(Pokemon poke, std::string num){ //Esta función imprime los datos de cada pokemon, usada al momento de elegir un pokemon.

  std::cout <<"\n\n"<<num<<". " <<poke.get_nom();
  std::cout << "\nTipo 1: "<< poke.get_tipo1();
  std::cout << "\nTipo 2: "<< poke.get_tipo2();
  std::cout <<"\nVida: "<< poke.get_hp();
  std::cout <<"\nAtaque: "<< poke.get_at();
  std::cout <<"\nDefensa: "<< poke.get_def();
  std::cout <<"\nVelocidad: "<< poke.get_speed();
}

bool batalla = true; //Inicializa la variable que define si la batalla continua o ya ha terminado.

void prntDatosUIEne(PokeMalo pokeEne){ //Función usada para mostrar los datos del Pokémon enemigo en un formato amigable durante la batalla.
  std::system("CLS"); //Función para limpiar la consola.
  std::cout<<"                         "<<pokeEne.get_nom()<<"\n                         HP: "<<pokeEne.get_hp()<<"/"<<pokeEne.get_hp_total()<<"\n\n";
}

void prntDatosUI(Pokemon poke){ //Función que sirve para mostrar los datos del Pokémon aliado durante la batalla.
  std::cout <<"\n\n"<< poke.get_nom()<<"\nHP: "<<poke.get_hp()<<"/"<<poke.get_hp_total();
  std::cout<<"\n\nMovimientos:\n1. "<<poke.movimientos[0].get_nombreM()<<"\n2. "<<poke.movimientos[1].get_nombreM()<<"\n3. "<<poke.movimientos[2].get_nombreM()<<"\n4. "<<poke.movimientos[3].get_nombreM();

}


void comprobar_batalla(Pokemon *poke, PokeMalo *pokeEne){ //Función que comprueba si los pokémon se han debilitado.

  if (pokeEne->get_hp() < 0){
    pokeEne->set_hpEz(0); //En caso de que un pokémon alcance una cantidad de vida negativa, esta vuelve a 0 automáticamente.
  }
  if (pokeEne->get_hp() == 0){
    std::cout<<"\n"<<pokeEne->get_nom()<<" se ha debilitado, felicidades, has ganado!"<<"\n\nSu nivel de maldad era: "<<pokeEne->get_maldad()<<"."; //Mensaje de victoria si el pokémon enemigo se debilita.
  }

  if (poke->get_hp() < 0){
    poke->set_hpEz(0);
  }

  if (poke->get_hp() == 0){
    std::cout<<"\n"<<poke->get_nom()<<" se ha debilitado, has perdido el combate...";
  }

}

void selecMovimiento(Pokemon *poke, PokeMalo *pokeEne){ //Función que sirve para seleccionar el movimiento a usar durante el combate, así como calcular el daño que este ejerce sobre el pokémon enemigo.
  bool valido = false;
  int seleccion = 0;
  while (valido == false){ //Ciclo activo hasta seleccionar una opción de movimiento válida.
    std::cout<<"\n\nIngresa el numero del movimiento de tu eleccion: ";
    std::cin >> seleccion;

    if (seleccion == 1){ //Uso de apuntadores de memoria para poder usar los objetos reales dentro de la función en lugar de solo una copia, pudiendo así modificar los datos del pokémon a través de sus setters.
      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[0].get_pot(), 1, poke->movimientos[0].get_efec()); //Función de cálculo de daño aplicada al pokémon enemigo, llamando las variables que este cálculo requiere.
      valido = true;
    }
    else if (seleccion == 2){ //Misma metodología usada en cada movimiento según cual haya sido seleccionado.
      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[1].get_pot(), 1, poke->movimientos[1].get_efec());
      valido = true;
    }
    else if (seleccion == 3){
      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[2].get_pot(), 1, poke->movimientos[2].get_efec());
      valido = true;
    }
    else if (seleccion == 4){
      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[3].get_pot(), 1, poke->movimientos[3].get_efec());
      valido = true;
    }

    else {
      std::cout<<"Seleccion invalida, intente de nuevo";

    }
  }
}

void ataqueEnemigo(PokeMalo *poke, Pokemon *pokeEne){ //Función para calcuar el daño que el pokemón enemigo ejerce sobre el aliado en cada turno.

  srand(time(0)); //Se cambia la semilla de generación de números aleatorios en cada segundo para obtener diferentes resultados con cada ejecusión de la función.
  int randomNum = rand(); //Se guarda un número aleatorio dentro de una variable RandomNum, este número tiene como límite el valor arbitrario guardado en la constante RAND_MAX.
  int seleccion = (randomNum%10)/2; //Para obtener un número dentro del rango que necesita el programa, tomé solo el último dígito  del número generado
                                    //a través de obtener su residuo después de dividirlo entre 10, luego dividí entre 2 para obtener números del 0 al 5.
    int espera;
    if (seleccion == 1){ //El número generado es usado para seleccionar el movimiento que usará el pokémon enemigo.

      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[0].get_pot(), 1, poke->movimientos[0].get_efec());
      std::cout<<poke->get_nom()<<" ha usado "<<poke->movimientos[0].get_nombreM();
      //espera = getch();

    }
    else if (seleccion == 2){

      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[1].get_pot(), 1, poke->movimientos[1].get_efec());
      std::cout<<poke->get_nom()<<" ha usado "<<poke->movimientos[1].get_nombreM();
      //espera = getch();

    }
    else if (seleccion == 3){

      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[2].get_pot(), 1, poke->movimientos[2].get_efec());
      std::cout<<poke->get_nom()<<" ha usado "<<poke->movimientos[2].get_nombreM();
      //espera = getch();

    }
    else if (seleccion == 4){

      pokeEne->set_hp(poke->get_at(), pokeEne->get_def(), poke->movimientos[3].get_pot(), 1, poke->movimientos[3].get_efec());
      std::cout<<poke->get_nom()<<" ha usado "<<poke->movimientos[3].get_nombreM();
      //espera = getch();
    }
    else { //En caso de que el número generado sea 0 o 5, el pokémon enemigo descansa ese turno. Teniendo la suerte de que descanse en varios turnos es posible ganar el combate.
      std::cout<<poke->get_nom()<<" se ha quedado observando... ";
      //espera = getch();
    }



    }



int main(){

  std::system("CLS"); //Función para limpiar la consola.

  Movimiento Lanzallamas("Lanzallamas","Fuego",95,100,1); //Creación de los objetos de la clase Movimiento.
  Movimiento Terremoto("Terremoto","Tierra",100,100,1);
  Movimiento GarraD("Garra Dragon","Dragon",80,100,1);
  Movimiento Vuelo("Vuelo","Volador",90,90,1);
  Movimiento AlaAcero("Ala de acero","Acero",90,90,1);
  Movimiento Triturar("Triturar","Siniestro",80,100,2);
  Movimiento ABocajarro("A bocajarro", "Lucha", 120, 75,0.5);
  Movimiento RocaAfilada("Roca Afilada", "Roca", 100, 80,1);
  Movimiento Zumbido("Zumbido", "Bicho", 90, 100,2);
  Movimiento Psiquico("Psiquico", "Psiquico", 90, 100,0.5);

  Pokemon Charizard("Charizard","Fuego","Volador",297,254,206,236); //Creción de los objetos de la clase Pokemon
  Charizard.set_movimiento(Lanzallamas, 0); //Asignación de los movimientos disponibles para cada pokémon, rellenando los espacios de los movimientos generados por el constructor default.
  Charizard.set_movimiento(Vuelo, 1);
  Charizard.set_movimiento(AlaAcero, 2);
  Charizard.set_movimiento(GarraD, 3);

  Pokemon Garchomp("Garchomp","Dragon","Tierra",357,296,226,240);
  Garchomp.set_movimiento(GarraD, 0);
  Garchomp.set_movimiento(Terremoto, 1);
  Garchomp.set_movimiento(Triturar, 2);
  Garchomp.set_movimiento(RocaAfilada, 3);

  Pokemon Volcarona("Volcarona","Fuego","Bicho",311,306,246,236);
  Volcarona.set_movimiento(Zumbido, 0);
  Volcarona.set_movimiento(Lanzallamas, 1);
  Volcarona.set_movimiento(Psiquico, 2);
  Volcarona.set_movimiento(Vuelo, 3);

  Pokemon Lucario("Lucario","Lucha","Acero",281,266,176,286);
  Lucario.set_movimiento(ABocajarro,0);
  Lucario.set_movimiento(Psiquico,1);
  Lucario.set_movimiento(RocaAfilada,2);
  Lucario.set_movimiento(Terremoto,3);

  PokeMalo Mewtwo("Mewtwo", "Psiquico", " ",353,344,192,272);
  Mewtwo.set_movimiento(Psiquico,0);
  Mewtwo.set_movimiento(ABocajarro,1);
  Mewtwo.set_movimiento(Terremoto,2);
  Mewtwo.set_movimiento(Lanzallamas,3);


  srand(time(0)); //Generación de números aleatorios siguiendo la misma lógica que en la función de daño del enemigo.
  int ranNum = rand();
  int NumMaldad = (ranNum%10)/2;

  if (NumMaldad == 0){ //Definición del nivel de maldad en base al número aleatorio obtenido.
    Mewtwo.set_maldad("nulo");
  }
  else if (NumMaldad == 1){
    Mewtwo.set_maldad("bajo");
  }
  else if (NumMaldad == 2){
    Mewtwo.set_maldad("medio");
  }
  else if (NumMaldad == 3){
    Mewtwo.set_maldad("alto");
  }
  else if (NumMaldad == 4){
    Mewtwo.set_maldad("enorme");
  }
  else if (NumMaldad == 5){
    Mewtwo.set_maldad("extremo");
  }

  std::cout << "Bienvenido a esta batalla Pokemon, elige un Pokemon para comenzar:\n"; //Mensaje de bienvenida.

  prntDatos(Charizard,"1"); //Impresión de los datos de cada pokémon disponible para el usuario en pantalla.
  prntDatos(Garchomp,"2");
  prntDatos(Volcarona,"3");
  prntDatos(Lucario,"4");


  int seleccion;
  bool valido = false;
  while (valido == false){ //Ciclo de validación de la selección de un pokémon, falso hasta que una selección válida sea realizada.
    std::cout<<"\n\nIngresa el numero del Pokemon de tu seleccion: ";
    std::cin >> seleccion;

    if (seleccion == 1){
      Charizard.set_seleccion(true); //Asiganción del atributo de seleccion a verdadero para el pokémon que haya sido seleccionado.
      valido = true; //Selección válida.
    }
    else if (seleccion == 2){
      Garchomp.set_seleccion(true);
      valido = true;
    }
    else if (seleccion == 3){
      Volcarona.set_seleccion(true);
      valido = true;
    }
    else if (seleccion == 4){
      Lucario.set_seleccion(true);
      valido = true;
    }
    else {
      std::cout<<"Seleccion invalida, intente de nuevo";
    }
  }



while (batalla == true){ //Ciclo que se repetira durante la duración de la batalla, hasta que alguno o ambos pokémon se debiliten.

  int espera;

    prntDatosUIEne(Mewtwo); //Impresión de los datos del pokémon enemigo arriba de la consola.

    if (Charizard.get_selec() == true){ //Comprueba si este pokémon cuenta con el atributo de seleccion como verdadero.
      prntDatosUI(Charizard); //Imprime los datos de combate del pokémon aliado.
      selecMovimiento(&Charizard, &Mewtwo); //Realiza la selección de un movimiento para atacar al pokémon enemigo, y calcula el daño en base a las estadísticas de ambos pokémon y del movimiento.
      ataqueEnemigo(&Mewtwo, &Charizard); //Realiza el calculo de daño y la selección del movimiento de igual forma pero para el pokémon aliado.
      comprobar_batalla(&Charizard, &Mewtwo); //Ejecuta la función para comprobar si algún pokémon se ha debilitado.
      espera = getch(); //Espera a recibir un input del usuario para continuar con la batalla.
    }
    else if (Garchomp.get_selec()==true){ //Misma aplicación de las funciones en caso de que otro pokémon haya sido seleccionado.
      prntDatosUI(Garchomp);
      selecMovimiento(&Garchomp, &Mewtwo); //Se utilizan apuntadores para especificar que se quiere trabajar con los objetos originales y no con copias con el find e poder modificar sus atributos.
      ataqueEnemigo(&Mewtwo, &Garchomp);
      comprobar_batalla(&Garchomp, &Mewtwo);
      espera = getch();
    }
    else if (Volcarona.get_selec()==true){
      prntDatosUI(Volcarona);
      selecMovimiento(&Volcarona, &Mewtwo);
      ataqueEnemigo(&Mewtwo, &Volcarona);
      comprobar_batalla(&Volcarona, &Mewtwo);
      espera = getch();
    }
    else if (Lucario.get_selec()==true){
      prntDatosUI(Lucario);
      selecMovimiento(&Lucario, &Mewtwo);
      ataqueEnemigo(&Mewtwo, &Lucario);
      comprobar_batalla(&Lucario, &Mewtwo);
      espera = getch();
    }
    if (Charizard.get_hp() == 0 || Garchomp.get_hp() == 0 || Volcarona.get_hp() == 0 || Lucario.get_hp() == 0 || Mewtwo.get_hp() == 0){ //Comprobación final de si un pokémon ha sido debilitado para finalizar el ciclo de batalla.
      batalla = false;}

  }
}
