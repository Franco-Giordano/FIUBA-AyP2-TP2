/*
 * GrafoDirigido.cpp
 *
 *  Created on: 28 jun. 2018
 *      Author: federico
 */

#include "GrafoDirigidoPonderado.h"

GrafoDirigidoPonderado::GrafoDirigidoPonderado(CatalogoDe<Destino>* catalogo, std::string cultivoBuscado) {
	listaAdyacencia = new ListaNombrada<ListaNombrada<unsigned int>*>();

	for (unsigned int i = 0; i < catalogo->obtenerCantidadDisponible(); i++) {

		if (catalogo->obtenerPosicion(i)->obtenerNombreCultivo() == cultivoBuscado) {
			Destino* actual = catalogo->obtenerPosicion(i);
			std::string origenDeActual = catalogo->obtenerPosicion(i)->obtenerOrigen();

			if (listaAdyacencia->yaExisteNombre(origenDeActual)) {

				ListaNombrada<unsigned int>* listaDestinos = listaAdyacencia->obtenerDatoDeNombre(origenDeActual);

				listaDestinos->agregar(actual->obtenerNombre(), actual->obtenerPrecio());
			}

			else {
				ListaNombrada<unsigned int>* nuevosAdyacentes = new ListaNombrada<unsigned int>();

				nuevosAdyacentes->agregar(actual->obtenerNombre(), actual->obtenerPrecio());

				listaAdyacencia->agregar(origenDeActual, nuevosAdyacentes);
			}

			if (!listaAdyacencia->yaExisteNombre(actual->obtenerNombre())) {
				ListaNombrada<unsigned int>* nuevosAdyacentes = new ListaNombrada<unsigned int>();

				listaAdyacencia->agregar(actual->obtenerNombre(), nuevosAdyacentes);
			}
		}

	}
}

void GrafoDirigidoPonderado::imprimirListaAdyacencia() {
	listaAdyacencia->iniciarCursor();
	while (listaAdyacencia->avanzarCursor()) {
		ListaNombrada<unsigned int>* actual = listaAdyacencia->obtenerDatoCursor();

		std::cout << listaAdyacencia->obtenerNombreCursor() << " |> ";

		actual->iniciarCursor();
		while (actual->avanzarCursor()) {
			std::cout << "[" << actual->obtenerNombreCursor() << " $" << actual->obtenerDatoCursor() << "] ";
		}
		std::cout << std::endl;

	}
}

ListaNombrada<ListaNombrada<unsigned int>*>* GrafoDirigidoPonderado::obtenerListaAdyacencia() {
	return listaAdyacencia;
}

GrafoDirigidoPonderado::~GrafoDirigidoPonderado() {
	listaAdyacencia->iniciarCursor();
	while (listaAdyacencia->avanzarCursor()) {
		ListaNombrada<unsigned int>* adyActual = listaAdyacencia->obtenerDatoCursor();
		delete adyActual;
	}
	delete listaAdyacencia;
}