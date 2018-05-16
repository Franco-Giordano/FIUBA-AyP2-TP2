#include "Acciones.h"
using namespace std;

Acciones::Acciones(){
	opcionElegida=0;
}

void Acciones::mostrarAccionesPosibles(){
	unsigned int opcion;
	cout<<"Estas son las acciones que puede realizar, elija la que desea:"<<endl;
	cout<<"1. Comprar semillas"<<endl;
	cout<<"2. Sembrar"<<endl;
	cout<<"3. Cosechar"<<endl;
	cout<<"4. Regar"<<endl;
	cout<<"5. Enviar una cosecha"<<endl;
	cout<<"6. Comprar un terreno"<<endl;
	cout<<"7. Vender un terreno"<<endl;
	cout<<"8. Comprar capacidad del tanque de agua"<<endl;
	cout<<"9. Comprar capacidad del almacen"<<endl;
	cout<<"10. Pasar de turno"<<endl;
	cin>>opcion;
	while (!opcionValida(opcion))
	{
		cout<<"Opcion invalida, ingrese otra: "<<endl;
		cin>>opcion;
	}
	opcionElegida=opcion;
}

unsigned int Acciones::obtenerOpcionElegida()
{
	return opcionElegida;
}

bool Acciones::opcionValida(unsigned int opcion)
{
	return (opcion>0 && opcion<11);
}