/*
 * Cultivo.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#include "Cultivo.h"

Cultivo::Cultivo() {

	this->nombre = "";
	this->costoSemilla = 0;
	this->tiempoCosecha = 0;
	this->rentabilidad = 0;
	this->tiempoRecuperacion = 0;
	this->consumoAgua = 0;
}

void Cultivo::modificarCultivo(std::string nombreRecibido, unsigned int costoSemillaRecibido, unsigned int tiempoCosechaRecibido,
															unsigned int rentabilidadRecibida, unsigned int tiempoRecuperacionRecibido, unsigned int consumoAguaRecibido) {

	this->nombre = nombreRecibido;
	this->costoSemilla = costoSemillaRecibido;
	this->tiempoCosecha = tiempoCosechaRecibido;
	this->rentabilidad = rentabilidadRecibida;
	this->tiempoRecuperacion = tiempoRecuperacionRecibido;
	this->consumoAgua = consumoAguaRecibido;
}

std::string Cultivo::obtenerNombre() {

	return this->nombre;
}

unsigned int Cultivo::obtenerCostoSemilla() {

	return this->costoSemilla;
}

unsigned int Cultivo::obtenerRentabilidad() {

	return this->rentabilidad;
}

unsigned int Cultivo::obtenerTiempoCosecha() {

	return this->tiempoCosecha;
}

unsigned int Cultivo::obtenerTiempoRecuperacion() {

	return this->tiempoRecuperacion;
}

unsigned int Cultivo::obtenerConsumoAgua() {
	return this->consumoAgua;
}

