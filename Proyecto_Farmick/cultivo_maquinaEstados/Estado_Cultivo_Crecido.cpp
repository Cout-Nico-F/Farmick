#include "Estado_Cultivo_Crecido.h"
#include "Estado_Cultivo_Terreno.h"
#include "../Motor/gestorTexturas.h"
#include "../Jugador.h"

Estado_Cultivo_Crecido::Estado_Cultivo_Crecido(Cultivo* contexto): _punteroAcultivo(contexto)
{
    progreso=0;
};

int Estado_Cultivo_Crecido::getProgreso()
{
    return progreso;
}

bool Estado_Cultivo_Crecido::aumentarProgreso()
{
    std::cout<<"Los frutos crecen "<<progreso+1<<"/4"<<std::endl;
    progreso++;
    if(progreso>=4)
    {
        return true;
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
    _punteroAcultivo->setM_mapaTexturas("terreno");
}

void Estado_Cultivo_Crecido::metodo_cargador_de_imagenes()
{
    GestorTexturas::getInstancia()->dibujar(_punteroAcultivo->getTextura(),_punteroAcultivo->getUbicacion_x(),_punteroAcultivo->getUbicacion_y(),100,50);
}
