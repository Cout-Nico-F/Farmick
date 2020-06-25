#include "Estado_Cultivo_Crecido.h"
#include "Estado_Cultivo_Terreno.h"
#include "../Motor/gestorTexturas.h"

Estado_Cultivo_Crecido::Estado_Cultivo_Crecido(Cultivo* contexto): _punteroAcultivo(contexto)
{
    progreso=0;
};

bool Estado_Cultivo_Crecido::aumentarProgreso()
{
    progreso++;
    if(progreso==4)
        return true;
    return false;
}

void Estado_Cultivo_Crecido::hacer()
{
    std::cout<<"Crecido cambiando de estado hacia Terreno"<<std::endl;

    _objeto = new Estado_Cultivo_Terreno(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
}

void Estado_Cultivo_Crecido::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar("crecido",_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
