/*
 * Parcela.cpp
 *
 *  Created on: 5 may. 2018
 *      Author: Federico
 */

#include "Parcela.h"

Parcela::Parcela() {

	this->cultivo = NULL;
	this->estado = Libre;
	this->regada = true;
	this->tiempoRecuperacion = 0;
	this->tiempoCosecha = 0;
}

Estado Parcela::obtenerEstado() {
	return this->estado;
}

bool Parcela::estaPlantada() {
	return this->estado == Plantada;
}

bool Parcela::estaListaParaCosechar() {
	return this->estado == ListaParaCosecha;
}

bool Parcela::estaLibre() {

	return this->estado == Libre;
}

Cultivo* Parcela::obtenerCultivo() {

	return this->cultivo;
}

int Parcela::obtenerTiempoCosecha() {

	return this->tiempoCosecha;
}

int Parcela::obtenerTiempoRecuperacion() {

	return this->tiempoRecuperacion;
}

void Parcela::modificarTiempoCosecha(int tiempoCosechaRecibido) {

	this->tiempoCosecha = tiempoCosechaRecibido;
}

void Parcela::modificarTiempoRecuperacion(int tiempoRecuperacionRecibido) {

	this->tiempoRecuperacion = tiempoRecuperacionRecibido;
}

void Parcela::modificarEstado(Estado estadoRecibido) {

	this->estado = estadoRecibido;
}

void Parcela::modificarCultivo(Cultivo* cultivoRecibido) {

	this->cultivo = cultivoRecibido;
}

void Parcela::regar() {

	this->regada = true;
}

void Parcela::secar() {

	this->regada = false;
}

bool Parcela::estaRegada() {

	return this->regada;
}

bool Parcela::sePuedeSembrar() {
	return estaLibre();
}

bool Parcela::sePuedeCosechar() {
	return obtenerTiempoCosecha() == 0 && estaListaParaCosechar();
}

