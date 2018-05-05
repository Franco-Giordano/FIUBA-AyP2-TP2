/*
 * Cultivo.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#include "Cultivo.h"

Cultivo :: Cultivo(){

	this -> nombre = "VACIO";
	this -> costoSemilla = 0;
	this -> tiempoCosecha = 0;
	this -> rentabilidad = 0;
	this -> tiempoRecuperacion = 0;
}

void Cultivo :: modificarCultivo(std::string nombreRecibido, int costoSemillaRecibido, int tiempoCosechaRecibido, int rentabilidadRecibida, int tiempoRecuperacionRecibido)
{

	this -> nombre = nombreRecibido;
	this -> costoSemilla = costoSemillaRecibido;
	this -> tiempoCosecha = tiempoCosechaRecibido;
	this -> rentabilidad = rentabilidadRecibida;
	this -> tiempoRecuperacion = tiempoRecuperacionRecibido;
}

std::string Cultivo::obtenerNombre()
{

	return this->nombre;
}

int Cultivo::obtenerCostoSemilla()
{

	return this->costoSemilla;
}

int Cultivo::obtenerRentabilidad()
{

	return this->rentabilidad;
}

int Cultivo::obtenerTiempoCosecha()
{

	return this->tiempoCosecha;
}

int Cultivo::obtenerTiempoRecuperacion()
{

	return this->tiempoRecuperacion;
}



