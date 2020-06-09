#include <iostream>
#include "Motor.h"
#include "cultivo_maquinaEstados/Cultivo.h"



int main(int argc, char** argv)
{



    Motor::GetInstancia()->inicializar();
//Bucle principal del juego ( Game Loop )
    while(Motor::GetInstancia()->juegoActivo())
    {
        //Eventos
        Motor::GetInstancia()->eventos();
        //Actualizacion
        Motor::GetInstancia()->actualizar();
        //Renderizado (Crear Dibujo)
        Motor::GetInstancia()->renderizar();
    }

    Motor::GetInstancia()->limpiar();//devuelve la memoria pedida

    return 0;
}

/* necesitamos :
-cargar dos imagenes usando el gestor de texturas.
-lograr vincular una imagen con cada uno de los 2 estados de la maquina de estados actual.
basicamente vamos a ver como cambia de una imagen a otra en la ventana de sdl.
*/
