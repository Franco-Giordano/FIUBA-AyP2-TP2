/*
 * Usuario.cpp
 *
 *  Created on: 5 may. 2018
 *      Author: Alvaro
 */

#include "Jugador.h"

#include "Monedero.h"
#include "Lista.h"

using namespace std;

Jugador::Jugador(int N, int M, int dificultad) {

	this->monedero = new Monedero(N, M, dificultad);
	this->terrenos = new Lista<Terreno*>;
	Terreno* terreno = new Terreno(N, M);
	terrenos->agregar(terreno);
	this->tanque = new TanqueDeAgua(N, M, dificultad);
	this->almacen = new Almacen(N, M, dificultad);
}

Lista<Terreno*>* Jugador::obtenerListaTerreno() {

	return this->terrenos;
}

Monedero* Jugador::obtenerMonedero() {

	return this->monedero;
}

TanqueDeAgua* Jugador::obtenerTanqueDeAgua() {

	return this->tanque;
}

Almacen* Jugador::obtenerAlmacen() {

	return this->almacen;
}

void Jugador::venderTerreno(int terrenoAVender) {

	this->terrenos->remover(terrenoAVender);
}

Jugador::~Jugador() {
	delete monedero;
	delete tanque;
	delete almacen;

	terrenos->iniciarCursor();
	while (terrenos->avanzarCursor()) {
		delete terrenos->obtenerCursor();
	}

	delete terrenos;
}
