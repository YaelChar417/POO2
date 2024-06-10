/*---------------------------------------------------*/
/*-----------Proyecto: Restaurante Charl´s-----------*/
/*-----------Hecho por: Yael Charles Marin-----------*/
/*---------------Matricula: A01711111----------------*/
/*-------------Profesor: Benjamin Valdez-------------*/
/*----Materia: Programacion orientada a objetos 2----*/
/*-------Fecha de entrega: 06 de junio de 2024-------*/
/*----------------------------------------------------*/
/* Clase Pedido: La cual es clase madre para la clase
* Comida y Bebida, su funcion es tener atributos
* básicos y metodos como calcular precio y mostrar
* sus datos. Del mismo modo realiza polimorfismo con
* Sus clases hijas. Finalmente esta es una clase abstracta
* pues es mejor que se creen solo objetos de sus clases
* hijas en lugar de esta 								*/
/*----------------------------------------------------*/
/*-El comando ifndef verifica si no ha sido definida--*/
/*-la clase previamente y si no es así la define.-----*/
#ifndef PEDIDO_H
#define PEDIDO_H
/*-Se incluyen las librerias necesarias para funcionar-*/
#include <iostream> 
#include <string>
using namespace std;

class Pedido {
	protected: 
	// contiene los atributos de la clase y que se heredarán
		string orden;
		float costo;
		int cantidad;
	public:
		// Constructores de la clase
		Pedido(): orden(""), costo(0.0), cantidad(0){}; //por default
		Pedido(string o, float c, int ca): orden(o), costo(c), cantidad(ca){};
		// Destructor de clase que hace polimorfismo
		virtual ~Pedido(){}; 
		// getters de la clase
		string get_orden();
		float get_costo();
		int get_cantidad();
		// setters de la clase
		void set_orden(string o);
		void set_costo(float c);
		void set_cantidad(int ca);
		//metodos virtuales de la clase
		virtual float calcula_total(float c, int ca) = 0;
		virtual void mostrar_datos() = 0;
};
/*----------INICIO DE LOS GETTERS----------*/
string Pedido::get_orden(){
	return orden;
}
float Pedido::get_costo(){
	return costo;
}
int Pedido::get_cantidad(){
	return cantidad;
}
/*-----------FIN DE LOS GETTERS------------*/
/*----------INICIO DE LOS SETTERS----------*/
void Pedido::set_orden(string o){
	orden = o;
}
void Pedido::set_costo(float c){
	costo = c;
}
void Pedido::set_cantidad(int ca){
	cantidad = ca;
}
/*-----------FIN DE LOS SETTERS-----------*/
#endif //FIN DE LA CLASE