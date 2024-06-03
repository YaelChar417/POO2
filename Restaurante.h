/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/* Clase Restaurante: La cual es una clase propia que
* cuenta con una composicion de la clase Persona por
* lo que tendrá este como un tipo de dato y también se
* agregará de las clases Comida y Bebida que actuarán
* como el menú para manejarlo de manera más optimizada */
/*------------------------------------------------------*/
/*-El comando ifndef verifica si no ha sido definida----*/
/*-la clase previamente y si no es así la define.-------*/
#ifndef RESTAURANTE_H
#define RESTAURANTE_H
/*-Se incluyen las librerias necesarias para funcionar-*/
/*-Así como las clases Persona, Comida y Bebida para---*/
/*-hacer las funciones planteadas----------------------*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Persona.h"
#include "Comida.h"
#include "Bebida.h"

class Restaurante{
	private:
		// Atibutos de la clase Restaurante
		string nom_restaurante;
		vector <Persona> clientes; // vector sin tamaño fijo
		Pedido *pedidos[10];
		int index = 0;
	public:
		// Constructores de la clase Restaurante
		Restaurante(): nom_restaurante(""){};
		Restaurante(string n_r):nom_restaurante(n_r){};
		//Destructor de clase
		~Restaurante(){}; 
		// Metodos de la clase Restaurante
		vector<Persona> recibe_cliente(int num);
		void mostrar_cliente(int num);
		void agrega_pedidos(Pedido *pedido);
		void muestra_menu(int n);
		float calcula_costo(Comida comida, Bebida bebida);
};
/*---------INICIO DE LOS METODOS----------*/

/*-		 	METODO DE RECIBE_CLIENTE 		
* 
* Usa un ciclo for que se repetira dependiendo el numero de veces
* que desee el usuario, esta funcion crea clientes con sus diferentes atributos
* para ello pide los atributos de nombre, edad y dinero (pertenecientes a la -
* clase cliente) y con los setters los añade a un objeto que a su vez se guarda en 
* una posicion de un arreglo con el comando push_back. El limite de clientes que
* soporta el restaurante es 50.
*
* @param int: que actua como el numero de veces que se repetira
* el ciclo for y que a su vez es el numero de clientes que llegan en total
* @return arreglo de clientes.													-*/
vector<Persona> Restaurante::recibe_cliente(int num){
	int num_personas = 0;
	string n;
	int e;
	float d;
	
	for(int i = 0;i < num; i++)
	{
		cout << "Nombre del cliente " << i+1 << ": "; cin >> n;
		cout << "Edad del cliente " << i+1 << ": "; cin >> e; 
		cout << "Dinero del cliente " << i+1 << ": "; cin >> d; cout << endl;
		if(num_personas < 50)
		{
			Persona cnt; // crea un objeto persona llamado cnt (cliente) que le agrega sus datos con los setters
			cnt.set_nombre(n);
			cnt.set_edad(e);
			cnt.set_dinero(d);
			clientes.push_back(cnt); // añade al vector de clientes los clientes
			num_personas++;
		}else 
		{
			cout << "El restaurante está lleno, por favor espere un momento :)" << endl;
		}
	}   
	return clientes; 
}
/*-		 	METODO DE MOSTRAR_CLIENTE		
* 
* Con un ciclo for muestra los atributos de los clientes de nombre, edad y dinero
* con el uso demlos getters y además de los elementos de la lista creada previamente
* 
* @param int: actua como el numero de clientes que quiere mostrar
* @return 																			-*/
void Restaurante::mostrar_cliente(int num){
	for(int i = 0; i < num; i++)
	{
		cout << "Cliente " << i+1 << ": " << clientes[i].get_nombre() << " ||" << " Edad: " << clientes[i].get_edad() << " || " << " Dinero " << clientes[i].get_dinero() << endl;
	}
}
/*-		 	METODO DE AGREGAR_PEDIDOS		
* 
* Añade a la lista de pedidos la orden que se mande llamar desde
* el main, y aumenta el index de la lista para ir agregando diferentes
* pedidos
* 
* @param Recibe un objeto de la clase Pedido, con polimorfismo
* @return 																			-*/
void Restaurante::agrega_pedidos(Pedido *pedido){
	pedidos[index] = pedido;
	index++;
}
/*-		 	METODO DE MUESTRA_MENU		
* 
* Mediante un ciclo for muestra los tres primeros elementos de la lista 
* creada en el main (Comida unicamente) y utiliza polimorfismo para llamar
* el metodo de mostrar datos correspondiente a la comida, el segundo for 
* muestra los ultimos elementos de la lista (Bebida unicamente) e igual llama
* su metodo de mostrar datos con polimorfismo.
*
* @param int: actua como el numero de productos que quiere mostrar
* @return 																	-*/
void Restaurante::muestra_menu(int n){
	cout << "|| --- M  e  n  u     d  e     c  o  m  i  d  a  s --- ||" << endl;
	for(int i = 0; i < n; i++)
    {
        cout << "ORDEN " << i+1 << endl;
        pedidos[i]->mostrar_datos();
        cout << "\n";
    }
	cout << "|| --- M  e  n  u     d  e     b  e  b  i  d  a  s  --- ||" << endl;
	for(int i = 3; i < n+3; i++)
	{
		cout << "BEBIDA " << i+1 << endl;
		pedidos[i]->mostrar_datos();
		cout << "\n";
	}
}
/*-		 	METODO DE CALCULA_COSTO		
* 			  METODO SOBRECARGADO
* 
* Usando los getters de costo y cantidad de comida y bebida respectivamente
* calcula el precio multiplicando costo * cantidad y sumandolos. 
* 
* @param Objeto de clase comida y Objeto de clase bebida
* @return float costo que es la suma del precio de la comida y la bebida -*/
float Restaurante::calcula_costo(Comida comida, Bebida bebida){
	float costo = 0.0;
	costo = (comida.get_costo() * comida.get_cantidad()) + (bebida.get_costo() * bebida.get_cantidad());
	return costo;
}
/*------------FIN DE LOS METODOS-----------*/

#endif //fin de la clase