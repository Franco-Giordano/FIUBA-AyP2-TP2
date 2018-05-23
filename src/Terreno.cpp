/*
 * Terreno.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#include "Terreno.h"

Terreno::Terreno(int cantidadFilasRecibidas, int cantidadColumnasRecibidas){

		if (cantidadFilasRecibidas > 0 && cantidadColumnasRecibidas > 0)
		{

			this->limiteFilas = cantidadFilasRecibidas;
			this -> limiteColumnas = cantidadColumnasRecibidas;

			terreno = new ListaCoordenada<ListaCoordenada<Parcela*>*>(limiteFilas);
		}
		else
		{
			throw std::string("La cantidad de filas o columnas es inválida.");
		}
	}

int Terreno::obtenerFilas(){

	return this->limiteFilas;
}

int Terreno::obtenerColumnas(){

	return this->limiteColumnas;
}


Parcela*  Terreno::obtenerParcela(int filaElegida, int columnaElegida){

	return terreno->obtenerEnCoordenada(filaElegida)->obtenerEnCoordenada(columnaElegida);
}

bool Terreno::estaOcupada(int filaRecibida, int columnaRecibida) {
	return terreno->estaOcupadaLaCoordenada(filaRecibida) && terreno->obtenerEnCoordenada(filaRecibida)->estaOcupadaLaCoordenada(columnaRecibida);
}


void Terreno::prepararParcela(int fila, int columna) {



}


Terreno::~Terreno(){
	terreno->iniciarCursor();
	while (terreno->avanzarCursor()) {
		ListaCoordenada<Parcela*>* colActual = terreno->obtenerCursor();
		colActual->iniciarCursor();
		while (colActual->avanzarCursor()) {
			delete colActual->obtenerCursor();
		}
		delete colActual;
	}
	delete terreno;
};



