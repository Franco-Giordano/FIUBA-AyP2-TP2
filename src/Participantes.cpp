/*
 * Jugadores.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: Alvaro
 */

#include "Participantes.h"

Participantes::Participantes(unsigned int numeroDeJugadores, int N, int M, int dificultad) {
	this->participantes = new Lista<Jugador*>;

	for (unsigned int i = 1; i <= numeroDeJugadores; i++) {
		Jugador* jugador = new Jugador(N, M, dificultad);
		participantes->agregar(jugador);
	}

}

Lista<Jugador*>* Participantes::obtenerListaParticipantes() {
	return this->participantes;
}

Participantes::~Participantes() {
	participantes->iniciarCursor();
	while (participantes->avanzarCursor()) {
		delete participantes->obtenerCursor();
	}
	delete participantes;
}
