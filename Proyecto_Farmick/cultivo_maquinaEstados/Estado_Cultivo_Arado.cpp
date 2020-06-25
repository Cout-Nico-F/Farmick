#include <iostream>
#include "Estado_Cultivo_Sembrado.h"
#include "Estado_Cultivo_Arado.h"
#include "../Motor/gestorTexturas.h"

Estado_Cultivo_Arado::Estado_Cultivo_Arado(Cultivo* contexto): _punteroAcultivo(contexto)//(esta inicializando el atributo)
{
 //_contexto(contexto) esto es lo mismo que: _contexto = contexto;
 progreso=0;
};

bool Estado_Cultivo_Arado::aumentarProgreso()
{
    progreso++;
    if(progreso==5)    return true;
return false;
}

void Estado_Cultivo_Arado::hacer()
{
    std::cout<<"Arado cambiando de estado hacia Sembrado"<<std::endl;
    //Cuando el metodo hacer lo implementa estado_cultivo_arado hace algo diferente a cuando hacer es implementado por otra clase de estado ( ej terreno)
    //GestorTexturas::getInstancia()->borrar("logoGrande");
    //GestorTexturas::getInstancia()->borrar("arada");

    _objeto = new Estado_Cultivo_Sembrado(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);//En esta linea estamos cambiando de estado hacia terreno.
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);

}

void Estado_Cultivo_Arado::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar("arado",_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}

