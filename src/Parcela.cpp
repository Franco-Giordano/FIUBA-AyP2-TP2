/*
 * Parcela.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: federico
 */

#include "Parcela.h"



Parcela::Parcela(){

	Cultivo cultivo;
	this -> estado = Libre;
	this -> regada = false;

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


Cultivo& Parcela::obtenerCultivo(){

	return this->cultivo;
}


void Parcela::liberarParcela(){
	this->estado = Libre;
}

void Parcela::sembrarCultivo(std::string nombreLeido,int costoSemillaLeido,int tiempoCosechaLeido,
							int rentabilidadLeida, int tiempoRecuperacionLeido,Monedero &monedero,
							int consumoDeAguaRecibido){

	obtenerCultivo().modificarCultivo(nombreLeido,costoSemillaLeido,tiempoCosechaLeido,rentabilidadLeida,
									  tiempoRecuperacionLeido, consumoDeAguaRecibido);
	monedero.gastarDinero(obtenerCultivo().obtenerCostoSemilla());

}

void Parcela::regarParcela(TanqueDeAgua& tanqueAgua, int costoDeAgua){

	if (!this -> regada){
		this -> regada = true;
		tanqueAgua.restarAgua(costoDeAgua);
	}
}


void Parcela:: cultivarParcela(Monedero& monedero){

	monedero.sumarDinero(this->obtenerCultivo().obtenerRentabilidad());
	obtenerCultivo().modificarCultivo(" VACIO ", 0, 0, 0, this->obtenerCultivo().obtenerTiempoRecuperacion(), 0);
	this->liberarParcela();
}
