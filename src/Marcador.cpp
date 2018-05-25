/* 
*Marcador.cpp
* Created by:Alvaro
*25 may. 2018
*01:12:38
*/

#include "Marcador.h"
#include <iostream>

using namespace std;

Marcador::Marcador() {}

void Marcador::mostrarTurno(Jugador* jugadorActual){
		Almacen* almacen = jugadorActual->obtenerAlmacen();
		Monedero* monedero = jugadorActual->obtenerMonedero();
		TanqueDeAgua* tanque = jugadorActual->obtenerTanqueDeAgua();

		std::cout<<"//Cantidad de terrenos propios: "<< jugadorActual->obtenerListaTerreno()->contarElementos()<<std::endl;
		std::cout<<"//Dinero disponible: "<< monedero->obtenerDineroActual()<<std::endl;
		std::cout<<"//Uso del tanque de agua: "<< tanque->obtenerCantidadDeAguaActual()<<"/"<<tanque->obtenerCantidadDeAguaMaxima()<<std::endl;
		std::cout<<"//Uso del almacen: "<<almacen->contarCultivos()<<"/"<<almacen->obtenerCapacidad()<<std::endl<<std::endl;

	}

