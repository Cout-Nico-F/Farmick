#include <iostream>
#include "Estado_Cultivo_Sembrado.h"
#include "Estado_Cultivo_Arado.h"
#include "../Motor/gestorTexturas.h"
#include "../Jugador.h"

Estado_Cultivo_Arado::Estado_Cultivo_Arado(Cultivo* contexto): _punteroAcultivo(contexto)//(esta inicializando el atributo)
{
//_contexto(contexto) esto es lo mismo que: _contexto = contexto;
    progreso=0;
};

int Estado_Cultivo_Arado::getProgreso()
{
    return progreso;
}

bool Estado_Cultivo_Arado::aumentarProgreso()
{
    std::cout<<"Preparando el arado "<<progreso+1<<"/4"<<std::endl;
    progreso++;
    if(progreso>=6)
    {
        return true;
    }
    return false;
}

void Estado_Cultivo_Arado::hacer()
{
    if(Jugador::getInstancia()->getSemillas() >= 1)
    {
        Jugador::getInstancia()->gastarSemillas();
        std::cout<<"Arado cambiando de estado hacia Sembrado"<<std::endl;

        _objeto = new Estado_Cultivo_Sembrado(_punteroAcultivo);
        _punteroAcultivo->setEstado(_objeto);//En esta linea estamos cambiando de estado hacia terreno.
        Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
        _punteroAcultivo->setM_mapaTexturas("a13sembrado");
    }
    else
    {
        SDL_Log("Necesitas al menos un paquete de semillas para poder sembrar");
    }

}

void Estado_Cultivo_Arado::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar(_punteroAcultivo->getTextura(),_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}

