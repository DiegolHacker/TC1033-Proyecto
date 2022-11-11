# TC1033-Proyecto
Mi proyecto es un simulador de batallas entre diferentes Pokémon, replicando la funcionalidad y jugabilidad de la serie de videojuegos, programado en c++ usando clases y métodos. Funciona en la consola.
## Contexto
Para llevar a cabo una batalla entre pokemon, primero se necesita seleccionar uno, y luego hacerlo usar un movimiento para hacer daño al pokémon enemigo basandose en los tipos tanto de ambos pokémon como de los movimientos pues estos pueden ofrecer ventaja o resistenica dependiendo de con qué tipo interactúen. El combate finaliza cuando uno de los 2 pokémon se debilita, y tiene un estilo de combate por turnos.
## Fucionalidad
El programa permite al usuario seleccionar un pokémon de una lista predeterminada, el cuál contará con diferentes características como lo son sus estadísticas de combate (ataque, defensa, vida, velocidad); sus tipos elementales; y sus movimientos, los cuáles a su vez constituyen otra clase donde se puede definir su potencia, tipo, y precisión. Este pokémon será usado para tener combates por turnos con otro pokémon, y estos podrán usar diferentes ataques para reducir la vida del enemigo y ganar.
## Consideraciones
Compilar con:
    "g++ pokemon.h movimiento.h batallas_pkmn.cpp"
    
 Correr en linux con:
      "/a.out"
      
 Correr en windows con:
      "a.exe"
