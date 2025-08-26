#include <iostream>
#include <fstream>
#include <sstream>
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
    do{
        cout<<"Tipo perfil(GENERAL O ADMIN): ";
        cin>>creaUsuario.perfil;
        for(char &c : creaUsuario.perfil) c = toupper(c);
    }while(creaUsuario.perfil!="GENERAL" && creaUsuario.perfil != "ADMIN");
    

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
    cout<<"Usuario guardado exitosamente"<<endl;
}

void listarUsuarios(const ListaUser &lista){
    cout<<"Se supone que inicia la funcion listarUsuario()"<<endl;
}

void eliminarUsuario(ListaUser &lista){
    cout<<"Se supone que inicia la funcion eliminarUsuario()"<<endl;
}

void cargarUsurariosLista(ListaUser &lista){
    ifstream archivo("data/USUARIOS.TXT");
    string linea;
    int maxId=0;

    while(getline(archivo, linea)){
        Usuario temporal;
        stringstream ss(linea);
        string u;

        getline(ss, u, ',');
        temporal.id=stoi(u);
        if (temporal.id>maxId){
            maxId=temporal.id;
        }
        getline(ss, temporal.nombre, ',');
        getline(ss, temporal.username, ',');
        getline(ss, temporal.password, ',');
        getline(ss, temporal.perfil, ',');

        lista.usuarios.push_back(temporal);
    }
    lista.nextId=maxId + 1;
}