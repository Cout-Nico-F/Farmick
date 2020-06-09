#pragma once
#include "Estado_Cultivo.h"

class Cultivo ///este es nuestro Contexto
{

public:
    Cultivo();
    void setEstado (Estado_Cultivo* nuevo_estado);
    void Hacer();

private:
    Estado_Cultivo* estado_actual;//composicion (un cultivo tiene un estado_cultivo)


};




