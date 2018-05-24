#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "Jugador.h"

class Jugadores {

private:
	Lista <Jugador*>* jugadores;

public:
	//Pre: numeroDeJugadores es un entero valido ingresado por el usuario
	//Post: se crea la lista de jugadores.

	Jugadores(unsigned int numeroDeJugadores, int M, int N, int dificultad);

	//Post: devuelve la lista de jugadores.
	Lista <Jugador*>* obtenerListaJugadores();

	~Jugadores();
};

#endif /* JUGADORES_H_ */
