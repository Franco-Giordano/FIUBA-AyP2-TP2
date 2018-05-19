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

	CatalogoDeSemillas(Lista<std::string*>* datosCSV);

	Cultivo* obtenerPosicion(ui pos);

	unsigned int obtenerCantidadDisponible();

	~CatalogoDeSemillas();
};


#endif /* SRC_CATALOGODESEMILLAS_H_ */
