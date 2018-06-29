#ifndef ListaCoordenada_H_
#define ListaCoordenada_H_

#include "NodoCoordenado.h"
#include <string>

/*
 * Representa una lista pero donde cada elemento tambien posee un atributo COORDENADA, no puede haber dos coordenadas iguales.
 * Los elementos de la misma estan ordenados segun dicho atributo (menor a mayor), donde la coordenada maxima posible sera el atributo LIMITE.
 * Asi, la posicion del elemento en la lista pierde peso, tomando COORDENADA un rol mas importante.
 */
template<class T> class ListaCoordenada {

private:

	NodoCoordenado<T>* primero;

	unsigned int tamanio;

	unsigned int limiteCoordenada;

	NodoCoordenado<T>* cursor;

public:

	/*
	 * post: Lista vacía, capaz de almacenar hasta las coordenada limiteRecibido.
	 */
	ListaCoordenada(unsigned int limiteRecibido);

	/*
	 * post: indica si la Lista tiene algún elemento.
	 */
	bool estaVacia();

	/*
	 * post: devuelve la cantidad de elementos que tiene la Lista.
	 */
	unsigned int contarElementos();

	/*
	 * post: agrega el elemento al final de la Lista, en la POSICION:
	 *       contarElementos() + 1.
	 */
	void agregar(T elemento);

	/*
	 * pre : coordenada pertenece al intervalo: [1, obtenerLimite()] y la misma NO esta ocupada.
	 * post: agrega el elemento en la coordenada indicada de forma ordenada.
	 *
	 */
	void agregarEnCoordenada(T elemento, unsigned int coordenada);

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: devuelve el elemento en la POSICION indicada.
	 */
	T obtener(unsigned int posicion);

	/*
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * post: remueve de la Lista el elemento en la posición indicada.
	 */
	void remover(unsigned int posicion);

	/* PRE: La coordenada pertenece a [1, obtenerLimite()] y esta ocupada.
	 * POST: Remueve el elemento con dicha coordenada de la lista, manteniendo el orden.
	 */
	void removerCoordenada(unsigned int coordenada);

	/*
	 * post: deja el cursor de la Lista preparado para hacer un nuevo
	 *       recorrido sobre sus elementos.
	 */
	void iniciarCursor();

	/*
	 * pre : se ha iniciado un recorrido (invocando el metodo
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
	 *       (fue invocado el metodo avanzarCursor() y devolvió true)
	 * post: devuelve el elemento en la posición del cursor.
	 *
	 */
	T obtenerCursor();

	/*
	 * POST: Devuelve la maxima coordenada que puede almacenar la lista.
	 */
	unsigned int obtenerLimite();

	/*
	 * PRE: coordenada pertenece a [1, obtenerLimite()]
	 * POST: Devuelve si la coordenada dada esta ocupada,
	 */
	bool estaOcupadaLaCoordenada(unsigned int coordenada);

	/* PRE: Lista no vacia
	 * POST: Devuelve la minima coordenada en toda la lista.
	 * (esencialmente, la coordenada del primero ya que esta ordenada)
	 */
	unsigned int verMinimaCoordenada();

	/*
	 * PRE: Coordenada esta en [1, obtenerLimite()] y esta ocupada.
	 * POST: Devuelve el elemento en la COORDENADA indicada.
	 */
	T obtenerEnCoordenada(unsigned int coordenada);

	/*
	 * PRE: posicion entre [1, contarElementos()], lista no vacia
	 * POST: Devuelve la coordenada correspondiente a la posicion recibida.
	 */
	unsigned int obtenerCoordenadaDeLaPosicion(unsigned int posicion);

	/*
	 * post: libera los recursos asociados a la Lista.
	 */
	virtual ~ListaCoordenada();

private:

	NodoCoordenado<T>* obtenerNodoConCoordenada(unsigned int coordenada);

	NodoCoordenado<T>* obtenerNodo(unsigned int posicion);

	NodoCoordenado<T>* obtenerNodoAnteriorALaCoordenada(unsigned int coordenada);

	NodoCoordenado<T>* obtenerNodoCursor();
};

template<class T> ListaCoordenada<T>::ListaCoordenada(unsigned int limiteRecibido) {

	this->primero = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
	this->limiteCoordenada = limiteRecibido;
}

template<class T> unsigned int ListaCoordenada<T>::obtenerCoordenadaDeLaPosicion(unsigned int posicion) {
	return this->obtenerNodo(posicion)->obtenerCoordenada();
}

template<class T> bool ListaCoordenada<T>::estaVacia() {

	return (this->tamanio == 0);
}

template<class T> unsigned int ListaCoordenada<T>::contarElementos() {

	return this->tamanio;
}

template<class T> void ListaCoordenada<T>::agregarEnCoordenada(T elemento, unsigned int coordenada) {

	if ((coordenada > 0) && (coordenada <= this->limiteCoordenada)) {

		NodoCoordenado<T>* nuevo = new NodoCoordenado<T>(elemento, coordenada);

		if (this->estaVacia() || this->verMinimaCoordenada() > coordenada) {
			nuevo->cambiarSiguiente(this->primero);
			this->primero = nuevo;

		} else {

			NodoCoordenado<T>* anterior = this->obtenerNodoAnteriorALaCoordenada(coordenada);
			nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
			anterior->cambiarSiguiente(nuevo);
		}

		this->tamanio++;

		/* cualquier recorrido actual queda invalidado */
		this->iniciarCursor();
	}

	else {
		throw std::string("Coordenada invalida");
	}
}

