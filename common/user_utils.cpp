#include "user_utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void cargarUsuariosLista(ListaUser &lista){
    const char* ruta = getenv("USER_FILE");
    if (ruta == nullptr) {
        cerr << "Error: no se encontró la variable USER_FILE" << endl;
        return;
    }

    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cerr << "ERROR: No se pudo abrir el archivo en " << ruta << endl;
        return;
    }

    string linea;
    int maxId = 0;

    while (getline(archivo, linea)) {
        Usuario temporal;
        stringstream ss(linea);
        string u;

        getline(ss, u, ',');
        temporal.id = stoi(u);
        if (temporal.id > maxId) {
            maxId = temporal.id;
        }

        getline(ss, temporal.nombre, ',');
        getline(ss, temporal.username, ',');
        getline(ss, temporal.password, ',');
        getline(ss, temporal.perfil, ',');

        lista.usuarios.push_back(temporal);
    }

    lista.nextId = maxId + 1;
}