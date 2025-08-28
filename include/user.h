#include <string>
#include <vector>
using namespace std;

struct Usuario{
    int id;
    string nombre;
    string username;
    string password;
    string perfil;  //puede ser "ADMIN" o "GENERAL"
};

struct ListaUser{
    vector<Usuario> usuarios;
    int nextId =1;
};

void ingresarUsuario(ListaUser &lista);
void listarUsuarios(const ListaUser &lista);
void eliminarUsuario(ListaUser &lista);
void cargarUsuariosLista(ListaUser &lista);