#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <typeinfo>
#include "Vehiculo.h"
#include "Cliente.h"
#include "Administrador.h"
#include "Usuario.h"

using namespace std;

string generarPlaca();
void listarCarros(vector<Vehiculo*>);
void guardarTxtUsuario(Usuario* usuario);
void guardarTxtVehiculo(Vehiculo* Vehiculo);
void guardarTxtFactura(string);
vector<Usuario*> cargarClientes(vector<Usuario*>);
vector<Vehiculo*> cargarVehiculos(vector<Vehiculo*> vehiculos);

int main(){
    vector<Usuario*> usuarios;
    ifstream file("Clientes.txt");
    if(file.is_open()){
        usuarios=cargarClientes(usuarios);
    } 
    vector<Vehiculo*> vehiculos;
    ifstream file1("Vehiculos.txt");
    if(file1.is_open()){
        vehiculos=cargarVehiculos(vehiculos);
    } 
    
    vector<Vehiculo*> vacio;
    vector<Vehiculo*> tempVeh;
    vector<string> facturas;
    Administrador adminRaiz;
    adminRaiz.setNombre("Admin");
    adminRaiz.setContrasena("qwerty");
    adminRaiz.setCargo("IT guy");
    adminRaiz.setSeguro(23456);
    int opcion=0;
    while (opcion != 5){
        cout<<"MENU"<<endl;
        cout<<"1.) LOGIN USUARIO"<<endl;
        cout<<"2.) LOGIN ADMINISTRADOR"<<endl;
        cout<<"3.) REGISTRARSE CLIENTE"<<endl;
        cout<<"4.) LISTAR USUARIOS"<<endl;
        cout<<"5.) SALIR "<<endl;
        cout<<"Eliga una opcion: "<<endl;
        cin>>opcion;

        if(opcion==1){
            string nombre, contrasena;
            stringstream acum,vacio2;
            Vehiculo* vehiculoRaiz;
            cout<<"Ingrese usuario: "<<endl;
            cin>>nombre;
            for (int i = 0; i < usuarios.size(); ++i)
            {
                if(usuarios[i]->getNombre().compare(nombre)==0){
                    cout<<"Ingrese contrasena:"<<endl;
                    cin>>contrasena;
                    if(usuarios[i]->getContrasena().compare(contrasena)==0){
                        Usuario* usuarioRaiz = usuarios[i];
                        int opcion2;
                         while (opcion2 != 3){
                         cout<<"\nMENU"<<endl;
                         cout<<"1.) Alquilar carro"<<endl;
                         cout<<"2.) Guardar factura"<<endl;
                         cout<<"3.) Salir"<<endl;
                         cout<<"Eliga una opcion: "<<endl;
                         cin>>opcion2;
                         tempVeh=vacio;
                         if(opcion2==1){
                            char resp='s';
                            while(resp=='s'||resp=='S'){
                            listarCarros(vehiculos);
                            int pos;
                            cout<<"Ingrese posicion de carro a alquilar: "<<endl;
                            cin>>pos;
                            vehiculoRaiz=vehiculos[pos];
                            if(vehiculoRaiz->getEstado()==false){
                                vehiculoRaiz->setEstado(true);
                                
                                cout<<"Carro alquilado!"<<endl;
                                acum<<"- Marca: "<<vehiculoRaiz->getMarca()<<" "<<"Placa: "<<vehiculoRaiz->getPlaca()<<" \n"
                                    <<"\n";
                            }else{
                                cout<<"El carro que escogio ya esta alquilado!"<<endl;
                            }
                            cout<<"Desea continuar[s/n]"<<endl;
                            cin>>resp;
                        }

                         }//fin if1
                         if(opcion2==2){
                             stringstream factura;
                             factura<<"Cliente: "<<usuarioRaiz->getNombre()<<"\n"<<acum.str();
                             
                             facturas.push_back(factura.str());
                             guardarTxtFactura(factura.str());
                             
                             
                         }
                     }//fin while


                    }//fin if
                }//fin if
            }//fin for
        }//fin opcion1

        if(opcion==2){
            string nombre, contrasena;
            cout<<"Ingrese nombre: "<<endl;
            cin>>nombre;
            if(nombre==adminRaiz.getNombre()){
                cout<<"Ingrese contrasena: "<<endl;
                cin>>contrasena;
                if(contrasena==adminRaiz.getContrasena()){
                    int opcion1;
                        while (opcion1 != 5){
                             cout<<"MENU"<<endl;
                             cout<<"1.) AGREGAR AUTO"<<endl;
                             cout<<"2.) MODIFICAR AUTO"<<endl;
                             cout<<"3.) ELIMINAR AUTO"<<endl;
                             cout<<"4.) REPORTE DE AUTOS"<<endl;
                             cout<<"5.) SALIR "<<endl;
                             cout<<"Eliga una opcion: "<<endl;
                             cin>>opcion1;

                             if(opcion1==1){
                                string placa,modelo,marca;
                                int year, precio;

                                placa=generarPlaca();
                                cout<<"Ingrese modelo: "<<endl;
                                cin>>modelo;
                                cout<<"Ingrese marca: "<<endl;
                                cin>>marca;
                                cout<<"Ingrese año: "<<endl;
                                cin>>year;
                                cout<<"Ingrese precio: "<<endl;
                                cin>>precio;

                                Vehiculo* vehiculoTemp = new Vehiculo(placa,modelo,marca,year,precio,false);
                                vehiculoTemp->setPrecio(precio);
                                vehiculos.push_back(vehiculoTemp);
                                guardarTxtVehiculo(vehiculoTemp);
                                cout<<"Se agrego el vehiculo exitosamente!"<<endl;

                             }
                             if(opcion1==2){
                                listarCarros(vehiculos);

                                int pos;
                                cout<<"Ingrese posicion que desea modificar: "<<endl;
                                cin>>pos;

                                string placa,modelo,marca;
                                int year, precio;

                                placa=generarPlaca();
                                cout<<"Ingrese modelo: "<<endl;
                                cin>>modelo;
                                cout<<"Ingrese marca: "<<endl;
                                cin>>marca;
                                cout<<"Ingrese año: "<<endl;
                                cin>>year;
                                cout<<"Ingrese precio: "<<endl;
                                cin>>precio;

                                vehiculos[pos]->setPlaca(placa);
                                vehiculos[pos]->setModelo(modelo);
                                vehiculos[pos]->setMarca(marca);
                                vehiculos[pos]->setYear(year);
                                vehiculos[pos]->setPrecio(precio);
                                cout<<"Se modifico el vehiculo exitosamente!"<<endl;

                             }
                             if(opcion1==3){
                                listarCarros(vehiculos);

                                int pos;
                                cout<<"Ingrese posicion que desea eliminar: "<<endl;
                                cin>>pos;

                                vehiculos.erase(vehiculos.begin()+pos);
                                cout<<"Se elimino el vehiculo exitosamente!"<<endl;
                             }
                             if(opcion1==4){
                                listarCarros(vehiculos);
                             }
                        }
                }
            }
        }//fin opcion2
        if(opcion==3){
            string membresia,nombre, contrasena;
            int op;
            cout<<"Ingrese un nombre"<<endl;
            cin>>nombre;
            cout<<"Ingrese una contrasena"<<endl;
            cin>>contrasena;
            cout<<"Ingrese una membresia"<<endl;
            cout<<"1)Platinum"<<endl;
            cout<<"2)Gold"<<endl;
            cout<<"3)Normal"<<endl;
            cin>>op;
                if(op==1){
                    membresia="Platinum";
                }
                if(op==2){
                    membresia="Gold";
                }
                if(op==3){
                    membresia="Normal";
                }else{
                    cout<<"Membresia no valida"<<endl;
                }
            Cliente* clienteTemp=new Cliente(membresia,nombre,contrasena);
            usuarios.push_back(clienteTemp);
            guardarTxtUsuario(clienteTemp);
            cout<<"Se agrego exitosamente!"<<endl;
        }
        if(opcion==4){
            int acum=0;
            for (int i = 0; i < usuarios.size(); i++)
            {
                   /* if(i==0){
                    cout<<adminRaiz.getNombre()<<", CONTRASENA SECRETA"<<" "<<adminRaiz.getSeguro()<<" "
                        <<adminRaiz.getCargo()<<endl;
                    }*/
                    //acum++;
                    cout<<i<<".) "<<usuarios[i]->getNombre()<<" "<<usuarios[i]->getContrasena()<<" "
                        <<reinterpret_cast<Cliente*>(usuarios[i])->getMembresia()<<endl;
                
            }
        }
    }//fin while
return 0;
}

