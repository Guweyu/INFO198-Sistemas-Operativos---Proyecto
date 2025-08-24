#include <string>
using namespace std;

struct Usuario{
    int id;
    string nombre;
    string username;
    string password;
    string perfil;
};


void ingresarUsuario();
void listarUsuarios();
void eliminarUsuario();