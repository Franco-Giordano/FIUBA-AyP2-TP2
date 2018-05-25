/*
 * DronAereo.cpp
 *
 *  Created on: 22 may. 2018
 *      Author: fedei
 */

#include "DronAereo.h"

DronAereo::DronAereo(unsigned int cantidadFilas,unsigned int cantidadColumnas) {

	srand(time(NULL));

	this->margenAlto = 10;
	this->margenAncho = 20;

	this->jugador = NULL;

	this->multiplicador = 50;

	this->resolucionDeFoto[0] = (cantidadFilas * multiplicador) + multiplicador
			+ margenAncho;
	this->resolucionDeFoto[1] = (cantidadColumnas * multiplicador)
			+ multiplicador + margenAlto;

	this->fotoTerreno.SetSize(resolucionDeFoto[0], resolucionDeFoto[1]);
	this->fotoTerreno.SetBitDepth(8);

	/*Imprime en la foto el pasto de fondo. Lo hace hasta resolucion menos 2 asi queda un recuadro
	 blanco (solamente estético)*/
	for (unsigned int i = 1; i < resolucionDeFoto[0] - 1; i++) {
		for (unsigned int j = 1; j < resolucionDeFoto[1] - 1; j++) {
			fotoTerreno(i, j)->Green = rand() % 161 + 255;
			fotoTerreno(i, j)->Red = 0;
			fotoTerreno(i, j)->Blue = 0;
		}
	}

	//Imprime en la foto las lineas horizontales de la matriz.
	for (unsigned int i = multiplicador + margenAncho; i < resolucionDeFoto[0];i++) {
		for (unsigned int j = multiplicador + margenAlto;j < resolucionDeFoto[1]; j += multiplicador) {

			fotoTerreno(i, j)->Blue = 255;
			fotoTerreno(i, j)->Red = 255;
			fotoTerreno(i, j)->Green = 255;
		}
	}

	//Imprime en la foto las lineas verticales de la matriz.
	for (unsigned int i = multiplicador + margenAncho; i < resolucionDeFoto[0];i += multiplicador) {
		for (unsigned int j = multiplicador + margenAlto;j < resolucionDeFoto[1]; j++) {

			fotoTerreno(i, j)->Blue = 255;
			fotoTerreno(i, j)->Red = 255;
			fotoTerreno(i, j)->Green = 255;
		}
	}

	RGBApixel colorFuente;

	colorFuente.Red = 255;
	colorFuente.Green = 255;
	colorFuente.Blue = 255;

	const char* texto = new char();

	//Imprime en la foto el indice horizontal de la matriz.
	unsigned int numeroDeParcela = 1;
	for (unsigned int i = multiplicador + margenAncho; i < resolucionDeFoto[0];i += multiplicador) {

		texto = convertirEnteroAString(numeroDeParcela).c_str();
		PrintString(fotoTerreno, (char*) texto, i, margenAlto,
				multiplicador - margenAncho, colorFuente);
		numeroDeParcela++;
	}

	//Imprime en la foto el indice vertical de la matriz.
	numeroDeParcela = 1;
	for (unsigned int i = multiplicador + margenAlto; i < resolucionDeFoto[1];i += multiplicador) {

		texto = convertirEnteroAString(numeroDeParcela).c_str();
		PrintString(fotoTerreno, (char*) texto, margenAlto, i,multiplicador - margenAncho, colorFuente);
		numeroDeParcela++;
	}

	delete texto;
	/*Crea el archivo plantilla, el cual las demas fotos tomaran como referente para
	 *  su creacion(mas rapida, ya que leen de este archivo).*/
	fotoTerreno.WriteToFile("Plantilla.bmp");

}

void DronAereo::tomarFoto(Jugador * jugadorRecibido,unsigned int numeroJugadorActual, unsigned int turnoActual) {

	this->jugador = jugadorRecibido;

	fotoTerreno.ReadFromFile("Plantilla.bmp");

	RGBApixel colorFuente;
	colorFuente.Red = 255;
	colorFuente.Blue = 255;
	colorFuente.Green = 255;

	char * texto = new char();

	int numeroTerrenoActual = 1;

	Lista<Terreno *>* terrenos = jugador -> obtenerListaTerreno();

	terrenos->iniciarCursor();

	while (terrenos->avanzarCursor()) {

		Terreno* terrenoActual =terrenos->obtenerCursor();

		int margenAnchoLetra = margenAncho + (margenAncho / 2);
		int margenAltoLetra = margenAlto + (margenAlto / 2);

		for (unsigned int i = 1;i <= terrenoActual->obtenerListaFilas()->contarElementos();i++) {

			ListaCoordenada<Parcela*>* filaActual =terrenoActual->obtenerListaFilas()->obtener(i);

			for (unsigned int j = 1; j <= filaActual->contarElementos(); j++) {

				Parcela* parcelaActual = filaActual->obtener(j);

				if (parcelaActual->obtenerEstado() == Plantada) {
					strcpy(texto, "P");

				}
				else if (parcelaActual->obtenerEstado() == Recuperando) {
					strcpy(texto, "R");

				}
				else if (parcelaActual->obtenerEstado() == ListaParaCosecha){
					strcpy(texto,"L");
				}

				PrintString(fotoTerreno, texto,filaActual->obtenerCoordenadaDeLaPosicion(j)* multiplicador + margenAnchoLetra,
						terrenoActual->obtenerListaFilas()->obtenerCoordenadaDeLaPosicion(i) * multiplicador + margenAltoLetra,
						multiplicador - margenAlto, colorFuente);
			}
		}

		fotoTerreno.WriteToFile(("Jugador" + this->convertirEnteroAString(numeroJugadorActual)+ "_Terreno"+ this->convertirEnteroAString(numeroTerrenoActual)+ "_Turno"
				+ this->convertirEnteroAString(turnoActual)+ ".bmp").c_str());
		fotoTerreno.ReadFromFile("Plantilla.bmp");

		numeroTerrenoActual++;
	}
	delete texto;
}

std::string DronAereo::convertirEnteroAString(int enteroAConvertir) {

	std::string enteroConvertido;
	std::stringstream conversor;
	conversor << enteroAConvertir;
	enteroConvertido = conversor.str();

	return enteroConvertido;

}

