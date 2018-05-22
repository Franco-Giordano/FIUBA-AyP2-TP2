#include "RealizadorDeAcciones.h"
#include <iostream>
using namespace std;

RealizadorDeAcciones::RealizadorDeAcciones()
{
	Acciones acciones;
	opcion=acciones.obtenerOpcionElegida();
}

void RealizadorDeAcciones::realizoAccion(unsigned int opcion, int dificultad)
{
	opcion=this-> opcion;
	switch (opcion)
	{
		case 1:	sembrar();
		break;
		case 2:	cosechar();
		break;
		case 3:	regar();
		break;
		case 4: enviarCosecha();
		break;
		case 5: comprarTerreno();
		break;
		case 6: venderTerreno();
		break;
		case 7: comprarCapacidadTanque(dificultad);
		break;
		case 8: comprarCapacidadAlmacen(dificultad);
		break;
		case 9: pasarTurno();
		break;
	}
}

unsigned int RealizadorDeAcciones::obtenerFila()
{
	unsigned int fila;
	cout<<"Ingrese la fila"<<endl;
	return fila;
}

unsigned int RealizadorDeAcciones::obtenerColumna()
{
	unsigned int columna;
	cout<<"Ingrese la columna"<<endl;
	return columna;
}

int RealizadorDeAcciones::obtenerTerreno()
{
	Jugador jugador;
	int terrenoAUtilizar;
	cout<<"¿Que terreno desea utilizar?"<<endl;
	cin>>terrenoAUtilizar;
	while (jugador.cantidadDeTerrenos < terrenoAUtilizar)
	{
		cout<<"No existe ese terreno, ingrese uno valido"<<endl;
		cin>>terrenoAUtilizar;
	}
	return terrenoAUtilizar;
}

void RealizadorDeAcciones::sembrar()
{
	Jugador jugador;
	Terreno terreno;
	unsigned int fila, columna;
	unsigned int terrenoASembrar;

	//mostrar y preguntar que cultivo quiere comprar y sembrar

	terrenoASembrar=obtenerTerreno();

	cout<<"¿En que parcela desea sembrar?"<<endl;
	fila=obtenerFila();
	columna=obtenerColumna();

	if((jugador.obtenerListaTerreno()->obtener(terrenoASembrar)->obtenerParcela(fila, columna).estaLibre()) &&
	(jugador.obtenerListaTerreno()->obtener(terrenoASembrar)->obtenerParcela(fila, columna).obtenerTiempoRecuperacion()==0))
	{
		jugador.sembrar(terrenoASembrar, fila, columna, cultivo); //falta el cultivo con la lista
		jugador.obtenerListaTerreno()->obtener(terrenoASembrar)->obtenerParcela(fila, columna).estado=Plantada;
	}
	else
		cout<<"No se puede sembrar alli."<<endl;

}

void RealizadorDeAcciones::cosechar()
{
	Jugador jugador;
	unsigned int terrenoACosechar=obtenerTerreno();

	cout<<"¿Que parcela desea cosechar?"<<endl;
	unsigned int fila=obtenerFila();
	unsigned int columna=obtenerColumna();

	if((jugador.obtenerListaTerreno()->obtener(terrenoACosechar)->obtenerParcela(fila, columna).estaPlantada()) &&
		(jugador.obtenerListaTerreno()->obtener(terrenoACosechar)->obtenerParcela(fila, columna).obtenerTiempoCosecha()==0))
	{
		jugador.cosechar(terrenoACosechar, fila, columna); //Falta que sume los creditos en cosecharParcela
		cout<<"Ha cosechado con exito"<<endl;
	}
	else
		cout<<"No se puede cosechar allí."<<endl; //Despues aclaro bien por qué no se puede
}

void RealizadorDeAcciones::regar()
{
	Jugador jugador;
	unsigned int terrenoARegar=obtenerTerreno();

	cout<<"¿Que parcela desea regar?"<<endl;
	unsigned int fila=obtenerFila();
	unsigned int columna=obtenerColumna();

	if(!(jugador.obtenerListaTerreno()->obtener(terrenoARegar)->obtenerParcela(fila, columna).estaRegada()) &&
		!(jugador.obtenerListaTerreno()->obtener(terrenoARegar)->obtenerParcela(fila, columna).estaLibre()))

		jugador.regar(terrenoARegar, fila, columna);

	else
		cout<<"No hace falta regar esa parcela"<<endl;
}

