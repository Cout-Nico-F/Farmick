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
//para el Prototipo
/* necesitamos como minimo:
+cargar dos imagenes usando el gestor de texturas.
+lograr vincular una imagen con cada uno de los 2 estados de la maquina de estados actual.
basicamente ver como cambia de una imagen a otra en la ventana de sdl usando los estados.
*/
//Para la entrega final
/*Objetivos:
+Indicador de monedas
+ciclo completo del cultivo
+implementar disparadores para el cambio de estado ( condiciones para que se efectue el cambio al estado correspondiente )
+
*/
