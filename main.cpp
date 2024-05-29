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
	/*---------------------- 	P	E	D	I	D	O	S	 ---------------------*/
	Pedido* comida1 = new Comida("Hamburguesa con papas", 150.5,1,"pequenio",0);
	Pedido* comida2 = new Comida("Caldo de pollo", 95.7,1,"pequenio",0);
	Pedido* comida3 = new Comida("Chilaquiles verdes", 69.99,1,"pequenio", 1);
	Pedido* bebida1 = new Bebida("Squirt", 35.5,1,20.5,0);
	Pedido* bebida2 = new Bebida("Coca-cola", 35.7,1,20.5,0);
	Pedido* bebida3 = new Bebida("Cerveza", 50.4,1,20.5,0);
	Pedido* lista_p[6] = {comida1,comida2,comida3, bebida1, bebida2, bebida3};
	
	/*-------------------------------------------------------------------------*/
	Restaurante charles("Charles");
	charles.agrega_pedidos(comida1);
	charles.agrega_pedidos(comida2);
	charles.agrega_pedidos(comida3);
	charles.agrega_pedidos(bebida1);
	charles.agrega_pedidos(bebida2);
	charles.agrega_pedidos(bebida3);
	/*-------------------------------------------------------------------------*/
	/*-------------------- DECLARACION DE VARIABLES ---------------------------*/
	int num_clientes, ciclo = 0, opcion, index_lista;
	float subtotal = 0, total = 0, cambio = 0;
	/*-------------------------------------------------------------------------*/
	cout << "Hola Mesero bienvenido a esta demostracion, el dia de hoy me ayudaras en el trabajo..." << endl;
	cout << "Mira, ya te han llegado clientes, por favor dime cuantos son: "; cin >> num_clientes; cout <<endl;
	vector<Persona> lista_clientes = charles.recibe_cliente(num_clientes);
	cout << "Verifica que sus datos sean correctos..." << endl;
	charles.mostrar_cliente(num_clientes);
	cout << "Muestrales el menu para que decidan que elegir..." << endl;
	charles.muestra_menu(3);
	
	do // ciclo que se repetira las veces que clientes que haya
	{
		cout << "\n" << "|| --- C L I E N T E " <<ciclo+1 << " --- ||" << endl;
		cout << "*actuaras como cliente un rato.*" << endl;
		cout << "te gustaria ordenar una comida del menu...: " << endl;
		cout << "1 = Si, 0 = No: "; cin >> opcion; cout << endl;
		switch(opcion)
		{
			case 0: // el cliente no pidio pedido
				cout << "Esta perfecto sin problema..." << endl;
				cout << "Trata de usar la opcion 1 para continuar..." << endl;
				break;
				
			case 1: // el cliente pidio pedido
				cout << "Que numero de comida te gustaria ordenar: "; cin >> index_lista; cout << endl;
				if(index_lista >= 1 && index_lista <=3) // verifica que el numero ingresado se encuentre en la lista
				{
					lista_p[index_lista - 1]->mostrar_datos(); // muestra los datos de la comida que eligio
					subtotal = lista_p[index_lista - 1]->calcula_total(lista_p[index_lista-1]->get_costo(),lista_p[index_lista-1]->get_cantidad());
					cout << "Subtotal = " << subtotal << endl;
					
				}else // no reconocio el numero en la lista
				{
					cout << "comida no reconocida..." << endl;
				}
				
				break;
				
			default:// se ingreso otra opcion diferente a uno o cero
				cout << "opcion no reconocida" << endl;
				break;	
		}
		
		cout << "\n" << "te gustaria ordenar una bebida del menu...: " << endl;
		cout << "1 = Si, 0 = No: "; cin >> opcion; cout << endl;
		switch(opcion)
		{
			case 0: //el cliente no pidio bebida
				cout << "Esta perfecto, sin problema..." << endl;
				cout << "trata de usar la opcion 1 para continuar mas :)" << endl;
				break;
			
			case 1: // el cliente pidio bebida
				cout << "Que numero de bebida te gustaria ordenar: "; cin >> index_lista; cout << endl;
				if(index_lista >= 4 && index_lista <= 6) // verifica que el numero ingresado se encuentre en la lista
				{
					lista_p[index_lista - 1]->mostrar_datos(); // muestra los datos de la comida que eligio
					total = total + subtotal;
					subtotal = lista_p[index_lista - 1]->calcula_total(lista_p[index_lista-1]->get_costo(),lista_p[index_lista-1]->get_cantidad());
					total = total + subtotal;
					cout << "El total es: " << total << endl;
				}else // no reconocio el numero en la lista
				{
					cout << "bebida no reconocida..." << endl;
				}

		}
		
		cout << "Ahora dale el cambio al cliente: " << endl;
		cambio = lista_clientes[ciclo].pagar(total);
		cout << "Su cambio del cliente " << lista_clientes[ciclo].get_nombre() << " es: " << cambio << endl;
		ciclo++; // aumento del contador del ciclo para que termine
	} while(ciclo < num_clientes); // condicion del ciclo
	
	return 0;	
}