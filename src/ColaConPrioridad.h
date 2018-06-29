#ifndef COLACONPRIORIDAD_H_
#define COLACONPRIORIDAD_H_

#ifndef INFINITO
#define INFINITO 99999999
#endif

#include <string>
#include "ListaNombrada.h"
#include "Candidato.h"
#include <iostream>

class ColaConPrioridad {
private:

	unsigned int maximaCantidad;

	Candidato<std::string>** candidatos; //se identificaran los vertices con strings (sus nombres) pero se ordenaran por peso minimo

	unsigned int posUltima;

	//POST: Copia la lista de adyacencia en el vector de candidatos.
	void copiarListaEnCandidatos(ListaNombrada<ListaNombrada<unsigned int>*>* listaOriginal, unsigned int origen);

	//PRE: el nombre esta en el array
	//POST: Devuelve la posicion en la que está el nombre recibido por parámetro.
	unsigned int hallarPosicionConNombre(std::string nombre);

	//PRE: El elemento en la posicion primero tiene una prioridad peor de la que deberia
	//POST: Acomoda el elemento en su posicion correcta
	void bajar(unsigned int primero);

	//POST: intercambia los punteros almacenados en candidatos[posA] y candidatos[posB]
	void intercambiar(unsigned int posA, unsigned int posB);

	//PRE: El elemento en la posicion pos esta desacomodado, tiene una prioridad mejor de la que deberia
	//POST:  Acomoda el elemento en su posicion correcta
	void subir(int pos);

public:

	//POST: Crea la cola con prioridad, dando prioridad a sus elementos a partir del peso de los mismos.
	ColaConPrioridad(ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia, unsigned int origen);

	//Utilizado para testeo del código.
	void imprimirHeap();

	//POST: Devuelve true si la cola está vacía.
	bool estaVacia();

	//POST: Devuelve el primer elemento de la cola y a su vez lo remueve de la misma.
	Candidato<std::string> removerRaiz();

	//POST: A paritr de un nombre recibido, mejora su peso por el recibido por parámetro.
	void mejorarPeso(std::string nombreRecibido, unsigned int pesoRecibido);

	//POST: Devuelve true en caso de que el nombre esté en la cola con prioridad.
	bool estaNombre(std::string nombre);

	//POST: Transforma la cola con prioridad en una lista nombrada y la devuelve para su uso.
	ListaNombrada<unsigned int>* convertirColaAlistaNombrada();

	~ColaConPrioridad();
};

#endif /* COLACONPRIORIDAD_H_ */
