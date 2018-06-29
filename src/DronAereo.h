/*
 * DronAereoAereo.h
 *
 *  Created on: 19 may. 2018
 *      Author: Federico
 */

#ifndef SRC_DronAereoAEREO_H_
#define SRC_DronAereoAEREO_H_

#include "EasyBMP_Font.h"
#include "Jugador.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>

class DronAereo {

private:

	BMP fotoTerreno;

	Jugador* jugador;

	unsigned int resolucionDeFoto[2];

	unsigned int multiplicador;

	unsigned int margenAlto;

	unsigned int margenAncho;

	//Post: Imprime los numeros verticales y horizontales de la cuadrilla para tenerlos como referencia al momento de jugar.
	void imprimirNumerosDeLaCuadrilla(char*  texto);

	RGBApixel colorFuente;

public:

	//Pre: Los parametros recibidos deben de estar validadas previamente.
	/*Post: Crea el objeto Dron Aereo que recibe como parametro la cantidad de filas y de columnas de los terrenos del juego.
	 * Este, a su vez, crea una imagen "Plantilla.bmp", que representa la estructura principal del terreno en dicha imagen.
	 */
	DronAereo(unsigned int cantidadColumnas, unsigned int cantidadFilas);

	//Pre:  El jugador debe de existir, y los parametros numericos deben de ser mayores a 0.
	//Post: Crea un archivo ".bmp" del estado actual de TODOS los terrenos del jugador recibido por parametro.
	void tomarFoto(Jugador * jugadorRecibido, unsigned int numeroJugadorActual, unsigned int turnoActual);

private:

	std::string convertirEnteroAString(int enteroAConvetir);

};

#endif /* SRC_DronAereoAEREO_H_ */
