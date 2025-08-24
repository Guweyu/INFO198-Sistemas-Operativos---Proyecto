#include <iostream>
#include <fstream>
#include "user.h"

using namespace std;

void ingresarUsuario(ListaUser &lista){
    Usuario creaUsuario;
    creaUsuario.id = lista.nextId++;
    cout<<"Nombre: ";
    cin>>creaUsuario.nombre;
    cout<<"username: ";
    cin>>creaUsuario.username;
    cout<<"password: ";
    cin>>creaUsuario.password;
    cout<<"Tipo perfil: ";
    cin>>creaUsuario.perfil;
    lista.usuarios.push_back(creaUsuario);
    const char* ruta = getenv("USER_FILE");
    if (ruta == nullptr) {
        cerr << "Error: no se encontro la variable USER_FILE" << endl;
        return;
    }
    ofstream archivo(ruta, ios::app);
    if (archivo.is_open()){
        archivo<<creaUsuario.id<<","<<creaUsuario.nombre<<","<<creaUsuario.username<<","<<creaUsuario.password<<","<<creaUsuario.perfil<<endl;
        archivo.close();
    }
}

void listarUsuarios(const ListaUser &lista){
    cout<<"Se supone que inicia la funcion listarUsuario()"<<endl;
}

void eliminarUsuario(ListaUser &lista){
    cout<<"Se supone que inicia la funcion eliminarUsuario()"<<endl;
}