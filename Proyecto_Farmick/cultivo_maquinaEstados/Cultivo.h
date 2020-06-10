#pragma once
#include "Estado_Cultivo.h"
#include "../Motor/Motor.h"

class Cultivo ///este es nuestro Contexto
{

public:
    Cultivo();
    void setEstado (Estado_Cultivo* nuevo_estado);
    void Hacer();
    void metodo_cargador_de_imagenes();

    //void setEstadoMotor(Estado_Cultivo* estado);

private:
    Estado_Cultivo* estado_actual;//composicion (un cultivo tiene un estado_cultivo)
    //Motor * estado_motor;
};




