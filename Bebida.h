/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/*-Clase Bebida: La cual es clase hija de la clase------*/
/*-pedido, por lo que conserva sus atributos y metodos--*/
/*su funcion es tener atributos propios y si el cliente-*/
/*-lo desea, que se le añada hielo a su bebida----------*/
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
	private: // atributos de la clase más los heredados.
		float onzas;
		bool hielo;
	public:
		// Constructores de la clase Bebida con los atributos de la clase Pedido.
		Bebida(): Pedido(), onzas(0.0), hielo(0){};
		Bebida(string o, float c, int ca, float onz, bool hie): Pedido(o,c,ca), onzas(onz), hielo(hie){};
		// getters de la clase bebida.
		float get_onzas();
		bool get_hielo();
		// setters de la clase bebida.
		void set_onzas(float onz);
		void set_hielo(bool hie); 
		//metodos de la clase.
		void mostrar_datos();
		void agregar_hielo(bool hie);
		float calcula_total(bool hie, int ca, float c);
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
void Bebida::mostrar_datos(){
	cout << "Orden: " << get_orden() << "	||	" << "Costo: " << get_costo() << "	||	" << "Cantidad: " << get_cantidad() << endl;
	cout << "Onzas: " << get_onzas() << "	||	" << "hielo: " << get_hielo() << endl;
}
void Bebida::agregar_hielo(bool hie){
	if(hie != 1)
	{
		set_hielo(1);
	}
}
float Bebida::calcula_total(bool hie, int ca, float c){
	float precio = 0.0;
	if(hie != 1)
	{
		precio = c * ca;
	}else
	{
		precio = c * ca * 1.2;
	}
	return precio;
}
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
