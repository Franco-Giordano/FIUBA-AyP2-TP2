
#ifndef TANQUEDEAGUA_H_
#define TANQUEDEAGUA_H_

#include <iostream>
#include "Monedero.h"

class TanqueDeAgua {
private:
	unsigned int cantidadDeAguaActual;
	unsigned int cantidadDeAguaMaxima;
public:
	//Pre: se recibe N,M y la dificultad
	//dado el tamaño del terreno como [N,M] y la dificultad en el intervalo [1,3]
	// ambas ingresadas por el usuario
	//Post: se crea el tanque de agua vacio (cantidad de agua = 0)
	TanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad);

	//Pre: Se recibe la cantidad de agua a agregar en el tanque, la cual es un entero valido
	//Post: Se modifica la cantidad de agua en el tanque
	void agregarAgua(int cantidad);

	//Pre: La cantidad de agua no puede ser mayor a la cantidad actual, ya que de lo contrario,
	// el usuario quedaria con una cantidad negativa de agua en su tanque.
	//Post: Quita el agua del tanque.
	void restarAgua(int cantidad);

	//Post: devuelve los potenciadores de agua disponibles para el usuario
	int obtenerCantidadDeAguaActual();

	//Post: devuelve la capacidad maxima del tanque de agua.
	int obtenerCantidadDeAguaMaxima();

	//Pre: La ampliacion depende de la dificultad y de la eleccion del usuario. El usuario podrá
	//elegir una ampliacion de 5, 10 o 15 unidades, y la dificultad cambiara el dinero requerido para
	//llevar a cabo esa accion. Recibe el monedero para poder modificar el haber del jugador.
	//Post: se amplia el tanque restando el dinero del monedero.
	void ampliarTanque(int dificultad, Monedero &monedero, int ampliacionElegida);

	~TanqueDeAgua();
};

#endif /* TANQUEDEAGUA_H_ */
