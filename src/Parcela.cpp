/*
 * Parcela.cpp
 *
 *  Created on: 5 may. 2018
 *      Author: Alvaro
 */

#include "Parcela.h"


Parcela::Parcela(){

	this -> cultivo = NULL;
	this -> estado = Libre;
	this -> regada = false;
	this->tiempoRecuperacion = 0;
	this->tiempoCosecha = 0;

}


bool Parcela:: estaRegada(){
	return this -> regada;
}


bool Parcela::estaPlantada(){
	return this->estado == Plantada;
}


bool Parcela::estaLibre(){
	return this->estado == Libre;
}


Cultivo* Parcela::obtenerCultivo(){

	return this->cultivo;
}


void Parcela::liberarParcela(){
	this->estado = Libre;
	this->cultivo = NULL;
}

int Parcela::obtenerTiempoCosecha(){

	return this->tiempoCosecha;
}

int Parcela::obtenerTiempoRecuperacion(){

	return this->tiempoRecuperacion;
}


void Parcela::sembrarCultivo(Cultivo* cultivoParaSembrar,Monedero* monedero){

	this->cultivo = cultivoParaSembrar;
	this->tiempoCosecha = this->cultivo->obtenerTiempoCosecha();
	this->tiempoRecuperacion = this->cultivo->obtenerTiempoRecuperacion();
	monedero->gastarDinero(this->obtenerCultivo()->obtenerCostoSemilla());

}

void Parcela::regarParcela(TanqueDeAgua* tanqueAgua, int costoDeAgua){

	if (!this -> regada){							// Esto se podria chequear en otro lado.
		this -> regada = true;
		tanqueAgua->restarAgua(costoDeAgua);
	}
}


void Parcela:: cosecharParcela(Monedero* monedero, Almacen* almacen){

	almacen->agregarCultivo(this->cultivo);
	this->tiempoRecuperacion= this->obtenerCultivo()->obtenerTiempoRecuperacion();

	this->cultivo=NULL;
	this->estado= Cosechada;

	this->liberarParcela();
}

