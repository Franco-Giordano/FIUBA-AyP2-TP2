/*
 * Terreno.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#include "Terreno.h"

Terreno::Terreno(unsigned int cantidadFilasRecibidas, unsigned int cantidadColumnasRecibidas) {

	if (cantidadFilasRecibidas > 0 && cantidadColumnasRecibidas > 0) {

		this->limiteFilas = cantidadFilasRecibidas;
		this->limiteColumnas = cantidadColumnasRecibidas;

		filas = new ListaCoordenada<ListaCoordenada<Parcela*>*>(limiteFilas);
	} else {
		throw std::string("La cantidad de filas o columnas es inválida.");
	}
}

unsigned int Terreno::obtenerFilas() {

	return this->limiteFilas;
}

ListaCoordenada<ListaCoordenada<Parcela*>*>* Terreno::obtenerListaFilas() {
	return this->filas;
}

unsigned int Terreno::obtenerColumnas() {

	return this->limiteColumnas;
}

Parcela* Terreno::obtenerParcela(unsigned int filaElegida, unsigned int columnaElegida) {

	return filas->obtenerEnCoordenada(filaElegida)->obtenerEnCoordenada(columnaElegida);
}

bool Terreno::estaOcupada(unsigned int filaRecibida, unsigned int columnaRecibida) {

	return filas->estaOcupadaLaCoordenada(filaRecibida) && filas->obtenerEnCoordenada(filaRecibida)->estaOcupadaLaCoordenada(columnaRecibida);
}

void Terreno::prepararParcela(unsigned int fila, unsigned int columna) {
	if (!estaOcupada(fila, columna)) {

		Parcela* parcelaVacia = new Parcela;

		if (filas->estaOcupadaLaCoordenada(fila)) {
			ListaCoordenada<Parcela*>* filaExistente = filas->obtenerEnCoordenada(fila);
			filaExistente->agregarEnCoordenada(parcelaVacia, columna);
		}

		else {
			ListaCoordenada<Parcela*>* columnaNueva = new ListaCoordenada<Parcela*>(this->obtenerColumnas());
			columnaNueva->agregarEnCoordenada(parcelaVacia, columna);
			filas->agregarEnCoordenada(columnaNueva, fila);
		}
	}
}

bool Terreno::estaTodoVacio() {
	return this->obtenerListaFilas()->contarElementos() == 0;
}

Terreno::~Terreno() {
	filas->iniciarCursor();
	while (filas->avanzarCursor()) {
		ListaCoordenada<Parcela*>* colActual = filas->obtenerCursor();
		colActual->iniciarCursor();
		while (colActual->avanzarCursor()) {
			delete colActual->obtenerCursor();
		}
		delete colActual;
	}
	delete filas;
}
;
