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

public:

	//PRE: Los par�metros recibidos deben de estar validadas previamente.
	/*POST: Crea el objeto Dron Aereo que recibe como par�metro la cantidad de filas y de columnas de los terrenos del juego.
	 * Este, a su vez, crea una imagen "Plantilla.bmp", que representa la estructura principal del terreno en dicha imagen. Gracias a esto, al momento
	 * de "tomarFoto", la creaci�n de los archivos que genere dicho metodo, ser� mas r�pida, ya que leer�n el archivo "Plantilla.bmp" }
	 * y solamente deber�n modificar los pixeles que se vean implicados en el cambio, y no as�, crear toda la foto desde cero.
	 */
	DronAereo(unsigned int cantidadColumnas, unsigned int cantidadFilas);

	//PRE:  Los par�metros recibidos deben de est�r validados previamente.
	//POST: Crea un archivo ".bmp" del estado actual de TODOS los terrenos del jugador recibido por par�metro.
	void tomarFoto(Jugador * jugadorRecibido, unsigned int numeroJugadorActual, unsigned int turnoActual);

private:

	//POST: Convierte el entero recibido por parametro en una cadena de caracteres de tipo string.
	std::string convertirEnteroAString(int enteroAConvetir);

};

#endif /* SRC_DronAereoAEREO_H_ */
