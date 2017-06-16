#include "Usuario.h"

Usuario::Usuario(){

}

Usuario::Usuario(string nombre, string contrasena){
	this->nombre=nombre;
	this->contrasena=contrasena;
}

string Usuario::getNombre(){
	return nombre;
}

void Usuario::setNombre(string nombre){
	this->nombre=nombre;
}

string Usuario::getContrasena(){
	return contrasena;
}

void Usuario::setContrasena(string contrasena){
	this->contrasena=contrasena;
}