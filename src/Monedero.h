#ifndef MONEDERO_H_
#define MONEDERO_H_

class Monedero {
private:
	unsigned int dinero;
public:
	//Pre: Recibe N y M, los cuales representan las dimensiones del terreno inicial.
	// La dificultad se encuentra en el intervalo [1,3]
	//Post: Crea el monedero que usar� el usuario a lo largo de la partida.
	Monedero(unsigned int N, unsigned int M, unsigned int dificultad);

	//Post: devuelve el dinero que el usuario podr� gastar en su proximo turno.
	int obtenerDineroActual();

	//Post: devuelve true si el usuario posee mas dinero del que va a gastar.
	bool dineroSuficiente(unsigned int dineroAGastar);

	//Pre: recibe el dinero que se sumar� al haber del jugador.
	//Post: Suma el dinero obtenido al que el usuario ten�a previamente.
	void sumarDinero(unsigned int dineroASumar);

	//Pre: El dinero a gastar no puede ser mayor al dinero que el usuario posee, ya que de lo contrario
	// el jugar quedaria con un monto negativo.
	//Post: Resta el dinero del haber del jugador.
	void gastarDinero(unsigned int dineroAGastar);

	virtual ~Monedero();
};

#endif /* MONEDERO_H_ */
