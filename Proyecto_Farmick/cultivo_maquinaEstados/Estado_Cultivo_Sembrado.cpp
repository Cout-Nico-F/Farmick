#include "Estado_Cultivo_Sembrado.h"
#include "Estado_Cultivo_Terreno.h"
#include "../Motor/gestorTexturas.h"

Estado_Cultivo_Sembrado::Estado_Cultivo_Sembrado(Cultivo* contexto): _punteroAcultivo(contexto)
{

};

void Estado_Cultivo_Sembrado::hacer()
{
    std::cout<<"Sembrado cambiando de estado hacia Terreno"<<std::endl;

    _objeto = new Estado_Cultivo_Terreno(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
}

void Estado_Cultivo_Sembrado::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar("sembrado",_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
