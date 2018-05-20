/*
 * Terreno.cpp
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#include "Terreno.h"

Terreno::Terreno(int cantidadFilasRecibidas, int cantidadColumnasRecibidas){

		if (cantidadFilasRecibidas >= 0 && cantidadColumnasRecibidas >= 0)
		{

			this->cantidadFilas = cantidadFilasRecibidas;
			this -> cantidadColumnas = cantidadColumnasRecibidas;

			terreno = new Parcela * [cantidadFilas];

			for ( int i = 0; i < cantidadFilas; i ++ )
			{

				terreno[i] = new Parcela [cantidadColumnas];
			}
		}
		else
		{
			throw std::string("La cantidad de filas o columnas es inválida.");
		}
	}

	int Terreno::obtenerFilas(){

		return this->cantidadFilas;
	}

	int Terreno::obtenerColumnas(){

		return this->cantidadColumnas;
	}

	Parcela*  Terreno::obtenerParcela(int coordenadaX, int coordenadaY){

		return &( this -> terreno[coordenadaX][coordenadaY]);
	}

	Terreno::~Terreno(){

		for (int i = 0; i < cantidadFilas; i++){
			delete [] terreno[i];
		}
		delete [] terreno;
	}



