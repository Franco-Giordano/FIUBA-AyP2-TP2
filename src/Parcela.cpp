/*
 * Parcela.cpp
 *
 *  Created on: 5 may. 2018
 *      Author: Federico
 */

#include "Parcela.h"


Parcela::Parcela(){

	this -> liberarParcela();
}


bool Parcela::estaPlantada(){
	return this->estado == Plantada;
}


bool Parcela:: estaRegada(){

	return this -> regada;
}


bool Parcela::estaLibre(){

	return this->estado == Libre;
}

void Parcela::liberarParcela(){

	this -> cultivo = NULL;
	this -> estado = Libre;
	this -> regada = false;
	this->tiempoRecuperacion = 0;
	this->tiempoCosecha = 0;
}


Cultivo* Parcela::obtenerCultivo(){

	return this->cultivo;
}


int Parcela::obtenerTiempoCosecha(){

	return this->tiempoCosecha;
}


int Parcela::obtenerTiempoRecuperacion(){

	return this->tiempoRecuperacion;
}


void Parcela::modificarTiempoCosecha(int tiempoCosechaRecibido){

	this -> tiempoCosecha = tiempoCosechaRecibido;
}


void Parcela::modificarTiempoRecuperacion(int tiempoRecuperacionRecibido){

	this -> tiempoRecuperacion = tiempoRecuperacionRecibido;
}


void Parcela:: modificarEstado(Estado estadoRecibido){

	this -> estado = estadoRecibido;
}

void Parcela:: modificarCultivo(Cultivo* cultivoRecibido){

	this -> cultivo = cultivoRecibido;
}

void Parcela:: modificarRegado(){

	this -> regada = true;
}

