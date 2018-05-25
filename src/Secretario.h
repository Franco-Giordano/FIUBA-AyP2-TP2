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

    //Pre: se reciben los cat�logo, los cuales se suponen v�lidos.
    //Post: Crea un secretario, cuya funcion es la de atender al jugador durante el juego, este conoce
    // el numero de turnos, la cantidad de jugadores, el tama�o del terreno y la dificultad del juego.
    // Incluso posee los catalogos, de semillas y de destinos, que son las semillas que se pueden sembrar,
    // en una parcela y los lugares a donde se pueden enviar una vez cosechadas.
	Secretario(CatalogoDe<Cultivo>* pCatalogoSemillas, CatalogoDe<Destino>* pCatalogoDestinos);

	//Post:  valida que el numero ingresado este en el rango (minimo, maximo).
	int obtenerNumero(int minimo, int maximo, std::string textoOpcional = "");

	//Post: valida que el numero ingresado sea mayor al minimo recibido por parametro.
	int obtenerNumero(int minimo, std::string textoOpcional = "");

	//Post: devuelve la cantidad de turnos.
	int obtenerCantidadTurnos();

	//Post: devuelve N, que hace referencia a la cantidad de filas.
	int obtenerFilas();

	//Post: devuelve M, que hace referencia a la cantidad de columnas.
	int obtenerColumnas();

	//Post: devuelve el numero de jugadores.
	int obtenerNumeroDeJugadores();

	//Post: devuelve la dificultad.
	int obtenerDificultad();

	//Pre: recibe al jugador el cual va a realizar la accion.
	//Post: El jugador elige la accion dentro del rango de opciones que posee.
	void atenderJugador(Jugador* jugador);

	//Post: realiza la accion elegida por el jugador en atenderJugador().
	bool administrarEleccion(unsigned int eleccion, Jugador* jugador, Acciones acciones);

	//Post: devuelve el terreno en el cual se va a realizar la accion deseada.
    unsigned int obtenerTerrenoDeJugador(Jugador* jugador);

    //Post: si el terreno no esta vacio te avisa que se puede llegar a perder una cosecha.
    bool advertirQuePuedePerderCosechas(Jugador* jugador, unsigned int posicionT);

    //Post: siembra el cultivo y larga un mensaje indicandole al jugador que fue correcto su intento de sembrar,
    // en caso contrario le avisa que no se pudo llevar a cabo la accion.
    void gestionarSiembra(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    //Post: cosecha el cultivo y larga un mensaje indicandole al jugador que fue correcto su intento de cosechar,
    // en caso contrario le avisa que no se pudo llevar a cabo la accion.
    void gestionarCosecha(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    //Post: riega el cultivo y larga un mensaje indicandole al jugador que fue correcto su intento de regar,
    // en caso contrario le avisa que no se pudo llevar a cabo la accion.
    void gestionarRiego(Terreno* terreno, unsigned int fila, unsigned int columna, Jugador* jugador);

    //Pre: recibe al jugador que llevara a cabo la accion.
    //Post: envia el cultivo al destino indicado chequeando previamente que se cumpla cada condicion.
    void gestionarEnvioCosecha(Jugador* jugador, Acciones acciones);

    //Pre: recibe al jugador que llevara a cabo la accion.
    //Post: compra un terreno para el usuario si posee el dinero necesario como para comprar.
    void gestionarCompraTerreno(Jugador* jugador);

    //Pre: recibe al jugador que llevara a cabo la accion.
    //Post: Chequea que el usuario pueda vender un terreno, luego le muestra el potencial dinero que podria llegar
    // a ganar luego de la venta del terreno. Luego puede, si lo desea, realizarse la venta.
    void gestionarVentaTerreno(Jugador* jugador);

    //Pre: recibe al jugador que llevara a cabo la accion.
    //Post: El jugador ingresa en cuantas unidades desea ampliar el tanque, una vez hecho esto, chequea que posea
    // el dinero suficiente, en caso positivo, amplia el tanque.
    void gestionarAmpliarTanque(Jugador* jugador);

    //Pre: recibe al jugador que llevara a cabo la accion.
    //Post: Amplia el almacen si el jugador posee el dinero suficiente con el tama�o ingresado, en caso contrario
    // le avisa al jugador que no se pudo llevar a cabo la accion.
    void gestionarAmpliarAlmacen(Jugador* jugador);

    // FALTA AMPLIARRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR.
    Cultivo* seleccionarCultivoDeCatalogo();
};



#endif /* SRC_SECRETARIO_H_ */
