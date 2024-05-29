/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 23 de mayo de 2024--------*/
/*-----------------------------------------------------.*/
/*-Clase Comida: La cual es clase hija de la clase------*/
/*-pedido, por lo que conserva sus atributos y metodos--*/
/*su funcion es tener atributos propios y si el cliente-*/
/*-lo desea, que se prepare su comida como vegana-------*/
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
	private: //atributos de la clase más los heredados.
		string tamanio;
		bool vegano;
	public: 
		// contructores de la clase Comida con los atributos de la clase Pedido.
		Comida(): Pedido(), tamanio(""), vegano(0){};
		Comida(string o, float c, int ca, string t, bool v): Pedido(o,c,ca), tamanio(t), vegano(v){};
		~Comida(){}; // Destructor de clase
		// getters de la clase
		string get_tamanio();
		bool get_vegano();
		//setters de la clase
		void set_tamanio(string t);
		void set_vegano(bool v);
		//metodos de la clase:
		void mostrar_datos();
		void cambiar_vegano(bool v);
		float calcula_total(float c, int ca);
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
void Comida::mostrar_datos(){
	cout << "Orden: " << get_orden() << "	||	" << "Costo: " << get_costo() << "	||	" << "Cantidad: " << get_cantidad() << endl;
	cout << "Tamanio: " << get_tamanio() << "	||	" << "Pedido vegano: " << get_vegano() << endl;
}
void Comida::cambiar_vegano(bool v){
	if (v != 1)
	{
		set_vegano(true);
	}
}
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