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
    //std::cout<<"Las plantas crecen "<<progreso+1<<"/4"<<std::endl;
    //progreso++;                                           //en este caso vamos a necesitar que el progreso sea en base al tiempo.
    if(SDL_GetTicks() - tiempoCreacion >= m_tiempoCrecimiento/6)      //como minimo parece que necesito saber en que tick se creó el cultivo
    {
        tiempoCreacion+=SDL_GetTicks()-tiempoCreacion;                //y en base a ese numero cuando se llega a tiempobase+tiempocultivo se dispara el metodo hacer (devuelve true el metodo aumentarProgreso)
        progreso++;
        if(progreso==6)return true;
    }
//    else
//        std::cout<<"Hay que darle mas tiempo al cultivo para crecer"<<std::endl;
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
