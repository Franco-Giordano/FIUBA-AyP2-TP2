/*
 * tanqueDeAgua.h
 *
 *  Created on: 28 abr. 2018
 *      Author: Alvaro
 */

#ifndef TANQUEDEAGUA_H_
#define TANQUEDEAGUA_H_

#include <iostream>
#include "Monedero.h"

class TanqueDeAgua {
private:
	unsigned int cantidadDeAguaActual;
	unsigned int capacidadMaxima;
public:
	//Pre: se recibe N,M y la dificultad
	//dado el tamanio del terreno como [N,M] y la dificultad en el intervalo [1,3]
	// ambas ingresadas por el usuario
	//Post: se crea el tanque de agua vacio (cantidad de agua = 0)
	TanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad);

	//Pre: Se recibe la cantidad de agua a agregar en el tanque, la cual es un entero valido
	//Post: Se modifica la cantidad de agua en el tanque y  devuelve cuanta agua se perdio, es decir, unidades de riego que superar la capacidad (0 si no se perdio nada).
	unsigned int agregarAgua(int cantidad);

	//Pre: La cantidad de agua no puede ser mayor a la cantidad actual, ya que de lo contrario,
	// el usuario quedaria con una cantidad negativa de agua en su tanque.
	//Post: Quita el agua del tanque.
	void restarAgua(int cantidad);

	//Post: devuelve los potenciadores de agua disponibles para el usuario
	unsigned int obtenerCantidadDeAguaActual();

	//Post: devuelve la capacidad maxima del tanque de agua.
	unsigned int obtenerCantidadDeAguaMaxima();

	//Post: devuelve true si la cantidad de agua en el tanque es mayor a 0.
	bool hayAguaEnElTanque();

	//Pre: La ampliacion depende de la dificultad y de la eleccion del usuario. El usuario podra
	//elegir una ampliacion de 5, 10 o 15 unidades, y la dificultad cambiara el dinero requerido para
	//llevar a cabo esa accion. Recibe el monedero para poder modificar el haber del jugador.
	//Post: se amplia el tanque restando el dinero del monedero.
	void ampliarTanque(int ampliacionElegida);

	~TanqueDeAgua();
};

#endif /* TANQUEDEAGUA_H_ */
