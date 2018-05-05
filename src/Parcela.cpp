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

Cultivo& Parcela::obtenerCultivo(){

	return this->cultivo;
}

void Parcela::sembrarCultivo(std::string nombreLeido,int costoSemillaLeido,int tiempoCosechaLeido,int rentabilidadLeida,
																int tiempoRecuperacionLeido,Monedero &monedero){

	obtenerCultivo().modificarCultivo(nombreLeido,costoSemillaLeido,tiempoCosechaLeido,rentabilidadLeida,tiempoRecuperacionLeido);
	monedero.gastarDinero(obtenerCultivo().obtenerCostoSemilla());

}

void Parcela::regarParcela(TanqueDeAgua& tanqueAgua, int costoDeAgua){

	if (!this -> regada){
		this -> regada = true;
		tanqueAgua.restarAgua(costoDeAgua);
	}
}

bool Parcela::obtenerRegado(){

	return this -> regada;
}