template<class T>
bool ListaCoordenada<T>::estaOcupadaLaCoordenada(unsigned int coordenada) {

	bool estaOcupada = false;

	this->iniciarCursor();
	NodoCoordenado<T>* NodoCoordenadoActual;

	while (this->avanzarCursor() && !estaOcupada) {

		NodoCoordenadoActual = this->obtenerNodoCursor();

		if (NodoCoordenadoActual->obtenerCoordenada() == coordenada) {

			estaOcupada = true;
		}
	}
	return estaOcupada;
}

template<class T> T ListaCoordenada<T>::obtener(unsigned int posicion) {

	T elemento;

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		elemento = this->obtenerNodo(posicion)->obtenerDato();
	}

	return elemento;
}

template<class T> T ListaCoordenada<T>::obtenerEnCoordenada(unsigned int coordenada) {

	T elemento;

	if ((coordenada > 0) && (this->estaOcupadaLaCoordenada(coordenada))) {

		elemento = this->obtenerNodoConCoordenada(coordenada)->obtenerDato();
	}

	return elemento;
}

template<class T> void ListaCoordenada<T>::remover(unsigned int posicion) {

	if ((posicion > 0) && (posicion <= this->tamanio)) {

		NodoCoordenado<T>* removido;

		if (posicion == 1) {

			removido = this->primero;
			this->primero = removido->obtenerSiguiente();

		} else {

			NodoCoordenado<T>* anterior = this->obtenerNodo(posicion - 1);
			removido = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}

		delete removido;
		this->tamanio--;

		/* cualquier recorrido actual queda invalidado */
		this->iniciarCursor();
	}
}

template<class T> void ListaCoordenada<T>::removerCoordenada(unsigned int coordenada) {

	if ((coordenada > 0) && (estaOcupadaLaCoordenada(coordenada))) {

		NodoCoordenado<T>* removido;

		if (this->verMinimaCoordenada() == coordenada) {

			removido = this->primero;
			this->primero = removido->obtenerSiguiente();

		} else {

			NodoCoordenado<T>* anterior = this->obtenerNodoAnteriorALaCoordenada(coordenada);
			removido = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}

		delete removido;
		this->tamanio--;

		/* cualquier recorrido actual queda invalidado */
		this->iniciarCursor();
	}
}

template<class T> unsigned int ListaCoordenada<T>::verMinimaCoordenada() {
	return this->primero->obtenerCoordenada();
}

template<class T> void ListaCoordenada<T>::iniciarCursor() {

	this->cursor = NULL;
}

template<class T> bool ListaCoordenada<T>::avanzarCursor() {

	if (this->cursor == NULL) {

		this->cursor = this->primero;

	} else {

		this->cursor = this->cursor->obtenerSiguiente();
	}

	/* pudo avanzar si el cursor ahora apunta a un NodoCoordenado */
	return (this->cursor != NULL);
}

template<class T> T ListaCoordenada<T>::obtenerCursor() {

	T elemento;

	if (this->cursor != NULL) {

		elemento = this->cursor->obtenerDato();
	}

	return elemento;
}

template<class T> NodoCoordenado<T>* ListaCoordenada<T>::obtenerNodoCursor() {
	NodoCoordenado<T>* elemento;

	if (this->cursor != NULL) {
		elemento = this->cursor;
	}

	return elemento;
}

template<class T> ListaCoordenada<T>::~ListaCoordenada() {

	while (this->primero != NULL) {

		NodoCoordenado<T>* aBorrar = this->primero;
		this->primero = this->primero->obtenerSiguiente();

		delete aBorrar;
	}
}

template<class T>
NodoCoordenado<T>* ListaCoordenada<T>::obtenerNodoConCoordenada(unsigned int coordenada) {

	NodoCoordenado<T>* actual = this->primero;
	unsigned int i = actual->obtenerCoordenada();
	while ((i < coordenada) && (i != 0)) {

		actual = actual->obtenerSiguiente();
		i = actual->obtenerCoordenada();
	}

	return actual;
}

template<class T>
NodoCoordenado<T>* ListaCoordenada<T>::obtenerNodo(unsigned int posicion) {

	NodoCoordenado<T>* actual = this->primero;
	for (unsigned int i = 1; i < posicion; i++) {

		actual = actual->obtenerSiguiente();
	}

	return actual;
}

template<class T>
NodoCoordenado<T>* ListaCoordenada<T>::obtenerNodoAnteriorALaCoordenada(unsigned int coordenada) {

	NodoCoordenado<T>* actual = NULL;
	this->iniciarCursor();
	while ((this->avanzarCursor()) && (this->obtenerNodoCursor()->obtenerCoordenada() < coordenada)) {
		actual = this->obtenerNodoCursor();
	}

	return actual;
}

template<class T>
unsigned int ListaCoordenada<T>::obtenerLimite() {
	return this->limiteCoordenada;
}

#endif /* ListaCoordenada_H_ */
