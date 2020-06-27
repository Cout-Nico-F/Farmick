#include "Estado_Cultivo_Crecido.h"
#include "Estado_Cultivo_Terreno.h"
#include "../Motor/gestorTexturas.h"
#include "../Jugador.h"
#include "Timer.h"

Estado_Cultivo_Crecido::Estado_Cultivo_Crecido(Cultivo* contexto): _punteroAcultivo(contexto)
{
    tiempoCreacion = SDL_GetTicks();
    m_tiempoCrecimiento = 10000 * Timer::getInstancia()->getDeltaTime();
    progreso=0;
};

int Estado_Cultivo_Crecido::getProgreso()
{
    return progreso;
}

bool Estado_Cultivo_Crecido::aumentarProgreso()
{
    //std::cout<<"Los frutos crecen "<<progreso+1<<"/4"<<std::endl;
   if(SDL_GetTicks() - tiempoCreacion >= m_tiempoCrecimiento/6)
    {
        tiempoCreacion+=SDL_GetTicks()-tiempoCreacion;
        progreso++;
        if(progreso==6)return true;
    }
    return false;
}

void Estado_Cultivo_Crecido::hacer()
{
    std::cout<<"Crecido cambiando de estado hacia Terreno ( Se vendio la cosecha por 20 monedas )"<<std::endl;
    Jugador::getInstancia()->incrementarMonedas(20);

    _objeto = new Estado_Cultivo_Terreno(_punteroAcultivo);
    _punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
    _punteroAcultivo->setM_mapaTexturas("a00terreno");
}

void Estado_Cultivo_Crecido::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar(_punteroAcultivo->getTextura(),_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
