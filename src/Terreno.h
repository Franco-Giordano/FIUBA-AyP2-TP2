/*
 * Terreno.h
 *
 *  Created on: 4 may. 2018
 *      Author: Federico
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "Parcela.h"

class Terreno
{
private:

	int cantidadFilas;
	int cantidadColumnas;
	Parcela** terreno;

public:

	//Post: Crea el terreno, o sea, una matriz de cantidadFilasRecibidas x cantidadColumnasRecibidas. Cada uno de las posiciones está ocupada por un objeto Parcela, incializado con su constructor.
	Terreno(int cantidadFilasRecibidas, int cantidadColumnasRecibidas);

	//Post: Devuelve la cantidad de filas que tiene la matriz.
	int obtenerFilas();

	//Post: Devuelve la cantidad de columnas que tiene la matriz.
	int obtenerColumnas();

	//Post: Devuelve el objeto parcela como referencia para su modifición. OJO CON ESTO, funciona, pero no se que les parece.
	Parcela* obtenerParcela(int filaElegida, int columnaElegida);

	//Post: Libera la memoria utilizada por la matriz dinámica Terreno.
	~Terreno();
};

#endif /* TERRENO_H_ */
