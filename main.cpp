/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charles-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*---------------------------------------------------*/
/*-Main del proyecto de gestion de hospitales, en----*/
/*-el cual se pueden realizar pruebas para comprobar-*/
/*-el funcionamiento de cada clase y ver algunas-----*/
/*-interacciones.-*/
/*---------------------------------------------------*/


/*-Se incluyen las librerias necesarias para leer y -*/
/*-mostrar variables, asi como manipular strings-----*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*-Se incluyen las clases desarrolladas--------------*/
#include "Restaurante.h"

int main() { 
	/*-A continuacion se crean 3 objetos tanto de comida como de bebida, se optó-*/
	/*-por ese numero para no saturar al usuario con información al momento de---*/
	/*-usar la función muestra_menu(). Posteriormente se crea un restaurante con-*/
	/*el nombre de Charles y se agregan los objetos de comida y bebida a este restaurante-*/
	/*---------------------- 	C	O	M	I	D	A	 ---------------------*/
	Comida comida1("Hamburguesa con papas", 150.5,1,"pequenio",0);
	Comida comida2("Caldo de pollo", 95.7,1,"pequenio",0);
	Comida comida3("Chilaquiles verdes", 69.99,1,"pequenio", 1);
	Comida lista_c[3] = {comida1,comida2,comida3};
	/*------------------------------ B E B I D A -----------------------------*/
	Bebida bebida1("Squirt", 35.5,1,20.5,0);
	Bebida bebida2("Coca-cola", 35.7,1,20.5,0);
	Bebida bebida3("Cerveza", 50.4,1,20.5,0);
	Bebida lista_b[3] = {bebida1,bebida2,bebida3};
	/*-------------------------------------------------------------------------*/
	Restaurante charles("Charles");
	charles.agrega_comida(comida1);
	charles.agrega_comida(comida2);
	charles.agrega_comida(comida3);
	charles.agrega_bebida(bebida1);
	charles.agrega_bebida(bebida2);
	charles.agrega_bebida(bebida3);
	/*-------------------------------------------------------------------------*/
	/*-------------------- DECLARACION DE VARIABLES ---------------------------*/
	int num_clientes, opcion, index_lista;
	int ciclo = 0;
	float total = 0.0;
	float subtotal = 0.0;
	bool vegano, hielo;
	/*-------------------------------------------------------------------------*/
	/*-El programa actuará como una historia donde se usen las funciones del programa-*/
	cout << "Bienvenido a tu primer dia de trabajo mesero, me ayudaras el dia de hoy..." << endl;
	cout << "\n" << "En una mesa te han pedido una hamburgesa con papas y un squirt, podrias preguntarle si la quiere vegana y su refresco con hielo..." << endl;
	cout << "Desea su comida vegana? (1-> si, 0 -> no): "; cin >> vegano; 
	cout << "Desea su bebida con hielo? (1-> si, 0 -> no): "; cin >> hielo; cout << endl;
	comida1.set_vegano(vegano); // setter que modifica el atributo de Comida vegano.
	bebida1.set_hielo(hielo); // setter que modifica el atributo de Bebida hielo.
	/*-A continuacion usa un getter para recibir el nombre de la Comida y Bebida, ademas de dos metodos calcula_total diferentes-*/
	/*-el metodo de comida recibe un costo, cantidad y si la comida es vegana, el metodo de bebida recibe si tiene hielo, cantidad-*/
	/*- y el costo-*/
	cout << "Ahora muestrale su total de la compra..." << endl;
	cout << "Precio de " << comida1.get_orden() << ": " << comida1.calcula_total(comida1.get_costo(),comida1.get_cantidad(), vegano) << endl;
	cout << "Precio de " << bebida1.get_orden() << ": " << bebida1.calcula_total(hielo, bebida1.get_cantidad(), bebida1.get_costo()) << endl;
	subtotal = comida1.calcula_total(comida1.get_costo(),comida1.get_cantidad(), vegano); // vuelve a llamar y lo asigna a la variable subtotal
	total = total + subtotal; // donde lo agrega al total como un contador.
	subtotal = bebida1.calcula_total(hielo, bebida1.get_cantidad(), bebida1.get_costo()); // llama y asigna un nuevo valor a la variable sutotal
	total = total + subtotal; // lo guarda en el contador de total y lo imprime
	cout << "Total de la compra: " << total << "\n" << endl;
	total = 0.0; // vuelve a asignar el valor de total en 0 para "limpiarlo"
	
	/*-CONTINUACION DE LA HISTORIA-*/
	cout << "Oh mira te han llegado clientes, ingresa cuantos son: "; cin >> num_clientes; cout << "\n";
	charles.recibe_cliente(num_clientes); // crea Clientes dependiendo cuantos quiere crear con un ciclo for de la funcion.
	cout << "Muy bien, verifica que los clientes tengan los datos correctos..." << endl;
	charles.mostrar_cliente(num_clientes); // muestra los Clientes que hay en un arreglo con el mismo numero que creo el usuario
	
	cout << "Ahora deberias mostrarles el menu para que decidan que comer..." << "\n" << endl;
	charles.muestra_menu(3); // muestra el menu que recibe el numero de posiciones a imprimir, como tenemos 3 productos recibe un 3
		
	do // repetirá la seccion de codigo dependiendo el numero de clientes que ingreso
	{
		cout << "\n" << "|| --- C L I E N T E " <<ciclo+1 << " --- ||" << endl;
		cout << "*actuaras como cliente un rato, te gustaria ordenar una comida del menu...*" << endl;
		cout << "1 = Si, 0 = No: "; cin >> opcion; cout << endl;
		switch (opcion) // switch para el caso de que elija pedir comida o no
		{
			case 0: // el cliente no pidio comida
				cout << "Esta perfecto, sin problema..." << endl;
				cout << "trata de usar la opcion 1 para continuar mas :)" << endl;
				break;
			
			case 1: // el cliente pidio comida
				cout << "Que numero de comida te gustaria ordenar: "; cin >> index_lista; cout << endl;
				if(index_lista >= 1 && index_lista <=3) // verifica que el numero ingresado se encuentre en la lista
				{
					lista_c[index_lista - 1].mostrar_datos(); // muestra los datos de la comida que eligio
				}else // no reconocio el numero en la lista
				{
					cout << "comida no reconocida..." << endl;
				}
				subtotal = lista_c[index_lista - 1].calcula_total(lista_c[index_lista - 1].get_costo(),lista_c[index_lista - 1].get_cantidad(),lista_c[index_lista - 1].get_vegano());
				cout << "Subtotal de compra: " << subtotal << endl; // asigna el subtotal del pedido de comida que eligio y lo imprime.
				break;
				
			default: // se ingreso otra opcion diferente a uno o cero
				cout << "opcion no reconocida" << endl;
				break;
		}
		cout << "\n" << "*te gustaria ordenar una bebida del menu...*" << endl;
		cout << "1 = Si, 0 = No: "; cin >> opcion; cout << endl;
		switch (opcion) // switch para el caso de que elija una bebida o no
		{
			case 0: //el cliente no pidio bebida
				cout << "Esta perfecto, sin problema..." << endl;
				cout << "trata de usar la opcion 1 para continuar mas :)" << endl;
				break;
			case 1: // el cliente pidio bebida
				cout << "Que numero de bebida te gustaria ordenar: "; cin >> index_lista; cout << endl;
				if(index_lista >= 1 && index_lista <= 3) // verifica que el numero ingresado se encuentre en la lista
				{
					lista_b[index_lista - 1].mostrar_datos();
				}else // no reconocio el numero en la lista
				{
					cout << "bebida no reconocida..." << endl;
				}
				total = total + subtotal; // guarda el valor del subtotal en un contador con nombre total
				subtotal = lista_b[index_lista - 1].calcula_total(lista_b[index_lista - 1].get_onzas(),lista_b[index_lista - 1].get_costo(),lista_b[index_lista - 1].get_cantidad());
				total = total + subtotal; // asigna el subtotal del pedido de bebida que eligio y lo guarda en total nuevamente.
				break;
			default: // no reconocio la opcion
				cout << "opcion no reconocida" << endl;
				break;
		}
		cout << "Total del cliente " << ciclo+1 <<" : " << total << endl; // imprime el total de cliente
		total = 0.0; // los vuelve 0 para el futuro cliente
		subtotal = 0.0; // los vuelve 0 para el futuro cliente
		ciclo++; // se actualiza el ciclo para que logre salir de este
	}while(ciclo < num_clientes); // condicion que permite que se repita
	
	return 0;	
}