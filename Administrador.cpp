#include "Administrador.h"

Administrador::Administrador(){

}

Administrador::Administrador(string nombre, string contrasena,string cargo, int seguro) {
	this->cargo = cargo;
	this->seguro=seguro;
	this->nombre=nombre;
	this->contrasena=contrasena;

}

string Administrador:: getCargo(){
	return cargo;
}

void Administrador::setCargo(string cargo){
	this->cargo = cargo;
}

int Administrador:: getSeguro(){
	return seguro;
}

void Administrador::setSeguro(int cargo){
	this->seguro= cargo;
}