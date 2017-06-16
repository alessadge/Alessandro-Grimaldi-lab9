#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;
#include "Usuario.h"
#include <iostream>
#include <string>


class Cliente : public Usuario{

	private:
		string membresia;

	public:
		Cliente();
		Cliente(string,string,string);

		string getMembresia();
		void setMembresia(string);

};

#endif