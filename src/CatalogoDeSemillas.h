/*
 * BolsaDeSemillas.h
 *
 *  Created on: 18 may. 2018
 *      Author: frank
 */

#ifndef SRC_CATALOGODESEMILLAS_H_
#define SRC_CATALOGODESEMILLAS_H_

#include "Cultivo.h"
#include "Lista.h"
#include "ConversorDeDatos.h"


//Representa TODOS los tipos de semillas disponibles en el juego. (Ej: Papa, Zanahoria, Soja, etc...)
class CatalogoDeSemillas {
private:
	unsigned int cantidadDisponible;
	Cultivo* semillas;

public:

	/* PRE: Recibe un puntero a una lista, donde cada elemento de la misma es un puntero a un array de strings. Cada uno de estos arrays tiene 6 de tamanio,
	 * donde cada posicion sera una propiedad de un cultivo, expresado en string, siendo estas: nombre, precio, rentabilidad,
	 * tiempoCosecha, tiempoRecuperacion y consumoAgua respectivamente.
	 * Ej: dentro de la lista, se podra contener un puntero a un array con la siguiente estructura ["Papa", "1", "2", "3", "2", "4"]
	 * POST: Crea un catalogo de semillas, donde contendra objetos Cultivo con las propiedades dictadas por datosCSV.
	 */
	CatalogoDeSemillas(Lista<std::string*>* datosCSV);


	/* PRE: 0 <= pos < obtenerCantidadDisponible()
	 * POST: Devuelve un puntero a un objeto Cultivo, perteneciente al Catalogo.
	 */
	Cultivo* obtenerPosicion(ui pos);


	/* POST: Devuelve la cantidad de semillas indexadas en el Catalogo.
	 */
	unsigned int obtenerCantidadDisponible();

	~CatalogoDeSemillas();
};


#endif /* SRC_CATALOGODESEMILLAS_H_ */
