/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 06 de junio de 2024--------*/
/*-----------------------------------------------------.*/
/*-Clase Persona: La cual es una clase propia que-------*/
/*-cuenta con atributos como nombre, edad y cantidad----*/
/*-de dinero, así como un metodo para mostrar sus datos-*/
/*-esta clase actuará como un cliente del restaurante,--*/
/*-donde la clase Persona va a componer a Restaurante---*/
/*------------------------------------------------------*/
/*-El comando ifndef verifica si no ha sido definida----*/
/*-la clase previamente y si no es así la define.-------*/
#ifndef PERSONA_H
#define PERSONA_H
/*-Se incluyen las librerias necesarias para funcionar-*/
#include <iostream>
#include <string>
using namespace std;

class Persona{
	private: 
	// atributos de la clase Persona
		string nombre;
		int edad;
		float dinero;
	public:
		// Constructores de la clase persona con sus atributos propios
		Persona(): nombre(""), edad(0), dinero(0.0){}; // por default
		Persona(string n, int e, float d): nombre(n), edad(e), dinero(d){};
		// Destructor de clase
		~Persona(){}; 
		// getters de la clase
		string get_nombre();
		int get_edad();
		float get_dinero();
		// setters de la clase
		void set_nombre(string n);
		void set_edad(int e);
		void set_dinero(float d);
		// metodos de la clase
		void mostrar_datos();
		float pagar(float t);
};
/*----------INICIO DE LOS GETTERS----------*/
string Persona::get_nombre(){
	return nombre;
}
int Persona::get_edad(){
	return edad;
}
float Persona::get_dinero(){
	return dinero;
}
/*-----------FIN DE LOS GETTERS------------*/
/*----------INICIO DE LOS SETTERS----------*/
void Persona::set_nombre(string n){
	nombre = n;
}
void Persona::set_edad(int e){
	edad = e;
}
void Persona::set_dinero(float d){
	dinero = d;
}
/*-----------FIN DE LOS SETTERS-----------*/
/*---------INICIO DE LOS METODOS----------*/

/*-		 	METODO DE MOSTRAR_DATOS 		
*
* Usando los getters de la clase imprime los
* atributos de la clase Persona
*
* @param
* @return-*/
void Persona::mostrar_datos(){
	cout << "Nombre: " << get_nombre() << endl;
	cout << "Edad: " << get_edad() << endl;
	cout << "Dinero: " << get_dinero() << endl; 
}
/*-		 	METODO DE PAGAR		
*
* Usando el parametro que recibe y el dinero
* que tiene la persona calcula el cambio 
* haciendo la resta entre ellos, asimismo
* si el dinero es insuficiente manda un mensaje
* de error
*
* @param float calculado en el main en base a lo que
* pidio el usuario, representa el total de la cuenta.
* @return float con la resta entre el dinero y el total-*/
float Persona::pagar(float t){
	float cambio = 0;
	cambio = get_dinero() - t;
	if (cambio <= 0)
	{
		cout << "No tienes suficiente dinero..." << endl;
		return cambio = -1;
	}else
	{
		return cambio;
	}
}
/*------------FIN DE LOS METODOS-----------*/

#endif // Fin de la clase