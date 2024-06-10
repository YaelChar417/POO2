/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/* Clase Bebida: La cual es clase hija de la clase
* pedido, por lo que conserva sus atributos y metodos
* su funcion es tener atributos propios y si el cliente
* lo desea, que se le añada hielo a su bebida			*/
/*------------------------------------------------------*/
/*-El comando ifndef verifica si no ha sido definida----*/
/*-la clase previamente y si no es así la define.-------*/
#ifndef BEBIDA_H
#define BEBIDA_H
/*-Se incluyen las librerias necesarias para funcionar-*/
/*-además de la clase madre para poder heredar-*/
#include <iostream>
#include <string>
using namespace std;
#include "Pedido.h"

class Bebida:public Pedido {
	private: 
	// atributos de la clase Bebida más los heredados de la clase Pedido.
		float onzas;
		bool hielo;
	public:
		// Constructores de la clase Bebida con los atributos de la clase Pedido.
		Bebida(): Pedido(), onzas(0.0), hielo(0){}; // por default
		Bebida(string o, float c, int ca, float onz, bool hie): Pedido(o,c,ca), onzas(onz), hielo(hie){}; 
		// Destructor de clase
		~Bebida(){}; 
		// getters de la clase bebida.
		float get_onzas();
		bool get_hielo();
		// setters de la clase bebida.
		void set_onzas(float onz);
		void set_hielo(bool hie); 
		//metodos de la clase.
		void agregar_hielo(bool hie); 
		// sobreescritos de Pedido con polimorfismo
		void mostrar_datos(); 
		float calcula_total(float c, int ca);
		 // sobrecarga
		float calcula_total(float onz, float c, int ca);
};
/*----------INICIO DE LOS GETTERS----------*/
float Bebida::get_onzas(){
	return onzas;
}
bool Bebida::get_hielo(){
	return hielo;
}
/*-----------FIN DE LOS GETTERS------------*/
/*----------INICIO DE LOS SETTERS----------*/
void Bebida::set_onzas(float onz){
	onzas = onz;
}
void Bebida::set_hielo(bool hie){
	hielo = hie;
}
/*-----------FIN DE LOS SETTERS-----------*/
/*---------INICIO DE LOS METODOS----------*/

/*-		 	METODO DE MOSTRAR_DATOS 		
*			  METODO SOBREESCRITO
*
* Imprime con el uso de los getters los atributos de
* orden (nombre de la bebida), costo, cantidad, tamaño y 
* si el pedido tiene hielo o no.
*
* @param 
* @return -*/
void Bebida::mostrar_datos(){
	cout << "Orden: " << get_orden() << "	||	";
	cout << "Costo: " << get_costo() << "	||	"; 
	cout << "Cantidad: " << get_cantidad() << "	||	" << endl; 
	cout << "Onzas: " << get_onzas() << "	||	";
	cout << "hielo: " << get_hielo() << "	||	" << endl; 
}
/*-		 	METODO DE AGREGAR_HIELO 		
*
* Verifica si el atributo de hielo del pedido esta en 0
* (falso) y lo cambia a que sea 1 (true)
*
* @param bool: recibe un 0 o 1 el cual cambia si es 0.
* @return -*/
void Bebida::agregar_hielo(bool hie){
	if(hie != 1)
	{
		set_hielo(1);
	}
}
/*-		 	METODO DE MOSTRAR_DATOS 		
*			  METODO SOBREESCRITO
*
* Verifica si la comida no tiene hielo, entonces 
* calcula el total multiplicando el costo por la
* cantidad y si tiene hielo le pone un pequeño aumento
*
* @param float, int: donde el float actua como el costo
* y el int actua como la cantidad
* @return float precio el cual puede ser modificado 
* dependiendo si el pedido tiene hielo o no	-*/
float Bebida::calcula_total(float c, int ca){
	float precio = 0.0;
	if(get_hielo() != 1)
	{
		precio = c * ca;
	}else
	{
		precio = c * ca * 1.2;
	}
	return precio;
}
/*-		 	METODO DE CALCULA_TOTAL 		
*			 METODO SOBRECARGADO
* 
* Verifica las onzas que tenga la orden y en base a 
* esto calcula el precio, aumentando el precio conforme
* aumentan las onzas.
* 
* @param float, float, int: el primer float actua como las onzas
* de la orden, el segundo float como el costo e int como la cantidad
* @return float precio que se modifica segun aumentan las onzas
* del pedido, calculado como cantidad * costo (* aumento si aplica)-*/
float Bebida::calcula_total(float onz, float c, int ca){
	float precio = 0.0;
	if (onz >= 0 && onz <= 30)
	{
		precio = c * ca;
	}else if(onz >=31 && onz <= 50)
	{
		precio = c * ca * 1.1;
	}else if(onz >=51)
	{
		precio = c * ca * 1.2;
	}else
	{
		precio = -1;
	}
	return precio;
}
/*------------FIN DE LOS METODOS-----------*/

#endif //FIN DE LA CLASE
