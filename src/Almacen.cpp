/*
 * Almacen.cpp
 *
 *  Created on: 6 may. 2018
 *      Author: Alvaro
 */

#include "Almacen.h"
#include <iostream>
using namespace std;

Almacen::Almacen(int N, int M, int dificultad) {
	this->capacidad = (2 * (N + M)) / dificultad;
	this->cultivos = new Lista<Cultivo*>;
}

int Almacen::obtenerCapacidad() {
	return this->capacidad;
}

bool Almacen::capacidadValida() {
	return (cultivos->contarElementos() <= capacidad);
}

void Almacen::agrandarAlmacen(unsigned int capacidadAAgregar) {

	this->capacidad += capacidadAAgregar;
}

void Almacen::agregarCultivo(Cultivo* cultivo) {
	cultivos->agregar(cultivo);
}

int Almacen::contarCultivos() {
	return this->cultivos->contarElementos();
}

bool Almacen::hayEspacioLibre() {
	return this->obtenerCapacidad() > this->contarCultivos();
}

void Almacen::quitarCultivo(int posicion) {
	cultivos->remover(posicion);
}

void Almacen::mostrarNombresDeCultivosEnElAlmacen() {
	cultivos->iniciarCursor();
	int i = 1;
	while (cultivos->avanzarCursor()) {
		cout << i << ". " << cultivos->obtener(i)->obtenerNombre() << endl;
		i++;
	}

}

Cultivo* Almacen::obtenerCultivoEnPosicion(unsigned int posicion) {
	return this->cultivos->obtener(posicion);
}

Almacen::~Almacen() {
	delete cultivos;
}
