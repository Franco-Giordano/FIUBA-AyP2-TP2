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
#include "Mercado.h"

class Secretario {

private:
	unsigned int turnos, numeroDeJugadores, filas, columnas, dificultad;
    CatalogoDe<Cultivo>* catalogoSemillas;
    CatalogoDe<Destino>* catalogoDestinos;

    std::string convertirIntAString(int i);

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

	bool administrarEleccion(unsigned int eleccion, Jugador* jugador, Acciones acciones);

    unsigned int obtenerTerrenoDeJugador(Jugador* jugador);

    bool advertirQuePuedePerderCosechas(Jugador* jugador, unsigned int posicionT);


    void gestionarSiembra(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    void gestionarCosecha(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    void gestionarRiego(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    void gestionarEnvioCosecha();

    void gestionarCompraTerreno(Jugador* jugador);

    void gestionarVentaTerreno(Jugador* jugador);

    void gestionarAmpliarTanque(Jugador* jugador);

    void gestionarAmpliarAlmacen(Jugador* jugador);

    Cultivo* seleccionarCultivoDeCatalogo();
};



#endif /* SRC_SECRETARIO_H_ */
