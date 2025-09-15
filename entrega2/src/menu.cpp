#include <iostream>     // cout, cin
#include <fstream>      // ifstream
#include <sstream>      // stringstream
#include <string>       // std::string
#include <vector>       // std::vector
#include <map>     
#include <algorithm>     // std::map
#include "utils.h"
#include "../common/user_utils.h" 

using namespace std;


//escribir export USER_FILE=../data/USUARIOS.TXT
//para compilar make y despues ./bin/app2


map<string, vector<int>> cargarPerfiles(const string &ruta) {
    map<string, vector<int>> perfiles;
    ifstream archivo(ruta);
    string linea;

    while (getline(archivo, linea)) {
        string perfil, numeros;
        stringstream ss(linea);

        getline(ss, perfil, ';');     // ADMIN o GENERAL
        getline(ss, numeros);         // "0,1,2,3,4,5,6"

        stringstream sp(numeros);
        string num;
        vector<int> permisos;

        while (getline(sp, num, ',')) {
            permisos.push_back(stoi(num));
        }

        perfiles[perfil] = permisos;
    }

    return perfiles;
}

// ------------------- Mostrar menú según permisos -------------------
void mostrarMenu(const string &usuario, const string &perfil, const map<string, vector<int>> &perfiles) {
    if (perfiles.find(perfil) == perfiles.end()) {
        cout << "⚠️ Perfil no encontrado en PERFILES.TXT\n";
        return;
    }

    vector<int> permisos = perfiles.at(perfil);
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "Usuario: " << usuario << " | Perfil: " << perfil << "\n";
        cout << "--------------------------\n";

        for (int p : permisos) {
            switch (p) {
                case 0: cout << "0) Salir\n"; break;
                case 1: cout << "1) Admin de usuarios y perfiles\n"; break;
                case 2: cout << "2) Multiplica matrices NxN\n"; break;
                case 3: cout << "3) Juego\n"; break;
                case 4: cout << "4) ¿Es palindromo?\n"; break;
                case 5: cout << "5) Calcular f(x) = x*x + 2x + 8\n"; break;
                case 6: cout << "6) Conteo sobre texto\n"; break;
            }
        }

        cout << "==========================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (find(permisos.begin(), permisos.end(), opcion) == permisos.end()) {
            cout << "⚠️ No tienes permiso para esta opción.\n";
            continue;
        }

        switch (opcion) {
            case 1: adminUsuarios(); break;
            case 2: multiplicarMatrices(); break;
            case 3: iniciarJuego(); break;
            case 4: opcionPalindromo(); break;
            case 5: calcularFuncion(); break;
            case 6: conteoTexto(); break;
            case 0: cout << "Saliendo del programa...\n"; break;
        }

    } while (opcion != 0);
}

// ------------------- Main -------------------
int main(int argc, char* argv[]) {
    if (argc < 5) {
        cout << "Uso: ./app2 -u <usuario> -p <password>\n";
        return 1;
    }

    string usuario, password;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-u" && i + 1 < argc) usuario = argv[++i];
        else if (arg == "-p" && i + 1 < argc) password = argv[++i];
    }

    ListaUser lista;
    cargarUsuariosLista(lista);  // ya la tienes implementada
    auto perfiles = cargarPerfiles("../data/PERFILES.TXT");

    bool loginExitoso = false;

    for (const Usuario &u : lista.usuarios) {
        if (u.username == usuario && u.password == password) {
            loginExitoso = true;
            mostrarMenu(u.username, u.perfil, perfiles);
            break;
        }
    }

    if (!loginExitoso) {
        cout << "❌ Usuario o contraseña inválidos.\n";
    }

    return 0;
}