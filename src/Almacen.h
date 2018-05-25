/*
 * Almacen.h
 *
 *  Created on: 6 may. 2018
 *      Author: Alvaro
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Monedero.h"
#include "Lista.h"
#include "Cultivo.h"

class Almacen {
private:
	unsigned int capacidad;
	Lista<Cultivo*>* cultivos;

public:
	/* Crea el objeto almacen que depende del tama�o inicial del terreno y de la dificultad
	 * Este objeto tiene un atributo llamado capacidad que data del maximo de cultivos cosechados que se
	 * podran almacenar en el mismo.
	 */
	Almacen(int N, int M, int dificultad);

	//Post: devuelve la capacidad actual que posee el almacen.
	int obtenerCapacidad();

	//Post: compara la cantidad de elementos con la capacidad del almacen. En caso que de haber mas elementos
	// que la capacidad, devuelve false.
	bool capacidadValida();

	//Post: devuelve true si hay espacio libre para agregar algun cultivo en el almacen.
	bool hayEspacioLibre();

	//Post: devuelve el numero de cultivos cosechadas que hay guardados en el almacen.
	int contarCultivos();

	//Post: incrementa la capacidad del almacen para poder seguir agregando elementos a la lista.
	void agrandarAlmacen(unsigned int capacidadAAgregar);

	//Post: agrega un nodo cultivo a la lista de cultivos.
	void agregarCultivo(Cultivo* cultivo);

	// Post: quita un elemento de la lista de cultivos-
	void quitarCultivo(int posicion);

	//Funcion creada para probar la funcionalidad del codigo.
	void mostrarNombresDeCultivosEnElAlmacen();

	//Pre: recibe la posicion del cultivo que se desea obtener.
	//Post: devuelve el cultivo en la posicion pasada por parametro.
	Cultivo* obtenerCultivoEnPosicion(unsigned int posicion);

	//Post: hace delete de la lista de cultivos del almacen.
	~Almacen();
};

#endif /* ALMACEN_H_ */
