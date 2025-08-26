#include <iostream>
#include "user.h"

using namespace std; 

int main(){
    int opcion;
    ListaUser lista;
    cargarUsurariosLista(lista);
    
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
                ingresarUsuario(lista); //FUNCION CASI LISTA UNICO PROBLEMA ES QUE EL ID SE REINICIA CADA QUE SE EJECUTA EL PROGRAMA
                break;
            case 2:
                listarUsuarios(lista);
                break;
            case 3:
                eliminarUsuario(lista);
                break;
            case 0:
                cout<<"Adios..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<< endl;
        }
        cout<<endl;
    }while(opcion !=0);


    return 0;
}