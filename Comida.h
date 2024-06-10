/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/* Clase Comida: La cual es clase hija de la clase
* pedido, por lo que conserva sus atributos y metodos
*su funcion es tener atributos propios y si el cliente
*lo desea, que se prepare su comida como vegana. 		*/
/*------------------------------------------------------*/
/*-El comando ifndef verifica si no ha sido definida----*/
/*-la clase previamente y si no es así la define.-------*/
#ifndef COMIDA_H
#define COMIDA_H
/*-Se incluyen las librerias necesarias para funcionar-*/
/*-además de la clase madre para poder heredar-*/
#include <iostream>
#include <string>
using namespace std;
#include "Pedido.h"

class Comida:public Pedido {
	private: 
	//atributos de la clase Comida más los heredados de Pedido.
		string tamanio;
		bool vegano;
	public: 
		// contructores de la clase Comida con los atributos de la clase Pedido.
		Comida(): Pedido(), tamanio(""), vegano(0){}; // por default
		Comida(string o, float c, int ca, string t, bool v): Pedido(o,c,ca), tamanio(t), vegano(v){};
		// Destructor de clase
		~Comida(){}; 
		// getters de la clase
		string get_tamanio();
		bool get_vegano();
		//setters de la clase
		void set_tamanio(string t);
		void set_vegano(bool v);
		//metodos de la clase:
		void cambiar_vegano(bool v);
		// Sobreescritos de Pedido con polimorfismo
		void mostrar_datos(); 
		float calcula_total(float c, int ca);
		// sobrecarga
		float calcula_total(string t, float c, int ca);	
};
/*----------INICIO DE LOS GETTERS----------*/
string Comida::get_tamanio(){
	return tamanio;
}
bool Comida::get_vegano(){
	return vegano;
}
/*-----------FIN DE LOS GETTERS------------*/
/*----------INICIO DE LOS SETTERS----------*/
void Comida::set_tamanio(string t){
	tamanio = t;
}
void Comida::set_vegano(bool v){
	vegano = v;
}
/*-----------FIN DE LOS SETTERS-----------*/
/*---------INICIO DE LOS METODOS----------*/

/*-		 	METODO DE MOSTRAR_DATOS 		
*			  METODO SOBREESCRITO
*
* Imprime con el uso de los getters los atributos de
* orden (nombre de la comida), costo, cantidad, tamaño y 
* si el pedido es vegano o no.
*
* @param 
* @return -*/
void Comida::mostrar_datos(){
	cout << "Orden: " << get_orden() << "	||	";
	cout  << "Costo: " << get_costo() << "	||	";
	cout  << "Cantidad: " << get_cantidad() << "	||	" << endl;
	cout << "Tamanio: " << get_tamanio() << "	||	";
	cout  << "Pedido vegano: " << get_vegano() << "	||	" << endl;
}
/*-		 	METODO DE CAMBIAR_VEGANO 		
*
* Verifica si el atributo de vegano del pedido esta en 0
* (falso) y lo cambia a que sea 1 (true)
*
* @param bool: recibe un 0 o 1 el cual cambia si es 0.
* @return -*/
void Comida::cambiar_vegano(bool v){
	if (v != 1)
	{
		set_vegano(true);
	}
}
/*-		 	METODO DE CALCULA_TOTAL 		
*			  METODO SOBREESCRITO
*
* Verifica si la comida no es vegana, entonces 
* calcula el total multiplicando el costo por la
* cantidad y si es vegana le pone un pequeño aumento
*
* @param float, int: donde el float actua como el costo
* y el int actua como la cantidad
* @return float precio el cual puede ser modificado 
* dependiendo si el pedido es vegano o no-*/
float Comida::calcula_total(float c, int ca){
	float precio = 0.0;
	if(get_vegano() != 1)
	{
		precio = c * ca;
	}else
	{
		precio = (c * ca) * 1.3;
	}
	return precio;
}
/*-		 	METODO DE CALCULA_TOTAL 		
*			 METODO SOBRECARGADO
* 
* Verifica el tamaño que tenga la orden y en base a 
* esto calcula el precio, aumentando el precio conforme
* aumenta el tamaño.
* 
* @param string, float, int: string actua como el tamaño
* de la orden, float como el costo e int como la cantidad
* @return float precio que se modifica segun aumenta el tamaño
* del pedido, calculado como cantidad * costo (* aumento si aplica)-*/
float Comida::calcula_total(string t, float c, int ca){
	float precio = 0.0;
	if(t == "pequenio")
	{
		precio = c * ca;
	}else if (t == "mediano")
	{
		precio = c * ca * 1.2;
	} else if (t == "grande")
	{
		precio = c * ca * 1.4;
	}else
	{
		precio = -1;
	}
	return precio;
}
/*------------FIN DE LOS METODOS-----------*/

#endif //FIN DE LA CLASE