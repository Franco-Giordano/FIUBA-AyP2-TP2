/*
 * LectorCSV.cpp
 *
 *  Created on: 19 may. 2018
 *      Author: frank
 */

#include "LectorCSV.h"

LectorCSV::LectorCSV(std::string rutaArchivo, unsigned int cantidadParametros) {

	parametrosPorLinea = cantidadParametros;
	datosGuardados = new Lista<std::string*>;

	std::ifstream entrada;
	entrada.open(rutaArchivo.c_str());
	std::string linea;

	int fila = 0, leyendoParamEnPos = 0;

	while (getline(entrada, linea)) {
		std::string* datosLineaActual = new std::string[cantidadParametros];
		std::stringstream ss(linea);
		while (std::getline(ss, linea, ',')) {

			datosLineaActual[leyendoParamEnPos] = linea;

			leyendoParamEnPos++;
			leyendoParamEnPos %= cantidadParametros;
		}

		datosGuardados->agregar(datosLineaActual);
		fila++;
	}
}

Lista<std::string*>* LectorCSV::obtenerLista() {
	return datosGuardados;
}

unsigned int LectorCSV::obtenerCantParametros() {
	return parametrosPorLinea;
}

LectorCSV::~LectorCSV() {
	datosGuardados->iniciarCursor();
	std::string* linea;

	while (datosGuardados->avanzarCursor()) {
		linea = datosGuardados->obtenerCursor();

		delete[] linea;
	}

	delete datosGuardados;
}

