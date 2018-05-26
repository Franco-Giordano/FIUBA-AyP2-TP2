#ifndef PARTICIPANTES_H_
#define PARTICIPANTES_H_

#include "Jugador.h"

class Participantes {

private:
	Lista<Jugador*>* participantes;

public:
	//Pre: numeroDeJugadores es un entero valido ingresado por el usuario
	//Post: se crea la lista de jugadores.

	Participantes(unsigned int numeroDeJugadores, int M, int N, int dificultad);

	//Post: devuelve la lista de jugadores.
	Lista<Jugador*>* obtenerListaParticipantes();

	virtual ~Participantes();
};

#endif /* PARTICIPANTES_H_ */