void RealizadorDeAcciones::enviarCosecha()
{

}

void RealizadorDeAcciones::comprarTerreno()
{
	Jugador jugador;
	cout<<"Ingrese la cantidad de filas y columnas que desea que su nuevo terreno posea: "<<endl;
	unsigned int filas=obtenerFila();
	unsigned int columnas=obtenerColumna();
	//Falta el precio del terreno
	jugador.comprarTerreno(filas, columnas);
}

void RealizadorDeAcciones::venderTerreno()
{
	Jugador jugador;
	unsigned int terrenoAVender=obtenerTerreno();
	//Falta el precio del terreno
	jugador.venderTerreno(terrenoAVender);
}

void RealizadorDeAcciones::comprarCapacidadTanque(int dificultad)
{
	TanqueDeAgua tanque;
	Monedero* monedero;
	unsigned int ampliacion;
	cout<<"¿Cuanto desea ampliar su tanque?"<<endl;
	cin>>ampliacion;
	if(monedero->dineroSuficiente(dificultad*ampliacion)) //dificultad*ampliacion es el precio
		tanque.ampliarTanque(dificultad, monedero, ampliacion);
	else
		cout<<"No posee dinero suficiente"<<endl;
}

void RealizadorDeAcciones::comprarCapacidadAlmacen(int dificultad, Almacen *almacen, Monedero* monedero)
{
	unsigned int ampliacion, precio=(ampliacion + dificultad) *10; 
	cout<<"¿Cuanto desea ampliar su almacen?"<<endl;
	cin>>ampliacion;
	if(almacen->capacidadValida() && monedero->dineroSuficiente(precio))
	{
		almacen->agrandarAlmacen(monedero, ampliacion, dificultad); 
	}
	else
		cout<<"No se ha podido realizar la expansion"<<endl;

}

void RealizadorDeAcciones::pasarTurno()
{

}

void RealizadorDeAcciones::impresionFinDeJuego(Lista<Jugador*>* jugadores)
{
	unsigned int ganador;
	for (unsigned int j=1; j<jugadores->contarElementos(); j++)
	{
		Jugador* jugadorActual=jugadores->obtener(j);
		Jugador* jugadorSiguiente;
		if(j!=jugadores->contarElementos())
			jugadorSiguiente=jugadores->obtener(j+1);
		else
			jugadorSiguiente=jugadorActual;
		cout<<"Jugador "<<j<<endl;
		cout<<"Cantidad de terrenos: "<<jugadorActual->obtenerListaTerreno()->contarElementos()<<endl;
		cout<<"Creditos: "<<jugadorActual->monedero->obtenerDineroActual()<<endl;
		if(jugadorActual->monedero->obtenerDineroActual() >= jugadorSiguiente->monedero->obtenerDineroActual())
			ganador=j;
		else
			ganador=j+1;
	}
	cout<<"El ganador es el jugador "<< ganador;
}

void RealizadorDeAcciones::verMisTerrenos(Jugador* jugadorActual)
{
	unsigned int f, c, t; //fila, columna, terreno
	Lista<Terreno*>* listaJugadorActual=jugadorActual->obtenerListaTerreno();
	for(t=1; t<=listaJugadorActual->contarElementos(); t++)
	{
		cout<<"Terreno "<<t<<endl;
		for (f=0; f<listaJugadorActual->obtener(t)->obtenerFilas(); f++)
		{
			for (c=0; c<listaJugadorActual->obtener(t)->obtenerColumnas(); c++)
			{
				if (listaJugadorActual->obtener(t)->obtenerParcela(f,c).estaLibre())
				cout<<"L"; //libre
				else if (listaJugadorActual->obtener(t)->obtenerParcela(f,c).estaPlantada())
				cout<<"P"; //plantada
			}
			cout<<endl;
		}
		cout<<endl;
	}
}