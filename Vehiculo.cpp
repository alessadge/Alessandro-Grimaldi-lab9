#include "Vehiculo.h"

Vehiculo::Vehiculo(){

}

Vehiculo::Vehiculo(string placa,string modelo, string marca, int year, int pecio,bool estado){
	this->placa=placa;
	this->modelo=modelo;
	this->marca=marca;
	this->year=year;
	this->precio=precio;
	this->estado=false;
	

}

string Vehiculo::getPlaca(){
	return placa;
}

void Vehiculo::setPlaca(string placa){
	this->placa=placa;
}

string Vehiculo::getMarca(){
	return marca;
}

void Vehiculo::setMarca(string marca){
	this->marca=marca;
}

string Vehiculo::getModelo(){
	return modelo;
}

void Vehiculo::setModelo(string modelo){
	this->modelo=modelo;
}

int Vehiculo::getYear(){
	return year;
}

void Vehiculo::setYear(int year){
	this->year=year;
}
int Vehiculo::getPrecio(){
	return precio;
}

void Vehiculo::setPrecio(int precio){
	this->precio=precio;
}

bool Vehiculo::getEstado(){
	return estado;
}

void Vehiculo::setEstado(bool precio){
	this->estado=precio;
}
