/*
 * ConversorDeDatos.h
 *
 *  Created on: 19 may. 2018
 *      Author: frank
 */

#ifndef SRC_CONVERSORDEDATOS_H_
#define SRC_CONVERSORDEDATOS_H_

#include "Cultivo.h"
#include <sstream>
typedef unsigned int ui;

class ConversorDeDatos {
private:
public:

	//POST: Crea un objeto ConversorDeDatos listo para ser usado
	ConversorDeDatos();


	/* PRE: Recibe un puntero a un array de strings de tamanio 6, donde cada posicion representa las propiedades
	 * de un cultivo: nombre, precio, rentabilidad, tiempoCosecha, tiempoRecuperacion, consumoAgua respectivamente.
	 * Cada propiedad debera ser valida ya que sera convertida a su tipo correspondiente, condiciones de validez ya descriptas en "Cultivo.h"
	 * Ademas, recibe por referencia un objeto del tipo Cultivo
	 * POST: le asigna a 'cultivoAmodificar' las propiedades descriptas en 'datos'.
	 */
	void convertirCultivo(std::string* datos, Cultivo &cultivoAmodificar);


	//--------------FALTA HACER CLASE DESTINO (o no?)-----------------------
	/* void convertirDestino(std::string* datos, Destino &destinoAmodificar);
	 */

};



#endif /* SRC_CONVERSORDEDATOS_H_ */
