/*
 * Marcador.h
 *
 *  Created on: 23 may. 2018
 *      Author: frank
 */

#ifndef MARCADOR_H_
#define MARCADOR_H_

#include "Jugador.h"
#include <iostream>

class Marcador {
private:

public:
	void mostrarTurno(Jugador* jugadorActual){
		Almacen* almacen = jugadorActual->obtenerAlmacen();
		Monedero* monedero = jugadorActual->obtenerMonedero();
		TanqueDeAgua* tanque = jugadorActual->obtenerTanqueDeAgua();



		std::cout<<"//Cantidad de terrenos propios: "<< jugadorActual->obtenerListaTerreno()->contarElementos()<<std::endl;
		std::cout<<"//Dinero disponible: "<< monedero->obtenerDineroActual()<<std::endl;
		std::cout<<"//Uso del tanque de agua: "<< tanque->obtenerCantidadDeAguaActual()<<"/"<<tanque->obtenerCantidadDeAguaMaxima()<<std::endl;
		std::cout<<"//Uso del almacen: "<<almacen->contarCultivos()<<"/"<<almacen->obtenerCapacidad()<<std::endl<<std::endl;

	}

	void mostrarPuntuacionFinal() {

	}


};


#endif /* MARCADOR_H_ */
