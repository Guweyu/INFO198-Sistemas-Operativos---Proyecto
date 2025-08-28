#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
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

    cout << "1) Guardar     2) Cancelar" << endl;
    char opcion;
    cin >> opcion;

    if (opcion == '1') {
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

        cout << "Usuario guardado exitosamente" << endl;
    } else {
        cout << "Operación cancelada." << endl;
    }

}

void listarUsuarios(const ListaUser &lista){
    /*cout<<left<< setw(5)<<"ID"<<setw(20)<<"Nombre"<<setw(10)<<"Perfil"<<endl;
    for(const Usuario &u : lista.usuarios){
        cout<<left<<setw(5)<<u.id <<setw(20)<<u.nombre <<setw(10)<<u.perfil<<endl;
    }*/
    for(const Usuario &u : lista.usuarios){
        cout << "ID: " << u.id << endl;
        cout << "Nombre: " << u.nombre << endl;
        cout << "Perfil: " << u.perfil << endl;
        cout << "---------------------" << endl;
    }

}

void eliminarUsuario(ListaUser &lista){
    int id_elim;
    cout << "ID usuario a borrar: ";
    cin >> id_elim;

    int indice = -1;
    for (int i = 0; i < (int)lista.usuarios.size(); i++) {
        if (lista.usuarios[i].id == id_elim) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "ERROR. El ID no existe." << endl;
        return;
    }

    Usuario u = lista.usuarios[indice];

   
    if (u.perfil == "ADMIN") {
        cout << "ALERTA. Se está intentando eliminar un usuario ADMIN. "
             << "Esto puede ser un error." << endl;
    }

    cout << "¿Seguro que deseas eliminar al usuario con ID = " << u.id << "?" << endl;
    cout << "1) Guardar     2) Cancelar" << endl;
    char opcion;
    cin >> opcion;

    if (opcion == '1') {
        lista.usuarios.erase(lista.usuarios.begin() + indice);

        //reescribir archivo txt 
        ofstream archivo("data/USUARIOs.TXT", ios::trunc);
        if(archivo.is_open()){
            for(const Usuario &usr : lista.usuarios){
                archivo << usr.id << "," << usr.nombre << "," << usr.username << "," << usr.password << "," << usr.perfil << endl;
            }
            archivo.close();

            cout << "Usuario eliminado exitosamente." << endl;
        }else{
            cerr << "ERROR. No se pudo abrir el archivo para reescribir" << endl;
        }
    } else {
        cout << "Operación cancelada." << endl;
    }
}

void cargarUsuariosLista(ListaUser &lista){
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