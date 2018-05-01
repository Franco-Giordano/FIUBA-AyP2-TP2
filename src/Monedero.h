#ifndef MONEDERO_H_
#define MONEDERO_H_

class Monedero {
private:
	unsigned int dinero;
public:
	//Pre: Recibe N y M, los cuales representan las dimensiones del terreno inicial.
	// La dificultad se encuentra en el intervalo [1,3]
	//Post: Crea el monedero que usará el usuario a lo largo de la partida.
	Monedero(unsigned int N, unsigned int M, unsigned int dificultad);

	//Post: devuelve el dinero que el usuario podrá gastar en su proximo turno.
	int obtenerDineroActual();

	//Pre: recibe el dinero que se sumará al haber del jugador.
	//Post: Suma el dinero obtenido al que el usuario tenía previamente.
	void sumarDinero(unsigned int dineroASumar);

	//Pre: El dinero a gastar no puede ser mayor al dinero que el usuario posee, ya que de lo contrario
	// el jugar quedaria con un monto negativo.
	//Post: Resta el dinero del haber del jugador.
	void gastarDinero(unsigned int dineroAGastar);


	~Monedero();
};

#endif /* MONEDERO_H_ */