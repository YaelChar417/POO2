/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charles-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 06 de junio de 2024-------*/
/*---------------------------------------------------*/
/*-Main del proyecto de gestion de Restaurante en
* el cual se crean productos de comida y bebida que se 
* asignan a un menu y muestra una pequeña recreación de 
* un  restaurante, en el cual puedes ordenar comida y 
* bebida donde en base a esto puedes calcular el costo.-*/
/*------------------------------------------------------*/

/*-Se incluyen las librerias necesarias para leer y -*/
/*-mostrar variables, asi como manipular strings-----*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*-		Se incluyen las clases desarrolladas		-*/
#include "Restaurante.h"

int main() { 
	

	/*-A continuacion se crean 3 objetos tanto de comida como de bebida, se optó-*/
	/*-por ese numero para no saturar al usuario con información al momento de---*/
	/*-usar la función muestra_menu(). Posteriormente se crea un restaurante con-*/
	/*el nombre de Charles y se agregan los objetos de comida y bebida a este restaurante-*/
	/*---------------------- 	P	E	D	I	D	O	S	 ---------------------*/
	Pedido* comida1 = new Comida("Hamburguesa", 150.5,1,"pequenio",0);
	Pedido* comida2 = new Comida("Caldo de pollo", 95.7,1,"pequenio",0);
	Pedido* comida3 = new Comida("Chilaquiles", 69.99,1,"pequenio", 0);
	Pedido* bebida1 = new Bebida("Squirt", 35.5,1,20.5,0);
	Pedido* bebida2 = new Bebida("Fanta", 35.7,1,20.5,0);
	Pedido* bebida3 = new Bebida("Cerveza", 50.4,1,20.5,0);
	/*-------------------------------------------------------------------------*/
	Restaurante charles("Charles");
	charles.agrega_pedidos(comida1);
	charles.agrega_pedidos(comida2);
	charles.agrega_pedidos(comida3);
	charles.agrega_pedidos(bebida1);
	charles.agrega_pedidos(bebida2);
	charles.agrega_pedidos(bebida3);
	/*-------------------- DECLARACION DE VARIABLES ---------------------------*/
	int num_clientes, ciclo = 0, opcion;
	int c_list = 0, b_list = 0; //indices de comida y bebida de las listas respectivamente
	float subtotal = 0, total = 0, cambio = 0;
	/*-------------------------------------------------------------------------*/
	/*Comienzo del programa
	* Se mostrará una pequeña historia representando clientes ordenando*/
	// pide los datos de los clientes.
	cout << "Hola Mesero bienvenido a esta demostracion, el dia de hoy me ayudaras en el trabajo... \n";
	cout << "Mira, ya te han llegado clientes, por favor dime cuantos son: ";
	cin >> num_clientes; cout <<"\n";
	vector<Persona> lista_clientes = charles.recibe_cliente(num_clientes);
	// Imprime los datos de los clientes.
	cout << "Verifica que sus datos sean correctos..." << endl;
	charles.mostrar_cliente(num_clientes);
	//muestra el menu a los clientes (usuario)
	cout << " \n Muestrales el menu para que decidan que elegir..." << endl;
	charles.muestra_menu(3);
	
	do // ciclo que se repetira las veces que clientes que haya
	{
		cout << "\n" << "|| --- C L I E N T E " <<ciclo+1 << " --- ||" << endl;
		cout << "*actuaras como cliente un rato.*" << endl;
		cout << "te gustaria ordenar una comida del menu...: " << endl;
		cout << "1 = Si, 0 = No: "; cin >> opcion;
		//switch para verificar la opcion del cliente de pedir comida
		switch(opcion)
		{
			case 0: // el cliente no pidio comida
				cout << "Esta perfecto sin problema..." << endl;
				break;
				
			case 1: // el cliente pidio comida
				cout << "Que numero de comida te gustaria ordenar: "; cin >> c_list;
				if(c_list >= 1 && c_list <=3) // verifica que el numero ingresado se encuentre en la lista
				{
					// calcula el subtotal del pedido y lo asgina en el contador total
					subtotal = charles.pedidos[c_list - 1]->calcula_total(charles.pedidos[c_list-1]->get_costo(),
					charles.pedidos[c_list-1]->get_cantidad()); // misma linea
					total = total + subtotal;
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
		cout << "1 = Si, 0 = No: "; cin >> opcion;
		//switch para verificar la opcion del cliente de pedir bebida
		switch(opcion)
		{
			case 0: //el cliente no pidio bebida
				cout << "----------------------- ORDEN ACTUAL: -----------------------" << endl;
				if(!c_list == 0) // verifica si el cliente si pidio comida para mostrar los datos
				{
					charles.pedidos[c_list - 1]->mostrar_datos(); // muestra los datos de la comida
				}
				cout << "---------------------------------------------------------------" << endl;
				// muestra en reducidas cuentas lo que pidió el cliente y su cambio
				cout << "|| ----------------- R   E   C   I   B   O ----------------- ||" << endl;
				cout << "Orden		Costo		Cantidad " << endl;
				if(!c_list == 0) // verifica si el cliente si pidio comida para mostrar los datos
				{
					cout << charles.pedidos[c_list-1]->get_orden() << "	";
					cout << charles.pedidos[c_list-1]->get_costo() << "		";
					cout << charles.pedidos[c_list-1]->get_cantidad() << "		\n";
				}
				cambio = lista_clientes[ciclo].pagar(subtotal);
				cout << "Total de la compra: " << subtotal << endl;
				cout << "Cambio: " << cambio << endl;
				cout << "---------------------------------------------------------------" << endl;
				break;
			
			case 1: // el cliente pidio bebida
				cout << "Que numero de bebida te gustaria ordenar: "; cin >> b_list; cout << endl;
				if(b_list >= 4 && b_list <= 6) // verifica que el numero ingresado se encuentre en la lista
				{	
					cout << "----------------------- ORDEN ACTUAL: -----------------------" << endl;
					if (!c_list == 0) // verifica si el cliente si pidio comida para mostrar los datos
					{
						charles.pedidos[c_list-1]->mostrar_datos(); // muestra los datos de la comida que eligio
					}
					if(!b_list == 0) // verifica si el cliente si pidio bebida para mostrar los datos
					{
						charles.pedidos[b_list-1]->mostrar_datos(); // muestra los datos de la comida que eligio
						// calcula el subtotal de la bebida y lo asgina a total para calcular el cambio
						subtotal = charles.pedidos[b_list-1]->calcula_total(charles.pedidos[b_list-1]->get_costo(),
						charles.pedidos[b_list-1]->get_cantidad());
						total = total + subtotal;
						cambio = lista_clientes[ciclo].pagar(total);
					}
					cout << "---------------------------------------------------------------" << endl;
					// muestra en reducidas cuentas lo que pidió el cliente y su cambio
					cout << "|| ----------------- R   E   C   I   B   O ----------------- ||" << endl;
					cout << "Orden		Costo		Cantidad " << endl;
					if(!c_list == 0)// verifica si el cliente si pidio comida para mostrar los datos
					{
						cout << charles.pedidos[c_list-1]->get_orden() << "	";
						cout << charles.pedidos[c_list-1]->get_costo() << "		";
						cout << charles.pedidos[c_list-1]->get_cantidad() << "	\n";
					}
					if(!b_list == 0)// verifica si el cliente si pidio bebida para mostrar los datos
					{
						cout << charles.pedidos[b_list-1]->get_orden() << "		";
						cout << charles.pedidos[b_list-1]->get_costo() << "		";
						cout << charles.pedidos[b_list-1]->get_cantidad() << "		\n";
					}
					cout << "Total de la compra: " << total << endl;
					cout << "Cambio: " << cambio << endl;
					cout << "--------------------------------------------------------------" << endl;
				}else // no reconocio el numero en la lista
				{
					cout << "bebida no reconocida..." << endl;
				}
		}
		ciclo++; // aumento del contador del ciclo para que termine
		cambio = 0; total = 0; subtotal = 0;
		c_list = 0; 
		b_list = 0; //regresamos ambos index y totales a 0 para que no afecten el funcionamiento
	} while(ciclo < num_clientes); // condicion del ciclo
	cout << "Agradecemos su visita, buen dia." << endl;
	return 0;	
}