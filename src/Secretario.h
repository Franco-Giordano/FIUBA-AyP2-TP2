/*
 * Secretario.h
 *
 *  Created on: 20 may. 2018
 *      Author: frank
 */

#ifndef SRC_SECRETARIO_H_
#define SRC_SECRETARIO_H_

#include <iostream>
#include <sstream>
#include <string>
#include "Acciones.h"
#include "Jugador.h"
#include "Catalogo.h"

class Secretario {

private:
	unsigned int turnos, numeroDeJugadores, filas, columnas, dificultad;
    CatalogoDe<Cultivo>* catalogoSemillas;
    CatalogoDe<Destino>* catalogoDestinos;

public:

	Secretario(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos);

	int obtenerNumero(int minimo, int maximo, std::string textoOpcional = "");

	int obtenerNumero(int minimo, std::string textoOpcional = "");

	int obtenerCantidadTurnos();

	int obtenerFilas();

	int obtenerColumnas();

	int obtenerNumeroDeJugadores();

	int obtenerDificultad();

	void atenderJugador(Jugador* jugador);

    unsigned int obtenerTerrenoDeJugador(Jugador* jugador);

    Cultivo* seleccionarCultivoDeCatalogo();
};



#endif /* SRC_SECRETARIO_H_ */
