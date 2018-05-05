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




