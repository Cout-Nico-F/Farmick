#include <iostream>
#include "Motor.h"

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

    Motor::GetInstancia()->limpiar();

    return 0;
}


