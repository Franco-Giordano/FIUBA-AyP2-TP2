/*
 * Destino.h
 *
 *  Created on: 20 may. 2018
 *      Author: frank
 */

#ifndef SRC_DESTINO_H_
#define SRC_DESTINO_H_

#include <string>

class Destino {
private:
	std::string nombreLugar;
	int distanciaKM;
	int precio;
	std::string cultivo;
public:

	//Post: Crea un objeto Destino con todos sus atributos inicializados en nulo ("" o 0 segun corresponda).
	Destino();

	/* Pre: Los parametros son del tipo indicado, con todos los enteros mayores a 0.
	 * Post: Modifica los atributos del objeto Destino con los parametros dados.
	 */
	void modificarDestino(std::string nombreLugarRecibido, int distanciaKMRecibido, int precioRecibido, std::string cultivoRecibido);

	//Post: Devuelve el nombre del Destino como string.
	std::string obtenerNombre();

	//Post: Devuelve la distancia del Destino como entero.
	int obtenerDistancia();

	//Post: Devuelve el precio del Destino como entero.
	int obtenerPrecio();

	//Post: Devuelve el nombre del cultivo del Destino como string.
	std::string obtenerNombreCultivo();

};

#endif /* SRC_DESTINO_H_ */
