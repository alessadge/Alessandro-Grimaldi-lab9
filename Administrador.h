#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include <iostream>

using namespace std;
#include "Usuario.h"

class Administrador:public Usuario{

	private:
		string cargo;
		int seguro;

	public:
		Administrador();
		Administrador(string,string, string, int);

		string getCargo();
		void setCargo(string);

		int getSeguro();
		void setSeguro(int);

};

#endif