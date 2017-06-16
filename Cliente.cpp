#include "Cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(string membresia, string nombre, string contrasena):Usuario(nombre, contrasena){
	this->membresia=membresia;
	this->nombre=nombre;
}

string Cliente:: getMembresia(){
	return membresia;
}
void Cliente:: setMembresia(string membresia){
	this->membresia=membresia;

}