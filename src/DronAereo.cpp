/*
 * DronAereo.cpp
 *
 *  Created on: 22 may. 2018
 *      Author: fedei
 */

#include "DronAereo.h"

DronAereo::DronAereo(unsigned int cantidadFilas, unsigned int cantidadColumnas){

			srand(time(NULL));

			this -> margenAlto = 10;
			this -> margenAncho = 20;

			this -> jugador = NULL;

			this ->  multiplicador = 50;

			this -> resolucionDeFoto[0] = (cantidadFilas *multiplicador )+ multiplicador+margenAncho;
			this -> resolucionDeFoto[1] = (cantidadColumnas *multiplicador)+multiplicador+margenAlto;

			this -> fotoTerreno.SetSize(resolucionDeFoto[0],resolucionDeFoto[1]);
			this -> fotoTerreno.SetBitDepth(8);

			/*Imprime en la foto el pasto de fondo. Lo hace hasta resolucion menos 2 as� queda un recuadro
			blanco*/
			for (unsigned int i = 1; i < resolucionDeFoto[0]-1; i ++){
				for (unsigned int j = 1; j < resolucionDeFoto[1]-1; j ++){
					fotoTerreno(i,j)->Green = rand()%161+255;
					fotoTerreno(i,j)->Red = 0;
					fotoTerreno(i,j) -> Blue = 0;
				}
			}

			//Imprime en la foto las lineas horizontales de la matriz.
			for (unsigned int i = multiplicador+margenAncho; i < resolucionDeFoto[0]; i++){
				for (unsigned int j = multiplicador+margenAlto; j < resolucionDeFoto[1]; j+=multiplicador){

					fotoTerreno(i,j)->Blue = 255;
					fotoTerreno(i,j)->Red = 255;
					fotoTerreno(i,j)->Green = 255;
				}
			}

			//Imprime en la foto las lineas verticales de la matriz.
			for (unsigned int i = multiplicador+margenAncho; i < resolucionDeFoto[0]; i += multiplicador){
				for (unsigned int j = multiplicador+margenAlto; j < resolucionDeFoto[1]; j++){

					fotoTerreno(i,j)->Blue = 255;
					fotoTerreno(i,j)->Red = 255;
					fotoTerreno(i,j)->Green = 255;
				}
			}

		RGBApixel colorFuente;

		colorFuente.Red = 255;
		colorFuente.Green = 255;
		colorFuente.Blue = 255;

		char* texto = new char();
		std::string numeroConvertido;
		std::stringstream conversor;


		//Imprime en la foto el indice horizontal de la matriz.
		unsigned int numeroDeParcela = 1;
		for (unsigned int i = multiplicador+margenAncho; i <resolucionDeFoto[0]; i+= multiplicador){

			conversor << numeroDeParcela;
			numeroConvertido = conversor.str();
			conversor.str(std::string());

			strcpy (texto,numeroConvertido.c_str());
			PrintString(fotoTerreno,texto,i,margenAlto,multiplicador-margenAncho,colorFuente);
			numeroDeParcela++;
		}

		//Imprime en la foto el indice vertical de la matriz.
		numeroDeParcela= 1;
		for (unsigned int i = multiplicador+margenAlto;i < resolucionDeFoto[1]; i+= multiplicador){

			conversor << numeroDeParcela;
			numeroConvertido = conversor.str();
			conversor.str(std::string());

			strcpy (texto,numeroConvertido.c_str());
			PrintString(fotoTerreno,texto,margenAlto,i,multiplicador-margenAncho,colorFuente);
			numeroDeParcela++;
		}

		delete texto;
		//Crea el archivo plantilla, el cual las demas fotos tomar�n como referente para su creaci�n (mas rapida, ya que leen de este archivo).
		fotoTerreno.WriteToFile("Plantilla.bmp");

		}

	void DronAereo::tomarFoto(Jugador * jugadorRecibido, unsigned int numeroJugadorActual ,unsigned int turnoActual){

		this -> jugador = jugadorRecibido;

		jugador->obtenerListaTerreno()->iniciarCursor();


		fotoTerreno.ReadFromFile("Plantilla.bmp");

		RGBApixel colorFuente;
								colorFuente.Red = 255;
								colorFuente.Blue = 255;
								colorFuente.Green = 255;

		char * texto = new char();

		int numeroTerrenoActual = 1;

		while (jugador->obtenerListaTerreno()->avanzarCursor()){

			Terreno* terrenoActual= jugador -> obtenerListaTerreno()->obtenerCursor();

			int margenAnchoLetra = margenAncho+(margenAncho/2);
			int margenAltoLetra = margenAlto + 5;


			for (unsigned int i=1; i<=terrenoActual->obtenerListaFilas()->contarElementos(); i++){
			        ListaCoordenada<Parcela*>* filaActual = terrenoActual->obtenerListaFilas()->obtener(i);
			        for (unsigned int j=1; j <= filaActual->contarElementos(); j++){

			            Parcela* parcelaActual = filaActual->obtener(j);

						bool escribir = false;

							if (parcelaActual->estaRegada() && parcelaActual->obtenerEstado() != Recuperando){
								strcpy(texto,"P");
								escribir = true;
							}

						else if (!parcelaActual->estaRegada() && parcelaActual->obtenerEstado() != Recuperando){
							strcpy(texto,"S");
							escribir = true;
						}

						else if (parcelaActual->obtenerEstado() == Recuperando){
							strcpy(texto,"R");
							escribir = true;
						}

						if (escribir){
						PrintString(fotoTerreno,texto,filaActual ->obtenerCoordenadaDeLaPosicion(j)*multiplicador+margenAnchoLetra,
												terrenoActual->obtenerListaFilas()->obtenerCoordenadaDeLaPosicion(i)*multiplicador+margenAltoLetra,
												multiplicador-margenAlto,colorFuente);
						}
					}
				}

			std::string jugadorConvertido;
			std::stringstream conversor ;
			conversor<<numeroJugadorActual;
			jugadorConvertido = conversor.str();
			conversor.str(std::string());
			std::string terrenoActualConvertido;
			conversor<< numeroTerrenoActual;
			terrenoActualConvertido = conversor.str();
			conversor.str(std::string());

			std::string turnoActualConvertido;
			conversor<< turnoActual;
			turnoActualConvertido = conversor.str();
			conversor.str(std::string());
			fotoTerreno.WriteToFile(("Jugador"+jugadorConvertido+"_Terreno"+terrenoActualConvertido+
																	"_Turno"+turnoActualConvertido+".bmp").c_str());
			numeroTerrenoActual ++;
			}
		delete texto;
	}






