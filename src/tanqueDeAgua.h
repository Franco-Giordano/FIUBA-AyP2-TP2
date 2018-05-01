#ifndef TANQUEDEAGUA_H_
#define TANQUEDEAGUA_H_

#include <iostream>

class tanqueDeAgua {
private:
	unsigned int cantidadDeAguaActual;
	unsigned int cantidadDeAguaMaxima;
public:
	//Pre: se recibe N,M y la dificultad
	//dado el tamaño del terreno como [N,M] y la dificultad en el intervalo [1,3]
	// ambas ingresadas por el usuario
	//Post: se crea el tanque de agua vacio (cantidad de agua = 0)
	tanqueDeAgua(unsigned int N, unsigned int M, unsigned int dificultad);

	//Pre: Se recibe la cantidad de agua a agregar en el tanque, la cual es un entero valido
	//Post: Se modifica la cantidad de agua en el tanque
	void agregarAgua(int cantidad);

	//Mismas condiciones que para agregarAgua
	void restarAgua(int cantidad);

	//Pre: La ampliacion depende de la dificultad y de la eleccion del usuario. El usuario podrá
	//elegir una ampliacion de 5, 10 o 15 unidades, y la dificultad cambiara el dinero requerido para
	//llevar a cabo esa accion.
	//Post: se amplia el tanque restando el dinero del monedero
	void ampliarTanque(int dificultad);

	~tanqueDeAgua();
};

#endif /* TANQUEDEAGUA_H_ */
