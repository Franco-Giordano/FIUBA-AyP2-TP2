/*
 * Destino.cpp
 *
 *  Created on: 20 may. 2018
 *      Author: frank
 */

#include "Destino.h"

Destino::Destino() {
	nombreLugar = "";
	distanciaKM = 0;
	precio = 0;
	cultivo = "";
	origen = "";
}

void Destino::modificarDestino(std::string origenRecibido, std::string nombreLugarRecibido, int distanciaKMRecibido, int precioRecibido, std::string cultivoRecibido) {
	origen = origenRecibido;
	nombreLugar = nombreLugarRecibido;
	distanciaKM = distanciaKMRecibido;
	precio = precioRecibido;
	cultivo = cultivoRecibido;

}

std::string Destino::obtenerNombre() {
	return nombreLugar;
}

int Destino::obtenerDistancia() {
	return distanciaKM;
}

int Destino::obtenerPrecio() {
	return precio;
}

std::string Destino::obtenerNombreCultivo() {
	return cultivo;
}

std::string Destino::obtenerOrigen() {
	return origen;
}

