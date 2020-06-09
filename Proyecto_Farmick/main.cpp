#include <iostream>
#include "Motor.h"
#include "cultivo_maquinaEstados/Cultivo.h"

int main(int argc, char** argv)
{

    Cultivo cultivo1;


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

        //a modo de prueba de la maquina de estados de cultivo:
        cultivo1.Hacer();

    }

    Motor::GetInstancia()->limpiar();

    return 0;
}


