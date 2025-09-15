#include <string>
#include <vector>
using namespace std;

struct Usuario{
    int id;
    string nombre;
    string username;
    string password;
    string perfil;
};

struct ListaUser{
    vector<Usuario> usuarios;
    int nextId =1;
};

void cargarUsuariosLista(ListaUser &lista);