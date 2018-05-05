#ifndef DADO_H_
#define DADO_H_

class Dado {
	private:
	int numeroRandom;

	public:

	//PRE: El dado no depende de ningun parametro.
	//POST: crea el dado.
	Dado();

	//PRE:
	//POST: devuelve un numero obtenido de forma aleatoria, del 1 al 6.
	void tirarDado();

	//PRE:
	//POST: tira el dado y luego devuelve el numero obtenido.

	int obtenerNumeroRandom();

	~Dado();

};

#endif /* DADO_H_ */
