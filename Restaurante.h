/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/*-Clase Restaurante: La cual es una clase propia que---*/
/*-cuenta con una composicion de la clase Persona por---*/
/*-lo que tendrá este como un tipo de dato y también se-*/
/*-agregará de las clases Comida y Bebida que actuarán--*/
/*-como el menú para manejarlo de manera más optimizada-*/
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
/*-Las variables c y b actuan como nuestros contadotes-*/
/*-que tienen la funcion de controlar la posicion de---*/
/*-la lista en la que se encuentran los objetos de-----*/
/*-comida y bebida respectivamente-*/
int c = 0;
int b = 0;
	
class Restaurante{
	private:
		string nom_restaurante;
		Persona cliente[50];
		Comida lista_c[10];
		Bebida lista_b[10];
	public:
		// Constructores de la clase Restaurante
		Restaurante(): nom_restaurante(""){};
		Restaurante(string n_r):nom_restaurante(n_r){};
		// Metodos de la clase Restaurante
		void recibe_cliente(int num);
		void mostrar_cliente(int num);
		void agrega_comida(Comida comida);
		void agrega_bebida(Bebida bebida);
		void muestra_menu(int n);
		float calcula_costo(Comida comida, Bebida bebida);
};
/*---------INICIO DE LOS METODOS----------*/
void Restaurante::recibe_cliente(int num){
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
			cliente[i].set_nombre(n);
			cliente[i].set_edad(e);
			cliente[i].set_dinero(d);
			num_personas++;
		}else 
		{
			cout << "El restaurante está lleno, por favor espere un momento :)" << endl;
		}
	}         
}
void Restaurante::mostrar_cliente(int num){
	for(int i = 0; i < num; i++)
	{
		cout << "Cliente " << i+1 << ": " << cliente[i].get_nombre() << " ||" << " Edad: " << cliente[i].get_edad() << " || " << " Dinero " << cliente[i].get_dinero() << endl;
	}
}
void Restaurante::agrega_comida(Comida comida){
	lista_c[c] = comida;
	c++;	
}
void Restaurante::agrega_bebida(Bebida bebida){
	lista_b[b] = bebida;
	b++;
}
void Restaurante::muestra_menu(int n){
	cout << "|| --- M  e  n  u     d  e     c  o  m  i  d  a  s --- ||" << endl;
	for(int i = 0; i < n; i++)
    {
        cout << "ORDEN " << i+1 << endl;
        lista_c[i].mostrar_datos();
        cout << "\n";
    }
	cout << "|| --- M  e  n  u     d  e     b  e  b  i  d  a  s  --- ||" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "BEBIDA " << i+1 << endl;
		lista_b[i].mostrar_datos();
		cout << "\n";
	}
}
float Restaurante::calcula_costo(Comida comida, Bebida bebida){
	float costo = 0.0;
	costo = (comida.get_costo() * comida.get_cantidad()) + (bebida.get_costo() * bebida.get_cantidad());
	return costo;
}
/*------------FIN DE LOS METODOS-----------*/

#endif //fin de la clase