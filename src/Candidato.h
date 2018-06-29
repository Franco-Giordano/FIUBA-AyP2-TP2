#ifndef CANDIDATO_H_
#define CANDIDATO_H_

template <class T>
class Candidato{

private:
    T identificador;

    unsigned int peso;

public:

    //Post: Inicializa el objeto con basura.
    Candidato<T>();

    //Post: crea un candidato, el cual representa un nodo del heap y que posee un identificador y un peso. Este peso
    // es el del camino del grafo ponderado.
    Candidato<T>(T ident, unsigned int peso);

    // Post: devuelve el identificador que es de tipo T.
    T obtenerIdentificador();

    // Post: modifica el peso actual por el nuevoPeso recibidio por parametro.
    void modificarPeso(unsigned int nuevoPeso);

    // Post: devuelve el peso del candidato.
    unsigned int obtenerPeso();
};

template <class T>
Candidato<T>::Candidato() {
	T objeto;
	this->identificador = objeto;
	this->peso = 0;
}


template <class T>
Candidato<T>::Candidato(T ident, unsigned int peso) {

	this->identificador = ident;

    this->peso = peso;
}

template <class T>
T Candidato<T>::obtenerIdentificador() {

	return identificador;
}

template <class T>
void Candidato<T>::modificarPeso(unsigned int nuevoPeso){

	this->peso= nuevoPeso;
}

template <class T>
unsigned int Candidato<T>::obtenerPeso() {

	return peso;
}

#endif /* CANDIDATO_H_ */
