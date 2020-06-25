#include "Estado_Cultivo_Crecido.h"
#include "Estado_Cultivo_Sembrado.h"
#include "../Motor/gestorTexturas.h"
#include "Timer.h"

Estado_Cultivo_Sembrado::Estado_Cultivo_Sembrado(Cultivo* contexto): _punteroAcultivo(contexto)
{
    progreso = SDL_GetTicks();//guarda el tick de cuando fue creado ( como si fuera su fecha de creacion )
    m_tiempoCrecimiento = 30000 * Timer::getInstancia()->getDeltaTime();
};

bool Estado_Cultivo_Sembrado::aumentarProgreso()
{
    //std::cout<<"Las plantas crecen "<<progreso+1<<"/4"<<std::endl;
    //progreso++;                                           //en este caso vamos a necesitar que el progreso sea en base al tiempo.
    if(SDL_GetTicks() - progreso >= m_tiempoCrecimiento)      //como minimo parece que necesito saber en que tick se creó el cultivo
    {                                                       //y en base a ese numero cuando se llega a tiempobase+tiempocultivo se dispara el metodo hacer (devuelve true el metodo aumentarProgreso)
        progreso = 0;
        return true;
    }
    else
        std::cout<<"Hay que darle mas tiempo al cultivo para crecer"<<std::endl;
    return false;
}

void Estado_Cultivo_Sembrado::hacer()
{
    std::cout<<"Sembrado cambiando de estado hacia Crecido"<<std::endl;

    _objeto = new Estado_Cultivo_Crecido(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
}

void Estado_Cultivo_Sembrado::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar("sembrado",_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
