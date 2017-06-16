#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
using namespace std;


class Usuario{

	protected:
		string nombre;
		string contrasena;

	public:
		Usuario();
		Usuario(string,string);

		string getNombre();
		void setNombre(string);

		string getContrasena();
		void setContrasena(string);

};

#endif