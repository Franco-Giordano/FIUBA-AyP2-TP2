#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

#include <string>

template<class T> class NodoNombrado {

private:
	std::string nombre;

	T dato;

	NodoNombrado<T>* siguiente;

public:

	/*
	 * post: el Nodo resulta inicializado con el dato dado
	 *       y sin un Nodo siguiente.
	 */
	NodoNombrado(std::string nombre, T dato) {

		this->nombre = nombre;
		this->dato = dato;
		this->siguiente = NULL;
	}

	/*
	 * post: devuelve el valor del dato.
	 */
	T obtenerDato() {

		return this->dato;
	}

	/*
	 * post: cambia el valor del dato.
	 */
	void cambiarDato(T nuevoDato) {

		this->dato = nuevoDato;
	}

	/*
	 * post: devuelve el siguiente Nodo.
	 */
	NodoNombrado<T>* obtenerSiguiente() {

		return this->siguiente;
	}

	/*
	 * post: cambia el siguiente Nodo por nuevoSiguiente.
	 */
	void cambiarSiguiente(NodoNombrado<T>* nuevoSiguiente) {

		this->siguiente = nuevoSiguiente;
	}

	/*
	 * post: devuelve el valor del dato.
	 */
	T obtenerNombre() {

		return this->nombre;
	}

	/*
	 * post: cambia el valor del dato.
	 */
	void cambiarNombre(std::string nombre) {

		this->nombre = nombre;
	}
};

#endif /* NODO_H_ */
