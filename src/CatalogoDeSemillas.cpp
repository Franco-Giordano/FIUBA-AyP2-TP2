/*
 * CatalogoDeSemillas.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: frank
 */

#include "CatalogoDeSemillas.h"


CatalogoDeSemillas::CatalogoDeSemillas(Lista<std::string*>* datosCSV) {
	cantidadDisponible = datosCSV->contarElementos();
	semillas = new Cultivo[cantidadDisponible];

	ConversorDeDatos conversor;

	datosCSV->iniciarCursor();
	std::string* datosCultivoActual;

	int posicion = 0;
	while (datosCSV->avanzarCursor()) {
		datosCultivoActual = datosCSV->obtenerCursor();

		Cultivo cultivoActual;
		conversor.convertirCultivo(datosCultivoActual, cultivoActual);

		semillas[posicion] = cultivoActual;
		posicion++;
	}
}


Cultivo* CatalogoDeSemillas::obtenerPosicion(ui pos) {
	return &semillas[pos];
}


unsigned int CatalogoDeSemillas::obtenerCantidadDisponible() {
	return cantidadDisponible;
}


CatalogoDeSemillas::~CatalogoDeSemillas() {
	delete[] semillas;
}