string generarPlaca(){

stringstream ss;
string digito[6];
digito[0]="A";
digito[1]="B";
digito[2]="C";
digito[3]="D";
digito[4]="E";
digito[5]="G";


    for (int i = 0; i < 3; i++)
    {
        int rand1= rand()%5+1;
        ss<<digito[rand1];
    }
    ss<<"-";

    for (int i = 0; i < 4; i++)
    {
        int rand1= rand()%9+1;
        ss<<rand1;
    }

return ss.str();
}

void listarCarros(vector<Vehiculo*> vehiculos){
    for (int i = 0; i < vehiculos.size(); ++i)
    {
        cout<<i<<".) Placa: "<<vehiculos[i]->getPlaca()<<", Modelo: "<<vehiculos[i]->getModelo()<<", Marca: "<<
                vehiculos[i]->getMarca()<<", Year: "<<
                vehiculos[i]->getYear()<<", Precio: "<<vehiculos[i]->getPrecio()<<", Alquilado: ";
                if(vehiculos[i]->getEstado()==true){
                    cout<<"Si"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
    }
}

void guardarTxtUsuario(Usuario* usuario){
    ofstream archivo;
    string ruta="Nombre.txt";
    stringstream ss;
    ss<<"Clientes.txt";
    ruta=ss.str();
    archivo.open(ruta.c_str(),ios::app);
        Cliente* cliente = reinterpret_cast<Cliente*>(usuario);
        archivo<<usuario->getNombre()<<" "<<usuario->getContrasena()<<" "<<cliente->getMembresia()<<endl;
    
    archivo.close();
}

void guardarTxtVehiculo(Vehiculo* vehiculo){
    ofstream archivo;
    string estado;
    string ruta="Nombre.txt";
    stringstream ss;
    ss<<"Vehiculos.txt";
    ruta=ss.str();
    archivo.open(ruta.c_str(),ios::app);
    if(vehiculo->getEstado()==true){
        estado="Si";
    }else{
        estado="No";
    }
    archivo<<vehiculo->getPlaca()<<" "<<vehiculo->getModelo()<<" "<<vehiculo->getMarca()   
            <<" "<<vehiculo->getYear()<<" "<<vehiculo->getPrecio()<<" "<<estado<<endl;
    
    archivo.close();
}

void guardarTxtFactura(string factura){
    ofstream archivo;
    string ruta="Nombre.txt";
    stringstream ss;
    ss<<"Factura.txt";
    ruta=ss.str();
    archivo.open(ruta.c_str(),ios::app);
    archivo<<factura<<endl;   
    
    archivo.close();
}
 vector<Usuario*> cargarClientes(vector<Usuario*> usuarios){


        ifstream archivo("Clientes.txt"); //

        while(!archivo.eof()){

                string contrasena = "";
                string nombre = "";
                string membresia = "";

                archivo >> contrasena;
                archivo >> membresia;
                archivo >> nombre;

                Usuario* usuario = new Cliente(nombre,contrasena,membresia);
                usuarios.push_back(usuario);
        }
        archivo.close();

        return usuarios;
}

vector<Vehiculo*> cargarVehiculos(vector<Vehiculo*> vehiculos){


        ifstream archivo("Vehiculos.txt"); //

        while(!archivo.eof()){

                string placa="", modelo="", marca="";
                int year, precio;
                bool estado;

                archivo >> placa;
                archivo >> modelo;
                archivo >> marca;
                archivo >> year;
                archivo >> precio;
                archivo >> estado;

                Vehiculo* vehiculo = new Vehiculo(placa,modelo,marca,year,precio,estado);
                vehiculos.push_back(vehiculo);
        }
        archivo.close();

        return vehiculos;
}

