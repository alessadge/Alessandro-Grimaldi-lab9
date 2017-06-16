#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>

using namespace std;


class Vehiculo{

	private:
		string placa, modelo, marca;
		int year, precio;
		bool estado;

	public:
		Vehiculo(string,string,string, int, int, bool);
		Vehiculo();
		

		string getPlaca();
		void setPlaca(string);

		string getModelo();
		void setModelo(string);

		string getMarca();
		void setMarca(string);

		int getYear();
		void setYear(int);

		int getPrecio();
		void setPrecio(int);

		bool getEstado();
		void setEstado(bool);

};

#endif