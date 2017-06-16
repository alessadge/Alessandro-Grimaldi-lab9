in: Main.o Usuario.o Administrador.o Cliente.o Vehiculo.o 
	g++ Main.o Usuario.o Administrador.o Cliente.o Vehiculo.o -o Main

Main.o: Main.cpp Usuario.h Administrador.h Cliente.h Vehiculo.h 
	g++ -c Main.cpp
 
Usuario.o: Usuario.cpp Usuario.h 
	g++ -c Usuario.cpp 
 
Administrador.o:  Administrador.h Administrador.cpp Usuario.h 
	g++ -c Administrador.cpp 
 
Cliente.o:  Cliente.h Cliente.cpp Usuario.h 
	g++ -c Cliente.cpp 
 
Vehiculo.o: Vehiculo.cpp Vehiculo.h 
	g++ -c Vehiculo.cpp 
 
clean: 
	rm -f *.0 *.main
