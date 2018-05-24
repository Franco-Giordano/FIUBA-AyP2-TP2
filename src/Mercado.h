/*
 * Mercado.h
 *
 *  Created on: 23 may. 2018
 *      Author: frank
 */

#ifndef MERCADO_H_
#define MERCADO_H_

class Mercado {
private:
	unsigned int dificultad;
public:

	Mercado(unsigned int dificultad) {
		this->dificultad = dificultad;
	}

	void comprarCapacidadTanque(Jugador* jugador, unsigned int ampliacionElegida) {
		jugador->obtenerTanqueDeAgua()->ampliarTanque(ampliacionElegida);

		int dineroGastado= ampliacionElegida*dificultad;
		jugador->obtenerMonedero()->gastarDinero(dineroGastado);

	}

	void comprarCapacidadAlmacen(Jugador* jugador, unsigned int ampliacionElegida) {
			jugador->obtenerAlmacen()->agrandarAlmacen(ampliacionElegida);

			int dineroGastado= (ampliacionElegida + dificultad) *10;
			jugador->obtenerMonedero()->gastarDinero(dineroGastado);

	}

	void venderTerrenoAjugador(Jugador* jugador, unsigned int filas, unsigned int columnas) {

		unsigned int cantidadTerrenos = jugador->obtenerListaTerreno()->contarElementos();

		jugador->obtenerMonedero()->gastarDinero(filas*columnas*dificultad*cantidadTerrenos);

		Terreno* nuevoTerreno = new Terreno(filas, columnas);

		jugador->obtenerListaTerreno()->agregar(nuevoTerreno);

	}

	void comprarTerrenoDeJugador(Jugador* jugador, unsigned int posicionTerreno, unsigned int costoActual) {
		jugador->obtenerListaTerreno()->remover(posicionTerreno);
		jugador->obtenerMonedero()->sumarDinero(costoActual);
	}


};



#endif /* MERCADO_H_ */
