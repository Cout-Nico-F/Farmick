#include <iostream>
#include "Estado_Cultivo_Terreno.h"
#include "Estado_Cultivo_Arado.h"
#include "gestorTexturas.h"
#include "Motor.h"

Estado_Cultivo_Terreno::Estado_Cultivo_Terreno(Cultivo* contexto) : punteroAcultivo(contexto)
{
   //INFO SOBRE PORQUE SE HACE ESA ASIGNACION EN EL CONSTRUCTOR ESTE EN EL PRIMER COMENTARIO 298LIKES---> https://stackoverflow.com/questions/2785612/c-what-does-the-colon-after-a-constructor-mean
    progreso=0;
}

bool Estado_Cultivo_Terreno::aumentarProgreso()
{
    progreso++;
    if(progreso==10)    return true;
return false;
}

void Estado_Cultivo_Terreno::hacer()
{
    std::cout<<"Terreno cambiando de estado hacia Arado"<<std::endl;

    _objeto = new Estado_Cultivo_Arado(punteroAcultivo);
    punteroAcultivo->setEstado(_objeto);
    Motor::GetInstancia()->actualizarEstadoCultivo(_objeto);
}

void Estado_Cultivo_Terreno::metodo_cargador_de_imagenes()
    {
        GestorTexturas::getInstancia()->dibujar("logoGrande",120,66,728,259);
        GestorTexturas::getInstancia()->dibujar("click",591,570,174,70);
        GestorTexturas::getInstancia()->dibujar("terreno",punteroAcultivo->getUbicacion_x(),punteroAcultivo->getUbicacion_y(),100,50);
    }

