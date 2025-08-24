#include <iostream>
#include "user.h"

using namespace std; 

int main(){
    int opcion;
    do {
        cout<<"Administrador de Usuarios"<< endl;
        cout<<"1. Ingresar usuario"<< endl;
        cout<<"2. Lista usuarios"<< endl;
        cout<<"3. Eliminar usuario"<< endl;
        cout<<"0. Salir"<< endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        

        switch(opcion){
            case 1:
                ingresarUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
                eliminarUsuario();
                break;
            case 0:
                cout<<"Adios..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<< endl;
        }
    }while(opcion !=0);


    return 0;
}