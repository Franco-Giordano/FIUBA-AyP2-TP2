#ifndef LISTA_H_
#define LISTA_H_

#ifndef NULL
#define NULL 0
#endif

#include "NodoNombrado.h"


template<class T> class ListaNombrada {

private:

	NodoNombrado<T>* primero;

	unsigned int tamanio;

	NodoNombrado<T>* cursor;

public:

	/*
	 * post: Lista vacía.
	 */
	ListaNombrada();

	/*
	 * post: Lista que tiene los mismos elementos que otraLista.
	 *       La instancia resulta en una copia de otraLista.
	 */
	ListaNombrada(ListaNombrada<T>& otraLista);

	/*
	 * post: indica si la Lista tiene algún elemento.
	 */
	bool estaVacia();

	/*
	 * post: devuelve la cantidad de elementos que tiene la Lista.
	 */
	unsigned int contarElementos();

	/*
	 * post: agrega el elemento al final de la Lista, en la posición:
	 *       contarElementos() + 1.
	 */
	void agregar(std::string nombre, T elemento);

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
	 * post: agrega el elemento en la posición indicada.
	 *
	 */
	void agregar(std::string nombre, T elemento, unsigned int posicion);

	/*
	 * post: agrega todos los elementos de otraLista
	 *       a partir de la posición contarElementos() + 1.
	 */
	void agregar(ListaNombrada<T> &otraLista);

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: devuelve el elemento en la posición indicada.
	 */
	T obtenerDato(unsigned int posicion);


	T obtenerNombre(unsigned int posicion);

//	/*
//	 * pre : posicion pertenece al intervalo: [1, contarElementos()]
//	 * post: cambia el elemento en la posición indicada por el
//	 *       elemento dado.
//	 */
//	void asignar(T elemento, unsigned int posicion);

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: remueve de la Lista el elemento en la posición indicada.
	 */
	void remover(unsigned int posicion);

	/*
	 * post: deja el cursor de la Lista preparado para hacer un nuevo
	 *       recorrido sobre sus elementos.
	 */
	void iniciarCursor();

	/*
	 * pre : se ha iniciado un recorrido (invocando el método
	 *       iniciarCursor()) y desde entonces no se han agregado o
	 *       removido elementos de la Lista.
	 * post: mueve el cursor y lo posiciona en el siguiente elemento
	 *       del recorrido.
	 *       El valor de retorno indica si el cursor quedó posicionado
	 *       sobre un elemento o no (en caso de que la Lista esté vacía o
	 *       no existan más elementos por recorrer.)
	 */
	bool avanzarCursor();

	/*
	 * pre : el cursor está posicionado sobre un elemento de la Lista,
	 *       (fue invocado el método avanzarCursor() y devolvió true)
	 * post: devuelve el elemento en la posición del cursor.
	 *
	 */
	T obtenerCursor();

	/*
	 * post: libera los recursos asociados a la Lista.
	 */
	virtual ~ListaNombrada();

private:

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: devuelve el NodoNombrado en la posición indicada.
	 */
	NodoNombrado<T>* obtenerNodoNombrado(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> ListaNombrada<T>::ListaNombrada() {

	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}

template<class T> ListaNombrada<T>::ListaNombrada(ListaNombrada<T>& otraLista) {

	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;

	/* copia los elementos de otraLista */
	this->agregar(otraLista);
}

template<class T> bool ListaNombrada<T>::estaVacia() {

	return (this->tamanio == 0);
}

template<class T> unsigned int ListaNombrada<T>::contarElementos() {

	return this->tamanio;
}

template<class T> void ListaNombrada<T>::agregar(std::string nombre, T elemento) {

	this->agregar(nombre, elemento, this->tamanio + 1);
}

template<class T> void ListaNombrada<T>::agregar(std::string nombre, T elemento, unsigned int posicion) {

	if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

		NodoNombrado<T>* nuevo = new NodoNombrado<T>(nombre, elemento);

		if (posicion == 1) {

			nuevo->cambiarSiguiente(this->primero);
			this->primero = nuevo;

		} else {

			NodoNombrado<T>* anterior = this->obtenerNodoNombrado(posicion - 1);
			nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
			anterior->cambiarSiguiente(nuevo);
		}

		this->tamanio++;

		/* cualquier recorrido actual queda invalidado */
		this->iniciarCursor();
	}

}

template<class T> void ListaNombrada<T>::agregar(ListaNombrada<T> &otraLista) {

	otraLista.iniciarCursor();
	while (otraLista.avanzarCursor()) {
		this->agregar(otraLista.obtenerCursor());
	}
}

template<class T> T ListaNombrada<T>::obtenerDato(unsigned int posicion) {

	T elemento;

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		elemento = this->obtenerNodoNombrado(posicion)->obtenerDato();
	}

	return elemento;
}

template<class T> T ListaNombrada<T>::obtenerNombre(unsigned int posicion) {

	T elemento;

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		elemento = this->obtenerNodoNombrado(posicion)->obtenerNombre();
	}

	return elemento;
}

//template<class T> void ListaNombrada<T>::asignar(T elemento, unsigned int posicion) {
//
//	if ((posicion > 0) && (posicion <= this->tamanio)) {
//
//		this->obtenerNodoNombrado(posicion)->cambiarDato(elemento);
//	}
//}

template<class T> void ListaNombrada<T>::remover(unsigned int posicion) {

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		NodoNombrado<T>* removido;

		if (posicion == 1) {

			removido = this->primero;
			this->primero = removido->obtenerSiguiente();

		} else {

			NodoNombrado<T>* anterior = this->obtenerNodoNombrado(posicion - 1);
			removido = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}

		delete removido;
		this->tamanio--;

		/* cualquier recorrido actual queda invalidado */
		this->iniciarCursor();
	}
}

template<class T> void ListaNombrada<T>::iniciarCursor() {

	this->cursor = NULL;
}

template<class T> bool ListaNombrada<T>::avanzarCursor() {

	if (this->cursor == NULL) {

		this->cursor = this->primero;

	} else {

		this->cursor = this->cursor->obtenerSiguiente();
	}

	/* pudo avanzar si el cursor ahora apunta a un NodoNombrado */
	return (this->cursor != NULL);
}

template<class T> T ListaNombrada<T>::obtenerCursor() {

	T elemento;

	if (this->cursor != NULL) {

		elemento = this->cursor->obtenerDato();
	}

	return elemento;
}

template<class T> ListaNombrada<T>::~ListaNombrada() {

	while (this->primero != NULL) {

		NodoNombrado<T>* aBorrar = this->primero;
		this->primero = this->primero->obtenerSiguiente();

		delete aBorrar;
	}
}

template<class T>
NodoNombrado<T>* ListaNombrada<T>::obtenerNodoNombrado(unsigned int posicion) {

	NodoNombrado<T>* actual = this->primero;
	for (unsigned int i = 1; i < posicion; i++) {

		actual = actual->obtenerSiguiente();
	}

	return actual;
}

#endif /* LISTA_H_ */
