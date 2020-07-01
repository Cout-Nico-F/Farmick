#include "Estado_Cultivo_Crecido.h"
#include "Estado_Cultivo_Sembrado.h"
#include "../Motor/gestorTexturas.h"
#include "Timer.h"

Estado_Cultivo_Sembrado::Estado_Cultivo_Sembrado(Cultivo* contexto): _punteroAcultivo(contexto)
{
    tiempoCreacion = SDL_GetTicks();//guarda el tick de cuando fue creado ( como si fuera su fecha de creacion )
    m_tiempoCrecimiento = 10000 * Timer::getInstancia()->getDeltaTime();
    progreso=0;
};

int Estado_Cultivo_Sembrado::getProgreso()
{
    return progreso;
}

bool Estado_Cultivo_Sembrado::aumentarProgreso()
{
    if(SDL_GetTicks() - tiempoCreacion >= m_tiempoCrecimiento/6)
    {
        tiempoCreacion+=SDL_GetTicks()-tiempoCreacion;
        progreso++;
        if(progreso==6)return true;
    }
    return false;
}

void Estado_Cultivo_Sembrado::hacer()
{
    std::cout<<"Sembrado cambiando de estado hacia Crecido"<<std::endl;

    _objeto = new Estado_Cultivo_Crecido(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
    _punteroAcultivo->setM_mapaTexturas("a19crecido");
}

void Estado_Cultivo_Sembrado::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar(_punteroAcultivo->getTextura(),_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
