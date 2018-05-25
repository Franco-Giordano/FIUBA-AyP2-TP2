/*
 * Tiempo.cpp
 *
 *  Created on: 23 may. 2018
 *      Author: fedei
 */

#include "Tiempo.h"

Tiempo::Tiempo(Jugador* jugadorRecibido){

	this -> jugador = jugadorRecibido;

}

void Tiempo::madurarParcela(Terreno* terrenoRecibido,unsigned int fila,
													unsigned int columna){

	Parcela* parcela = terrenoRecibido->obtenerParcela(fila,columna);

	if (parcela->obtenerEstado() == Plantada && parcela->estaRegada() &&  parcela->obtenerTiempoCosecha()>0){

		parcela->modificarTiempoCosecha(parcela->obtenerTiempoCosecha() - 1);
		parcela->secar();
	}
	else if (parcela->obtenerEstado() == Plantada && !parcela->estaRegada()){

		parcela->modificarEstado(Recuperando);
	}
	else if (parcela->obtenerEstado() == Recuperando && parcela->obtenerTiempoRecuperacion() > 0){

		parcela->modificarTiempoRecuperacion(parcela->obtenerTiempoRecuperacion() - 1);
	}
	else if (parcela->obtenerEstado() == Recuperando && parcela->obtenerTiempoRecuperacion() == 0){

		this -> liberarParcela(terrenoRecibido,fila,columna);
	}
	else if (parcela->obtenerEstado() == Plantada && parcela->obtenerTiempoCosecha() == 0){

		parcela->modificarEstado(ListaParaCosecha);
	}
	else if (parcela->obtenerEstado() == ListaParaCosecha){

		parcela->modificarEstado(Recuperando);
		parcela->modificarTiempoRecuperacion(parcela->obtenerTiempoRecuperacion()/2);
	}

}

void Tiempo::liberarParcela(Terreno* terrenoRecibido, unsigned int fila, unsigned int columna){

	//Libero parcela.
	Parcela* parcelaABorrar = terrenoRecibido->obtenerParcela(fila,columna);
	delete parcelaABorrar;

	//Elimino el nodo.
	if (terrenoRecibido->obtenerListaFilas()->obtenerEnCoordenada(fila)->contarElementos() > 1){
		terrenoRecibido->obtenerListaFilas()->obtenerEnCoordenada(fila)->removerCoordenada(columna);
	}
	else {
		terrenoRecibido->obtenerListaFilas()->removerCoordenada(fila);
	}
}


void Tiempo::madurarTerreno(Terreno* terrenoRecibido) {

	for (unsigned int i=1; i<=terrenoRecibido->obtenerListaFilas()->contarElementos(); i++){
		ListaCoordenada<Parcela*>* filaActual = terrenoRecibido->obtenerListaFilas()->obtener(i);

		for (unsigned int j=1; j <= filaActual->contarElementos(); j++){

			unsigned int fila = terrenoRecibido->obtenerListaFilas()->obtenerCoordenadaDeLaPosicion(i);
			unsigned int columna = filaActual->obtenerCoordenadaDeLaPosicion(j);

			this->madurarParcela(terrenoRecibido, fila, columna);
		}
	}
}


void Tiempo::madurarTodosLosTerrenosDelJugador() {

	this->jugador->obtenerListaTerreno()->iniciarCursor();

	while (this->jugador->obtenerListaTerreno()->avanzarCursor()){
		Terreno* terrenoActual = this->jugador->obtenerListaTerreno()->obtenerCursor();

		this->madurarTerreno(terrenoActual);
	}
}
