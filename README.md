# INFO198-Sistemas-Operativos---Proyecto


1. Proposito de la aplicacion

Este proyecto implementa un administrador de usuarios en C++.
El sistema permite:
Ingresar usuario (ID, nombre, username, password, perfil).
Listar los usuarios registrados.
Eliminar usuarios por ID.

Los usuarios se mantienen en memoria desde el inicio de la aplicacion y se van actualizando cada vez que se hace algun cambio y tambien se almacenan de manera persistentes en un archivo de texto 'USUARIOS.TXT'

2. Como se debe ejecutar
Desde la carpeta raiz del proyecto, ejecutar:
make
esto generara el ejecutable ./app
Para exportar la variable de entorno manualmente antes de ejecutar
export USER_FILE=data/USUARIOS.TXT
./app

3. Variables de entorno
El sistema una utiliza variable de entorno definida en un archivo .env

USER_FILE es la ruta del archivo donde se guardan los usuarios.


