/*
 * Jugadores.cpp
 *
 *  Created on: 24 may. 2018
 *      Author: Alvaro
 */

#include "Jugadores.h"

Jugadores::Jugadores(unsigned int numeroDeJugadores, int N, int M, int dificultad) {
	this->jugadores= new Lista<Jugador*>;

	for (unsigned int i=1; i<= numeroDeJugadores; i++){
			Jugador* jugador= new Jugador(N, M,dificultad);
			jugadores->agregar(jugador);
		}

}

Lista<Jugador*>* Jugadores::obtenerListaJugadores(){
	return this->jugadores;
}

Jugadores::~Jugadores() {
	delete jugadores;
}
