/*
 * DronAereo.cpp
 *
 *  Created on: 22 may. 2018
 *      Author: fedei
 */

#include "DronAereo.h"
#include <iostream>

DronAereo::DronAereo(unsigned int cantidadFilas, unsigned int cantidadColumnas) {

	srand(time(NULL));

	this->margenAlto = 10;
	this->margenAncho = 20;

	this->jugador = NULL;

	//El multiplicador se encarga de "darle un tamaño" a cada parcela, caso contrario cada parcela tendría tamaño de 1 pixel.
	this->multiplicador = 50;

	//Asigno las dimensiones de la foto en un vector.
	this->resolucionDeFoto[0] = (cantidadFilas * multiplicador) + multiplicador + margenAncho;
	this->resolucionDeFoto[1] = (cantidadColumnas * multiplicador) + multiplicador + margenAlto;

	//Asigno el color de la fuente a blanco.
	this->colorFuente.Red = 255;
	this->colorFuente.Green = 255;
	this->colorFuente.Blue = 255;

	//Matriz donde se encarga la información de que parte de la foto deberá ser pintada.
	bool matrizMemoria[resolucionDeFoto[0]][resolucionDeFoto[1]];

	this->fotoTerreno.SetSize(resolucionDeFoto[0], resolucionDeFoto[1]);
	this->fotoTerreno.SetBitDepth(8);

	//Inicializo la matriz.
	for (unsigned int i = 0; i < resolucionDeFoto[0]; i++) {
		for (unsigned int j = 0; j < resolucionDeFoto[0]; j++) {
			matrizMemoria[i][j] = false;
		}
	}

	//"Imprime" en la foto las lineas horizontales de la matriz.
	for (unsigned int i = multiplicador + margenAncho; i < resolucionDeFoto[0]; i++) {
		for (unsigned int j = multiplicador + margenAlto; j < resolucionDeFoto[1]; j += multiplicador) {
			matrizMemoria[i][j] = true;
		}
	}

	//"Imprime" en la foto las lineas verticales de la matriz.
	for (unsigned int i = multiplicador + margenAncho; i < resolucionDeFoto[0]; i += multiplicador) {
		for (unsigned int j = multiplicador + margenAlto; j < resolucionDeFoto[1]; j++) {
			matrizMemoria[i][j] = true;
		}
	}

	//En base a la matriz, imprime en el archivo bmp.
	for (unsigned int i = 1; i < resolucionDeFoto[0] - 1; i++) {
		for (unsigned int j = 1; j < resolucionDeFoto[1] - 1; j++) {
			if (matrizMemoria[i][j] == false) {
				fotoTerreno(i, j)->Green = rand() % 161 + 255;
				fotoTerreno(i, j)->Red = 0;
				fotoTerreno(i, j)->Blue = 0;
			} else {
				fotoTerreno(i, j)->Green = 255;
				fotoTerreno(i, j)->Red = 255;
				fotoTerreno(i, j)->Blue = 255;
			}
		}
	}

	char* texto = new char[5];

	imprimirNumerosDeLaCuadrilla(texto);

	delete[] texto;
	/*Crea el archivo plantilla, el cual las demas fotos tomaran como referente para
	 *  su creacion(mas rapida, ya que leen de este archivo).*/
	fotoTerreno.WriteToFile("Plantilla.bmp");

}

void DronAereo::imprimirNumerosDeLaCuadrilla(char* texto) {

	//Imprime en la foto el indice horizontal de la matriz.
	unsigned int numeroDeParcela = 1;
	for (unsigned int i = this->multiplicador + this->margenAncho; i < this->resolucionDeFoto[0]; i += this->multiplicador) {
		strcpy(texto, convertirEnteroAString(numeroDeParcela).c_str());
		PrintString(fotoTerreno, (char*) texto, i, this->margenAlto, this->multiplicador - this->margenAncho, colorFuente);
		numeroDeParcela++;
	}

	//Imprime en la foto el indice vertical de la matriz.
	numeroDeParcela = 1;
	for (unsigned int i = this->multiplicador + this->margenAlto; i < this->resolucionDeFoto[1]; i += this->multiplicador) {
		strcpy(texto, convertirEnteroAString(numeroDeParcela).c_str());
		PrintString(fotoTerreno, (char*) texto, this->margenAlto, i, this->multiplicador - this->margenAncho, colorFuente);
		numeroDeParcela++;
	}

}

void DronAereo::tomarFoto(Jugador * jugadorRecibido, unsigned int numeroJugadorActual, unsigned int turnoActual) {

	this->jugador = jugadorRecibido;

	fotoTerreno.ReadFromFile("Plantilla.bmp");

	char * texto = new char[5];

	int numeroTerrenoActual = 1;

	Lista<Terreno *>* terrenos = jugador->obtenerListaTerreno();

	terrenos->iniciarCursor();

	while (terrenos->avanzarCursor()) {

		Terreno* terrenoActual = terrenos->obtenerCursor();

		int margenAnchoLetra = margenAncho + (margenAncho / 2);
		int margenAltoLetra = margenAlto + (margenAlto / 2);

		for (unsigned int i = 1; i <= terrenoActual->obtenerListaFilas()->contarElementos(); i++) {

			ListaCoordenada<Parcela*>* filaActual = terrenoActual->obtenerListaFilas()->obtener(i);

			for (unsigned int j = 1; j <= filaActual->contarElementos(); j++) {

				Parcela* parcelaActual = filaActual->obtener(j);

				if (parcelaActual->obtenerEstado() == Plantada) {
					strcpy(texto, "P");
				} else if (parcelaActual->obtenerEstado() == Recuperando) {
					strcpy(texto, "R");
				} else if (parcelaActual->obtenerEstado() == ListaParaCosecha) {
					strcpy(texto, "C");
				}
				PrintString(fotoTerreno, texto, filaActual->obtenerCoordenadaDeLaPosicion(j) * multiplicador + margenAnchoLetra,
										terrenoActual->obtenerListaFilas()->obtenerCoordenadaDeLaPosicion(i) * multiplicador + margenAltoLetra,
										multiplicador - margenAlto, colorFuente);
			}
		}

		fotoTerreno.WriteToFile(("Jugador" + this->convertirEnteroAString(numeroJugadorActual) +
															"_Terreno" + this->convertirEnteroAString(numeroTerrenoActual) +
															"_Turno" + this->convertirEnteroAString(turnoActual)+ ".bmp").c_str());

		fotoTerreno.ReadFromFile("Plantilla.bmp");

		numeroTerrenoActual++;
	}
	delete[] texto;
}

std::string DronAereo::convertirEnteroAString(int enteroAConvertir) {

	std::string enteroConvertido;
	std::stringstream conversor;
	conversor << enteroAConvertir;
	enteroConvertido = conversor.str();

	return enteroConvertido;

}

