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

	void copiarListaEnCandidatos(ListaNombrada<ListaNombrada<unsigned int>*>* listaOriginal, unsigned int origen);

	//PRE: el nombre esta en el array
	unsigned int hallarPosicionConNombre(std::string nombre);

	void bajar(unsigned int primero, unsigned int ultimo);

	//intercambia los punteros almacenados en candidatos[posA] y candidatos[posB]
	void intercambiar(unsigned int posA, unsigned int posB);

    void subir(int pos);

public:

	ColaConPrioridad(ListaNombrada<ListaNombrada<unsigned int>*>* listaAdyacencia, unsigned int origen);

	void imprimirHeap();

	bool estaVacia();

	Candidato<std::string> removerRaiz();

	void mejorarPeso(std::string nombreRecibido, unsigned int pesoRecibido);

	bool estaNombre(std::string nombre);

	ListaNombrada<unsigned int>* convertirColaAlistaNombrada();

	~ColaConPrioridad();
};



#endif /* COLACONPRIORIDAD_H_ */
