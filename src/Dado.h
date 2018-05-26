#ifndef DADO_H_
#define DADO_H_

class Dado {
private:
	int numeroRandom;

public:

	//Post: crea el objeto dado.
	Dado();

	//Post: guarda en el atributo numeroRandom, el numero obtenido de forma aleatoria.
	void tirarDado();

	//Post: tira el dado y luego devuelve el numero obtenido.

	int obtenerNumeroRandom();

	~Dado();

};

#endif /* DADO_H_ */
